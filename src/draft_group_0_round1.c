#include "draft_signatures.h"
#include <stdlib.h>

// FUNCTION_MARKER sub_80064D60
uint32 sub_80064D60(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    // TODO Bind the existing deferred free helper
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80064CECu,object)));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80065124
uint32 sub_80065124(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 callbacks=0x800910A0u,result;
    draft_call_adapter(0x8006F1D0u,1u);
    for(;;) {
        result=(uint32)draft_call_adapter(0x8006F22Cu);
        if(result) return draft_scratch_result(native_stack_mark, (uint64)(result));
        if(draft_call_adapter(r_u32(callbacks))) callbacks+=4u;
        /* Service native VBlank after the original scheduler callback */
        if (VSync(0) < 0) abort();
    }

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800650CC
uint32 sub_800650CC(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 callbacks=0x800910A0u,result;
    for(;;) {
        // TODO Bind DrawSync and synchronization callbacks
        result=(uint32)draft_call_adapter(0x8007FF6Cu,1u);
        if(!result) return draft_scratch_result(native_stack_mark, (uint64)(result));
        if(draft_call_adapter(r_u32(callbacks))) callbacks+=4u;
    }

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8006197C
uint32 sub_8006197C(uint32 surface,uint32 object_type)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 kind=surface&0xFEu;
    uint32 result=kind==16u?16u:(kind==8u || kind==64u)?1u:512u;
    if(((object_type&0xFFu)==15u || ((object_type-7u)&0xFFu)<2u || !(object_type&0xFFu)) && result>=257u) result=256u;
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80065F68
uint32 sub_80065F68(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    int32 result;
    // TODO Bind the existing particle update and random helper
    draft_call_adapter(0x80065EB0u,object,r_u32(0x800A9010u));
    result=(int8)r_u8(object+13u);
    if(result<0) {
        w_u16(object+32u,r_u16(r_u32(0x800A62ECu)+92u));
        w_u8(object+13u,(uint8)(((uint32)draft_call_adapter(0x80069A50u)&31u)+20u));
        result=(int32)0x80065FD8u;
        w_u32(object,(uint32)result);
    }
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80069EFC
uint32 sub_80069EFC(uint32 wanted,uint32 node)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 i=0u;
    while(i<(r_u32(r_u32(0x800A84FCu)+8u*node+4u)&15u)) {
        // TODO Bind the existing graph-neighbor lookup
        if((uint32)draft_call_adapter(0x80069D8Cu,node,i)==wanted) return draft_scratch_result(native_stack_mark, (uint64)(i));
        ++i;
    }
    return draft_scratch_result(native_stack_mark, (uint64)(0xFFFFFFFFu));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80069F84
uint32 sub_80069F84(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 count=r_u32(r_u32(0x800A84FCu)+8u*object+4u)&15u,start,i;
    if(!count) return draft_scratch_result(native_stack_mark, (uint64)(0xFFFFFFFFu));
    // TODO Bind random and graph-neighbor helpers
    start=(uint32)draft_call_adapter(0x80069A50u)%count;
    for(i=start;i<count;++i) {
        uint32 node=(uint32)draft_call_adapter(0x80069D8Cu,object,i);
        if(!(r_u32(r_u32(0x800A84FCu)+8u*node+4u)&0x400u)) return draft_scratch_result(native_stack_mark, (uint64)(node));
    }
    for(i=0u;i<start;++i) {
        uint32 node=(uint32)draft_call_adapter(0x80069D8Cu,object,i);
        if(!(r_u32(r_u32(0x800A84FCu)+8u*node+4u)&0x400u)) return draft_scratch_result(native_stack_mark, (uint64)(node));
    }
    return draft_scratch_result(native_stack_mark, (uint64)(0xFFFFFFFFu));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80077A20
uint32 sub_80077A20(uint32 text,uint32 maximum_width)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 original=(uint32)(int32)(int16)r_u16(0x800A9A5Cu),packed_count=0u,output=0x800A8334u;
    for(;;) {
        uint32 c=r_u8(text),width;
        if(!c || c==32u || c==160u || c==10u || c==13u) break;
        packed_count+=0x10000u;
        w_u8(output++,(uint8)c);
        ++text;
        width=(uint32)(int32)(int16)r_u16(0x800A9A5Cu)+r_u8(0x800903F6u+5u*c);
        w_u16(0x800A9A5Cu,(uint16)width);
        if((int32)maximum_width<(int16)width) {
            w_u16(0x800A9A5Cu,(uint16)original);
            return draft_scratch_result(native_stack_mark, (uint64)(0u));
        }
    }
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)((int32)packed_count>>16)));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8005A944
uint32 sub_8005A944(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 i,buffer=r_u32(0x800A62F4u),object=r_u32(0x800A62ECu),phase=r_u32(0x800A7454u),result;
    for(i=0;i<2u;++i) {
        uint32 dest=2u*(uint32)(int32)(int16)r_u16(object+120u)+i;
        uint32 source=2u*((uint32)(int32)(int16)r_u16(object+122u)+phase)+i;
        w_u32(buffer+4u*dest+20u,r_u32(buffer+4u*source+20u));
    }
    phase=r_u32(0x800A7450u)+76u*(uint32)((int32)r_u32(0x800A63D8u)>>8);
    w_u32(0x800A7450u,phase);
    if((int32)phase>983039) w_u32(0x800A7450u,phase-983040u);
    result=(uint32)(int32)(int16)r_u16(0x800A7452u);
    w_u32(0x800A7454u,result);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80070634
uint32 sub_80070634(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    int32 current=(int16)sub_80037BB8(),previous=(int32)r_u32(0x800A6474u);
    int32 state=current==previous?current:-1;
    uint32 result;
    w_u32(0x800A6474u,(uint32)current);
    if(state==0) { w_u16(r_u32(0x80091EF8u)+30u,8u); return draft_scratch_result(native_stack_mark, (uint64)(8u)); }
    if(state==2 || state==3) {
        w_u16(r_u32(0x80091EF8u)+30u,10u);
        result=state==2?14u:48u;
        w_u16(0x80091F5Cu,(uint16)result);
        w_u16(0x8009204Cu,(uint16)result);
        return draft_scratch_result(native_stack_mark, (uint64)(result));
    }
    // TODO Bind menu transition helper
    draft_call_adapter(0x80070700u,2u);
    result=r_u32(0x80092054u);
    w_u16(result+14u,0u);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80043820
uint32 sub_80043820(uint32 text,uint32 color,uint32 x,uint32 y,uint32 depth,uint32 fixed_width)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 origin=x-160u,cursor=origin,baseline=y-120u;
    for(;;) {
        uint32 c=r_u8(text++),font;
        if(!c || c==10u || c==13u) break;
        font=r_u32(0x800A5F68u);
        if(c==32u) { cursor+=r_u8(font+162u); continue; }
        // TODO Bind glyph primitive construction
        draft_call_adapter(0x8004328Cu,font,0x54000040u,c,color,cursor,baseline+1u,depth);
        font=r_u32(0x800A5F68u);
        if(r_u8(font+5u*c+4u)!=1u && r_u8(font+5u*c+4u)!=6u)
            draft_call_adapter(0x8004328Cu,font,0x64000040u,c,color,cursor+1u,baseline+2u,depth);
        cursor+=fixed_width?15u:r_u8(r_u32(0x800A5F68u)+5u*c+2u);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(cursor-origin));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800213F4
uint32 sub_800213F4(uint32 ordering_table,uint32 packet,uint32 x,uint32 y,uint32 width,uint32 height)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 rectangle=draft_scratch_adapter(8u),head=ordering_table+7996u;
    // TODO Bind draw-area and tile packet SDK helpers
    draft_call_adapter(0x80080800u,0x800A6720u);
    w_u16(rectangle,(uint16)x);
    w_u16(rectangle+2u,(uint16)(256u-(uint32)(int32)(int16)r_u16(0x800A6722u)+y));
    w_u16(rectangle+4u,(uint16)width);
    w_u16(rectangle+6u,(uint16)height);
    draft_call_adapter(0x80080D84u,packet,rectangle);
    w_u32(packet,(r_u32(packet)&0xFF000000u)|(r_u32(head)&0xFFFFFFu));
    w_u32(head,(r_u32(head)&0xFF000000u)|(packet&0xFFFFFFu));
    return draft_scratch_result(native_stack_mark, (uint64)(packet+12u));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80056288
uint32 sub_80056288(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 timer=r_u32(object+80u),result=0xFFFFFFFFu;
    if((int32)timer>0) w_u32(object+80u,timer-1u);
    if(!r_u32(object+80u)) {
        uint32 state=r_u8(object+90u);
        w_u32(object+80u,0xFFFFFFFFu);
        if(state==7u) {
            // TODO The original null callback has no observable effects
            w_u16(object+114u,4u);
            w_u32(object,0x80045510u);
            if(r_u8(object+12u)>=4u) draft_call_adapter(0x8005F920u,object);
        } else {
            w_u32(0x800A6228u,r_u32(0x800A6228u)-1u);
            if(r_u8(object+12u)>=4u) draft_call_adapter(0x8005F920u,object);
            draft_call_adapter(0x8002289Cu,object);
        }
        result=r_u32(0x800A622Cu);
        if(result==object) w_u32(0x800A622Cu,0u);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8005792C
uint32 sub_8005792C(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 state=r_u8(object+90u),result=7u,i;
    if(state==7u) return draft_scratch_result(native_stack_mark, (uint64)(result));
    // TODO Bind voice cleanup and graph membership helper
    draft_call_adapter(0x80036CFCu,object+8u);
    for(i=0;i<2u;++i) {
        uint32 node=r_u16(object+64u+2u*i);
        uint32 index=(uint32)draft_call_adapter(0x80069E94u,node,object);
        if(index!=0xFFFFFFFFu) {
            uint32 offset=(uint32)((int32)r_u32(r_u32(0x800A84FCu)+8u*node+4u)>>11);
            uint32 slot=r_u32(0x800A7E2Cu)+4u*(offset+index);
            w_u32(slot,r_u32(slot)|0xFFFFF000u);
        }
    }
    state=r_u8(object+90u);
    result=(state-1u)<2u;
    if(state==6u || state-3u<2u || state==5u || result) {
        uint32 entry=r_u32(0x800A84FCu)+8u*r_u16(object+64u)+4u;
        result=r_u32(entry)&0xFFFFFEFFu;
        w_u32(entry,result);
    }
    w_u32(object+80u,0u);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80036434
uint32 sub_80036434(uint32 position,uint32 index)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 temporary=draft_scratch_adapter(20u),vector=temporary+12u,d0,d1,spread,distance;
    w_u32(vector,r_u32(0x800A5C58u));
    w_u32(vector+4u,r_u32(0x800A5C5Cu));
    sub_80031B6C(0x800A7EF4u,vector,temporary);
    // TODO Bind integer vector length
    d0=(uint32)draft_call_adapter(0x80069BE0u,r_u32(0x800A7EE4u)+r_u32(temporary)-r_u32(position),r_u32(0x800A7EECu)+r_u32(temporary+8u)-r_u32(position+8u));
    w_u16(vector,136u);
    sub_80031B6C(0x800A7EF4u,vector,temporary);
    d1=(uint32)draft_call_adapter(0x80069BE0u,r_u32(0x800A7EE4u)+r_u32(temporary)-r_u32(position),r_u32(0x800A7EECu)+r_u32(temporary+8u)-r_u32(position+8u));
    spread=(uint32)((int32)(d0+d1)>>7);
    distance=(uint32)draft_call_adapter(0x80069BE0u,r_u32(0x800A7EE4u)-r_u32(position),r_u32(0x800A7EECu)-r_u32(position+8u));
    w_u32(0x800A7C7Cu+(uint32)((int32)(index<<16)>>12),distance);
    return draft_scratch_result(native_stack_mark, (uint64)(spread+126u>=253u?0xFFFFFFFFu:0u));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800707D4
uint32 sub_800707D4(uint32 buttons)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 original=r_u32(0x800A6460u),fallback=original,retry=0u,result;
    uint32 forward=buttons&0x4000u,backward=buttons&0x1000u;
    do {
        uint32 current,menu,target,valid;
        if(forward) w_u32(0x800A6460u,r_u32(0x800A6460u)+1u);
        else if(!backward && retry) {
            result=(uint32)draft_call_adapter(0x80070938u,fallback);
            w_u32(0x800A6460u,result);
            return draft_scratch_result(native_stack_mark, (uint64)(result));
        }
        if(backward) w_u32(0x800A6460u,r_u32(0x800A6460u)-1u);
        current=r_u32(0x800A6460u);
        menu=r_u32(0x80091EE0u+12u*r_u32(0x800A645Cu));
        target=r_u32(menu+16u*current);
        // TODO Bind menu-item availability
        valid=(uint32)draft_call_adapter(0x80070A0Cu,target);
        if(valid) {
            retry=0u;
            if((int32)current<0 || current==r_u32(0x800A75C4u)) w_u32(0x800A6460u,fallback);
        } else {
            retry=1u;
            if((int32)current<0 || current==r_u32(0x800A75C4u)) {
                w_u32(0x800A6460u,fallback);
                retry=0u;
            }
        }
    } while(retry);
    result=r_u32(0x800A6460u);
    if(original!=result) return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80035A08u,29u,2048u,255u,0u)));
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80036BE4
uint32 sub_80036BE4(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 entry=0x800A7D64u,offset=224u;
    do {
        uint32 voice_pointer=r_u32(entry);
        int32 voice=(int8)r_u8(voice_pointer);
        if(voice>=0) {
            // TODO Bind SPU voice status and pitch helpers
            draft_call_adapter(0x80086EE4u,1u<<voice);
            if((int16)draft_call_adapter(0x80036584u,r_u32(0x800A7C80u+offset),(uint32)voice)==-1) {
                voice_pointer=r_u32(entry);
                draft_call_adapter(0x800899C0u,0u,1u<<r_u8(voice_pointer));
                w_u8(voice_pointer,254u);
                w_u32(entry,0x800A7DFCu);
            } else {
                voice=(int8)r_u8(r_u32(entry));
                draft_call_adapter(0x80086EBCu,0x800BBEFCu+((uint32)voice<<6));
            }
        }
        entry+=16u;
        offset+=16u;
    } while(entry<0x800A7E04u);
    return draft_scratch_result(native_stack_mark, (uint64)(0u));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80064E78
uint32 sub_80064E78(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 index=r_u32(0x800A7488u),pointer,block,left,right,left_index,right_index,flags=0u;
    if(index==r_u32(0x800A7484u)) return draft_scratch_result(native_stack_mark, (uint64)(1u));
    pointer=r_u32(0x800AA6A8u+4u*index);
    block=pointer-8u;
    left=block-(r_u32(pointer-4u)&0xFFFFFu);
    right=block+(r_u32(block)&0xFFFFFu);
    // TODO Bind free-list indexing and removal helpers
    left_index=(uint32)draft_call_adapter(0x80064D80u,left);
    right_index=(uint32)draft_call_adapter(0x80064D80u,block);
    if(left_index!=0xFFFFFFFFu) flags|=1u;
    if(right_index!=0xFFFFFFFFu) flags|=2u;
    if(flags) {
        uint32 active=flags==2u?right_index:left_index;
        uint32 size=right-left-((r_u32(left+4u)>>20)+((r_u32(left)>>20)<<12))-8u;
        if(flags==2u) w_u32(0x800AC6A8u+8u*active,left);
        w_u32(0x800AC6ACu+8u*active,size);
        if(flags==3u) {
            uint32 last=(uint32)draft_call_adapter(0x80064DCCu);
            if(last!=right_index) {
                uint32 source=0x800AC6A8u+8u*last,dest=0x800AC6A8u+8u*right_index;
                w_u32(dest,r_u32(source));
                w_u32(dest+4u,r_u32(source+4u));
            }
        }
    }
    w_u32(right+4u,(r_u32(right+4u)&0xFFF00000u)|((right-left)&0xFFFFFu));
    w_u32(left,(r_u32(left)&0xFFF00000u)|((right-left)&0xFFFFFu));
    if(!flags) draft_call_adapter(0x80064DF4u,left);
    index=r_u32(0x800A7488u)+1u;
    if(index==2048u) index=0u;
    w_u32(0x800A7488u,index);
    return draft_scratch_result(native_stack_mark, (uint64)(0u));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80030040
uint32 sub_80030040(uint32 output,uint32 previous,uint32 position,uint32 offsets)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 temporary=draft_scratch_adapter(24u),candidate=temporary+12u,i,mask=1u,result=0u;
    w_u16(output+96u,0u);
    w_u16(output+98u,0u);
    for(i=0;i<3u;++i) w_u32(temporary+4u*i,r_u32(previous+4u*i));
    sub_8002F3FC(temporary,position);
    for(i=0;i<3u;++i) w_u32(temporary+4u*i,r_u32(position+4u*i));
    w_u32(candidate+4u,r_u32(position+4u));
    for(i=0;i<8u;++i,mask=(mask*2u)&255u) {
        uint32 offset=offsets+8u*i;
        w_u32(candidate,r_u32(position)+(uint32)(int32)(int16)r_u16(offset));
        w_u32(candidate+8u,r_u32(position+8u)+(uint32)(int32)(int16)r_u16(offset+4u));
        if(sub_8002F3FC(temporary,candidate)<<16) {
            uint32 hit=output+12u*i;
            result=i+1u;
            if(i>=4u) w_u16(output+96u,(uint16)(r_u16(output+96u)&15u));
            w_u16(output+96u,(uint16)(r_u16(output+96u)|mask));
            w_u32(hit,r_u32(temporary));
            w_u32(hit+8u,r_u32(temporary+8u));
            if(r_u32(temporary)) w_u32(position,r_u32(candidate)-(uint32)(int32)(int16)r_u16(offset));
            if(r_u32(temporary+8u)) w_u32(position+8u,r_u32(candidate+8u)-(uint32)(int32)(int16)r_u16(offset+4u));
            w_u32(temporary,r_u32(position));
            w_u32(temporary+8u,r_u32(position+8u));
        }
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8004E80C
uint32 sub_8004E80C(uint32 object,uint32 motion,uint32 previous)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 temporary=draft_scratch_adapter(16u),i,result;
    int32 hit;
    for(i=0;i<3u;++i) w_u32(temporary+4u*i,r_u32(previous+4u*i));
    // TODO Bind object collision corner construction
    draft_call_adapter(0x80029DDCu,object,0x800A6EF8u,r_u8(r_u32(0x800A8548u)+r_u16(object+32u)));
    result=sub_80030040(0x800A6F38u,temporary,object+20u,0x800A6EF8u)<<16;
    hit=(int32)result>>16;
    if(hit) {
        if(!r_u8(object+88u)) {
            for(i=0;i<3u;++i) w_u32(object+20u+4u*i,r_u32(object+128u+4u*i));
            draft_call_adapter(0x8004C8A8u,object);
        }
        w_u32(motion,r_u32(motion)<<8);
        w_u32(motion+8u,r_u32(motion+8u)<<8);
        // TODO Bind wall motion adjustment
        draft_call_adapter(0x80023918u,r_u32(0x800A6F38u+12u*((uint32)hit-1u)),r_u32(0x800A6F40u+12u*((uint32)hit-1u)),motion,motion+8u);
        w_u32(motion,(uint32)((int32)r_u32(motion)>>8));
        w_u32(motion+8u,(uint32)((int32)r_u32(motion+8u)>>8));
        result=r_u32(0x800A6F98u);
        w_u8(object+88u,(uint8)result);
    } else w_u8(object+88u,0u);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80029EEC
uint32 sub_80029EEC(uint32 object,uint32 corners,uint32 output)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 i,j,command[3]={0x486012u,0x48E012u,0x496012u};
    uint32 reverse=(int16)r_u16(object+44u)<0;
    uint32 slots[4]={reverse?1u:0u,reverse?0u:1u,reverse?3u:2u,reverse?2u:3u};
    for(i=0;i<5u;++i) xport_gte_write_control(i,r_u32(object+36u+4u*i));
    for(i=0;i<6u;++i) xport_gte_write_data(i,r_u32(corners+4u*i));
    for(i=0;i<3u;++i) {
        draft_gte_command_adapter(command[i]);
        for(j=0;j<3u;++j) w_u16(output+8u*slots[i]+2u*j,(uint16)xport_gte_read_data(9u+j));
    }
    xport_gte_write_data(0u,r_u32(corners+24u));
    xport_gte_write_data(1u,r_u32(corners+28u));
    draft_gte_command_adapter(0x486012u);
    for(j=0;j<3u;++j) w_u16(output+8u*slots[3]+2u*j,(uint16)xport_gte_read_data(9u+j));
    return draft_scratch_result(native_stack_mark, (uint64)(output+8u*slots[3]));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80049FBC
uint32 sub_80049FBC(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 entity=r_u32(object);
    w_u32(0x800A6FD0u,0u);
    while((uint32)(int32)(int16)r_u16(entity+188u)<r_u32(0x800A63E4u)) {
        uint32 node,packed,distance;
        if((int32)r_u32(0x800A6FD0u)>=20) break;
        // TODO Bind waypoint lookup and vector length
        node=(uint32)draft_call_adapter(0x800476D8u,r_u16(entity+188u));
        w_u32(object+12u,(r_u32(node)&0x3FFu)<<9);
        node=(uint32)draft_call_adapter(0x800476D8u,r_u16(r_u32(object)+188u));
        w_u32(object+20u,((r_u32(node)>>10)&0x3FFu)<<9);
        entity=r_u32(object);
        distance=(uint32)draft_call_adapter(0x80069BE0u,r_u32(entity+20u)-r_u32(object+12u),r_u32(entity+28u)-r_u32(object+20u));
        if((int32)distance<(int32)r_u32(r_u32(object)+80u)) {
            node=(uint32)draft_call_adapter(0x800476D8u,r_u16(r_u32(object)+188u));
            packed=r_u32(node);
            w_u32(object+16u,0u-256u*((packed>>20)&255u));
            entity=r_u32(object);
            w_u16(0x800A6FD4u,(uint16)sub_80055A9C(r_u32(object+12u)-r_u32(entity+20u),r_u32(object+20u)-r_u32(entity+28u)));
            if(!draft_call_adapter(0x80049AC0u,object,(uint32)(int32)(int16)r_u16(0x800A6FD4u))) {
                entity=r_u32(object);
                w_u32(entity+80u,distance);
                w_u16(entity+170u,r_u16(entity+188u));
            }
        }
        entity=r_u32(object);
        w_u16(entity+188u,(uint16)(r_u16(entity+188u)+1u));
        w_u32(0x800A6FD0u,r_u32(0x800A6FD0u)+1u);
    }
    entity=r_u32(object);
    w_u16(entity+112u,0u);
    w_u8(entity+199u,1u);
    w_u8(entity+87u,1u);
    w_u16(entity+114u,0u);
    return draft_scratch_result(native_stack_mark, (uint64)(entity));

    draft_scratch_release(native_stack_mark);
}

static void d01_vectors(uint32 first,uint32 second,uint32 third)
{
    xport_gte_write_data(0u,r_u32(first));xport_gte_write_data(1u,r_u32(first+4u));
    xport_gte_write_data(2u,r_u32(second));xport_gte_write_data(3u,r_u32(second+4u));
    xport_gte_write_data(4u,r_u32(third));xport_gte_write_data(5u,r_u32(third+4u));
}

static void d01_link(uint32 cursor,uint32 table,uint32 bias,uint32 depth,uint32 length)
{
    uint32 link=table+4u*bias+4u*(uint32)((int32)depth>>3);
    w_u32(cursor,(r_u32(link)&0xFFFFFFu)|(length<<24));
    w_u32(link,(r_u32(link)&0xFF000000u)|(cursor&0xFFFFFFu));
}

// FUNCTION_MARKER sub_8001A660
uint32 sub_8001A660(uint32 cursor,uint32 vertices,uint32 source,uint32 ordering_table,uint32 depth_bias,uint32 count,uint32 next_source)
{
    uint32 native_stack_mark = draft_scratch_mark();

    while(count--) {
        uint32 record=source+20u,depth;
        d01_vectors(vertices+8u*r_u16(record-10u),vertices+8u*r_u16(record-6u),vertices+8u*r_u16(record-2u));
        draft_gte_command_adapter(0x280030u);
        xport_gte_write_data(0u,r_u32(vertices+8u*r_u16(record+2u)));
        xport_gte_write_data(1u,r_u32(vertices+8u*r_u16(record+2u)+4u));
        draft_gte_command_adapter(0x1400006u);
        if((int32)xport_gte_read_data(24u)>=0) {
            draft_gte_command_adapter(0x158002Du);
            depth=xport_gte_read_data(7u);
            if(depth) {
                w_u32(cursor+8u,xport_gte_read_data(12u));w_u32(cursor+16u,xport_gte_read_data(13u));w_u32(cursor+24u,xport_gte_read_data(14u));
                draft_gte_command_adapter(0x180001u);
                d01_vectors(vertices+8u*r_u16(record-12u),vertices+8u*r_u16(record-8u),vertices+8u*r_u16(record-4u));
                xport_gte_write_data(6u,r_u32(source+4u));
                w_u32(cursor+32u,xport_gte_read_data(14u));
                draft_gte_command_adapter(0x118043Fu);
                xport_gte_write_data(0u,r_u32(vertices+8u*r_u16(record)));
                xport_gte_write_data(1u,r_u32(vertices+8u*r_u16(record)+4u));
                w_u32(cursor+4u,xport_gte_read_data(20u));w_u32(cursor+12u,xport_gte_read_data(21u));w_u32(cursor+20u,xport_gte_read_data(22u));
                draft_gte_command_adapter(0x108041Bu);
                d01_link(cursor,ordering_table,depth_bias,depth,8u);
                w_u32(cursor+28u,xport_gte_read_data(22u));
                cursor+=36u;
            }
        }
        source+=24u;
    }
    w_u32(next_source,source);
    return draft_scratch_result(native_stack_mark, (uint64)(cursor));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8001B76C
uint32 sub_8001B76C(uint32 cursor,uint32 vertices,uint32 source,uint32 ordering_table,uint32 uv,uint32 depth_bias,uint32 count,uint32 next_source)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 saved[5],i;
    xport_gte_write_data(6u,0x3C808080u);
    for(i=0;i<5u;++i) saved[i]=draft_gte_control_adapter(i);
    // TODO Original also reads translation controls without restoring them
    for(i=5u;i<8u;++i) draft_gte_control_adapter(i);
    while(count--) {
        uint32 record=source+8u,depth,rotation;
        d01_vectors(vertices+8u*r_u16(record+14u),vertices+8u*r_u16(record+18u),vertices+8u*r_u16(record+22u));
        draft_gte_command_adapter(0x280030u);
        xport_gte_write_data(0u,r_u32(vertices+8u*r_u16(record+26u)));
        xport_gte_write_data(1u,r_u32(vertices+8u*r_u16(record+26u)+4u));
        draft_gte_command_adapter(0x158002Du);
        depth=xport_gte_read_data(7u);
        if(depth) {
            draft_gte_command_adapter(0x1400006u);
            if((int32)xport_gte_read_data(24u)>=0) {
                w_u32(cursor+8u,xport_gte_read_data(12u));w_u32(cursor+20u,xport_gte_read_data(13u));w_u32(cursor+32u,xport_gte_read_data(14u));
                draft_gte_command_adapter(0x180001u);
                d01_vectors(vertices+8u*r_u16(record+12u),vertices+8u*r_u16(record+16u),vertices+8u*r_u16(record+20u));
                w_u32(cursor+44u,xport_gte_read_data(14u));
                draft_gte_command_adapter(0xF80416u);
                w_u32(uv,r_u16(record-4u));w_u32(uv+8u,r_u16(record));
                rotation=r_u32(0x800A84B0u);
                for(i=0;i<5u;++i) xport_gte_write_control(i,r_u32(rotation+4u*i));
                draft_gte_command_adapter(0x486012u);
                w_u32(uv+24u,r_u32(record+4u));w_u32(uv+32u,r_u32(record+8u));
                w_u8(uv,(uint8)(((int16)xport_gte_read_data(9u)>>6)+64));
                draft_gte_command_adapter(0x48E012u);
                xport_gte_write_data(0u,r_u32(vertices+8u*r_u16(record+24u)));
                xport_gte_write_data(1u,r_u32(vertices+8u*r_u16(record+24u)+4u));
                w_u8(uv+8u,(uint8)(((int16)xport_gte_read_data(9u)>>6)+64));
                draft_gte_command_adapter(0x496012u);
                w_u32(cursor+12u,(r_u32(record-4u)&0xFFFF0000u)|r_u32(uv));
                w_u8(uv+24u,(uint8)(((int16)xport_gte_read_data(9u)>>6)+64));
                draft_gte_command_adapter(0x486012u);
                w_u32(cursor+24u,(r_u32(record)&0xFFFF0000u)|r_u32(uv+8u));
                w_u8(uv+32u,(uint8)(((int16)xport_gte_read_data(9u)>>6)+64));
                for(i=0;i<5u;++i) xport_gte_write_control(i,saved[i]);
                w_u32(cursor+4u,xport_gte_read_data(20u));w_u32(cursor+16u,xport_gte_read_data(21u));w_u32(cursor+28u,xport_gte_read_data(22u));
                draft_gte_command_adapter(0xE80413u);
                w_u32(cursor+48u,r_u32(uv+32u));w_u32(cursor+36u,r_u32(uv+24u));
                d01_link(cursor,ordering_table,depth_bias,depth,12u);
                w_u32(cursor+40u,xport_gte_read_data(22u));
                cursor+=52u;
            }
        }
        source+=36u;
    }
    w_u32(next_source,source);
    return draft_scratch_result(native_stack_mark, (uint64)(cursor));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80061A78
uint32 sub_80061A78(uint32 object,uint32 points,uint32 tags,uint32 force_mask,uint32 excluded_mask,uint32 count)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result=r_u8(object+12u)<4u,i,temporary=draft_scratch_adapter(76u),tag=temporary+48u;
    if(result) { for(i=0;i<4u;++i) w_u8(points+48u+i,0u); return draft_scratch_result(native_stack_mark, (uint64)(result)); }
    result=0u;
    for(i=0;(int32)i<(int32)count;++i) {
        uint32 current=r_u8(points+48u+i),bit=1u<<i,forced=force_mask&bit;
        w_u32(tag,current);
        if(!(excluded_mask&bit)) {
            // TODO Bind terrain-contact tag classification
            draft_call_adapter(0x80061938u,r_u8(tags+i),tag,forced);
            current=r_u32(tag);
            if(forced || (current&0xFEu)==64u || (current&0xFEu)==8u || (current&0xFEu)==16u) {
                uint32 kind=sub_8006197C(current,r_u8(object+13u)&127u);
                uint32 strength=(uint32)draft_call_adapter(0x800619FCu,current);
                uint32 local=temporary+12u*i;
                uint32 model=r_u32(0x800A9750u)+40u*r_u8(r_u32(0x800A8548u)+r_u16(object+32u))+8u*i;
                draft_call_adapter(0x80031CE8u,object+36u,object+20u,model,local);
                draft_call_adapter(0x80031CC0u,model,local);
                // TODO Original GTE output is written to the matching temporary triplet
                if(current&1u) draft_call_adapter(0x80061E1Cu,points+12u*i,local,kind,strength,current);
                else {
                    uint32 j;
                    w_u32(tag,current|1u);
                    w_u32(local+4u,0u-(uint32)draft_call_adapter(0x8002E310u,local,temporary+56u,temporary+64u));
                    for(j=0;j<3u;++j) w_u32(points+12u*i+4u*j,r_u32(local+4u*j));
                }
                w_u8(points+48u+i,(uint8)r_u32(tag));
                result=i+1u<count;
                continue;
            }
        }
        if(current) w_u8(points+48u+i,0u);
        result=(int32)(i+1u)<(int32)count;
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8006F950
uint32 sub_8006F950(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 row=30u,index=0u,entry,menu=r_u32(0x80091EE0u+12u*object);
    uint32 title=r_u32(0x800A8B38u+4u*r_u16(0x80091ED8u+12u*object));
    w_u32(0x800A75C8u,0u);
    sub_80043820(title,0x7F7F7Fu,28u,18u,100u,0u);
    while((entry=r_u32(menu+16u*index))!=0u) {
        // TODO Bind menu-entry filtering and string selection
        if(draft_call_adapter(0x80070A0Cu,entry)) {
            uint32 color=r_u32(0x800A6460u)==index?0x7F7F7Fu:0x4F4F4Fu;
            uint32 strings=r_u32(0x800A8B38u+4u*r_u16(0x80091EDAu+12u*object));
            uint32 text=(uint32)draft_call_adapter(0x8006F554u,strings,index),width;
            row+=entry==265u?18u:12u;
            width=sub_80043820(text,color,30u,row,100u,0u);
            if((int32)r_u32(0x800A75C8u)<(int32)width) w_u32(0x800A75C8u,width);
        }
        ++index;
        menu=r_u32(0x80091EE0u+12u*object);
    }
    w_u32(0x800A75C4u,index);
    draft_call_adapter(0x80020C60u,199u,r_u32(0x800A9A74u),0x3F3F3Fu,2u,0u-140u,0u-120u,50u,240u);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80020C60u,200u,r_u32(0x800A9A74u),r_u32(0x80092054u+4u*r_u32(0x800A9A38u)),2u,0u-160u,0u-120u,320u,240u)));

    draft_scratch_release(native_stack_mark);
}

static uint32 d01_inside(uint32 polygon,uint32 x,uint32 z,uint32 bx,uint32 bz)
{
    uint32 px[4],pz[4],i;
    for(i=0;i<4u;++i) {
        uint32 offset=i?6u+4u*(i-1u):0u;
        px[i]=bx+(uint32)(int32)(int16)r_u16(polygon+offset);
        pz[i]=bz+(uint32)(int32)(int16)r_u16(polygon+(i?offset+2u:4u));
    }
    for(i=0;i<4u;++i) {
        uint32 j=(i+1u)&3u;
        if((int32)((pz[i]-pz[j])*(x-px[j])+(px[j]-px[i])*(z-pz[j]))<0) return 0u;
    }
    return 1u;
}

static int32 d01_div(uint32 numerator,uint32 denominator)
{
    if(!denominator || (denominator==0xFFFFFFFFu && numerator==0x80000000u)) abort();
    return (int32)numerator/(int32)denominator;
}

// FUNCTION_MARKER sub_8002FC90
uint32 sub_8002FC90(uint32 object,uint32 output,uint32 corners,uint32 update_flag)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 i,result=0u,model=r_u32(0x800A90ACu)+40u*r_u8(r_u32(0x800A8548u)+r_u16(object+32u));
    uint32 vertical=(uint32)((int16)r_u16(model+32u)>>1)-256u;
    for(i=4u;i>0u;) {
        uint32 corner=corners+8u*--i;
        uint32 x=r_u32(object+20u)+(uint32)(int32)(int16)r_u16(corner);
        uint32 z=r_u32(object+28u)+(uint32)(int32)(int16)r_u16(corner+4u);
        uint32 bx=x&0xFFFFF000u,bz=z&0xFFFFF000u;
        uint32 initial=r_u16(r_u32(0x800A84F8u)+8u*((uint32)((int32)z>>12)*80u+(uint32)((int32)x>>12))+4u);
        uint32 layer=initial,height,list,polygon=0u;
        for(;;) {
            height=r_u16(r_u32(0x800A869Cu)+2u*layer);
            if((int32)(0u-(vertical+r_u32(object+24u))) < (int32)(2u*(height&0x7FFFu)) && !(height&0x8000u)) { layer+=3u; continue; }
            list=r_u16(r_u32(0x800A869Cu)+2u*layer+4u);
            result=height&0x8000u;
            if(list!=0xFFFFu) {
                list=r_u32(0x800A9CE4u)+2u*list;
                for(;;) {
                    uint32 tag=r_u16(list);
                    polygon=r_u32(0x800A9CE8u)+28u*(tag&0x7FFFu);
                    if(d01_inside(polygon,x,z,bx,bz)) break;
                    polygon=0u;
                    if(tag&0x8000u) break;
                    list+=2u;
                }
            }
            if(polygon) break;
            layer+=3u;
            if(result) { w_u16(output+2u*i,0u); break; }
        }
        if(polygon) {
            uint32 nx=(uint32)(int32)(int16)r_u16(polygon+18u),ny=(uint32)(int32)(int16)r_u16(polygon+20u),nz=(uint32)(int32)(int16)r_u16(polygon+22u);
            uint32 plane=0u-(nx*(x-bx-(uint32)(int32)(int16)r_u16(polygon))+nz*(z-bz-(uint32)(int32)(int16)r_u16(polygon+4u)));
            uint32 flags=r_u16(polygon+24u);
            w_u16(output+2u*i,(uint16)((uint32)d01_div(plane,ny)+(uint32)(int32)(int16)r_u16(polygon+2u)));
            w_u8(output+8u+i,(uint8)flags);
            result=flags>>15;
            if((int16)update_flag) w_u32(0x800A563Cu,result);
        }
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8004E954
uint32 sub_8004E954(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 temporary=draft_scratch_adapter(80u),motion=temporary,previous=temporary+16u,normal=temporary+32u,tag=temporary+40u,desired=temporary+48u;
    uint32 result,height,ground,model,old_angle,i;
    // TODO Bind vehicle mode update
    result=(uint32)draft_call_adapter(0x8004D04Cu,object);
    if(result) {
        if((int32)result>=0) {w_u32(object,0x80029968u);return draft_scratch_result(native_stack_mark, (uint64)(0x80029968u));}
        w_u32(object,0x8004EC84u);
    }
    old_angle=r_u16(object+182u);
    for(i=0;i<3u;++i) w_u32(previous+4u*i,r_u32(object+128u+4u*i));
    w_u32(0x800A6EF4u,previous);
    w_u32(0x800A6F9Cu,object);
    w_u32(0x800A6FB4u,0u);
    sub_8004BC94(0x800A6F9Cu);
    w_u32(motion,r_u32(object+100u));w_u32(motion+8u,r_u32(object+104u));
    ground=(uint32)draft_call_adapter(0x8002E310u,object+20u,normal,tag);
    if(ground) {ground=0u-ground;w_u32(object+276u,0u);}
    else {ground=r_u32(object+24u)+1200u;w_u32(object+276u,r_u32(object+276u)+1u);}
    if((int32)r_u32(object+276u)>=1801) draft_call_adapter(0x8004BC18u,object);
    model=r_u32(0x800A90ACu)+40u*r_u8(r_u32(0x800A8548u)+r_u16(object+32u));
    height=(uint32)((int16)r_u16(model+32u)/2)+r_u32(object+24u);
    result=height-ground;
    if((int32)result<0) result=0u-result;
    if(r_u8(object+198u)==12u) draft_call_adapter(0x80048F9Cu,object+20u,motion,object+182u,12u);
    else if((int32)result>=273) {
        uint32 speed=r_u16(object+178u);
        w_u32(0x800A6FC4u,speed);w_u32(0x800A6FB8u,object);w_u32(0x800A6FC0u,motion);w_u32(0x800A6FC8u,speed>>6);
        w_u32(desired,r_u32(object+92u));w_u32(desired+8u,r_u32(object+96u));w_u32(0x800A6FBCu,desired);
        draft_call_adapter(0x80047CF0u,0x800A6FB8u);
    }
    if(r_u8(object+196u)==6u) {
        int32 h=(int16)r_u16(model+32u);
        draft_call_adapter(0x8004E53Cu,object,ground,(uint32)(((h>0)-h)>>1),1u);
    } else draft_call_adapter(0x8004E53Cu,object,ground,0u-1200u,0u);
    sub_8004E80C(object,motion,previous);
    if(r_u8(object+12u)<4u) draft_call_adapter(0x80036CFCu,object+194u);
    else {
        draft_call_adapter(0x8004E6A4u,object,old_angle);
        draft_call_adapter(0x80029970u,object,r_u16(model+32u),2u,1u,previous);
        draft_call_adapter(0x800369E0u,object+20u,object+194u,1024u,18u);
    }
    w_u32(object+100u,r_u32(motion));w_u32(object+104u,r_u32(motion+8u));
    for(i=0;i<3u;++i) w_u32(object+128u+4u*i,r_u32(object+20u+4u*i));
    return draft_scratch_result(native_stack_mark, (uint64)(r_u32(object+20u)));

    draft_scratch_release(native_stack_mark);
}

static uint32 d01_waypoint(uint32 index)
{
    // TODO Bind graph node lookup
    return (uint32)draft_call_adapter(0x800476D8u,index);
}
static uint32 d01_neighbor(uint32 node,uint32 index)
{
    return (uint32)(int32)(int16)draft_call_adapter(0x80047718u,node,index);
}
static uint32 d01_length(uint32 x,uint32 z)
{
    return (uint32)draft_call_adapter(0x80069BE0u,x,z);
}
static uint32 d01_waypoint_x(uint32 node) {return (r_u32(node)&0x3FFu)<<9;}
static uint32 d01_waypoint_z(uint32 node) {return ((r_u32(node)>>10)&0x3FFu)<<9;}
static int32 d01_angle_delta(uint32 value)
{
    value&=4095u;
    return value>=2049u?(int32)value-4096:(int32)value;
}

// FUNCTION_MARKER sub_80047788
uint32 sub_80047788(uint32 object,uint32 position)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 previous=d01_waypoint(r_u16(object+172u)),current=d01_waypoint(r_u16(object+174u));
    uint32 distance0=d01_length(r_u32(position)-d01_waypoint_x(previous),r_u32(position+8u)-d01_waypoint_z(previous));
    uint32 distance=d01_length(r_u32(position)-d01_waypoint_x(current),r_u32(position+8u)-d01_waypoint_z(current));
    uint32 degree=r_u32(current+4u)&15u,i,candidate;
    int32 best_angle=2048,selected;
    int16 angle;
    if(!degree) return draft_scratch_result(native_stack_mark, (uint64)((uint32)(int32)(int16)r_u16(object+174u)));
    selected=(int16)((uint32)draft_call_adapter(0x80069A50u)%degree);
    angle=(int16)sub_80055A9C(r_u32(position)-r_u32(object+20u),r_u32(position+8u)-r_u32(object+28u));
    if((int32)(distance-distance0)>=513 && (int8)r_u8(object+85u)<=0) w_u8(object+85u,2u);
    if((int8)r_u8(object+85u)>0) angle=(int16)(angle+2048);
    for(i=0u;i<(r_u32(current+4u)&15u);++i) {
        uint32 node=d01_waypoint(d01_neighbor((uint32)(int32)(int16)r_u16(object+174u),i));
        uint32 x=d01_waypoint_x(node);
        uint32 z=d01_waypoint_z(d01_waypoint(d01_neighbor((uint32)(int32)(int16)r_u16(object+174u),i)));
        uint32 next_distance=d01_length(r_u32(position)-x,r_u32(position+8u)-z);
        int32 delta=d01_angle_delta((uint32)angle-sub_80055A9C(x-d01_waypoint_x(current),z-d01_waypoint_z(current)));
        int32 absolute=delta<0?-delta:delta,best=best_angle<0?-best_angle:best_angle;
        candidate=d01_neighbor((uint32)(int32)(int16)r_u16(object+174u),i);
        if(absolute<best && candidate!=(uint32)(int32)(int16)r_u16(object+172u) && (r_u32(d01_waypoint(candidate)+4u)&15u)) {
            distance=next_distance;selected=(int16)i;best_angle=delta;
        } else if((int32)next_distance<(int32)distance && candidate!=(uint32)(int32)(int16)r_u16(object+172u) && (r_u32(d01_waypoint(candidate)+4u)&15u)) {
            selected=(int16)i;distance=next_distance;
        }
    }
    if(r_u32(object+144u) && (int16)r_u16(object+190u)<0) {
        uint32 temporary=draft_scratch_adapter(12u);
        int32 n;
        for(n=0;n<(int32)r_u32(0x800A6EF0u);++n) {
            uint32 index=(uint32)(int32)(int16)(-1-n);
            uint32 x=d01_waypoint_x(d01_waypoint(index)),z=d01_waypoint_z(d01_waypoint(index));
            uint32 next_distance=d01_length(r_u32(position)-x,r_u32(position+8u)-z);
            w_u32(temporary,x);w_u32(temporary+4u,r_u32(object+24u));w_u32(temporary+8u,z);
            if((int32)next_distance<(int32)distance && ((uint32)draft_call_adapter(0x8002EAE4u,temporary,object+20u,0u)<<16)) {
                selected=(int16)index;distance=next_distance;
            }
        }
    }
    if(selected>=0) {
        uint32 index=(uint32)selected,node=d01_waypoint(d01_neighbor((uint32)(int32)(int16)r_u16(object+174u),index));
        uint32 x=d01_waypoint_x(node),z=d01_waypoint_z(d01_waypoint(d01_neighbor((uint32)(int32)(int16)r_u16(object+174u),index)));
        int32 delta=d01_angle_delta(r_u16(object+182u)-sub_80055A9C(x-d01_waypoint_x(current),z-d01_waypoint_z(current)));
        if(d01_length(x,z)<distance || (delta<0?-delta:delta)>=769) {
            if((r_u32(previous+4u)&15u)<3u && !draft_call_adapter(0x80069A50u)) selected=(int16)r_u16(object+172u);
        }
        return draft_scratch_result(native_stack_mark, (uint64)(d01_neighbor((uint32)(int32)(int16)r_u16(object+174u),(uint32)(int32)selected)));
    }
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)selected));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800563AC
uint32 sub_800563AC(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 temporary=draft_scratch_adapter(76u),old_position=temporary,normal=temporary+16u,tag=temporary+24u,point=temporary+32u,normal2=temporary+48u,tag2=temporary+56u;
    uint32 i,active=0u,model,vertical,ground,speed,turn_step,angle,direction,movement;
    int32 target=(r_u8(object+91u)&1u)?0:-5120;
    for(i=0;i<3u;++i) w_u32(old_position+4u*i,r_u32(object+20u+4u*i));
    speed=r_u16(object+10u);
    if(((int32)(speed<<16)>>24)!=(target>>8)) {
        uint32 numerator=(uint32)((int16)speed>=target?6720u:11520u)*r_u32(0x800A9010u);
        uint32 step=(uint32)d01_div(numerator,r_u32(0x800A56C0u));
        w_u16(object+10u,(uint16)((int16)speed>=target?speed-step:speed+step));
    }
    if(r_u8(object+91u) || r_u32(object+84u)) active=1u;
    model=r_u32(0x800A90ACu)+40u*r_u8(r_u32(0x800A8548u)+r_u16(object+32u));
    if((int16)r_u16(object+10u)<255) {
        uint32 old_angle=r_u16(object+78u),scale=(uint32)((int32)r_u32(0x800A63D8u)>>8),product;
        int32 delta=d01_angle_delta(r_u16(object+76u)-old_angle),absolute=delta<0?-delta:delta;
        vertical=(uint32)((int16)r_u16(model+32u)>>1);
        product=(absolute<1025?7680u:10240u)*scale;
        turn_step=(uint32)d01_div(60u*(uint32)((int32)product>>16),r_u32(0x800A56C0u));
        angle=sub_80055A9C(r_u32(object+68u)-r_u32(object+20u),r_u32(object+72u)-r_u32(object+28u));
        direction=(r_u8(object+91u)&128u)?angle-r_u16(object+78u):((angle-r_u16(object+76u))&4095u)+((angle-r_u16(object+78u))&4095u);
        delta=d01_angle_delta(direction);absolute=delta<0?-delta:delta;
        if((int16)turn_step>=absolute) w_u16(object+78u,(uint16)(old_angle+(uint32)delta));
        else w_u16(object+78u,(uint16)(old_angle+turn_step*(delta<0?0xFFFFFFFFu:1u)));
        if(absolute>=257 && (r_u8(object+91u)&128u)) {movement=0u;w_u16(object+10u,0u);}
        else movement=(uint32)d01_div(60u*(uint32)((int32)((uint32)r_u16(object+10u)<<16)>>24)*r_u32(0x800A9010u),r_u32(0x800A56C0u));
        w_u32(object+80u,r_u32(object+80u)+movement);
        angle=r_u16(object+78u)&4095u;
        product=(uint32)(int32)(int16)r_u16(0x800102E0u+2u*angle)*movement;
        w_u32(object+20u,r_u32(object+20u)-(uint32)((int32)product>>12));
        product=(uint32)(int32)(int16)r_u16(0x80010AE0u+2u*angle)*movement;
        w_u32(object+28u,r_u32(object+28u)-(uint32)((int32)product>>12));
        w_u32(object+24u,r_u32(object+24u)-vertical);
        ground=0u-(uint32)draft_call_adapter(0x8002E310u,object+20u,normal,tag);
        delta=(int32)(ground-r_u32(object+24u));
        if((delta<0?0u-(uint32)delta:(uint32)delta)<512u) w_u32(object+24u,ground-vertical);
        else w_u32(object+24u,r_u32(object+24u)+vertical);
        speed=(uint32)((int16)r_u16(model+34u)>>1);
        for(i=0;i<8u;++i) w_u8(normal+i,0u);
        w_u16(normal+4u,(uint16)(0u-speed));
        sub_80031B6C(object+36u,normal,point);
        w_u32(point,r_u32(point)+r_u32(object+20u));
        w_u32(point+4u,r_u32(point+4u)+ground-vertical);
        w_u32(point+8u,r_u32(point+8u)+r_u32(object+28u));
        product=0u-(uint32)draft_call_adapter(0x8002E310u,point,normal2,tag2);
        if(product) {
            int16 pitch=(int16)sub_80055A9C(product-ground,speed);
            int32 abs_pitch=pitch<0?-pitch:pitch;
            if(abs_pitch>=513) pitch=pitch<0?-512:512;
            draft_call_adapter(0x80054D38u,(uint32)(int32)pitch,old_angle+2048u,(uint32)(((int16)r_u16(object+78u)-(int16)old_angle)>>1),object+36u);
        }
    }
    if(r_u8(object+12u)<4u) return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80036CFCu,object+8u)));
    draft_call_adapter(0x80029970u,object,r_u16(model+32u),1u,active,old_position);
    if(r_u8(object+9u)) return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x800369E0u,object+20u,object+8u,1000u,42u)));
    speed=r_u32(0x800A63DCu)*5u+1u;w_u32(0x800A63DCu,speed);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x800369E0u,object+20u,object+8u,(speed&0xFFFFu)%1000u+3596u,11u)));

    draft_scratch_release(native_stack_mark);
}


// FUNCTION_MARKER sub_8002EDDC
uint32 sub_8002EDDC(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 first=r_u32(object),second=r_u32(object+4u),scratch=draft_scratch_adapter(12u);
    uint32 bx=r_u32(object+16u),bz=r_u32(object+20u),sx=r_u32(first)-bx,sz=r_u32(first+8u)-bz;
    uint32 ex=r_u32(second)-bx,ez=r_u32(second+8u)-bz,sum=0u,tag;
    uint32 x_slope=ex!=sx?(uint32)d01_div((sz-ez)<<10,ex-sx):0u;
    uint32 z_slope=ez!=sz?(uint32)d01_div((ex-sx)<<10,ez-sz):0u;
    w_u32(scratch,ex); w_u32(scratch+8u,ez);
    do {
        uint32 index=r_u32(object+12u),polygon,y=0u-r_u32(object+8u),i;
        int32 px[4],pz[4],minx=(int32)sx,maxx=(int32)r_u32(scratch);
        int32 minz=(int32)sz,maxz=(int32)r_u32(scratch+8u);
        uint32 left=1u,right=1u,below=1u,above=1u;
        w_u32(object+12u,index+1u);
        tag=r_u16(r_u32(0x800A9CDCu)+2u*index);
        polygon=r_u32(0x800A9024u)+20u*(tag&0x7FFFu);
        if((int32)y>=(int32)r_u16(polygon+2u) || (int32)y<=(int32)r_u16(polygon)) continue;
        if(minx>maxx) { int32 t=minx;minx=maxx;maxx=t; }
        if(minz>maxz) { int32 t=minz;minz=maxz;maxz=t; }
        for(i=0;i<4u;++i) {
            px[i]=(int16)r_u16(polygon+4u+4u*i); pz[i]=(int16)r_u16(polygon+6u+4u*i);
            left&=px[i]<minx; right&=px[i]>maxx; below&=pz[i]<minz; above&=pz[i]>maxz;
        }
        if(!(left||right||below||above)) {
            uint32 edge,contribution;
            edge=sub_8002F7E0(sx,sz,scratch,(uint32)px[0],(uint32)pz[0],(uint32)px[1],(uint32)pz[1],r_u32(object),x_slope,z_slope);
            contribution=sub_8002F7E0(sx,sz,scratch,(uint32)px[1],(uint32)pz[1],(uint32)px[2],(uint32)pz[2],r_u32(object),x_slope,z_slope)*4u;
            if((uint16)contribution) {
                contribution=(uint32)(int32)(int16)contribution;
                if((uint16)edge) { sum+=contribution;continue; }
                edge=contribution;
            }
            contribution=sub_8002F7E0(sx,sz,scratch,(uint32)px[2],(uint32)pz[2],(uint32)px[3],(uint32)pz[3],r_u32(object),x_slope,z_slope)*16u;
            if((uint16)contribution) {
                contribution=(uint32)(int32)(int16)contribution;
                if((uint16)edge) { sum+=contribution;continue; }
                edge=contribution;
            }
            contribution=(uint32)(int32)(int16)(sub_8002F7E0(sx,sz,scratch,(uint32)px[3],(uint32)pz[3],(uint32)px[0],(uint32)pz[0],r_u32(object),x_slope,z_slope)<<6);
            if((uint16)contribution) contribution=contribution==256u?1u:contribution&0xFFFDu;
            else contribution=edge;
            sum+=contribution;
        }
    } while(!(tag&0x8000u));
    if(!(uint16)sum) return draft_scratch_result(native_stack_mark, (uint64)(0u));
    w_u32(r_u32(object+4u),r_u32(scratch)+r_u32(object+16u));
    w_u32(r_u32(object+4u)+8u,r_u32(scratch+8u)+r_u32(object+20u));
    return draft_scratch_result(native_stack_mark, (uint64)(1u));

    draft_scratch_release(native_stack_mark);
}

static void d01_desired(uint32 context,uint32 source)
{
    uint32 i;
    for(i=0;i<3u;++i) w_u32(context+12u+4u*i,r_u32(source+4u*i));
}

static void d01_clear_route(uint32 entity)
{
    uint32 mode=r_u8(entity+198u),node;
    if(mode-16u>=2u && mode!=13u && (int8)r_u8(entity+85u)<=0) {
        if(mode!=(mode>=20u?29u:18u)) w_u8(entity+198u,0u);
    }
    node=d01_waypoint(r_u16(entity+172u)); w_u32(node+4u,r_u32(node+4u)&~0x200u);
    node=d01_waypoint(r_u16(entity+174u)); w_u32(node+4u,r_u32(node+4u)&~0x200u);
}

static uint32 d01_target_distance(uint32 entity,uint32 target)
{
    return d01_length(r_u32(target+20u)-r_u32(entity+20u),r_u32(target+28u)-r_u32(entity+28u));
}

static uint32 d01_target_heading(uint32 entity,uint32 target)
{
    return sub_80055A9C(r_u32(target+20u)-r_u32(entity+20u),r_u32(target+28u)-r_u32(entity+28u));
}

// FUNCTION_MARKER sub_8004BC94
uint32 sub_8004BC94(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 entity=r_u32(object),table=r_u32(0x800A851Cu),target,candidate,distance,heading,base,result,mode;
    if(!r_u8(r_u32(table+4u*(uint32)(int32)(int16)r_u16(entity+164u))+64u)) w_u16(entity+164u,0u);
    target=r_u32(table+4u*(uint32)(int32)(int16)r_u16(entity+164u));
    w_u32(object+4u,target); distance=d01_target_distance(entity,target);w_u32(object+8u,distance);
    base=((int32)distance<2048 && !r_u32(entity+144u) && r_u8(entity+197u)==7u)?r_u16(entity+360u):r_u16(entity+182u);
    heading=d01_target_heading(entity,target);
    w_u16(object+26u,(uint16)d01_angle_delta(heading-base));
    if(r_u32(entity+144u)) {
        w_u8(entity+84u,0u);w_u8(entity+85u,0u);
        candidate=sub_8004BAA4(entity,0x4000u);
        if(candidate) {
            target=candidate;w_u32(object+4u,target);w_u32(object+8u,d01_target_distance(entity,target));
            heading=d01_target_heading(entity,target);w_u16(object+26u,(uint16)d01_angle_delta(heading-base));
        }
        // TODO Bind the external movement-state transition
        if(r_u8(entity+196u)!=6u) draft_call_adapter(0x8004AB4Cu,object);
        if(r_u8(entity+198u)==11u) return draft_scratch_result(native_stack_mark, (uint64)(11u));
    }
    switch(r_u8(entity+196u)) {
    case 0:
        w_u8(entity+85u,0u);w_u8(entity+84u,0u);
        if(r_u32(entity+144u)) goto proximity;
        d01_desired(object,target+20u);
        if(r_u16(target+58u) && r_u16(entity+164u)) goto valid_target;
        candidate=sub_8004BAA4(entity,0x4000u);
        if(candidate) {
            target=candidate;w_u32(object+4u,target);w_u32(object+8u,d01_target_distance(entity,target));
            heading=d01_target_heading(entity,target);d01_desired(object,target+20u);
valid_target:
            if((int32)r_u32(object+8u)<0x4000 && !sub_80049AC0(object,r_u16(entity+182u))) {
                d01_clear_route(entity);goto finish_heading;
            }
        } else {
            w_u32(object+8u,d01_length(r_u32(entity+116u)-r_u32(entity+20u),r_u32(entity+124u)-r_u32(entity+28u)));
            heading=sub_80055A9C(r_u32(entity+116u)-r_u32(entity+20u),r_u32(entity+124u)-r_u32(entity+28u));
        }
        d01_desired(object,entity+116u);
        w_u32(object+8u,d01_length(r_u32(entity+116u)-r_u32(entity+20u),r_u32(entity+124u)-r_u32(entity+28u)));
        if((uint16)draft_call_adapter(0x8002EAE4u,object+12u,entity+20u,0u)) w_u8(entity+198u,10u);
        else if(!r_u8(entity+198u) || r_u8(entity+198u)==10u) w_u8(entity+198u,8u);
finish_heading:
        w_u16(object+26u,(uint16)d01_angle_delta(heading-base));
        sub_8004A17C(object);goto proximity;
    case 1:
        w_u8(entity+85u,0u);w_u8(entity+84u,0u);
        if(!r_u32(entity+144u)) {
            w_u8(entity+198u,10u);
            if(!r_u16(target+58u) || !r_u16(entity+164u)) {
                candidate=sub_8004BAA4(entity,0x4000u);
                if(candidate) {
                    target=candidate;w_u32(object+4u,target);
                    w_u16(object+26u,(uint16)d01_angle_delta(d01_target_heading(entity,target)-base));
                }
            }
            w_u32(object+8u,d01_length(r_u32(entity+116u)-r_u32(entity+20u),r_u32(entity+124u)-r_u32(entity+28u)));
            d01_desired(object,target+20u);sub_8004A17C(object);
        }
        result=d01_target_distance(r_u32(object),r_u32(object+4u))<0x4000u;goto proximity_result;
    case 2:
    case 3:
        mode=r_u8(entity+196u);
        if(r_u32(entity+144u)) goto proximity;
        if(!r_u16(target+58u) || !r_u16(entity+164u)) {
            candidate=sub_8004BAA4(entity,0x4000u);
            if(candidate) {
                target=candidate;w_u32(object+4u,target);w_u32(object+8u,d01_target_distance(entity,target));
                heading=d01_target_heading(entity,target);
                w_u16(object+26u,(uint16)d01_angle_delta(heading-base));
            } else if(mode==2u) w_u16(object+26u,(uint16)d01_angle_delta(heading-base));
        }
        d01_desired(object,target+20u);
        if(mode==2u && r_u8(entity+198u) && (int32)r_u32(object+8u)<0x4000 && !sub_80049AC0(object,r_u16(entity+182u))) d01_clear_route(entity);
        sub_8004A17C(object);goto proximity;
    case 5:
        target=r_u32(r_u32(0x800A851Cu)+4u*(uint32)(int32)(int16)r_u16(entity+164u));w_u32(object+4u,target);
        distance=d01_target_distance(entity,target);w_u32(object+8u,distance);
        if((int32)distance>=6001 || !(uint16)draft_call_adapter(0x8002EAE4u,target+20u,entity+20u,0u)) w_u8(entity+199u,1u);
        goto passive;
    case 4:
passive:
        result=r_u32(entity+144u);if(result) return draft_scratch_result(native_stack_mark, (uint64)(result));
        w_u8(entity+198u,12u);return draft_scratch_result(native_stack_mark, (uint64)(12u));
    case 6:
        w_u8(entity+198u,12u);return draft_scratch_result(native_stack_mark, (uint64)(12u));
    case 7:
        target=r_u32(r_u32(0x800A851Cu)+4u*(uint32)(int32)(int16)r_u16(entity+164u));w_u32(object+4u,target);
        { int32 angle=d01_angle_delta(d01_target_heading(entity,target)-r_u16(entity+182u));
          distance=d01_target_distance(entity,target);w_u32(object+8u,distance);
          if(angle<0) angle=-angle;
          w_u32(entity+80u,(int32)distance<16385 || angle<1281?1u:0xFFFFFFFFu); }
        if(!r_u32(entity+144u)) w_u8(entity+198u,12u);
        return draft_scratch_result(native_stack_mark, (uint64)(12u));
    default:goto impact;
    }
proximity:
    result=r_u32(object+8u)<0x4000u;
proximity_result:
    if(!result) return draft_scratch_result(native_stack_mark, (uint64)(result));
    entity=r_u32(object);target=r_u32(object+4u);result=(uint32)(int32)(int16)r_u16(entity+70u);
    if((int16)r_u16(target+70u)==(int32)result) return draft_scratch_result(native_stack_mark, (uint64)(result));
    result=r_u8(target+64u);if(!result) return draft_scratch_result(native_stack_mark, (uint64)(result));
impact:
    // TODO Bind collision damage and target destruction boundaries
    distance=(uint32)draft_call_adapter(0x8004915Cu,object);result=distance<<16;
    if(!result) return draft_scratch_result(native_stack_mark, (uint64)(result));
    entity=r_u32(object);target=r_u32(object+4u);
    if(r_u8(entity+12u)>=4u) return draft_scratch_result(native_stack_mark, (uint64)(sub_8003CB54(entity,distance-1u)));
    result=r_u32(0x800A7BACu);
    if(target!=result && !r_u8(entity+12u)) {
        result=r_u8(target+12u);
        if(!result) {
            w_u16(target+58u,(uint16)(r_u16(target+58u)-(uint32)draft_call_adapter(0x8003D338u,target+176u,distance-1u)));
            target=r_u32(object+4u);result=(uint32)(int32)(int16)r_u16(target+58u);
            if((int32)result<=0) {
                w_u16(target+58u,0u);draft_call_adapter(0x8004D8B4u,target);
                sub_80030F08((uint32)(int32)(int16)r_u16(entity+74u),r_u16(entity+68u),1u);
                result=0x80045510u;w_u32(r_u32(object+4u),result);
            }
        }
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}


