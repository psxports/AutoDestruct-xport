#include "draft_signatures.h"

uint32 sub_80036F0C(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 a,b,c,d,e,f,v= r_u32(0x800A5C60u),i;
    FUNCTION_MARKER(0x80036F0Cu, "1.EXE");
    if(v) return draft_scratch_result(native_stack_mark, (uint64)(v));
    if(r_s16(0x800A9A64u)!=1) return draft_scratch_result(native_stack_mark, (uint64)(1));
    draft_call_adapter(0x8007F8C8u,3u); draft_call_adapter(0x8007F8C8u,3u);
    a=r_u32(0x800A9308u); b=r_u32(0x800A7EE0u); c=r_u32(0x800A7FA8u);
    d=r_u8(0x800A9A40u); e=r_u8(0x800A9A41u); f=r_u32(0x800A9CD0u);
    w_u32(0x800A5C60u,1); w_u32(0x800A5C30u,a); w_u32(0x800A5C34u,b); w_u32(0x800A5C38u,c);
    w_u8(0x800A9678u,d); w_u8(0x800A9679u,e); w_u32(0x800A9684u,f);
    sub_80036EDC(0);
    for(i=0;i<10;i++){v=(uint32)draft_call_adapter(0x8007B4A0u,9u,0u);w_u32(0x800A7BE0u,v);if(v==1)break;draft_call_adapter(0x8007F8C8u,3u);}
    w_u32(0x800A966Cu,60); return draft_scratch_result(native_stack_mark, (uint64)(60));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80045EB0(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 table,target,other; int32 index;
    FUNCTION_MARKER(0x80045EB0u, "1.EXE");
    index=r_s16(a0+0x9Cu);table=r_u32(0x800A851Cu);target=r_u32(table+(uint32)index*4u);
    if(index==-1){w_u16(a0+0xA4u,0);return draft_scratch_result(native_stack_mark, (uint64)(0));}
    draft_call_adapter(0x8004561Cu,target,a0); w_u32(target,r_u32(a0));
    index=r_s16(a0+0xA2u);w_u8(a0+0xE1u,0);w_u8(a0+0x40u,0);w_u8(a0+0x42u,1);w_u8(a0+0x41u,1);
    if(index!=-1){other=r_u32(table+(uint32)index*4u);if(!r_u8(other+0x40u)){w_u8(other+0x42u,r_u8(other+0x42u)-1);w_u16(a0+0xA2u,0xFFFF);}}
    w_u16(a0+0x72u,4);w_u32(a0,0x80045510u);return draft_scratch_result(native_stack_mark, (uint64)(1));

    draft_scratch_release(native_stack_mark);
}

void sub_8005FF80(uint32 a0,uint32 a1)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 o,resource,flags;
    FUNCTION_MARKER(0x8005FF80u, "1.EXE");
    while((int32)a1>0){o=(uint32)draft_call_adapter(0x800227C4u,40u);w_u8(o+34,8);w_u16(o+36,288);w_u16(o+38,0);
        w_u32(o+20,r_u32(a0));resource=r_u32(0x800A62ECu);w_u32(o+24,r_u32(a0+4));w_u32(o+28,r_u32(a0+8));--a1;
        flags=r_u8(o+14);resource=r_u16(resource+0x3E);w_u8(o+14,flags|2);w_u32(o,0x8005F1E0u);w_u8(o+13,16);w_u16(o+32,resource);
        w_u16(o+8,(sub_80069A50()&31)-16);w_u16(o+10,0-(sub_80069A50()&15));w_u16(o+16,(sub_80069A50()&31)-16);w_u16(o+18,sub_80069A50()&255);
    }

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80034264(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 state,v;
    FUNCTION_MARKER(0x80034264u, "1.EXE");
    v=r_u32(0x800A9D5Cu);if((int32)v>0){w_u32(0x800A9D5Cu,v-1);return draft_scratch_result(native_stack_mark, (uint64)(0));}
    if(r_u32(0x800A84D4u)){state=r_u32(0x800A6D04u);w_u32(0x800A98F4u,0);if(state==1)w_u32(0x800A98F4u,2000);
        v=(uint32)draft_call_adapter(0x800339D0u,r_u32(0x800A98F4u));w_u32(0x800A6D08u,v);w_u32(0x800A6CF8u,0);if(r_u32(0x800A6D04u)==1)return draft_scratch_result(native_stack_mark, (uint64)(0xFFFF));}
    state=r_u32(0x800A6D04u);
    if((!r_u32(0x800A8E70u)&&!r_u32(0x800A84D4u)&&(r_u32(0x800A6D14u)&0x900))||state==2||state==3){w_u16(0x800A6D10u,2);return draft_scratch_result(native_stack_mark, (uint64)(0xFFFF));}
    return draft_scratch_result(native_stack_mark, (uint64)(!r_u32(0x800A84D4u)&&state==1?0xFFFF:0));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8006EB64(uint32 a0,uint32 a1,uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 t=r_u32(a0+16),v;
    FUNCTION_MARKER(0x8006EB64u, "1.EXE");
    v=sub_8006E748(a1,t+20);
    if((!r_s16(t+0x3A)&&a2!=4)||(r_u32(t+12)&0xA0000)!=0xA0000||(int32)v>=12001)return draft_scratch_result(native_stack_mark, (uint64)(sub_8006E790(a0)));
    w_u16(a0+32,sub_8006EA04((uint32)r_s8(a0+13),1));
    if(r_s8(a0+13)==3)w_u16(a0+54,0);else w_u16(a0+54,r_u16(a0+54)+10*r_u32(0x800A9010u));
    sub_80055228((uint32)r_s16(a0+54),a0+36);
    w_u32(a0+20,r_u32(t+20));w_u32(a0+24,r_u32(t+24));v=r_u32(t+28);w_u32(a0+28,v);return draft_scratch_result(native_stack_mark, (uint64)(v));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005C8E4(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 t=r_u32(0x800A9A58u),scratch,v;
    FUNCTION_MARKER(0x8005C8E4u, "1.EXE");
    // TODO Bind addressable callback output through project scratch adapter
    scratch=draft_scratch_adapter(8);draft_call_adapter(r_u32(r_u32(t+16)+20),t,scratch);
    sub_8005C8A4(a0,r_u32(0x800A9A58u)+20,(uint32)r_s16(a0+40));
    if(r_u8(a0+46)){w_u8(a0+46,0);sub_8005C560(a0);}else{w_u16(a0+38,50);if(draft_call_adapter(0x8005C31Cu,a0))sub_8005C560(a0);}
    v=sub_8005C270(a0+12,a0+28,(uint32)r_s16(a0+38));
    if(v&&r_u32(a0)==r_u32(0x800A7EE4u)&&r_u32(a0+4)==r_u32(0x800A7EE8u)&&r_u32(a0+8)==r_u32(0x800A7EECu)){
        w_u8(a0+44,r_u8(a0+47));w_u8(a0+45,r_u8(a0+47));
        if(r_u8(a0+47))draft_call_adapter(0x8005BA64u,a0);else{w_u16(0x800A8564u,0-r_u16(scratch+4));draft_call_adapter(0x8005B76Cu,a0);w_u16(a0+40,r_u16(scratch+2));}}
    return draft_scratch_result(native_stack_mark, (uint64)(sub_8005BEEC(a0)));

    draft_scratch_release(native_stack_mark);
}

void sub_800338D8(uint32 a0,uint32 a1,uint32 a2,uint32 a3)
{
    uint32 native_stack_mark = draft_scratch_mark();

    int32 index;
    FUNCTION_MARKER(0x800338D8u, "1.EXE");
    while(a1){index=(int8)draft_call_adapter(0x800334D4u,(uint32)r_s16(a1),(uint32)(int16)a2,(uint32)(int16)a3);
        if(index!=-1){draft_call_adapter(0x80041D90u,0x800A6C94u,r_u32(0x800A6C70u+12*a0)&r_u32(0x8008B91Cu+4*(uint32)index));
            draft_call_adapter(0x80020AB4u,0x800A6C94u,r_u32(0x800A9A74u)+716,1u,0u);draft_call_adapter(0x80020AB4u,0x800A6CB4u,r_u32(0x800A9A74u)+720,1u,0u);}
        a1=r_u32(a1+4);}

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005F920(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 o;
    FUNCTION_MARKER(0x8005F920u, "1.EXE");
    w_u8(0x800A8FB8u,1);w_u8(0x800A8FB7u,20);w_u8(0x800A8FB4u,r_u8(0x800A8FB4u)|2);
    w_u32(0x800A8FA0u,r_u32(a0+20)-r_u32(0x800A7EE4u));w_u32(0x800A8FA4u,r_u32(a0+24));w_u32(0x800A8FA8u,r_u32(a0+28)-r_u32(0x800A7EECu));
    o=(uint32)draft_call_adapter(0x800227C4u,40u);w_u32(o+20,r_u32(a0+20));w_u32(o+24,r_u32(a0+24));w_u32(o+28,r_u32(a0+28));
    w_u32(o,0x8005FA24u);w_u8(o+35,24);w_u8(o+13,0);w_u16(o+8,(sub_80069A50()&255)-127);w_u16(o+16,160);w_u16(o+18,4);w_u16(o+10,r_u16(a0+24));return draft_scratch_result(native_stack_mark, (uint64)(4));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800660D0(uint32 a0,uint32 a1,uint32 a2,uint32 a3)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 o,res,v;
    FUNCTION_MARKER(0x800660D0u, "1.EXE");
    o=(uint32)draft_call_adapter(0x800226E4u,56u);w_u32(o+20,a1+(r_u32(a0)&0xFFF));w_u32(o+28,a2+((r_u32(a0)>>12)&0xFFF));w_u32(o+24,0-r_u16(a0+4));
    res=r_u16(r_u32(0x800A8FD8u)+2*r_u8(a0+11));w_u8(o+14,r_u8(o+14)|2);w_u8(o+34,11);w_u32(o,0x800661CCu);w_u16(o+32,res);w_u8(o+14,r_u8(o+14)|32);
    w_u32(o+16,sub_80069A50());v=(uint32)draft_call_adapter(0x800551CCu,(r_u32(a0+4)>>14)&0xF80,o+36);w_u8(o+13,a3);return draft_scratch_result(native_stack_mark, (uint64)(v));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8003ADF4(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 v;
    FUNCTION_MARKER(0x8003ADF4u, "1.EXE");
    if(!a0){draft_call_adapter(0x8005B668u);draft_call_adapter(0x8003AD54u);sub_8003ADE0();w_u16(0x800A7E7Au,10000);w_u16(0x800A7E7Cu,r_u16(0x800A632Cu));draft_call_adapter(0x8005E258u,1u);
        v=r_u32(0x800A9760u);if(v==1){draft_call_adapter(0x8005E258u,0u);w_u32(0x800A9864u,v);w_u32(0x800A9868u,0);w_u32(0x800A985Cu,0);w_u32(0x800A9860u,0);w_u32(0x800A5694u,v);w_u32(0x800A6450u,v);draft_call_adapter(0x80043BA0u);}
        else{w_u32(0x800A5694u,0);w_u32(0x800A6450u,0);sub_8006F790();}
        w_u32(0x800A6DF4u,10);w_u32(0x800A9A48u,10);w_u16(0x800A9A64u,1);w_u32(0x800A9D5Cu,0);}
    w_u32(0x800A6E64u,0);w_u32(0x800A6DECu,0);sub_80038964(0xFFFF);sub_800375A4();sub_800375F0();v=(uint32)draft_call_adapter(0x8007FED0u,1u);
    w_u32(0x800A6DF8u,0);w_u32(0x800A6E0Cu,0);w_u32(0x800A6E10u,0);w_u32(0x800A84DCu,0);w_u32(0x800A9344u,0);return draft_scratch_result(native_stack_mark, (uint64)(v));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8004AA30(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    int32 p=r_s16(a0+188),limit=r_s16(a0+192),i;uint32 v,t;
    FUNCTION_MARKER(0x8004AA30u, "1.EXE");
    if(limit<p){w_u8(a0+198,11);w_u32(a0+144,0);w_u16(a0+190,0);w_u16(a0+188,0);
        t=sub_800476D8((uint32)r_s16(a0+172));w_u32(a0+116,(r_u32(t)&1023)<<9);t=sub_800476D8((uint32)r_s16(a0+172));v=r_u32(t);w_u32(a0+124,((v>>10)&1023)<<9);w_u32(a0+120,r_u32(a0+24));return draft_scratch_result(native_stack_mark, (uint64)(0));}
    if(p<limit)w_u16(a0+190,p);i=r_s16(a0+190);if(i<0)i=-i;v=r_u16(r_u32(a0+144)+2*(uint32)i);w_u16(a0+188,r_u16(a0+188)+1);
    if((int16)v==r_s16(r_u32(a0+144))){i=r_s16(a0+190);if(i<0)i=-i;if(i==r_s16(a0+192)-1){w_u16(a0+190,0);w_u16(a0+188,1);}}
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)(int16)v));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8003CB98(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 index=(uint32)r_s16(0x800A5EF2u),table,count,delay;
    FUNCTION_MARKER(0x8003CB98u, "1.EXE");
    table=r_u32(0x800901DCu+12*index);
    if(!(r_u32(table+16)&r_u32(0x800A5EA8u))){draft_call_adapter(0x80035A08u,36u,2048u,255u,0u,0u);return draft_scratch_result(native_stack_mark, (uint64)(0xFFFFFFFF));}
    table=r_u32(0x800901D8u+12*index);count=0x800A5EACu+2*index;
    if((uint32)r_s16(count)<r_u32(table+12)){draft_call_adapter(0x80035A08u,36u,2048u,255u,0u,0u);w_u16(0x800A5EECu,100);return draft_scratch_result(native_stack_mark, (uint64)(0xFFFFFFFF));}
    if(r_s16(0x800A5EECu))return draft_scratch_result(native_stack_mark, (uint64)(0xFFFFFFFE));
    delay=index==3?128:index==11?80:r_u16(table+16);w_u16(0x800A5EECu,delay);index=(uint32)r_s16(0x800A5EF2u);count=0x800A5EACu+2*index;w_u16(count,r_u16(count)-1);
    index=(uint32)r_s16(0x800A5EF2u);draft_call_adapter(r_u32(0x800901E0u+12*index));return draft_scratch_result(native_stack_mark, (uint64)(0));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8005B364(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    int32 d;
    FUNCTION_MARKER(0x8005B364u, "1.EXE");
    d=(int32)sub_80069C78(r_u32(a0),r_u32(a0+8));
    if(d<5)return draft_scratch_result(native_stack_mark, (uint64)(0));if(d<10)return draft_scratch_result(native_stack_mark, (uint64)(1));if(d<24)return draft_scratch_result(native_stack_mark, (uint64)(2));if(d<64)return draft_scratch_result(native_stack_mark, (uint64)(5));if(d<256)return draft_scratch_result(native_stack_mark, (uint64)(10));if(d<512)return draft_scratch_result(native_stack_mark, (uint64)(20));
    if(d<1024)return draft_scratch_result(native_stack_mark, (uint64)(40));if(d<4096)return draft_scratch_result(native_stack_mark, (uint64)(60));if(d<8192)return draft_scratch_result(native_stack_mark, (uint64)(80));if(d<16384)return draft_scratch_result(native_stack_mark, (uint64)(100));if(d<=32767)return draft_scratch_result(native_stack_mark, (uint64)(150));if(d<=65535)return draft_scratch_result(native_stack_mark, (uint64)(200));return draft_scratch_result(native_stack_mark, (uint64)(0xFFFFFFFF));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8003D6F0(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    int32 n=r_s16(0x800A5EF8u),kind;uint32 previous,v;
    FUNCTION_MARKER(0x8003D6F0u, "1.EXE");
    if(n<=0)return draft_scratch_result(native_stack_mark, (uint64)((uint32)n));if((int32)r_u32(0x800A56BCu)>0)return draft_scratch_result(native_stack_mark, (uint64)((uint32)(n-1)));
    previous=r_u32(0x800A8538u);w_u16(0x800A5EF8u,n-1);w_u32(0x800A56BCu,20*r_u32(0x800A56C0u));w_u32(0x800A56C4u,previous);
    kind=r_s16(0x800A5EF4u);if(kind==0)w_u32(0x800A8538u,previous+546120);else if(kind==1)w_u32(0x800A8538u,previous+455100);else if(kind==2)w_u32(0x800A8538u,previous+364080);
    v=(uint32)draft_call_adapter(0x80035A08u,58u,2048u,192u,0u,0u);w_u16(0x800A56ACu,v);return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80035A08u,59u,2048u,192u,0u,0u)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80058508(uint32 a0,uint32 a1,uint32 a2,uint32 a3,uint32 a4,uint32 a5,uint32 a6,uint32 a7,uint32 a8,uint32 a9,uint32 a10,uint32 a11,uint32 a12)
{
    uint32 native_stack_mark = draft_scratch_mark();

    FUNCTION_MARKER(0x80058508u, "1.EXE");
    // TODO Bind SDK polygon adapters using scalar arguments recovered from MIPS
    draft_call_adapter(0x80041C9Cu,0x800A7108u,a2,(uint32)(int16)a3,(uint32)(int16)a4,(uint32)(uint16)a5,(uint32)(int16)a6,(uint32)(int16)a7,(uint32)(int16)a8,(uint32)(int16)a9);
    draft_call_adapter(0x80041DB4u,0x800A7108u,a10,a11,0u);sub_80041E1C(0x800A7108u,a0);draft_call_adapter(0x80041D90u,0x800A7108u,a1);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80020764u,0x800A7108u,r_u32(0x800A9A74u)+4*a12,1u,0u)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80067390(uint32 a0,uint32 a1,uint32 a2,uint32 a3)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 o,res;
    FUNCTION_MARKER(0x80067390u, "1.EXE");
    o=(uint32)draft_call_adapter(0x800226E4u,56u);w_u32(o+20,a1+(r_u32(a0)&0xFFF));w_u32(o+28,a2+((r_u32(a0)>>12)&0xFFF));w_u32(o+24,0-r_u16(a0+4));
    res=r_u16(r_u32(0x800A8FD8u)+2*r_u8(a0+11));w_u8(o+14,r_u8(o+14)|2);w_u8(o+34,17);w_u32(o,0x80067160u);w_u16(o+32,res);w_u8(o+14,r_u8(o+14)|32);
    w_u32(o+16,sub_80069A50());draft_call_adapter(0x800551CCu,(r_u32(a0+4)>>14)&0xF80,o+36);w_u8(o+13,a3);w_u32(o+8,0xFFFFFFFF);return draft_scratch_result(native_stack_mark, (uint64)(0xFFFFFFFF));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8006EA48(uint32 a0)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 target=r_u32(a0+16),step=r_u32(0x800A9010u),scratch,distance,v;
    FUNCTION_MARKER(0x8006EA48u, "1.EXE");
    // TODO Bind addressable vector storage through project scratch adapter
    scratch=draft_scratch_adapter(16);sub_8006E708(a0+20,target+20,scratch);
    distance=(uint32)draft_call_adapter(0x80069BE0u,r_u32(scratch),r_u32(scratch+4));distance=(uint32)draft_call_adapter(0x80069BE0u,distance,r_u32(scratch+8));
    if(distance<200*step){w_u32(a0+20,r_u32(target+20));w_u32(a0+24,r_u32(target+24));w_u8(a0+34,2);w_u32(a0+28,r_u32(target+28));return draft_scratch_result(native_stack_mark, (uint64)(2));}
    w_u16(a0+54,r_u16(a0+54)+10*step);sub_80055228((uint32)r_s16(a0+54),a0+36);sub_80055818(a0+20,scratch,150*step);v=sub_8006EA04((uint32)r_s8(a0+13),0);w_u16(a0+32,v);return draft_scratch_result(native_stack_mark, (uint64)(v));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800592D4(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 index,increment,position,scratch;int32 limit;
    FUNCTION_MARKER(0x800592D4u, "1.EXE");
    if((int32)r_u32(0x800A6274u)<10){index=r_u32(0x800A6278u);increment=(uint32)((int32)(12800u*(uint32)((int32)r_u32(0x800A63D8u)>>8))>>16);
        position=r_u16(0x800A73DCu)+increment;w_u16(0x800A73DCu,position);limit=r_s16(0x80090BA0u+2*index);
        if((int16)position>=limit){w_u32(0x800A6274u,10);w_u32(0x800A6278u,index+1);w_u16(0x800A73DCu,limit);if((int32)(index+1)>=4){w_u32(0x800A6278u,0);w_u16(0x800A73DCu,0);}}}
    // TODO Bind addressable sprite and transformed vector through project scratch adapter
    scratch=draft_scratch_adapter(48);w_u32(scratch,r_u32(0x800A73CCu));w_u32(scratch+4,r_u32(0x800A73D0u));w_u32(scratch+8,r_u32(0x800A73D4u));w_u16(scratch+12,r_u16(r_u32(0x800A62ECu)+44));
    draft_call_adapter(0x80055134u,0x800A73DCu,scratch+16);draft_call_adapter(0x80020300u,scratch,r_u32(0x800A9A74u),70u,113u,93u);
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80020300u,scratch,r_u32(0x800A9A74u),70u,113u,93u)));

    draft_scratch_release(native_stack_mark);
}
