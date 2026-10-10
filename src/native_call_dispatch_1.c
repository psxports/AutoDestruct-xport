#include "native_call_dispatch.h"

uint64 native_dispatch_group_1(uint32 target, uint32 argument_count, va_list args)
{
    uint64 result;
    switch (target)
    {
        case 0x80034264u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_80034264();
            break;
        }
        case 0x8003438Cu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8003438C(p0);
            break;
        }
        case 0x800345B0u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800345B0(p0);
            break;
        }
        case 0x80034820u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80034820(p0, p1);
            break;
        }
        case 0x80034868u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80034868(p0);
            break;
        }
        case 0x80034C88u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_80034C88();
            break;
        }
        case 0x80034CA8u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80034CA8(p0);
            break;
        }
        case 0x800352C4u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_800352C4();
            break;
        }
        case 0x80035664u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80035664(p0);
            break;
        }
        case 0x800356D8u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_800356D8();
            break;
        }
        case 0x8003570Cu:
        {
            native_dispatch_require(target, argument_count, 0u);
            sub_8003570C();
            result = 0;
            break;
        }
        case 0x80035758u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_80035758();
            break;
        }
        case 0x80035780u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_80035780(&p0);
            break;
        }
        case 0x800358DCu:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_800358DC(&p0);
            break;
        }
        case 0x80035988u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80035988(p0);
            break;
        }
        case 0x80035A08u:
        {
            native_dispatch_require(target, argument_count, 4u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p4 = {0};
            p4.stack_pointer = native_dispatch_stack(target, argument_count, 4u, args);
            result = (uint64)sub_80035A08(p0, p1, p2, p3, &p4);
            break;
        }
        case 0x80035CD0u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80035CD0(p0, p1);
            break;
        }
        case 0x80035FD8u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_80035FD8();
            break;
        }
        case 0x800360BCu:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            sub_800360BC(&p0);
            result = 0;
            break;
        }
        case 0x80036188u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80036188(p0, p1);
            break;
        }
        case 0x800361FCu:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800361FC(p0, p1);
            break;
        }
        case 0x800362B8u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p1 = {0};
            p1.stack_pointer = native_dispatch_stack(target, argument_count, 1u, args);
            result = (uint64)sub_800362B8(p0, &p1);
            break;
        }
        case 0x80036348u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_80036348(&p0);
            break;
        }
        case 0x80036434u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80036434(p0, p1);
            break;
        }
        case 0x80036584u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80036584(p0, p1);
            break;
        }
        case 0x800369E0u:
        {
            native_dispatch_require(target, argument_count, 4u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800369E0(p0, p1, p2, p3);
            break;
        }
        case 0x80036BE4u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_80036BE4();
            break;
        }
        case 0x80036CFCu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80036CFC(p0);
            break;
        }
        case 0x80036D6Cu:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_80036D6C();
            break;
        }
        case 0x80036E10u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_80036E10();
            break;
        }
        case 0x80036E9Cu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            sub_80036E9C(p0);
            result = 0;
            break;
        }
        case 0x80036EA8u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p1 = {0};
            p1.stack_pointer = native_dispatch_stack(target, argument_count, 1u, args);
            result = (uint64)sub_80036EA8(p0, &p1);
            break;
        }
        case 0x80036EDCu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80036EDC(p0);
            break;
        }
        case 0x80036F0Cu:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_80036F0C();
            break;
        }
        case 0x80036FE4u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_80036FE4();
            break;
        }
        case 0x8003708Cu:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8003708C();
            break;
        }
        case 0x80037150u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_80037150(&p0);
            break;
        }
        case 0x80037320u:
        {
            native_dispatch_require(target, argument_count, 0u);
            sub_80037320();
            result = 0;
            break;
        }
        case 0x8003732Cu:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8003732C(p0, p1);
            break;
        }
        case 0x80037490u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_80037490();
            break;
        }
        case 0x800374BCu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800374BC(p0);
            break;
        }
        case 0x800375A4u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_800375A4();
            break;
        }
        case 0x800375F0u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_800375F0();
            break;
        }
        case 0x800376C0u:
        {
            native_dispatch_require(target, argument_count, 0u);
            sub_800376C0();
            result = 0;
            break;
        }
        case 0x800376D0u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_800376D0();
            break;
        }
        case 0x80037864u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_80037864();
            break;
        }
        case 0x800379BCu:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_800379BC();
            break;
        }
        case 0x800379FCu:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_800379FC();
            break;
        }
        case 0x80037BB8u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_80037BB8();
            break;
        }
        case 0x80037D50u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_80037D50();
            break;
        }
        case 0x80037D8Cu:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_80037D8C();
            break;
        }
        case 0x8003806Cu:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameSceneCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_8003806C(&p0);
            break;
        }
        case 0x800380A8u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_800380A8();
            break;
        }
        case 0x800380C8u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameMainCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_800380C8(&p0);
            break;
        }
        case 0x8003893Cu:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameMainCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_8003893C(&p0);
            break;
        }
        case 0x80038964u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            sub_80038964(p0);
            result = 0;
            break;
        }
        case 0x80038970u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80038970(p0);
            break;
        }
        case 0x800389A8u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameMainCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_800389A8(&p0);
            break;
        }
        case 0x800389DCu:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_800389DC();
            break;
        }
        case 0x800389E8u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800389E8(p0);
            break;
        }
        case 0x80038B78u:
        {
            native_dispatch_require(target, argument_count, 0u);
            sub_80038B78();
            result = 0;
            break;
        }
        case 0x80038CDCu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80038CDC(p0);
            break;
        }
        case 0x800390E4u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_800390E4();
            break;
        }
        case 0x8003915Cu:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8003915C();
            break;
        }
        case 0x80039198u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_80039198();
            break;
        }
        case 0x80039224u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_80039224();
            break;
        }
        case 0x800392B4u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_800392B4(&p0);
            break;
        }
        case 0x800394B8u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameMainCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            sub_800394B8(&p0);
            result = 0;
            break;
        }
        case 0x8003AB60u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8003AB60(p0);
            break;
        }
        case 0x8003ABE4u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8003ABE4();
            break;
        }
        case 0x8003ACE4u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8003ACE4();
            break;
        }
        case 0x8003AD54u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_8003AD54(&p0);
            break;
        }
        case 0x8003ADE0u:
        {
            native_dispatch_require(target, argument_count, 0u);
            sub_8003ADE0();
            result = 0;
            break;
        }
        case 0x8003ADF4u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8003ADF4(p0);
            break;
        }
        case 0x8003AF20u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8003AF20();
            break;
        }
        case 0x8003B170u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8003B170();
            break;
        }
        case 0x8003B1ECu:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8003B1EC();
            break;
        }
        case 0x8003B3B0u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8003B3B0();
            break;
        }
        case 0x8003B574u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p2 = {0};
            p2.stack_pointer = native_dispatch_stack(target, argument_count, 2u, args);
            result = (uint64)sub_8003B574(p0, p1, &p2);
            break;
        }
        case 0x8003B864u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_8003B864(&p0);
            break;
        }
        case 0x8003B8E8u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8003B8E8(p0, p1);
            break;
        }
        case 0x8003B990u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8003B990(p0);
            break;
        }
        case 0x8003BA80u:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p3 = {0};
            p3.stack_pointer = native_dispatch_stack(target, argument_count, 3u, args);
            result = (uint64)sub_8003BA80(p0, p1, p2, &p3);
            break;
        }
        case 0x8003BD78u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8003BD78(p0, p1);
            break;
        }
        case 0x8003BE08u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p1 = {0};
            p1.stack_pointer = native_dispatch_stack(target, argument_count, 1u, args);
            result = (uint64)sub_8003BE08(p0, &p1);
            break;
        }
        case 0x8003BEA8u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p1 = {0};
            p1.stack_pointer = native_dispatch_stack(target, argument_count, 1u, args);
            result = (uint64)sub_8003BEA8(p0, &p1);
            break;
        }
        case 0x8003BEFCu:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_8003BEFC(&p0);
            break;
        }
        case 0x8003BF34u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p1 = {0};
            p1.stack_pointer = native_dispatch_stack(target, argument_count, 1u, args);
            result = (uint64)sub_8003BF34(p0, &p1);
            break;
        }
        case 0x8003BFACu:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_8003BFAC(&p0);
            break;
        }
        case 0x8003C058u:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p3 = {0};
            p3.stack_pointer = native_dispatch_stack(target, argument_count, 3u, args);
            result = (uint64)sub_8003C058(p0, p1, p2, &p3);
            break;
        }
        case 0x8003C0C4u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_8003C0C4(&p0);
            break;
        }
        case 0x8003C114u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_8003C114(&p0);
            break;
        }
        case 0x8003C2B8u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p1 = {0};
            p1.stack_pointer = native_dispatch_stack(target, argument_count, 1u, args);
            result = (uint64)sub_8003C2B8(p0, &p1);
            break;
        }
        case 0x8003C374u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameMainCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            sub_8003C374(&p0);
            result = 0;
            break;
        }
        case 0x8003C394u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_8003C394(&p0);
            break;
        }
        case 0x8003C3D4u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_8003C3D4(&p0);
            break;
        }
        case 0x8003C4B8u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_8003C4B8(&p0);
            break;
        }
        case 0x8003C5E4u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_8003C5E4(&p0);
            break;
        }
        case 0x8003C6D8u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p1 = {0};
            p1.stack_pointer = native_dispatch_stack(target, argument_count, 1u, args);
            result = (uint64)sub_8003C6D8(p0, &p1);
            break;
        }
        case 0x8003C87Cu:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_8003C87C(&p0);
            break;
        }
        case 0x8003C958u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_8003C958(&p0);
            break;
        }
        case 0x8003CA20u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8003CA20();
            break;
        }
        case 0x8003CA68u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8003CA68(p0);
            break;
        }
        case 0x8003CAB4u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8003CAB4(p0);
            break;
        }
        case 0x8003CAFCu:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8003CAFC();
            break;
        }
        case 0x8003CB14u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8003CB14();
            break;
        }
        case 0x8003CB54u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8003CB54(p0, p1);
            break;
        }
        case 0x8003CB98u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8003CB98(p0);
            break;
        }
        case 0x8003CCE0u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8003CCE0(p0, p1);
            break;
        }
        case 0x8003CF6Cu:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8003CF6C();
            break;
        }
        case 0x8003CF8Cu:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8003CF8C();
            break;
        }
        case 0x8003CFECu:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8003CFEC();
            break;
        }
        case 0x8003CFF8u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            sub_8003CFF8(p0);
            result = 0;
            break;
        }
        case 0x8003D0F4u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_8003D0F4(&p0);
            break;
        }
        case 0x8003D270u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8003D270();
            break;
        }
        case 0x8003D27Cu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            sub_8003D27C(p0);
            result = 0;
            break;
        }
        case 0x8003D324u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            sub_8003D324(p0);
            result = 0;
            break;
        }
        case 0x8003D338u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8003D338(p0, p1);
            break;
        }
        case 0x8003D654u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8003D654();
            break;
        }
        case 0x8003D67Cu:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8003D67C();
            break;
        }
        case 0x8003D688u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8003D688();
            break;
        }
        case 0x8003D694u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            sub_8003D694(p0);
            result = 0;
            break;
        }
        case 0x8003D6A0u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            sub_8003D6A0(p0);
            result = 0;
            break;
        }
        case 0x8003D6ACu:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8003D6AC();
            break;
        }
        case 0x8003D6B8u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            sub_8003D6B8(p0);
            result = 0;
            break;
        }
        case 0x8003D6F0u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8003D6F0();
            break;
        }
        case 0x8003D7F0u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p1 = {0};
            p1.stack_pointer = native_dispatch_stack(target, argument_count, 1u, args);
            result = (uint64)sub_8003D7F0(p0, &p1);
            break;
        }
        case 0x8003DB0Cu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8003DB0C(p0);
            break;
        }
        case 0x8003E5C4u:
        {
            native_dispatch_require(target, argument_count, 4u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8003E5C4(p0, p1, p2, p3);
            break;
        }
        case 0x8003E690u:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8003E690(p0, p1, p2);
            break;
        }
        case 0x8003E868u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8003E868(p0, p1);
            break;
        }
        case 0x8003E988u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8003E988(p0);
            break;
        }
        case 0x8003EFDCu:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8003EFDC(p0, p1);
            break;
        }
        case 0x8003F0F8u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8003F0F8(p0, p1);
            break;
        }
        case 0x8003F1B8u:
        {
            native_dispatch_require(target, argument_count, 7u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            uint32 p4 = (uint32)va_arg(args, uint32);
            uint32 p5 = (uint32)va_arg(args, uint32);
            uint32 p6 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8003F1B8(p0, p1, p2, p3, p4, p5, p6);
            break;
        }
        case 0x8003F2C4u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8003F2C4(p0);
            break;
        }
        case 0x8003F310u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8003F310(p0);
            break;
        }
        case 0x8003F7D8u:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            sub_8003F7D8(p0, p1, p2);
            result = 0;
            break;
        }
        case 0x8003FAD0u:
        {
            native_dispatch_require(target, argument_count, 4u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8003FAD0(p0, p1, p2, p3);
            break;
        }
        case 0x800407C0u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800407C0(p0);
            break;
        }
        case 0x80040840u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80040840(p0);
            break;
        }
        case 0x800408C0u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800408C0(p0);
            break;
        }
        case 0x8004094Cu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8004094C(p0);
            break;
        }
        case 0x80040964u:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80040964(p0, p1, p2);
            break;
        }
        case 0x800409E4u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800409E4(p0);
            break;
        }
        case 0x80040AECu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80040AEC(p0);
            break;
        }
        case 0x80040E78u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80040E78(p0, p1);
            break;
        }
        case 0x80040EF4u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80040EF4(p0);
            break;
        }
        case 0x80040F94u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80040F94(p0);
            break;
        }
        case 0x800410E4u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800410E4(p0, p1);
            break;
        }
        case 0x80041604u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80041604(p0);
            break;
        }
        case 0x800416CCu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800416CC(p0);
            break;
        }
        case 0x80041710u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_80041710();
            break;
        }
        case 0x800418E4u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800418E4(p0);
            break;
        }
        case 0x80041C9Cu:
        {
            native_dispatch_require(target, argument_count, 9u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p4 = {0};
            p4.stack_pointer = native_dispatch_stack(target, argument_count, 4u, args);
            result = (uint64)sub_80041C9C(p0, p1, p2, p3, &p4);
            break;
        }
        case 0x80041D90u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80041D90(p0, p1);
            break;
        }
        case 0x80041DB4u:
        {
            native_dispatch_require(target, argument_count, 4u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            sub_80041DB4(p0, p1, p2, p3);
            result = 0;
            break;
        }
        case 0x80041DE0u:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80041DE0(p0, p1, p2);
            break;
        }
        case 0x80041DF8u:
        {
            native_dispatch_require(target, argument_count, 5u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            uint32 p4 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80041DF8(p0, p1, p2, p3, p4);
            break;
        }
        case 0x80041E1Cu:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            sub_80041E1C(p0, p1);
            result = 0;
            break;
        }
        case 0x80041E24u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p2 = {0};
            p2.stack_pointer = native_dispatch_stack(target, argument_count, 2u, args);
            result = (uint64)sub_80041E24(p0, p1, &p2);
            break;
        }
        case 0x8004206Cu:
        {
            native_dispatch_require(target, argument_count, 5u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            uint32 p4 = native_dispatch_stack(target, argument_count, 4u, args);
            result = (uint64)sub_8004206C(p0, p1, p2, p3, p4);
            break;
        }
        case 0x800420C4u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p2 = {0};
            p2.stack_pointer = native_dispatch_stack(target, argument_count, 2u, args);
            result = (uint64)sub_800420C4(p0, p1, &p2);
            break;
        }
        case 0x80042130u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameSceneCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_80042130(&p0);
            break;
        }
        case 0x80042290u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p1 = {0};
            p1.stack_pointer = native_dispatch_stack(target, argument_count, 1u, args);
            result = (uint64)sub_80042290(p0, &p1);
            break;
        }
        case 0x80042318u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p1 = {0};
            p1.stack_pointer = native_dispatch_stack(target, argument_count, 1u, args);
            result = (uint64)sub_80042318(p0, &p1);
            break;
        }
        case 0x80042424u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = native_dispatch_stack(target, argument_count, 1u, args);
            result = (uint64)sub_80042424(p0, p1);
            break;
        }
        case 0x800424BCu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p1 = {0};
            p1.stack_pointer = native_dispatch_stack(target, argument_count, 1u, args);
            result = (uint64)sub_800424BC(p0, &p1);
            break;
        }
        case 0x80042598u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_80042598();
            break;
        }
        case 0x800428B0u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_800428B0();
            break;
        }
        case 0x80042D64u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p1 = {0};
            p1.stack_pointer = native_dispatch_stack(target, argument_count, 1u, args);
            result = (uint64)sub_80042D64(p0, &p1);
            break;
        }
        case 0x80042E14u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_80042E14(&p0);
            break;
        }
        case 0x80042ED4u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_80042ED4(&p0);
            break;
        }
        case 0x8004307Cu:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_8004307C(&p0);
            break;
        }
        case 0x800431ECu:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_800431EC(&p0);
            break;
        }
        case 0x8004328Cu:
        {
            native_dispatch_require(target, argument_count, 7u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p4 = {0};
            p4.stack_pointer = native_dispatch_stack(target, argument_count, 4u, args);
            result = (uint64)sub_8004328C(p0, p1, p2, p3, &p4);
            break;
        }
        case 0x800433D4u:
        {
            native_dispatch_require(target, argument_count, 4u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800433D4(p0, p1, p2, p3);
            break;
        }
        case 0x800436D4u:
        {
            native_dispatch_require(target, argument_count, 5u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            uint32 p4 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800436D4(p0, p1, p2, p3, p4);
            break;
        }
        case 0x80043820u:
        {
            native_dispatch_require(target, argument_count, 6u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            uint32 p4 = (uint32)va_arg(args, uint32);
            uint32 p5 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80043820(p0, p1, p2, p3, p4, p5);
            break;
        }
        case 0x800439A4u:
        {
            native_dispatch_require(target, argument_count, 6u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p4 = {0};
            p4.stack_pointer = native_dispatch_stack(target, argument_count, 4u, args);
            result = (uint64)sub_800439A4(p0, p1, p2, p3, &p4);
            break;
        }
        case 0x80043DF4u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80043DF4(p0);
            break;
        }
        case 0x800440E0u:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800440E0(p0, p1, p2);
            break;
        }
        case 0x800442ACu:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800442AC(p0, p1);
            break;
        }
        case 0x800442FCu:
        {
            native_dispatch_require(target, argument_count, 7u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            uint32 p4 = (uint32)va_arg(args, uint32);
            uint32 p5 = (uint32)va_arg(args, uint32);
            uint32 p6 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800442FC(p0, p1, p2, p3, p4, p5, p6);
            break;
        }
        case 0x80044534u:
        {
            native_dispatch_require(target, argument_count, 4u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80044534(p0, p1, p2, p3);
            break;
        }
        case 0x800445E0u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_800445E0();
            break;
        }
        case 0x80044618u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_80044618();
            break;
        }
        case 0x80044C78u:
        {
            native_dispatch_require(target, argument_count, 4u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80044C78(p0, p1, p2, p3);
            break;
        }
        case 0x80044E68u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_80044E68();
            break;
        }
        case 0x80044F50u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80044F50(p0);
            break;
        }
        case 0x80044F8Cu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80044F8C(p0);
            break;
        }
        case 0x8004510Cu:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8004510C(p0, p1);
            break;
        }
        case 0x800451B4u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800451B4(p0, p1);
            break;
        }
        case 0x8004525Cu:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8004525C();
            break;
        }
        case 0x80045280u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80045280(p0);
            break;
        }
        case 0x800452B8u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800452B8(p0);
            break;
        }
        case 0x800452E8u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800452E8(p0, p1);
            break;
        }
        case 0x8004530Cu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8004530C(p0);
            break;
        }
        case 0x80045340u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80045340(p0, p1);
            break;
        }
        case 0x8004549Cu:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8004549C(p0, p1);
            break;
        }
        case 0x8004557Cu:
        {
            native_dispatch_require(target, argument_count, 5u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            uint32 p4 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8004557C(p0, p1, p2, p3, p4);
            break;
        }
        case 0x80045AD8u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80045AD8(p0, p1);
            break;
        }
        case 0x80045DD4u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80045DD4(p0);
            break;
        }
        case 0x80045E18u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80045E18(p0, p1);
            break;
        }
        case 0x80045EB0u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80045EB0(p0);
            break;
        }
        case 0x80046004u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80046004(p0, p1);
            break;
        }
        case 0x800461BCu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800461BC(p0);
            break;
        }
        case 0x800461DCu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800461DC(p0);
            break;
        }
        case 0x800463F0u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800463F0(p0);
            break;
        }
        case 0x8004644Cu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8004644C(p0);
            break;
        }
        case 0x800464B0u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800464B0(p0);
            break;
        }
        case 0x800465A8u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800465A8(p0, p1);
            break;
        }
        case 0x800467A4u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800467A4(p0);
            break;
        }
        case 0x800469E8u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800469E8(p0);
            break;
        }
        case 0x80046A58u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80046A58(p0);
            break;
        }
        case 0x80046E18u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80046E18(p0);
            break;
        }
        case 0x80046E9Cu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80046E9C(p0);
            break;
        }
        case 0x80047124u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80047124(p0);
            break;
        }
        case 0x800473C8u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800473C8(p0);
            break;
        }
        case 0x80047438u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80047438(p0);
            break;
        }
        case 0x80047480u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80047480(p0);
            break;
        }
        case 0x80047670u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80047670(p0);
            break;
        }
        case 0x800476D8u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800476D8(p0);
            break;
        }
        case 0x80047718u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80047718(p0, p1);
            break;
        }
        case 0x80047788u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80047788(p0, p1);
            break;
        }
        case 0x80047CF0u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80047CF0(p0);
            break;
        }
        case 0x80048F9Cu:
        {
            native_dispatch_require(target, argument_count, 4u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80048F9C(p0, p1, p2, p3);
            break;
        }
        default:
            abort();
    }
    return result;
}
