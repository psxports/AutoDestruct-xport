#include "draft_signatures.h"
#include <stdlib.h>

static int32 draft18_div(int32 a,int32 b)
{
    if(!b||(b==-1&&(uint32)a==0x80000000u))abort();
    return a/b;
}

static int32 draft18_wrapsub(int32 a,int32 b)
{
    return (int32)((uint32)a-(uint32)b);
}

uint32 sub_80024C9C(uint32 object)
{
    uint32 native_stack_mark = draft_scratch_mark();

    int32 sign=r_s8(object+581),speed=(int32)r_u32(object+472),maximum=(int32)r_u32(0x800A8538u),difference=draft18_wrapsub(maximum,speed),segment=maximum/6,input=0,value,temp,divisor;uint32 index,target,flags,counter;
    FUNCTION_MARKER(0x80024C9Cu, "1.EXE");
    w_u32(0x800A5758u,0);w_u8(object+580,1);if(segment)w_u8(object+580,draft18_div(speed,segment)+1);if(sign==-1)w_u8(object+580,255);
    if(sub_80037D50()<<16){
        if((int16)draft_call_adapter(0x80037BB8u)==2)input=(uint8)draft_call_adapter(0x80037D14u);if(input==128)input=0;if(input>=5)w_u32(0x800A5758u,1);
        segment=(int32)r_u32(0x800A8538u)/6;if(!input)w_u32(object+484,0);w_u8(object+580,1);if(segment)w_u8(object+580,draft18_div((int32)r_u32(object+472),segment)+1);
        if(input&&r_s16(object+594)){w_u32(object+504,65536);w_u32(object+580,r_u32(object+580)|0x03000000);}if(sign==-1)w_u8(object+580,255);
        // TODO Keep switch destinations from the original table where pseudocode lost cases
        index=(uint32)(int32)(int8)(r_u8(object+580)+1);target=index<7?r_u32(0x80010028u+4*index):0x80025020u;speed=(int32)r_u32(object+472);
        switch(target){
        case 0x80024E90u:value=(int32)(4u*(uint32)segment);value=value>=speed?draft18_wrapsub(value,speed):draft18_wrapsub(speed,(int32)(3u*(uint32)segment));w_u32(object+484,(uint32)(value>>2));break;
        case 0x80024EC0u:
            value=draft18_wrapsub((int32)(2u*(uint32)segment),speed)/2;w_u32(object+484,(uint32)input<<16);
            if(value<(input<<16)){w_u32(object+484,value);if(input>=201){w_u32(object+484,value/4);w_u32(object+504,131072);w_u32(object+580,r_u32(object+580)|0x01000000);}}break;
        case 0x80024F24u:
            temp=(int32)((uint32)(draft18_wrapsub((int32)(3u*(uint32)segment),speed)/3)*(uint32)input);value=temp/256;w_u32(object+484,(uint32)input<<16);
            if(value<(input<<16)){w_u32(object+484,value);if(input>=201){w_u32(object+504,131072);w_u32(object+580,r_u32(object+580)|0x01000000);
                // TODO MIPS subtracts the pre-shift product sign after its signed multiply-high
                value=(int32)(((int64)value*0x55555556LL)>>32)-(temp>>31);w_u32(object+484,value);}}break;
        case 0x80024FACu:case 0x80024FC8u:case 0x80024FE8u:
            divisor=target==0x80024FACu?10:target==0x80024FC8u?7:5;temp=(int32)((uint32)(difference/divisor)*(uint32)input);value=temp/256;
            w_u32(object+484,(uint32)input<<16);if(value<(input<<16))w_u32(object+484,value);break;
        default:
            temp=(int32)((uint32)(difference/3)*(uint32)input);value=temp/256;if(value<0)value=0;w_u32(object+484,(uint32)input<<16);if(value<(input<<16))w_u32(object+484,value);break;
        }
        w_u32(object+484,r_u32(object+484)*(uint32)sign);if(r_u32(0x800A9864u))w_u32(object+484,1);
    }else{
        if((int16)draft_call_adapter(0x80037BB8u)==3&&!(r_u32(0x800A8398u)&1)&&(uint8)draft_call_adapter(0x80037D14u)>=201)sign=-1;
        maximum=(int32)r_u32(0x800A8538u);segment=maximum/6;w_u8(object+580,1);if(segment)w_u8(object+580,draft18_div((int32)r_u32(object+472),segment)+1);
        if((int32)r_u32(object+472)<=262143)w_u32(object+580,r_u32(object+580)&0xFCFFFFFF);if(sign==-1)w_u8(object+580,255);
        if(sign){w_u32(0x800A5758u,1);if(r_s16(object+594)){w_u32(object+504,65536);w_u32(object+580,r_u32(object+580)|0x03000000);}}else w_u32(object+484,0);
        difference=draft18_wrapsub((int32)r_u32(0x800A8538u),(int32)r_u32(object+472));index=(uint32)(int32)(int8)(r_u8(object+580)+1);target=index<8?r_u32(0x80010048u+4*index):0x80025388u;
        switch(target){
        case 0x80025228u:speed=(int32)r_u32(object+472);value=(int32)(4u*(uint32)segment);value=value>=speed?draft18_wrapsub(value,speed):draft18_wrapsub(speed,(int32)(3u*(uint32)segment));w_u32(object+484,value>>2);break;
        case 0x8002525Cu:
            w_u32(object+484,difference/16);if(sign&&!(r_u32(object+580)&0xF0000000)&&((int32)r_u32(object+472)>131072||r_u32(0x800A9760u))){w_u32(object+504,65536);w_u32(object+580,r_u32(object+580)|0x02000000);}w_u32(0x800A56D0u,30);break;
        case 0x800252ACu:
            w_u32(object+484,difference/14);if(!(r_u32(object+580)&0xF0000000)&&(sign&1)){w_u32(object+504,65536);w_u32(object+580,r_u32(object+580)|0x02000000);}w_u32(0x800A56D0u,30);break;
        case 0x80025314u:w_u32(object+484,difference/10);break;
        case 0x80025330u:w_u32(object+484,difference/7);break;
        case 0x80025350u:w_u32(object+484,difference/5);break;
        case 0x8002536Cu:w_u32(object+484,difference/3);break;
        default:break;
        }
        w_u32(object+484,r_u32(object+484)*(uint32)sign);if(r_u32(0x800A9864u))w_u32(object+484,1);
        if(sign&&!(r_u32(object+580)&0xF0000000)){counter=r_u32(0x800A56D0u);if((int32)counter<8||r_u32(0x800A56BCu)){
            if((int32)counter>=9&&r_u32(0x800A56BCu))w_u32(0x800A56D0u,1);
            if((int32)r_u32(object+484)>100000||r_u32(0x800A56D0u)-1<7){w_u32(object+504,65536);w_u32(object+580,r_u32(object+580)|0x02000000);counter=r_u32(0x800A56D0u);w_u32(0x800A56D0u,counter+1);if(!r_u32(0x800A56BCu)&&(int32)(counter+1)>=8)w_u32(0x800A56D0u,counter+2);}}}
        if((int32)r_u32(object+472)<=262144||!sign||(r_u32(object+580)&0xF0000000))w_u32(0x800A56D0u,0);
    }
    value=(int32)r_u32(object+484);speed=(int32)r_u32(object+472);
    temp=value<0?(((speed/14)>>5)&16383)+1536:(value?3584-((value>>7)&16383):1664)+(((speed/14)>>6)&16383);
    if((int32)r_u32(0x800A8538u)<speed){w_u32(object+484,0);return draft_scratch_result(native_stack_mark, (uint64)(1));}
    value=(int32)(5u*r_u32(object+484))/3;w_u32(object+484,value);sub_80036188((uint32)r_s16(0x800A56AEu),(uint32)(int16)temp);
    return draft_scratch_result(native_stack_mark, (uint64)(sub_800361FC((uint32)r_s16(0x800A5C44u),(uint32)(((int32)r_u32(object+472)/14)>>10))));

    draft_scratch_release(native_stack_mark);
}

uint32 sub_8001937C(uint32 packet,uint32 vertices,uint32 polygons,uint32 ot,uint32 unused_uv,uint32 depth,uint32 count,uint32 nextout)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 pointer=polygons+16,scratch=0,indices[4],p,flag,area,entry,i,j,color,screen;int32 a,b,c,d;int left,right,top,bottom;
    FUNCTION_MARKER(0x8001937Cu, "1.EXE");
    (void)unused_uv;
    while(count){for(i=0;i<4;i++)indices[i]=r_u16(pointer-6+2*i);for(i=0;i<3;i++){p=vertices+8*indices[i];xport_gte_write_data(2*i,r_u32(p));xport_gte_write_data(2*i+1,r_u32(p+4));}
        // TODO Bind unsupported GTE commands through project fail-fast adapters
        draft_gte_command_adapter(0x280030);p=vertices+8*indices[3];xport_gte_write_data(0,r_u32(p));xport_gte_write_data(1,r_u32(p+4));flag=draft_gte_control_adapter(31);draft_gte_command_adapter(0x1400006);count--;area=xport_gte_read_data(24);
        if((int32)flag>=0&&area+1023<2047){for(i=0;i<3;i++)w_u32(packet+8+4*i,xport_gte_read_data(12+i));draft_gte_command_adapter(0x180001);
            p=vertices+8*r_u16(pointer-8);xport_gte_write_data(0,r_u32(p));xport_gte_write_data(1,r_u32(p+4));w_u32(packet+20,xport_gte_read_data(14));draft_gte_command_adapter(0x168002E);
            color=r_u32(pointer-12);xport_gte_write_data(6,color);entry=ot+4*depth+4*(xport_gte_read_data(7)>>3);draft_gte_command_adapter(0x108041B);
            w_u32(packet,(r_u32(entry)&0xFFFFFF)|0x05000000);w_u32(entry,(r_u32(entry)&0xFF000000)|(packet&0xFFFFFF));w_u32(packet+4,xport_gte_read_data(22));packet+=24;
        }else{
            // TODO Bind addressable projected corners and subdivision grid without guest stack recreation
            if(!scratch)scratch=draft_scratch_adapter(96);for(i=0;i<3;i++)w_u32(scratch+72+4*i,xport_gte_read_data(12+i));draft_gte_command_adapter(0x180001);
            p=vertices+8*r_u16(pointer-8);xport_gte_write_data(0,r_u32(p));xport_gte_write_data(1,r_u32(p+4));w_u32(scratch+84,xport_gte_read_data(14));left=right=top=bottom=0;
            for(i=0;i<4;i++){screen=r_u32(scratch+72+4*i);a=(int16)screen;b=(int16)(screen>>16);left|=a<320;right|=a>0;top|=b<240;bottom|=b>0;}
            if(left&&right&&top&&bottom){xport_gte_write_data(6,r_u32(pointer-12));draft_gte_command_adapter(0x108041B);
                for(j=0;j<3;j++){a=r_s16(vertices+8*indices[0]+2*j);b=r_s16(vertices+8*indices[1]+2*j);c=r_s16(vertices+8*indices[2]+2*j);d=r_s16(vertices+8*indices[3]+2*j);
                    w_u16(scratch+2*j,a);w_u16(scratch+8+2*j,(a+b)>>1);w_u16(scratch+16+2*j,b);w_u16(scratch+24+2*j,(a+c)>>1);w_u16(scratch+32+2*j,(c+b)>>1);w_u16(scratch+40+2*j,(b+d)>>1);w_u16(scratch+48+2*j,c);w_u16(scratch+56+2*j,(c+d)>>1);w_u16(scratch+64+2*j,d);}
                packet=sub_8001DDA4(scratch+72,packet,ot,scratch,depth);}}
        pointer+=20;polygons+=20;
    }
    w_u32(nextout,polygons);return draft_scratch_result(native_stack_mark, (uint64)(packet));

    draft_scratch_release(native_stack_mark);
}

#define D18_GP(o) (0x800A5628u+(o))
uint32 sub_800788D4(uint32 a0,uint32 a1,uint32 a2,uint32 a3,uint32 keys,uint32 text,uint32 y)
{
    uint32 native_stack_mark = draft_scratch_mark();

    uint32 v,saved,result,offset;int32 draw_y=(int16)y;
    FUNCTION_MARKER(0x800788D4u, "1.EXE");
    w_u32(D18_GP(0x2490),13824);w_u32(D18_GP(0x4740),73);w_u32(D18_GP(0x2444),0);
    if((int16)draft_call_adapter(0x80037BB8u)==-1)draft_call_adapter(0x80044040u);
    else if((int32)r_u32(D18_GP(0x25BC))>=4){if(r_u32(D18_GP(0x249C)))sub_800442AC(35,(uint32)draw_y);
        if((int32)r_u32(D18_GP(0x249C))<(int32)(13*r_u32(D18_GP(0x25BC))-39))sub_800442AC(43,(uint32)draw_y+42);
        if((keys&0x5000)&&!r_u32(D18_GP(0x24AC)))w_u32(D18_GP(0x24AC),1);
        if(r_u32(D18_GP(0x24AC))==1&&!sub_800330D4()){v=(uint32)draft_call_adapter(0x800389DCu);sub_80078854((uint32)(int16)v);}}
    w_u32(D18_GP(0x2494),0);v=r_u32(D18_GP(0x24A0));if(v){w_u32(D18_GP(0x24A0),v-1);w_u32(D18_GP(0x2494),1);w_u32(D18_GP(0x249C),r_u32(D18_GP(0x249C))+1);}
    v=r_u32(D18_GP(0x24A4));if(v){w_u32(D18_GP(0x24A4),v-1);w_u32(D18_GP(0x2494),1);w_u32(D18_GP(0x249C),r_u32(D18_GP(0x249C))-1);}
    if((int32)r_u32(D18_GP(0x2EB8))>=2048){
        if(r_u32(D18_GP(0x24AC))==2)w_u32(D18_GP(0x24AC),0);
        if(!r_u32(0x800A84D4u)&&(a0||a1)&&(keys&64)&&!r_u32(D18_GP(0x2494))){w_u32(D18_GP(0x2EB8),0);w_u32(D18_GP(0x24A8),1);}
        if((int32)a2<=0){if(keys&2048){w_u32(D18_GP(0x24A8),1);w_u32(D18_GP(0x2EB8),0);w_u32(D18_GP(0x2444),2);}if(keys&256){w_u32(D18_GP(0x24A8),1);w_u32(D18_GP(0x2EB8),0);w_u32(D18_GP(0x2444),2);}
            if((int16)draft_call_adapter(0x80037BB8u)==2&&(keys&16)){w_u32(D18_GP(0x2444),3);w_u32(D18_GP(0x2EB8),0);w_u32(D18_GP(0x24A8),2);}}
        if(r_u32(0x800A84D4u)==1&&a3!=0xFFFFFFFF&&(int32)a2<=0&&(a0||a1)&&(keys&64)&&!r_u32(D18_GP(0x2494))){w_u32(D18_GP(0x2EB8),0);w_u32(D18_GP(0x24A8),1);}
        if(!r_u32(D18_GP(0x2EB8)))w_u32(D18_GP(0x24AC),2);
    }
    if((int32)r_u32(D18_GP(0x2EB8))<2048){w_u32(D18_GP(0x2EB8),2048);v=r_u32(D18_GP(0x24A8));if(v){w_u32(D18_GP(0x2440),v);w_u32(D18_GP(0x24A8),0);
        if((a0||a1)&&!r_u32(D18_GP(0x2494))&&(int32)a2<=0&&!sub_800330D4())draft_call_adapter(0x80035A08u,30u,2048u,255u,0u,0u);
        w_u32(D18_GP(0x2498),0);w_u32(D18_GP(0x2EB8),2048);offset=(uint32)((int32)((uint32)(r_s16(0x800112E0u)>>4)*r_u32(D18_GP(0x2490)))>>16);w_u32(D18_GP(0x4740),r_u32(D18_GP(0x4740))-offset);
        if((int32)a2<=0&&(int16)draft_call_adapter(0x80037BB8u)!=-1)draft_call_adapter(0x800440E0u,a0,a1,(uint32)draw_y);
        sub_800784F4(text,(uint32)draw_y,(uint32)draw_y-(r_u32(D18_GP(0x249C))-16));w_u32(D18_GP(0x2EB8),0);result=r_u32(D18_GP(0x2444));return draft_scratch_result(native_stack_mark, (uint64)(result?result:r_u32(D18_GP(0x2440))));}
        w_u32(D18_GP(0x2EB8),2048);}
    if((int32)a2<=0&&(int16)draft_call_adapter(0x80037BB8u)!=-1)draft_call_adapter(0x800440E0u,a0,a1,(uint32)draw_y);
    saved=r_u32(D18_GP(0x2EB8));w_u32(D18_GP(0x2EB8),2048);sub_800784F4(text,(uint32)draw_y,(uint32)draw_y-(r_u32(D18_GP(0x249C))-16));result=r_u32(D18_GP(0x2444));w_u32(D18_GP(0x2EB8),saved);return draft_scratch_result(native_stack_mark, (uint64)(result));

    draft_scratch_release(native_stack_mark);
}
#undef D18_GP
