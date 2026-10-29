"""Bind extracted XA sectors to their preserved original BCD addresses"""
from pathlib import Path
import hashlib
import json

ROOT = Path(__file__).resolve().parents[1]


def position(block):
    def bcd(value):
        if value >> 4 > 9 or value & 15 > 9:
            raise ValueError('Invalid BCD sector address')
        return (value >> 4) * 10 + (value & 15)
    return (bcd(block[12]) * 60 + bcd(block[13])) * 75 + bcd(block[14]) - 150


def main():
    rows = []
    for path in sorted((ROOT / 'bin/DATA/XA').rglob('*.XA')):
        size = path.stat().st_size
        digest = hashlib.sha256()
        with path.open('rb') as file:
            header = file.read(44)
            if header[:4] != b'RIFF' or header[8:12] != b'CDXA':
                raise ValueError('Expected extracted RIFF/CDXA: ' + str(path))
            if (size - 44) % 2352:
                raise ValueError('Incomplete XA sector: ' + str(path))
            digest.update(header)
            first = None
            count = 0
            while block := file.read(2352):
                digest.update(block)
                lba = position(block)
                if first is None:
                    first = lba
                if block[:12] != b'\0' + b'\xff' * 10 + b'\0' or block[15] != 2 or lba != first + count:
                    raise ValueError('Noncontiguous or invalid XA source: ' + str(path))
                count += 1
        rows.append(dict(path=path.relative_to(ROOT / 'bin').as_posix(), first_sector=first,
                         sectors=count, header_bytes=44, sha256=digest.hexdigest()))
    rows.sort(key=lambda row: row['first_sector'])
    for left, right in zip(rows, rows[1:]):
        if left['first_sector'] + left['sectors'] > right['first_sector']:
            raise ValueError('Overlapping extracted XA ranges')
    text = '// Generated from complete extracted XA sector headers\nstatic const AdCdFile ad_cd_index[] = {\n'
    text += ''.join('    {"%s", %du, %du, %du},\n' % (r['path'], r['first_sector'], r['sectors'], r['header_bytes']) for r in rows)
    text += '};\n'
    (ROOT / 'src/native_data_cd_files.h').write_bytes(text.encode())
    (ROOT / 'status/xa-file-source-index.json').write_text(json.dumps(dict(
        source='Extracted RIFF/CDXA files; every physical sector address checked', files=rows), indent=2) + '\n')
    print(json.dumps(dict(files=len(rows), sectors=sum(r['sectors'] for r in rows))))


if __name__ == '__main__':
    main()
