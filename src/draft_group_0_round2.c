#include "draft_signatures.h"
#include <stdlib.h>

static uint32 d02_call(uint32 target,uint32 a,uint32 b,uint32 c,uint32 d)
{
    // TODO Bind the original external boundary
    return (uint32)draft_call_adapter(target,a,b,c,d);
}
static uint32 d02_rand(void) { return (uint32)draft_call_adapter(0x80069A50u); }
static int32 d02_div(uint32 n,uint32 d)
{
    if(!d || (d==0xFFFFFFFFu && n==0x80000000u)) abort();
    return (int32)n/(int32)d;
}
static uint32 d02_model(uint32 object)
{
    return r_u32(0x800A90ACu)+40u*r_u8(r_u32(0x800A8548u)+r_u16(object+32u));
}

// FUNCTION_MARKER sub_8003F0F8
uint32 sub_8003F0F8(uint32 position,uint32 matrix)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 object=d02_call(0x800226E4u,56u,0u,0u,0u),i;
    w_u8(object+34u,8u);w_u8(object+14u,r_u8(object+14u)|2u);
    w_u16(object+32u,r_u16(r_u32(0x800A62ECu)+100u));
    for(i=0;i<3u;++i) w_u32(object+20u+4u*i,r_u32(position+4u*i));
    for(i=0;i<5u;++i) w_u32(object+36u+4u*i,r_u32(matrix+4u*i));
    w_u16(object+8u,1u);w_u32(object,0x8003F2C4u);return draft_scratch_result(native_stack_mark, (uint64)(object));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8005D800
uint32 sub_8005D800(uint32 flag)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 position=0x800A7EE4u,source=r_u32(0x800A9A58u),height=r_u32(source+24u);
    w_u32(position+4u,height-(flag?150u:350u));
    draft_call_adapter(0x8005B5D8u,position,flag?(d02_rand()&255u)+150u:(d02_rand()&511u)+700u);
    height=r_u32(r_u32(0x800A9A58u)+24u);
    if(flag && (int32)(r_u32(position+4u)-height)<-405) return draft_scratch_result(native_stack_mark, (uint64)(0u));
    return draft_scratch_result(native_stack_mark, (uint64)((int32)height>=(int32)r_u32(position+4u)));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8003B8E8
uint32 sub_8003B8E8(uint32 index,uint32 mode)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result=0u;
    draft_call_adapter(0x80059E2Cu);draft_call_adapter(0x80069BC0u,2u);w_u32(0x800A8690u,mode);
    if(mode==2u) { result=d02_call(0x8003B990u,(uint32)(int32)(int16)index,0u,0u,0u);if(result==0xFFFFFFFFu)w_u32(0x800A8690u,0u); }
    w_u32(0x800A6DE0u,d02_call(0x8003BA80u,index,1u,0u,0u));
    draft_call_adapter(0x8003C394u,0u);draft_call_adapter(0x80069B84u,3u);draft_call_adapter(0x800649E4u);
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800463F0
uint32 sub_800463F0(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    if(d02_call(0x80045E18u,object,object+56u,0u,0u)) return draft_scratch_result(native_stack_mark, (uint64)(object+32u));
    return draft_scratch_result(native_stack_mark, (uint64)(sub_8004557C(object,object+56u,0x800461DCu,0u,object+32u)));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8004644C
uint32 sub_8004644C(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    if(d02_call(0x80045E18u,object,object+56u,0u,0u)) return draft_scratch_result(native_stack_mark, (uint64)(object+32u));
    return draft_scratch_result(native_stack_mark, (uint64)(sub_8004557C(object,object+56u,0x800461BCu,0u,object+32u)));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800464B0
uint32 sub_800464B0(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint16 timer=(uint16)(r_u16(object+70u)-r_u16(0x800A63DAu));w_u16(object+70u,timer);
    if(timer&0x8000u) {
        uint16 count=(uint16)(r_u16(object+80u)-1u);w_u16(object+80u,count);w_u16(object+70u,r_u16(0x800A6EE4u));
        if(count&0x8000u) {
            int32 kind=(int16)r_u16(object+82u);w_u16(0x800A60A8u,0u);w_u16(object+80u,0u);
            if(kind>=27 && kind<29) {
                draft_call_adapter(0x80029A1Cu,3072u,object+20u);draft_call_adapter(0x8005F920u,object);
                draft_call_adapter(0x8002289Cu,object);draft_call_adapter(0x80035A08u,13u,576u,128u,object+20u);
            }
            return draft_scratch_result(native_stack_mark, (uint64)(1u));
        }
    }
    { uint16 add=r_u16(0x800A60AAu);if(add) { w_u16(0x800A60AAu,0u);w_u16(object+80u,r_u16(object+80u)+add); } }
    w_u16(0x800A60A8u,r_u16(object+80u));return draft_scratch_result(native_stack_mark, (uint64)(0u));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8005F598
uint32 sub_8005F598(uint32 object,uint32 model,uint32 size,uint32 color)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 i,result=0u;
    for(i=0;i<10u;++i) {
        uint32 p=d02_call(0x800227C4u,40u,0u,0u,0u),j;
        w_u8(p+34u,8u);w_u16(p+36u,(uint16)size);w_u16(p+38u,0u);w_u16(p+32u,(uint16)model);w_u8(p+14u,r_u8(p+14u)|2u);
        for(j=0;j<3u;++j)w_u32(p+20u+4u*j,r_u32(object+20u+4u*j));
        w_u32(p,0x8005F1E0u);w_u8(p+13u,(uint8)color);
        w_u16(p+8u,(uint16)((d02_rand()&15u)-7u));w_u16(p+10u,(uint16)(0u-(d02_rand()&7u)));
        w_u16(p+16u,(uint16)((d02_rand()&15u)-7u));result=d02_rand()&255u;w_u16(p+18u,(uint16)result);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8005F080
uint32 sub_8005F080(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 i,result=0u;
    w_u8(0x800A8FB8u,1u);w_u8(0x800A8FB7u,20u);w_u8(0x800A8FB4u,r_u8(0x800A8FB4u)|2u);
    w_u32(0x800A8FA0u,r_u32(object+20u)-r_u32(0x800A7EE4u));w_u32(0x800A8FA4u,r_u32(object+24u));w_u32(0x800A8FA8u,r_u32(object+28u)-r_u32(0x800A7EECu));
    for(i=0;i<10u;++i) {
        uint32 p=d02_call(0x800227C4u,40u,0u,0u,0u),j;
        w_u8(p+34u,8u);w_u16(p+36u,288u);w_u16(p+38u,0u);w_u8(p+14u,r_u8(p+14u)|2u);
        w_u16(p+32u,r_u16(r_u32(0x800A62ECu)+62u));
        for(j=0;j<3u;++j)w_u32(p+20u+4u*j,r_u32(object+20u+4u*j));
        w_u32(p,0x8005F1E0u);w_u8(p+13u,16u);
        w_u16(p+8u,(uint16)((d02_rand()&31u)-16u));w_u16(p+10u,(uint16)(0u-(d02_rand()&15u)));
        w_u16(p+16u,(uint16)((d02_rand()&31u)-16u));result=d02_rand()&255u;w_u16(p+18u,(uint16)result);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8003F1B8
uint32 sub_8003F1B8(uint32 object,uint32 timer,uint32 kind,uint32 height,uint32 offsets,uint32 sound,uint32 volume)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 p=d02_call(0x80022744u,72u,object,0u,0u),i;
    w_u8(p+34u,8u);for(i=0;i<3u;++i)w_u32(p+20u+4u*i,r_u32(object+20u+4u*i));
    w_u16(p+58u,22u);w_u16(p+60u,(uint16)timer);w_u16(p+62u,(uint16)height);
    w_u16(p+64u,(uint16)draft_call_adapter(0x80035A08u,(uint32)(int32)(int16)sound,1024u,volume&255u,0u));
    for(i=0;i<3u;++i)w_u16(p+66u+2u*i,r_u16(offsets+2u*i));
    w_u32(p,0x8003F310u);w_u32(p+16u,object);w_u16(p+56u,0u);w_u16(p+58u,(uint16)kind);return draft_scratch_result(native_stack_mark, (uint64)(0x8003F310u));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80049648
uint32 sub_80049648(uint32 object,uint32 first,uint32 second)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 bias=0u,node,index,result,angle;int32 dx,dz;
    if(r_u8(object+197u)!=22u && r_u8(object+197u)-8u>=2u)bias=160u*r_u32(0x800A6224u);
    node=d02_call(0x800476D8u,(uint32)(int32)(int16)first,0u,0u,0u);
    w_u32(object+92u,(r_u32(node)&1023u)<<9);
    node=d02_call(0x800476D8u,(uint32)(int32)(int16)first,0u,0u,0u);result=((r_u32(node)>>10)&1023u)<<9;w_u32(object+96u,result);
    if(r_u16(object+172u)!=r_u16(object+174u)) {
        node=d02_call(0x800476D8u,(uint32)(int32)(int16)second,0u,0u,0u);dx=(int32)(r_u32(node)&1023u)-((int32)r_u32(object+92u)>>9);
        node=d02_call(0x800476D8u,(uint32)(int32)(int16)second,0u,0u,0u);dz=(int32)((r_u32(node)>>10)&1023u)-((int32)r_u32(object+96u)>>9);
        angle=sub_80055A9C((uint32)dx,(uint32)dz)&4095u;w_u16(object+180u,(uint16)angle);index=2u*angle;
        w_u32(object+92u,r_u32(object+92u)+(uint32)((int32)(466u*(uint32)(int32)(int16)r_u16(0x800102E0u+index)+bias*(uint32)(int32)(int16)r_u16(0x80010AE0u+index))>>12));
        result=r_u32(object+96u)+(uint32)((int32)(466u*(uint32)(int32)(int16)r_u16(0x80010AE0u+index)-bias*(uint32)(int32)(int16)r_u16(0x800102E0u+index))>>12);w_u32(object+96u,result);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80071050
uint32 sub_80071050(uint32 index,uint32 menu_index)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 item=r_u32(r_u32(0x80091EE0u+12u*menu_index)+16u*index),buttons,result;
    draft_call_adapter(0x80071148u);buttons=(uint32)(int32)(int16)sub_800389DC();result=buttons&0x4000u;
    if(buttons&(0x10u|0x800u|0x1000u|0x4000u)) {
        uint32 screen=r_u32(0x800A6464u);
        if(screen==1u || screen==5u) {
            if(item==128u)draft_call_adapter(0x80036FE4u);
            else if(buttons&(0x800u|0x10u))w_u16(0x800A9A64u,1u);
            return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80037490u)));
        }
        result=1u;if(item!=128u){w_u16(0x800A9A64u,1u);return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x8003708Cu)));}
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8002A908
uint32 sub_8002A908(uint32 source,uint32 target)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 amount,health,quarter,half;
    w_u8(target+86u,1u);amount=d02_call(0x8003D338u,target+176u,(uint32)(int32)(int16)r_u16(source+58u),0u,0u);
    health=r_u16(target+58u);if(!health)return draft_scratch_result(native_stack_mark, (uint64)(1u));if(health!=32767u)w_u16(target+58u,(uint16)(health-amount));
    quarter=(uint32)((int32)(r_u16(target+166u)<<16)>>18);half=(uint32)((int32)(r_u16(target+166u)<<16)>>17);
    if((int32)quarter>=(int16)r_u16(target+58u))draft_call_adapter(0x80062D90u,target+140u,target,1u);
    else if((int32)half>=(int16)r_u16(target+58u))draft_call_adapter(0x80062D90u,target+140u,target,0u);
    if(r_u16(target+70u)==1u){w_u16(0x800A930Eu,r_u16(target+58u));w_u16(0x800A930Cu,r_u16(target+166u));w_u16(0x800A9310u,r_u8(target+176u));}
    if((int16)r_u16(target+58u)<=0){w_u16(0x800A9310u,0u);w_u16(0x800A930Eu,0u);w_u16(target+58u,0u);draft_call_adapter(0x80036CFCu,target+194u,amount);w_u8(target+14u,r_u8(target+14u)&~128u);return draft_scratch_result(native_stack_mark, (uint64)(0u));}
    return draft_scratch_result(native_stack_mark, (uint64)(1u));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800465A8
uint32 sub_800465A8(uint32 object,uint32 flag)
{
    uint32 native_stack_mark = draft_scratch_mark();

    if(d02_call(0x80045E18u,object,object+72u,0u,0u) || d02_call(0x80045DD4u,object,0u,0u,0u)) {
        w_u16(0x800A60A8u,0u);w_u32(object,0x80029968u);
        if(r_u8(object+67u) && r_u32(r_u32(0x800A851Cu)+4u*r_u32(0x800A9730u))==object)draft_call_adapter(0x8004525Cu);
        return draft_scratch_result(native_stack_mark, (uint64)(1u));
    }
    if(r_u32(0x800A9734u))return draft_scratch_result(native_stack_mark, (uint64)(1u));
    if(!(uint16)sub_800464B0(object))return draft_scratch_result(native_stack_mark, (uint64)(0u));
    w_u8(object+65u,0u);w_u8(object+64u,0u);w_u32(object,0x800469E8u);
    if(r_u8(object+67u) && r_u32(r_u32(0x800A851Cu)+4u*r_u32(0x800A9730u))==object)draft_call_adapter(0x8004525Cu);
    if(r_u32(0x800A8690u))return draft_scratch_result(native_stack_mark, (uint64)(1u));
    { uint32 player=r_u32(0x800A7BACu);
      if(flag){draft_call_adapter(0x80052988u,player);draft_call_adapter(0x800608F8u,player);}
      else{w_u8(0x800A9030u,r_u8(0x800A7E83u));draft_call_adapter(0x8005E2BCu,2u);w_u8(player+14u,r_u8(player+14u)|130u);w_u32(0x800A9734u,2u);sub_80030F08((uint32)(int32)(int16)r_u16(player+78u),0u,3u);} }
    return draft_scratch_result(native_stack_mark, (uint64)(1u));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80046004
uint32 sub_80046004(uint32 object,uint32 index)
{
    uint32 native_stack_mark = draft_scratch_mark();

    int32 slot;uint32 other,table;
    sub_80030F08((uint32)(int32)(int16)r_u16(object+58u),r_u16(object+68u),1u);w_u8(object+65u,0u);
    slot=(int16)r_u16(object+52u);table=r_u32(0x800A851Cu);
    if(slot!=-1){other=r_u32(table+4u*(uint32)slot);if(!r_u8(other+64u)){w_u8(other+66u,r_u8(other+66u)-1u);w_u16(object+52u,0xFFFFu);}}
    slot=(int16)r_u16(object+54u);
    if(slot!=-1){other=r_u32(table+4u*(uint32)slot);w_u8(other+14u,1u);other=r_u32(r_u32(0x800A851Cu)+4u*(uint32)(int32)(int16)r_u16(object+54u));
        if(r_u8(other+64u))w_u8(other+66u,136u);else{w_u32(other,0x80029968u);w_u8(r_u32(table+4u*(uint32)(int32)(int16)r_u16(object+54u))+66u,1u);}w_u16(object+54u,0xFFFFu);}
    if(r_u8(object+67u) && r_u32(r_u32(0x800A851Cu)+4u*r_u32(0x800A9730u))==object)draft_call_adapter(0x8004525Cu);
    {uint32 mode=r_u8(object+67u);if(mode==1u || mode==2u){uint32 p=0x800A7F54u+2u*(uint32)(int32)(int16)index+(mode==1u?0u:4u);w_u16(p,r_u16(p)-1u);draft_call_adapter(0x80044F8Cu,(uint32)(int32)(int16)index);}}
    w_u8(object+64u,0u);w_u32(object,0x80029968u);return draft_scratch_result(native_stack_mark, (uint64)(0x80029968u));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8002B6A8
uint32 sub_8002B6A8(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 model=d02_model(object),scratch=draft_scratch_adapter(24u),result;int32 height=(int16)r_u16(model+32u)/2,value;
    w_u32(scratch+8u,0u);w_u32(scratch+12u,0u);
    w_u16(scratch+8u,(uint16)((int16)r_u16(model+36u)/2));w_u16(scratch+10u,(uint16)height);w_u16(scratch+12u,(uint16)((int16)r_u16(model+34u)/2));
    w_u32(scratch,r_u32(scratch+8u));w_u32(scratch+4u,r_u32(scratch+12u));
    draft_call_adapter(0x80031B6Cu,object+36u,scratch,scratch+16u);value=(int32)r_u32(scratch+20u);if(value<0)value=-value;
    result=(uint32)height;if(value>=height)result=(uint32)value;return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8002ACCC
uint32 sub_8002ACCC(uint32 object,uint32 mask,uint32 velocity)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 i,result=0u;static const uint32 zmask[4]={3u,6u,192u,384u};static const uint32 xmask[4]={3072u,24u,48u,1536u};
    for(i=0;i<4u;++i){uint32 p=object+16u*i,word=r_u32(p+12u),amount;
        if((mask&zmask[i]) && !(r_u32(p+8u)&0xF0000u))amount=r_u32(velocity+8u);
        else if((mask&xmask[i]) && !(r_u32(p+8u)&0xF0000u))amount=r_u32(velocity);
        else {if(i==3u)result=(mask&0x200u)?r_u32(p+8u)&0xF0000u:(mask&0x400u)?r_u32(p+8u)&0xF0000u:mask&0x400u;continue;}
        result=((uint32)((int32)(word<<4)>>4)-(amount<<16))&0x0FFFFFFFu;w_u32(p+12u,(word&0xF0000000u)|result);
    }
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8006B198
uint32 sub_8006B198(uint32 object,uint32 step)
{
    uint32 native_stack_mark = draft_scratch_mark();

    int32 remaining=(int32)r_u32(object+8u);
    if(remaining<=0)w_u32(object+4u,(uint32)((int32)r_u32(object+4u)/2));
    else {
        int64 t=(int32)step<remaining?((int64)(int32)(step<<10)/(int64)remaining):1024;
        uint32 elapsed=(int32)step<remaining?step:(uint32)remaining;int32 delta=(int32)(r_u32(object+12u)-r_u32(object));
        int64 product=(int64)remaining*(int32)r_u32(object+4u),value;
        uint64 weighted=(uint64)product*(uint32)(t-1024);
        value=((int64)((1024-2*t)*delta)>>10)+(int64)(weighted>>10);
        value=(int64)((uint64)value*(uint64)(t-1024));value=(value>>10)+delta;
        value=(int64)((uint64)value*(uint64)t);value>>=10;
        w_u32(object+4u,(uint32)d02_div((uint32)value,elapsed));
        // TODO Preserve the full 64-bit quotient across the external compiler helper
        w_u32(object,r_u32(object)+(uint32)value);w_u32(object+8u,r_u32(object+8u)-elapsed);
    }
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)((int32)(r_u32(object)+512u)>>10)));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8002A090
uint32 sub_8002A090(uint32 object,uint32 model,uint32 output)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 i,result;
    for(i=0;i<5u;++i)xport_gte_write_control(i,r_u32(object+36u+4u*i));
    for(i=0;i<4u;++i)xport_gte_write_data(i,r_u32(model+8u+4u*i));
    draft_gte_command_adapter(0x486012u);for(i=0;i<3u;++i)w_u16(output+8u+2u*i,(uint16)xport_gte_read_data(9u+i));
    draft_gte_command_adapter(0x48E012u);for(i=0;i<3u;++i)w_u16(output+16u+2u*i,(uint16)xport_gte_read_data(9u+i));
    for(i=0;i<3u;++i){w_u16(output+2u*i,(uint16)(0u-r_u16(output+16u+2u*i)));w_u16(output+24u+2u*i,(uint16)(0u-r_u16(output+8u+2u*i)));}
    for(i=0;i<3u;++i){uint32 origin=(uint32)(int32)(int16)r_u16(output+2u*i);xport_gte_write_control(2u*i,(uint32)(int32)(int16)r_u16(output+8u+2u*i)-origin);xport_gte_write_data(9u+i,(uint32)(int32)(int16)r_u16(output+16u+2u*i)-origin);}
    draft_gte_command_adapter(0x170000Cu);result=xport_gte_read_data(26u);
    if((int32)result<0){for(i=0;i<2u;++i){uint32 p=output+16u*i,a=r_u32(p),b=r_u32(p+4u);w_u32(p,r_u32(p+8u));w_u32(p+4u,r_u32(p+12u));w_u32(p+8u,a);w_u32(p+12u,b);result=a;}}
    return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80030678
uint32 sub_80030678(uint32 previous,uint32 position)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 x=r_u32(position),z=r_u32(position+8u),bx=x&0xFFFFF000u,bz=z&0xFFFFF000u,layer=0u;
    uint32 initial=r_u16(r_u32(0x800A84F8u)+8u*(80u*(uint32)((int32)z>>12)+(uint32)((int32)x>>12))+4u),cursor=initial,tag,list;
    for(;;){tag=r_u16(r_u32(0x800A869Cu)+2u*cursor);if((int32)(0u-r_u32(position+4u))>=(int32)(2u*(tag&0x7FFFu)))break;cursor+=3u;if(tag&0x8000u)break;++layer;}
    list=r_u16(r_u32(0x800A869Cu)+2u*(initial+3u*layer)+4u);if(list==0xFFFFu)return draft_scratch_result(native_stack_mark, (uint64)(0u));
    do {
        uint32 p,j,inside=1u;int32 px[4],pz[4];tag=r_u16(r_u32(0x800A9CE4u)+2u*list++);p=r_u32(0x800A9CE8u)+28u*(tag&0x7FFFu);
        px[0]=(int16)r_u16(p);pz[0]=(int16)r_u16(p+4u);
        for(j=1;j<4u;++j){px[j]=(int16)r_u16(p+2u+4u*j);pz[j]=(int16)r_u16(p+4u+4u*j);}
        for(j=0;j<4u;++j){uint32 k=(j+1u)&3u;uint32 cross=(uint32)(pz[j]-pz[k])*(x-bx-(uint32)px[k])+(uint32)(px[k]-px[j])*(z-bz-(uint32)pz[k]);if((int32)cross<0)inside=0u;}
        if(inside){uint32 n=0u-((uint32)(int32)(int16)r_u16(p+18u)*(x-bx-(uint32)px[0])+(uint32)(int32)(int16)r_u16(p+22u)*(z-bz-(uint32)pz[0]));
            uint32 height=0u-((uint32)d02_div(n,(uint32)(int32)(int16)r_u16(p+20u))+(uint32)(int32)(int16)r_u16(p+2u));
            if((int32)height<(int32)r_u32(position+4u)){w_u32(position+4u,height);w_u32(position,r_u32(previous));w_u32(position+8u,r_u32(previous+8u));j=(uint32)(int32)(int16)r_u16(p+24u);return draft_scratch_result(native_stack_mark, (uint64)(j?j:16u));}
        }
    }while(!(tag&0x8000u));return draft_scratch_result(native_stack_mark, (uint64)(0u));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8002B93C
uint32 sub_8002B93C(uint32 output,uint32 reference,uint32 position,uint32 base,uint32 corners,uint32 polygon)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch=draft_scratch_adapter(24u),bx=r_u32(base),bz=r_u32(base+8u),i,bit=1u;
    uint32 x=r_u32(reference)-bx,z=r_u32(reference+8u)-bz;int32 px[4],pz[4];uint32 inside=1u;
    w_u32(position,r_u32(position)-bx);w_u32(position+8u,r_u32(position+8u)-bz);
    for(i=0;i<4u;++i){px[i]=(int16)r_u16(polygon+8u*i);pz[i]=(int16)r_u16(polygon+8u*i+4u);}
    {uint32 order[4]={2u,3u,1u,0u};for(i=0;i<4u;++i){uint32 a=order[i],b=order[(i+1u)&3u];if((int32)((uint32)(pz[a]-pz[b])*(x-(uint32)px[b])+(uint32)(px[b]-px[a])*(z-(uint32)pz[b]))>0)inside=0u;}}
    w_u32(scratch,x);w_u32(scratch+8u,z);
    if(inside){uint32 angle=d02_rand()&4095u;int32 dx=(int16)r_u16(0x800102E0u+2u*angle),dz=(int16)r_u16(0x80010AE0u+2u*angle);w_u32(scratch,x+(uint32)(dx<0?-dx:dx));w_u32(scratch+8u,z+(uint32)(dz<0?-dz:dz));}
    draft_call_adapter(0x8002A38Cu,scratch,position,polygon);w_u32(scratch,r_u32(position));w_u32(scratch+8u,r_u32(position+8u));
    for(i=0;i<8u;++i){uint32 corner=corners+8u*i,code;w_u32(scratch+12u,(uint32)(int32)(int16)r_u16(corner)+r_u32(position));w_u32(scratch+20u,(uint32)(int32)(int16)r_u16(corner+4u)+r_u32(position+8u));
        code=(uint32)(int32)(int16)draft_call_adapter(0x8002A38Cu,scratch,scratch+12u,polygon);
        if(code){w_u16(output+98u,(uint16)code);w_u16(output+96u,r_u16(output+96u)|(uint16)bit);w_u32(output+12u*i,r_u32(scratch));w_u32(output+12u*i+8u,r_u32(scratch+8u));
            if(r_u32(scratch))w_u32(position,r_u32(scratch+12u)-(uint32)(int32)(int16)r_u16(corner));
            if(r_u32(scratch+8u))w_u32(position+8u,r_u32(scratch+20u)-(uint32)(int32)(int16)r_u16(corner+4u));
            w_u32(scratch,r_u32(position));w_u32(scratch+8u,r_u32(position+8u));}
        bit*=2u;
    }
    w_u32(position,bx+r_u32(position));w_u32(position+8u,bz+r_u32(position+8u));return draft_scratch_result(native_stack_mark, (uint64)(r_u32(position)));

    draft_scratch_release(native_stack_mark);
}

static void d02_line(uint32 scratch,uint32 depth)
{
    draft_call_adapter(0x80070CF4u,scratch,scratch+8u,depth,0x3F3F3Fu);
}

// FUNCTION_MARKER sub_80070D6C
uint32 sub_80070D6C(uint32 x,uint32 y,uint32 width,uint32 height,uint32 depth)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 p=draft_scratch_adapter(16u);uint16 xx=(uint16)x,yy=(uint16)y,w=(uint16)width,h=(uint16)height;
    w_u16(p,xx+1u);w_u16(p+2u,yy);w_u16(p+8u,xx+1u+w);w_u16(p+10u,yy);d02_line(p,depth);
    w_u16(p+2u,yy+h);w_u16(p+10u,yy+h);d02_line(p,depth);
    w_u16(p,xx);w_u16(p+2u,yy+1u);w_u16(p+8u,xx+w+2u);w_u16(p+10u,yy+1u);d02_line(p,depth);
    w_u16(p+2u,yy+2u);w_u16(p+10u,yy+2u);draft_call_adapter(0x80070CF4u,p,p,depth,0x3F3F3Fu);draft_call_adapter(0x80070CF4u,p+8u,p+8u,depth,0x3F3F3Fu);
    w_u16(p+2u,yy+h-2u);w_u16(p+10u,yy+h-2u);draft_call_adapter(0x80070CF4u,p,p,depth,0x3F3F3Fu);draft_call_adapter(0x80070CF4u,p+8u,p+8u,depth,0x3F3F3Fu);
    w_u16(p+2u,yy+h-1u);w_u16(p+10u,yy+h-1u);d02_line(p,depth);
    w_u16(p,xx-1u);w_u16(p+2u,yy+2u);w_u16(p+8u,xx-1u);w_u16(p+10u,yy+h-2u);d02_line(p,depth);
    w_u16(p,xx+w+3u);w_u16(p+8u,xx+w+3u);d02_line(p,depth);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80020C60u,200u,r_u32(0x800A9A74u),0x3F3F3Fu,2u,(uint32)(int32)(int16)(xx-160u),(uint32)(int32)(int16)(yy-119u),(uint32)(int32)(int16)(w+3u),(uint32)(int32)(int16)(h-1u))));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_80070B88
uint32 sub_80070B88(uint32 index)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 x=r_u32(0x800A75C8u)+46u,menu=r_u32(0x800A645Cu),entry=r_u32(0x80091EE0u+12u*menu)+16u*index;
    sub_80070D6C(x,12u*(index+1u)+32u,64u,8u,100u);
    // TODO Preserve the selected entry parameter at the menu-decoration boundary
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80070C48u,199u,65280u,255u,3u,x,12u*(index+1u)+32u,(uint32)(int32)(int16)r_u16(entry+14u))));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800723C4
uint32 sub_800723C4(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 count=7u,table=0x80092084u,alternate=0u,i,max=0u,options,width,height;
    if((int16)sub_80037BB8()==2){count=6u;table=0x800920C0u;alternate=1u;}
    for(i=0;i<count;++i){uint32 text=d02_call(0x8006F554u,r_u32(0x800A8DACu),i,0u,0u);width=sub_80043820(text,0x4F4F4Fu,143u,12u*(i+1u)+75u,100u,0u);if((int32)max<(int32)width)max=width;}
    width=max+52u;height=12u*(count+1u)+12u;
    options=alternate?r_u32(0x800921F8u+4u*(uint32)(int32)(int16)r_u16(0x800A645Au)):r_u32(0x80092208u+4u*r_u32(0x800A6458u));
    for(i=0;i<count;++i){uint32 choice=r_u8(options+i);sub_80043820(r_u32(table+4u*choice),0x7F7F7Fu,width+104u,12u*(i+1u)+75u,99u,0u);w_u16(0x800A5C90u+2u*i,r_u16(0x8009219Cu+2u*choice));}
    return draft_scratch_result(native_stack_mark, (uint64)(sub_80070D6C(130u,75u,width,height,101u)));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8003E690
uint32 sub_8003E690(uint32 object,uint32 kind,uint32 acceleration)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch=draft_scratch_adapter(28u),toggle=(uint32)(int32)(int16)r_u16(object+54u),vtable=r_u32(object+16u),p,i;
    int32 speed=(int32)draft_call_adapter(r_u32(vtable),object)>>16;
    uint16 angle=(uint16)(draft_call_adapter(r_u32(vtable+12u),object)+2048u);int32 difference;
    draft_call_adapter(r_u32(vtable+20u),object,scratch);difference=(int32)((angle-r_u16(scratch+2u))&4095u)-2048;if(difference<0)difference=-difference;if(difference<1024)speed=-speed;
    p=d02_call(0x800226E4u,92u,0u,0u,0u);w_u8(p+34u,8u);for(i=0;i<3u;++i)w_u32(p+20u+4u*i,r_u32(object+20u+4u*i));
    w_u8(p+14u,r_u8(p+14u)|2u);w_u16(p+32u,r_u16(r_u32(0x800A62ECu)+260u));draft_call_adapter(0x80055288u,scratch,p+36u);
    w_u32(p,0x8003E988u);w_u32(p+16u,object);w_u16(p+58u,(uint16)kind);w_u16(p+76u,(uint16)speed);w_u16(p+78u,(uint16)acceleration);
    w_u16(p+80u,0u);w_u16(p+84u,0u);w_u16(p+86u,0xFFFFu);w_u16(p+82u,r_u16(scratch+2u));w_u16(p+88u,r_u8(0x80090370u+acceleration));w_u16(p+90u,r_u16(scratch));
    w_u32(scratch+8u,toggle?125u:0u-125u);w_u32(scratch+12u,0u-150u);w_u32(scratch+16u,(uint32)(int32)(int16)r_u16(p+76u)*r_u32(0x800A9010u));
    draft_call_adapter(0x80031E30u,p+36u,p+20u,scratch+8u);w_u8(p+72u,0u);w_u16(p+56u,0u);w_u16(object+54u,(toggle+1u)&1u);return draft_scratch_result(native_stack_mark, (uint64)(p));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8003E988
uint32 sub_8003E988(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch=draft_scratch_adapter(48u),i,step=r_u32(0x800A9010u),delta,old_y,terrain,heading,length,angle,result;
    if(r_u16(object+56u)){draft_call_adapter(0x80036CFCu,object+86u);return draft_scratch_result(native_stack_mark, (uint64)(d02_call(0x8002A5DCu,object,r_u16(object+56u),0u,0u)));}
    for(i=0;i<3u;++i)w_u32(scratch+4u*i,r_u32(object+20u+4u*i));
    delta=(uint32)d02_div(0u-60u*step*(uint32)(int32)(int16)r_u16(object+76u),50u);w_u16(object+80u,r_u16(object+80u)-delta);
    w_u32(scratch+16u,0u);w_u32(scratch+20u,0u);w_u32(scratch+24u,delta);
    draft_call_adapter(0x80031BBCu,object+36u,scratch+16u,scratch+16u);
    w_u32(object+20u,r_u32(object+20u)+r_u32(scratch+16u));w_u32(object+28u,r_u32(object+28u)+r_u32(scratch+24u));old_y=r_u32(object+24u);
    terrain=d02_call(0x8003E5C4u,object+20u,object+84u,r_u32(scratch+20u),200u);heading=sub_80055A9C(r_u32(scratch+16u),r_u32(scratch+24u))-(uint32)(int32)(int16)r_u16(object+82u);
    if((int32)heading<0)heading=0u-heading;
    length=d02_call(0x80069BE0u,r_u32(scratch+16u),r_u32(scratch+24u),0u,0u);angle=0u-(uint32)(int32)(int16)sub_80055A9C(heading<1025u?r_u32(object+24u)-old_y:old_y-r_u32(object+24u),length);
    angle=d02_call(0x80055764u,(uint32)(int32)(int16)r_u16(object+90u),(uint32)(int32)(int16)angle,10u*r_u32(0x800A9010u),0u);w_u16(object+90u,(uint16)angle);
    w_u16(scratch+32u,(uint16)angle);w_u16(scratch+34u,r_u16(object+82u));
    // TODO The unused roll halfword is supplied by the original local buffer
    w_u16(scratch+36u,0u);draft_call_adapter(0x80055288u,scratch+32u,object+36u);
    if((int16)r_u16(object+76u)<200)w_u16(object+76u,r_u16(object+76u)+(uint32)d02_div(60u*step*(uint32)(int32)(int16)r_u16(object+78u),50u));else w_u16(object+76u,200u);
    angle=(uint32)(int32)(int16)r_u16(object+88u);draft_call_adapter(0x800620A4u,object,object+60u,object+20u,scratch,(uint32)(sint32)(sint16)r_u16(r_u32(0x800A62ECu)+46u),150u,angle,48u);
    w_u32(scratch+16u,r_u32(scratch));w_u32(scratch+20u,r_u32(scratch+4u));w_u32(scratch+24u,r_u32(scratch+8u));
    result=d02_call(0x8002F3FCu,scratch+16u,object+20u,0u,0u);
    if((uint16)result){if(!(d02_rand()&15u)){w_u16(object+56u,7u);return draft_scratch_result(native_stack_mark, (uint64)(7u));}}
    else if((int16)r_u16(object+80u)<18000 && !(uint16)terrain)goto emit;
    draft_call_adapter(0x8002A8F0u,object);
emit:
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80029970u,object,136u,6u,1u,scratch,150u,angle,48u)));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8003F310
uint32 sub_8003F310(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch=draft_scratch_adapter(96u),parent=r_u32(object+8u),step=r_u32(0x800A9010u),i,count=0u,result;
    int32 offset=(int16)r_u16(object+70u);uint32 vtable=r_u32(parent+16u);
    w_u32(scratch,(uint32)(int32)(int16)r_u16(object+66u));w_u32(scratch+4u,(uint32)(int32)(int16)r_u16(object+68u));
    if(d02_call(0x8003DB0Cu,r_u32(object+16u),0u,0u,0u))offset>>=1;w_u32(scratch+8u,(uint32)offset);
    draft_call_adapter(r_u32(vtable+20u),parent,scratch+12u);
    draft_call_adapter(0x80054D38u,(uint32)(int32)(int16)r_u16(scratch+12u),(uint32)(int32)(int16)r_u16(scratch+14u),(uint32)(int32)(int16)r_u16(scratch+16u),scratch+56u);
    for(i=0;i<4u;++i)w_u32(object+36u+4u*i,r_u32(scratch+56u+4u*i));w_u16(object+52u,r_u16(scratch+72u));
    if(r_u16(object+56u))return draft_scratch_result(native_stack_mark, (uint64)(d02_call(0x8002A5DCu,object,(uint32)(int32)(int16)r_u16(object+56u),0u,0u)));
    if((int16)r_u16(object+60u)<0)return draft_scratch_result(native_stack_mark, (uint64)(d02_call(0x8002289Cu,object,0u,0u,0u)));
    for(i=0;i<3u;++i)w_u32(scratch+44u+4u*i,r_u32(parent+20u+4u*i));
    draft_call_adapter(0x80031D50u,scratch+56u,parent+20u,scratch,scratch+32u);sub_8003F0F8(scratch+32u,scratch+56u);w_u32(scratch+8u,r_u32(scratch+8u)-620u);
    for(;;){draft_call_adapter(0x80031D50u,scratch+56u,parent+20u,scratch,scratch+32u);result=d02_call(0x8002F3FCu,scratch+44u,scratch+32u,0u,0u);
        if(!(uint16)result){result=sub_80030678(scratch+44u,scratch+32u);if(!(uint16)result){for(i=0;i<3u;++i)w_u32(scratch+44u+4u*i,r_u32(scratch+32u+4u*i));++count;}}
        w_u32(scratch+8u,r_u32(scratch+8u)-620u);if((uint16)result)break;
        sub_8003F0F8(scratch+32u,scratch+56u);if(count>=10u)goto finished;
    }
    draft_call_adapter(0x8003F5CCu,scratch+32u);
finished:
    for(i=0;i<3u;++i)w_u32(scratch+32u+4u*i,r_u32(object+20u+4u*i));
    if((int16)r_u16(object+62u)<(int32)r_u32(scratch+8u))w_u16(object+62u,(uint16)-offset);
    w_u32(scratch+8u,(uint32)(int32)(int16)r_u16(object+62u));draft_call_adapter(0x80031D50u,scratch+56u,parent+20u,scratch,object+20u);
    // TODO Bind the remaining particle parameters at the external emitter
    draft_call_adapter(0x80029970u,object,136u,6u,1u,scratch+32u);
    result=r_u16(object+62u)-(step<<9);w_u16(object+62u,(uint16)result);w_u16(object+60u,r_u16(object+60u)-step);return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8006C714
uint32 sub_8006C714(uint32 object,uint32 kind)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch=draft_scratch_adapter(32u),p,target,angle,model;
    w_u32(scratch+8u,0u);w_u32(scratch+12u,0u);w_u16(scratch+10u,(uint16)-50);w_u16(scratch+12u,(uint16)-200);w_u16(scratch+8u,(uint16)(300u*r_u32(0x800A640Cu)-150u));
    w_u32(scratch,r_u32(scratch+8u));w_u32(scratch+4u,r_u32(scratch+12u));
    p=sub_8006C094(object,scratch,5120u,0u,0u,1u,0u-16u,0u,0u-32u,6144u);w_u32(0x800A640Cu,r_u32(0x800A640Cu)^1u);
    draft_call_adapter(r_u32(r_u32(object+16u)+20u),object,scratch+16u);angle=(r_u16(scratch+18u)+2048u)&4095u;if(angle>=2049u)angle|=0xF000u;w_u16(scratch+18u,(uint16)angle);
    target=(uint32)draft_call_adapter(0x8006BD08u,object+20u,(uint32)(int32)(int16)r_u16(scratch+16u),angle,r_u8(object+13u),scratch+24u);
    w_u16(p+80u,(uint16)-272);w_u32(p+88u,target);if(target){w_u8(target+15u,r_u8(target+15u)+1u);w_u8(p+84u,255u);}else w_u8(p+84u,(d02_rand()&31u)+5u);
    w_u32(p,0x8006C3D4u);w_u32(p+16u,object);model=r_u16(r_u32(0x800A62ECu)+200u);w_u8(p+14u,r_u8(p+14u)|2u);w_u16(p+32u,(uint16)model);
    w_u32(p+72u,(uint32)(int32)(int16)angle);w_u16(p+82u,0u);w_u8(p+104u,0u);w_u32(p+76u,(uint32)(int32)(int16)r_u16(scratch+16u));
    draft_call_adapter(target?0x8006AFF4u:0x8006AF08u,p);w_u8(p+130u,255u);draft_call_adapter(0x80035A08u,20u,1024u,255u,p+20u);w_u16(p+58u,(uint16)kind);w_u8(p+13u,48u);return draft_scratch_result(native_stack_mark, (uint64)(48u));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_800352C4
uint32 sub_800352C4(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 state,i;static const uint32 buttons[7]={0xFFFF8000u,8192u,4096u,16384u,64u,2048u,256u};
    if(!r_u32(0x800A84D4u))w_u32(0x800A9A68u,0u);draft_call_adapter(0x80078830u);
    if(r_u16(0x800A6D10u)==2u)return draft_scratch_result(native_stack_mark, (uint64)(0xFFFFFFFFu));
    draft_call_adapter(0x80034868u,r_u32(0x800A9020u));
    w_u16(0x800A6CF8u,0u);w_u16(0x800A6D04u,0u);w_u16(0x800A6D08u,0xFFFFu);w_u16(0x800A6CFCu,0u);w_u16(0x800A6CF4u,0u);w_u16(0x800A6D28u,0u);w_u16(0x800A6D10u,0u);
    draft_call_adapter(0x80038964u,0xFFFFu);w_u16(0x800A6D0Cu,0u);w_u16(0x800A6D24u,0u);
    for(;;){uint32 player;
        w_u16(0x800A98F4u,0u);sub_800697BC();w_u16(0x800A6D18u,1u);draft_call_adapter(0x800345B0u,r_u32(0x800A9020u));draft_call_adapter(0x8002DC94u);draft_call_adapter(0x80022A68u,0u);
        if(r_u32(0x800A622Cu)){player=r_u32(r_u32(0x800A851Cu)+4u*(uint32)(int32)(int16)r_u16(r_u32(r_u32(0x800A9020u)+8u)));w_u32(0x800A9A58u,r_u32(0x800A622Cu));draft_call_adapter(r_u8(player+13u) && (r_u8(player+13u)>=9u || r_u8(player+13u)<7u)?0x8005CC60u:0x8005DC0Cu,0x800A7EE4u);}
        draft_call_adapter(0x80021718u,0x800A7EE4u,1u);draft_call_adapter(0x8005E31Cu);draft_call_adapter(0x8005E7DCu);draft_call_adapter(0x80020E30u);draft_call_adapter(0x8001F690u);sub_8001F968();sub_80036BE4();
        w_u16(0x800A6D14u,0u);for(i=0;i<7u;++i)w_u16(0x800A6D14u,r_u16(0x800A6D14u)+(uint16)draft_call_adapter(0x80038970u,buttons[i]));
        draft_call_adapter(0x8003438Cu,r_u32(0x800A9020u));draft_call_adapter(0x8001FF7Cu,1u);draft_call_adapter(0x8001F850u);sub_8005A944();state=(uint32)(int32)(int16)r_u16(0x800A6D24u);
        if(!state){if((uint32)draft_call_adapter(0x80034264u)==0xFFFFFFFFu)w_u16(0x800A6D0Cu,1u);
            if((r_u16(0x800A6D0Cu)==1u && !r_u32(r_u32(0x800A9020u)+4u)) || r_u16(0x800A6D10u)==2u)w_u16(0x800A6D24u,1u);
            if(r_u16(0x800A6D0Cu)==1u && r_u32(r_u32(0x800A9020u)+4u) && !r_u16(0x800A6D24u) && !r_u32(0x800A562Cu)){w_u16(0x800A6D0Cu,0u);break;}
            state=(uint32)(int32)(int16)r_u16(0x800A6D24u);
        }
        if(state==1u){draft_call_adapter(0x800205C8u,0u,12u,0u);w_u16(0x800A6D24u,2u);}
        if(r_u16(0x800A6D24u)==2u && r_u8(0x800A7BDFu) && !r_u32(0x800A562Cu))break;
    }
    draft_call_adapter(0x80034C88u);return draft_scratch_result(native_stack_mark, (uint64)(0u));

    draft_scratch_release(native_stack_mark);
}

// FUNCTION_MARKER sub_8002CE90
uint32 sub_8002CE90(uint32 object,uint32 first,uint32 other,uint32 second)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 result=r_u32(other+16u),scratch=draft_scratch_adapter(80u),a=0x800B3484u+20u*(uint32)(int32)(int16)first,b=0x800B3484u+20u*(uint32)(int32)(int16)second;
    uint32 bound,dy,mode,code,x,z,polygon,i;
    if(object==result)return draft_scratch_result(native_stack_mark, (uint64)(result));bound=sub_8002B6A8(object)+r_u16(b+14u);dy=r_u32(object+24u)-r_u32(other+24u);if((int32)dy<0)dy=0u-dy;
    result=first<<16;if((int32)bound<(int32)dy)return draft_scratch_result(native_stack_mark, (uint64)(result));mode=r_u8(a+12u);
    if((mode==2u || mode==0u) && r_u16(r_u32(other+16u)+70u)==r_u16(object+70u))return draft_scratch_result(native_stack_mark, (uint64)((uint32)(int32)(int16)r_u16(object+70u)));
    result=second<<16;if(mode==9u && r_u16(r_u32(other+16u)+70u)==r_u16(r_u32(object+8u)+70u))return draft_scratch_result(native_stack_mark, (uint64)(result));
    x=r_u32(object+20u);z=r_u32(object+28u);w_u32(scratch+32u,r_u32(b)-x);w_u32(scratch+40u,r_u32(b+8u)-z);w_u32(scratch+48u,r_u32(other+20u)-x);w_u32(scratch+56u,r_u32(other+28u)-z);
    polygon=object+160u;if(mode){sub_8002A090(object,d02_model(object),scratch);polygon=scratch;}
    result=(uint32)draft_call_adapter(0x8002A38Cu,scratch+32u,scratch+48u,polygon)<<16;code=(uint32)((int32)result>>16);if(!code)return draft_scratch_result(native_stack_mark, (uint64)(result));
    w_u16(other+56u,r_u8(0x800A5774u+(uint32)(int32)(int16)r_u16(other+58u)));
    if(mode==7u || mode==10u){w_u16(object+56u,12u);for(i=0;i<3u;++i){uint32 value=(r_u32(other+20u+4u*i)-r_u32(b+4u*i))<<16;if(r_u32(0x800A9010u))value=(uint32)d02_div(value,r_u32(0x800A9010u));w_u32(scratch+64u+4u*i,value);}draft_call_adapter(r_u32(r_u32(object+16u)+24u),object,scratch+64u);}
    else if(mode==8u)w_u16(object+56u,12u);
    else {
        if(!mode){uint32 mapped=0u;switch(code){case 1:case 2048:mapped=1u;break;case 4:case 8:mapped=4u;break;case 32:case 64:mapped=16u;break;case 256:case 512:mapped=64u;break;case 2:mapped=2u;break;case 16:mapped=8u;break;default:break;}if(mapped)w_u16(0x800A8704u,(uint16)mapped);}
        draft_call_adapter(0x8002AA2Cu,other,object,mode);
    }
    w_u32(other+20u,x+r_u32(scratch+48u));result=z+r_u32(scratch+56u);w_u32(other+28u,result);return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}


static void d02_vertices(uint32 a,uint32 b,uint32 c)
{
    xport_gte_write_data(0u,r_u32(a));xport_gte_write_data(1u,r_u32(a+4u));xport_gte_write_data(2u,r_u32(b));xport_gte_write_data(3u,r_u32(b+4u));xport_gte_write_data(4u,r_u32(c));xport_gte_write_data(5u,r_u32(c+4u));
}
static void d02_packet(uint32 packet,uint32 table,uint32 bias,uint32 depth)
{
    uint32 link=table+4u*bias+4u*(depth>>3);w_u32(packet,(r_u32(link)&0xFFFFFFu)|0x05000000u);w_u32(link,(r_u32(link)&0xFF000000u)|(packet&0xFFFFFFu));
}

// FUNCTION_MARKER sub_8001D870
uint32 sub_8001D870(uint32 screen,uint32 packet,uint32 table,uint32 vertices,uint32 bias)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 start=0u,j;
    do {
        uint32 a=vertices+8u*start,b=a+8u,c=a+24u,d=a+32u,flag,depth,nclip;
        d02_vertices(a,b,c);draft_gte_command_adapter(0x280030u);xport_gte_write_data(0u,r_u32(d));xport_gte_write_data(1u,r_u32(d+4u));flag=draft_gte_control_adapter(31u);draft_gte_command_adapter(0x1400006u);nclip=xport_gte_read_data(24u);
        if((int32)flag>=0 && nclip<1024u){for(j=0;j<3u;++j)w_u32(packet+8u+4u*j,xport_gte_read_data(12u+j));draft_gte_command_adapter(0x180001u);w_u32(packet+4u,xport_gte_read_data(22u));draft_gte_command_adapter(0x168002Eu);w_u32(packet+20u,xport_gte_read_data(14u));depth=xport_gte_read_data(7u);d02_packet(packet,table,bias,depth);packet+=24u;goto next;}
        for(j=0;j<3u;++j)w_u32(screen+4u*j,xport_gte_read_data(12u+j));xport_gte_write_data(0u,r_u32(d));xport_gte_write_data(1u,r_u32(d+4u));draft_gte_command_adapter(0x180001u);w_u32(screen+12u,xport_gte_read_data(14u));
        {uint32 right=1u,left=1u,bottom=1u,top=1u;for(j=0;j<4u;++j){int32 x=(int16)r_u16(screen+4u*j),y=(int16)r_u16(screen+4u*j+2u);right&=x>=320;left&=x<=0;bottom&=y>=240;top&=y<=0;}if(right||left||bottom||top)goto next;}
        for(j=0;j<3u;++j){int32 va=(int16)r_u16(a+2u*j),vb=(int16)r_u16(b+2u*j),vc=(int16)r_u16(c+2u*j),vd=(int16)r_u16(d+2u*j);
            w_u16(vertices+72u+2u*j,(uint16)((va+vb)>>1));w_u16(vertices+80u+2u*j,(uint16)((va+vc)>>1));w_u16(vertices+88u+2u*j,(uint16)((vb+vc)>>1));w_u16(vertices+104u+2u*j,(uint16)((vd+vc)>>1));w_u16(vertices+96u+2u*j,(uint16)((vb+vd)>>1));}
        {uint32 indices[4][4]={{start,9u,10u,11u},{9u,start+1u,11u,12u},{10u,11u,start+3u,13u},{11u,12u,13u,start+4u}},part;
          for(part=0;part<4u;++part){d02_vertices(vertices+8u*indices[part][0],vertices+8u*indices[part][1],vertices+8u*indices[part][2]);draft_gte_command_adapter(0x280030u);d=vertices+8u*indices[part][3];xport_gte_write_data(0u,r_u32(d));xport_gte_write_data(1u,r_u32(d+4u));draft_gte_command_adapter(0x1400006u);
            if((int32)xport_gte_read_data(24u)>=0){for(j=0;j<3u;++j)w_u32(packet+8u+4u*j,xport_gte_read_data(12u+j));draft_gte_command_adapter(0x180001u);draft_gte_command_adapter(0x168002Eu);depth=xport_gte_read_data(7u);if(depth){w_u32(packet+20u,xport_gte_read_data(14u));d02_packet(packet,table,bias,depth);w_u32(packet+4u,xport_gte_read_data(22u));packet+=24u;}}
          }
        }
next:
        ++start;if(start==2u)start=3u;
    }while(start<5u);return draft_scratch_result(native_stack_mark, (uint64)(packet));

    draft_scratch_release(native_stack_mark);
}

static int32 d02_angle(uint32 value)
{
    value&=4095u;return value>=2049u?(int32)value-4096:(int32)value;
}
static uint32 d02_mass(uint32 object)
{
    uint32 result=r_u16(object+58u)?(uint32)(int32)(int16)r_u16(d02_model(object)+38u):1u;
    if(r_u16(object+32u)==166u)result+=(uint32)(int32)(int16)r_u16(r_u32(0x800A90ACu)+40u*r_u8(r_u32(0x800A8548u)+167u)+38u);
    return result;
}
static void d02_velocity(uint32 object,uint32 output)
{
    if(r_u16(object+58u))draft_call_adapter(r_u32(r_u32(object+16u)+4u),object,output);
    else{w_u32(output,0u);w_u32(output+8u,0u);}
}
static void d02_bounce(uint32 object,uint32 other,uint32 velocity)
{
    int32 angle=d02_angle(sub_80055A9C(r_u32(velocity),r_u32(velocity+8u))-sub_80055A9C(r_u32(other+20u)-r_u32(object+20u),r_u32(other+28u)-r_u32(object+28u)));
    if(angle<0)angle=-angle;
    if(angle>=1025){w_u8(object+87u,0u-r_u8(object+87u));w_u16(object+114u,(uint16)((5u*(r_u32(0x800A63D8u)>>8))>>8));}
}

// FUNCTION_MARKER sub_8002BE3C
uint32 sub_8002BE3C(uint32 object,uint32 first,uint32 other,uint32 second)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 bound=sub_8002B6A8(object)+sub_8002B6A8(other),dy=r_u32(object+24u)-r_u32(other+24u),result;
    uint32 entry=0x800B3484u+20u*(uint32)(int32)(int16)first,other_entry=0x800B3484u+20u*(uint32)(int32)(int16)second;
    uint32 scratch=draft_scratch_adapter(272u),polygon=scratch,corners=scratch+64u,contacts=scratch+96u,va=scratch+200u,vb=scratch+212u,pa=scratch+224u,pb=scratch+236u;
    uint32 flags,code,ma,mb,i,impulse,normal,total,dx,dz,ax,az,bx,bz,impact_a,impact_b,mode,other_mode;
    if((int32)dy<0)dy=0u-dy;result=(int32)bound<(int32)dy;if(result)return draft_scratch_result(native_stack_mark, (uint64)(result));
    result=second<<16;mode=r_u8(entry+12u);other_mode=r_u8(other_entry+12u);
    if(mode==9u && r_u32(r_u32(0x800A851Cu)+4u*(uint32)(int32)(int16)r_u16(object+58u))==other)return draft_scratch_result(native_stack_mark, (uint64)(result));
    if(other_mode==9u){result=r_u32(r_u32(0x800A851Cu)+4u*(uint32)(int32)(int16)r_u16(other+58u));if(result==object)return draft_scratch_result(native_stack_mark, (uint64)(result));}
    sub_8002A090(other,d02_model(other),corners);
    if(mode){
        w_u16(contacts+96u,0u);w_u16(contacts+98u,0u);sub_80029EEC(object,d02_model(object),polygon);draft_call_adapter(0x80029D44u,polygon);
        for(i=0;i<3u;++i){uint32 origin=(uint32)(int32)(int16)r_u16(polygon+2u*i);xport_gte_write_control(2u*i,(uint32)(int32)(int16)r_u16(polygon+8u+2u*i)-origin);xport_gte_write_data(9u+i,(uint32)(int32)(int16)r_u16(polygon+16u+2u*i)-origin);}draft_gte_command_adapter(0x170000Cu);
        result=sub_8002B93C(contacts,entry,object+20u,other+20u,polygon,corners);code=(uint32)(int32)(int16)r_u16(contacts+98u);flags=r_u16(contacts+96u);
    }else{w_u16(0x800A8706u,0u);result=sub_8002B93C(0x800A86A4u,entry,object+20u,other+20u,object+160u,corners);code=(uint32)(int32)(int16)r_u16(0x800A8706u);flags=r_u16(0x800A8704u);}
    if(!code)return draft_scratch_result(native_stack_mark, (uint64)(result));
    ma=d02_mass(object);mb=d02_mass(other);d02_velocity(object,va);d02_velocity(other,vb);
    ax=r_u32(va);az=r_u32(va+8u);bx=r_u32(vb);bz=r_u32(vb+8u);w_u32(pa,ax);w_u32(pa+8u,az);w_u32(pb,bx);w_u32(pb+8u,bz);
    dx=160u*(uint32)((int32)(bx-ax)>>8);dz=160u*(uint32)((int32)(bz-az)>>8);total=ma+mb;
    bx=(uint32)d02_div(ma*(ax-dx)+mb*bx,total);bz=(uint32)d02_div(ma*(az-dz)+mb*bz,total);ax=dx+bx;az=dz+bz;
    w_u32(va,ax);w_u32(va+8u,az);w_u32(vb,bx);w_u32(vb+8u,bz);
    impact_a=d02_call(0x80069BE0u,(uint32)((int32)(ax-r_u32(pa))>>17),(uint32)((int32)(az-r_u32(pa+8u))>>17),0u,0u);if((int32)impact_a>=19)impact_a=18u;
    impact_b=d02_call(0x80069BE0u,(uint32)((int32)(bx-r_u32(pb))>>17),(uint32)((int32)(bz-r_u32(pb+8u))>>17),0u,0u);if((int32)impact_b>=19)impact_b=18u;
    w_u32(pa,impact_a);w_u32(pa+8u,impact_a);w_u32(pb,impact_b);w_u32(pb+8u,impact_b);
    mode=r_u8(entry+12u);
    if(mode==1u){sub_8002BC6C(other,object,va);if(!r_u16(object+58u)){w_u32(va,2u*r_u32(va));w_u32(va+8u,2u*r_u32(va+8u));}sub_8002B224(object,(uint32)(int32)(int16)first,code,va,pa,0x8002E0B4u);}
    else if(mode==0u)draft_call_adapter(r_u32(r_u32(object+16u)+24u),object,va);
    else if(mode==2u){draft_call_adapter(r_u32(r_u32(object+16u)+24u),object,va);if(r_u8(object+197u)-8u>=2u)sub_8002AF4C(object+200u,r_u16(contacts+96u),pa);d02_bounce(object,other,va);}
    other_mode=r_u8(other_entry+12u);
    if(other_mode==2u){
        if(mode==2u || !mode){uint32 state=r_u8(other+197u);if(state==14u || state==16u || state==7u){w_u32(vb,(uint32)((int32)r_u32(vb)>>1));w_u32(vb+8u,(uint32)((int32)bz>>1));}
            else{sub_8002BC6C(object,other,vb);if(state-8u>=2u)sub_8002ACCC(other+200u,code,pb);}}
        draft_call_adapter(r_u32(r_u32(other+16u)+24u),other,vb);d02_bounce(other,object,vb);
        if(r_u32(0x800A9760u) && r_u8(other+197u)-8u<2u && r_u8(other+196u)!=6u){draft_call_adapter(0x80052988u,other);draft_call_adapter(0x800608F8u,other);}
    }else if(other_mode==1u){sub_8002BC6C(object,other,vb);if(!r_u16(other+58u)){w_u32(vb,2u*r_u32(vb));w_u32(vb+8u,2u*bz);}sub_8002B224(other,(uint32)(int32)(int16)second,code,vb,pb,0x8002DFF8u);}
    else if(other_mode==9u){w_u32(vb,(uint32)((int32)r_u32(vb)>>1));w_u32(vb+8u,(uint32)((int32)bz>>1));}
    impulse=d02_call(0x80069BE0u,(uint32)((int32)(r_u32(va)+r_u32(vb))>>8),(uint32)((int32)(r_u32(va+8u)+r_u32(vb+8u))>>8),0u,0u)<<8;
    normal=2u*((impact_a&255u)+(impact_b&255u))&126u;
    if((int32)impulse<=1310720)return draft_scratch_result(native_stack_mark, (uint64)(first<<16));
    if((int32)impulse<=2621440)draft_call_adapter(0x80035A08u,48u,2048u,normal,object+20u);
    else{uint32 random;draft_call_adapter(0x80035A08u,(int32)impulse>5242880?25u:23u,2048u,normal,object+20u);random=5u*r_u32(0x800A63DCu)+1u;w_u32(0x800A63DCu,random);draft_call_adapter(0x80035A08u,61u,(random&1023u)|2048u,(int32)impulse>5242880?255u:127u,(int32)impulse>5242880?object+20u:0u);}
    return draft_scratch_result(native_stack_mark, (uint64)(sub_8002B7FC(object+20u,flags,mode?polygon:object+160u,impulse)));

    draft_scratch_release(native_stack_mark);
}

