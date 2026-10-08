#include "draft_signatures.h"

uint32 sub_80032F44(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 text,i,color,other=r_u32(0x800A60A8u);int32 time=r_s16(0x800A7E18u),minutes,seconds;
    FUNCTION_MARKER(0x80032F44u, "1.EXE");
    // TODO Bind addressable text through project scratch adapter
    text=draft_scratch_adapter(24);for(i=0;i<9;i++)w_u8(text+i,r_u8(0x800A5BF8u+i));
    if(!time||(other&&(int32)other<time))time=(int16)other;if(!time)return draft_scratch_result(native_stack_mark, (uint64)(0x88880000));
    minutes=time/60;seconds=time-60*minutes;
    if(r_s16(0x800A6C44u)!=seconds){w_u16(0x800A6C44u,seconds);draft_call_adapter(0x80035A08u,seconds<10&&!minutes?71u:54u,2048u,255u,0u,0u);}
    draft_call_adapter(0x800325BCu,text+2,(uint32)minutes);draft_call_adapter(0x800325BCu,text+5,(uint32)seconds);w_u8(text+4,seconds&1?19:18);
    color=minutes==1?32896:32768;if(!minutes){color=128;if(seconds<10)color=seconds&1?128:64;}
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)draft_call_adapter(0x80044588u,color,text,254u,0xFFFFFF9Cu)));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_80051328(uint32 a0,uint32 a1,uint32 a2)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch,i,p,height,negative,diff;int32 initial,result=0;
    FUNCTION_MARKER(0x80051328u, "1.EXE");
    // TODO Bind addressable collision vectors through project scratch adapter
    scratch=draft_scratch_adapter(32);initial=(int32)draft_call_adapter(0x8002E310u,a0+20,scratch+16,a2);
    for(i=0;i<8;i++){p=a1+8*i;w_u32(scratch,r_u32(a0+20)+(uint32)r_s16(p));w_u32(scratch+4,r_u32(a0+24)+(uint32)r_s16(p+2));w_u32(scratch+8,r_u32(a0+28)+(uint32)r_s16(p+4));
        height=(uint32)draft_call_adapter(0x8002E310u,scratch,scratch+16,scratch+24);negative=0-height;diff=(uint32)initial-height;
        if((int32)negative<(int32)r_u32(scratch+4)&&((int32)diff<0?(int32)(height-(uint32)initial)<200:(int32)diff<200)){
            result=(int32)i+1;w_u32(a0+24,negative-(uint32)r_s16(p+2));continue;}
        if((int32)negative<(int32)r_u32(a0+24)&&((int32)diff<0?(int32)(height-(uint32)initial)>=201:(int32)diff>=201))result=-result;
    }
    return draft_scratch_result(native_stack_mark, (uint64)((uint32)(int16)result));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_800376D0(void)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 scratch,state,v;
    FUNCTION_MARKER(0x800376D0u, "1.EXE");
    // TODO Bind SDK mode attributes and output through project scratch adapter
    scratch=draft_scratch_adapter(32);w_u32(scratch+8,256);w_u32(scratch+28,0);draft_call_adapter(0x8008757Cu,scratch+8);
    if(!r_u32(0x800A5C48u)&&(int32)r_u32(0x800A966Cu)<=0){v=(uint32)draft_call_adapter(0x8007B368u,16u,0u,scratch);w_u32(0x800A7BE0u,v);if(v!=1)return draft_scratch_result(native_stack_mark, (uint64)(1));
        v=(uint32)draft_call_adapter(0x8007B8B8u,scratch);w_u32(0x800A7FA8u,v);w_u32(0x800A7BF4u,1);}
    state=r_u32(0x800A5C48u);
    if((int32)state>0){state++;w_u32(0x800A5C48u,state);if(state!=2)return draft_scratch_result(native_stack_mark, (uint64)(2));
        if(r_u32(0x800A5C50u)){v=(uint32)draft_call_adapter(0x8007B4A0u,9u,0u);w_u32(0x800A7BE0u,v);}
        else{draft_call_adapter(0x8003708Cu);w_u32(scratch+28,1);draft_call_adapter(0x8008757Cu,scratch+8);}
        w_u16(0x800A9A64u,1);w_u32(0x800A5C48u,0);return draft_scratch_result(native_stack_mark, (uint64)(1));}
    if((int32)r_u32(0x800A7FA8u)>=(int32)r_u32(0x800A7EE0u)){draft_call_adapter(0x8003708Cu);w_u32(0x800A5C48u,r_u32(0x800A5C48u)+1);v=(uint32)draft_call_adapter(0x8007B4A0u,9u,0u);w_u32(0x800A7BE0u,v);return draft_scratch_result(native_stack_mark, (uint64)(v));}
    if((int32)r_u32(0x800A966Cu)>=50){v=(uint32)draft_call_adapter(0x8007B368u,6u,0u,0u);w_u32(0x800A7BE0u,v);}
    v=r_u32(0x800A966Cu);if((int32)v<61)w_u32(0x800A7BF4u,1);v-=r_u32(0x800A9010u);w_u32(0x800A966Cu,v);return draft_scratch_result(native_stack_mark, (uint64)(v));

    draft_scratch_release(native_stack_mark);
}
