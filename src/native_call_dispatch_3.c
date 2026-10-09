#include "native_call_dispatch.h"

uint64 native_dispatch_group_3(uint32 target,uint32 argument_count,va_list args)
{
    uint64 result;
    switch(target){
    case 0x800643ECu: {
        native_dispatch_require(target,argument_count,0u);
        GameRenderCallContext context={0};
        context.stack_pointer=native_dispatch_stack(target,argument_count,0u,args);
        sub_800643EC(&context);
        result=0u;
        break;
    }

    case 0x80063418u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80063418(p0);
        break;
    }
    case 0x80063590u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80063590(p0,p1);
        break;
    }
    case 0x80063600u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80063600(p0);
        break;
    }
    case 0x80063654u: {
        native_dispatch_require(target,argument_count,4u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        uint32 p3=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80063654(p0,p1,p2,p3);
        break;
    }
    case 0x80063824u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80063824(p0,p1);
        break;
    }
    case 0x80063888u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        GameGeometryCallContext p1={0};
        p1.stack_pointer=native_dispatch_stack(target,argument_count,1u,args);
        result=(uint64)sub_80063888(p0,&p1);
        break;
    }
    case 0x80063904u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80063904(p0);
        break;
    }
    case 0x80063AFCu: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=native_dispatch_stack(target,argument_count,1u,args);
        result=(uint64)sub_80063AFC(p0,p1);
        break;
    }
    case 0x80063C3Cu: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=native_dispatch_stack(target,argument_count,1u,args);
        result=(uint64)sub_80063C3C(p0,p1);
        break;
    }
    case 0x80063E28u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=native_dispatch_stack(target,argument_count,1u,args);
        result=(uint64)sub_80063E28(p0,p1);
        break;
    }
    case 0x80064020u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=native_dispatch_stack(target,argument_count,1u,args);
        result=(uint64)sub_80064020(p0,p1);
        break;
    }
    case 0x80064200u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=native_dispatch_stack(target,argument_count,1u,args);
        result=(uint64)sub_80064200(p0,p1);
        break;
    }
    case 0x80064334u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        GameSceneCallContext p1={0};
        p1.stack_pointer=native_dispatch_stack(target,argument_count,1u,args);
        result=(uint64)sub_80064334(p0,&p1);
        break;
    }
    case 0x80064594u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        GameGeometryCallContext p2={0};
        p2.stack_pointer=native_dispatch_stack(target,argument_count,2u,args);
        result=(uint64)sub_80064594(p0,p1,&p2);
        break;
    }
    case 0x80064784u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80064784(p0,p1);
        break;
    }
    case 0x800648A4u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_800648A4(p0);
        break;
    }
    case 0x8006499Cu: {
        native_dispatch_require(target,argument_count,0u);
        GameSceneCallContext p0={0};
        p0.stack_pointer=native_dispatch_stack(target,argument_count,0u,args);
        result=(uint64)sub_8006499C(&p0);
        break;
    }
    case 0x800649D4u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_800649D4(p0);
        break;
    }
    case 0x800649E4u: {
        native_dispatch_require(target,argument_count,0u);
        GameGeometryCallContext p0={0};
        p0.stack_pointer=native_dispatch_stack(target,argument_count,0u,args);
        result=(uint64)sub_800649E4(&p0);
        break;
    }
    case 0x80064A44u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        GameGeometryCallContext p2={0};
        p2.stack_pointer=native_dispatch_stack(target,argument_count,2u,args);
        result=(uint64)sub_80064A44(p0,p1,&p2);
        break;
    }
    case 0x80064B04u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        GameGeometryCallContext p1={0};
        p1.stack_pointer=native_dispatch_stack(target,argument_count,1u,args);
        result=(uint64)sub_80064B04(p0,&p1);
        break;
    }
    case 0x80064CECu: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80064CEC(p0);
        break;
    }
    case 0x80064D60u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80064D60(p0);
        break;
    }
    case 0x80064D80u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80064D80(p0);
        break;
    }
    case 0x80064DCCu: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_80064DCC();
        break;
    }
    case 0x80064DF4u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80064DF4(p0);
        break;
    }
    case 0x80064E78u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_80064E78();
        break;
    }
    case 0x800650C4u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_800650C4();
        break;
    }
    case 0x800650CCu: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_800650CC();
        break;
    }
    case 0x80065124u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_80065124();
        break;
    }
    case 0x800651ACu: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        GameGeometryCallContext p1={0};
        p1.stack_pointer=native_dispatch_stack(target,argument_count,1u,args);
        result=(uint64)sub_800651AC(p0,&p1);
        break;
    }
    case 0x80065244u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80065244(p0,p1);
        break;
    }
    case 0x8006525Cu: {
        native_dispatch_require(target,argument_count,0u);
        sub_8006525C(); result=0;
        break;
    }
    case 0x800652C0u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_800652C0(p0);
        break;
    }
    case 0x80065D34u: {
        native_dispatch_require(target,argument_count,3u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80065D34(p0,p1,p2);
        break;
    }
    case 0x80065DD0u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80065DD0(p0);
        break;
    }
    case 0x80065EB0u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80065EB0(p0,p1);
        break;
    }
    case 0x80065EF8u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80065EF8(p0);
        break;
    }
    case 0x80065F68u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80065F68(p0);
        break;
    }
    case 0x80065FD8u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80065FD8(p0);
        break;
    }
    case 0x80066048u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80066048(p0);
        break;
    }
    case 0x80066090u: {
        native_dispatch_require(target,argument_count,3u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80066090(p0,p1,p2);
        break;
    }
    case 0x800660D0u: {
        native_dispatch_require(target,argument_count,4u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        uint32 p3=(uint32)va_arg(args,uint32);
        result=(uint64)sub_800660D0(p0,p1,p2,p3);
        break;
    }
    case 0x800661CCu: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_800661CC(p0);
        break;
    }
    case 0x8006623Cu: {
        native_dispatch_require(target,argument_count,3u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006623C(p0,p1,p2);
        break;
    }
    case 0x80066380u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80066380(p0);
        break;
    }
    case 0x80066958u: {
        native_dispatch_require(target,argument_count,3u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80066958(p0,p1,p2);
        break;
    }
    case 0x80066984u: {
        native_dispatch_require(target,argument_count,3u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80066984(p0,p1,p2);
        break;
    }
    case 0x80066AECu: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80066AEC(p0);
        break;
    }
    case 0x80066D7Cu: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80066D7C(p0);
        break;
    }
    case 0x8006706Cu: {
        native_dispatch_require(target,argument_count,3u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006706C(p0,p1,p2);
        break;
    }
    case 0x80067140u: {
        native_dispatch_require(target,argument_count,3u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80067140(p0,p1,p2);
        break;
    }
    case 0x80067160u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80067160(p0);
        break;
    }
    case 0x80067390u: {
        native_dispatch_require(target,argument_count,4u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        uint32 p3=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80067390(p0,p1,p2,p3);
        break;
    }
    case 0x80068F70u: {
        native_dispatch_require(target,argument_count,3u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80068F70(p0,p1,p2);
        break;
    }
    case 0x80069018u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80069018(p0);
        break;
    }
    case 0x800697BCu: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_800697BC();
        break;
    }
    case 0x8006984Cu: {
        native_dispatch_require(target,argument_count,4u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        uint32 p3=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006984C(p0,p1,p2,p3);
        break;
    }
    case 0x800698C8u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint64 p1=(uint64)va_arg(args,uint64);
        result=(uint64)sub_800698C8(p0,p1);
        break;
    }
    case 0x80069974u: {
        native_dispatch_require(target,argument_count,1u);
        uint64 p0=(uint64)va_arg(args,uint64);
        result=(uint64)sub_80069974(p0);
        break;
    }
    case 0x80069A04u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        sub_80069A04(p0); result=0;
        break;
    }
    case 0x80069A50u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_80069A50();
        break;
    }
    case 0x80069A70u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80069A70(p0,p1);
        break;
    }
    case 0x80069A98u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_80069A98();
        break;
    }
    case 0x80069AD4u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        GameSceneCallContext p1={0};
        p1.stack_pointer=native_dispatch_stack(target,argument_count,1u,args);
        result=(uint64)sub_80069AD4(p0,&p1);
        break;
    }
    case 0x80069B38u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        GameSceneCallContext p1={0};
        p1.stack_pointer=native_dispatch_stack(target,argument_count,1u,args);
        result=(uint64)sub_80069B38(p0,&p1);
        break;
    }
    case 0x80069B84u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        GameSceneCallContext p1={0};
        p1.stack_pointer=native_dispatch_stack(target,argument_count,1u,args);
        result=(uint64)sub_80069B84(p0,&p1);
        break;
    }
    case 0x80069BC0u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80069BC0(p0);
        break;
    }
    case 0x80069BE0u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80069BE0(p0,p1);
        break;
    }
    case 0x80069C78u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80069C78(p0,p1);
        break;
    }
    case 0x80069D8Cu: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80069D8C(p0,p1);
        break;
    }
    case 0x80069DC4u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80069DC4(p0,p1);
        break;
    }
    case 0x80069E54u: {
        native_dispatch_require(target,argument_count,0u);
        GameGeometryCallContext p0={0};
        p0.stack_pointer=native_dispatch_stack(target,argument_count,0u,args);
        result=(uint64)sub_80069E54(&p0);
        break;
    }
    case 0x80069E94u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80069E94(p0,p1);
        break;
    }
    case 0x80069EFCu: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80069EFC(p0,p1);
        break;
    }
    case 0x80069F84u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80069F84(p0);
        break;
    }
    case 0x8006A0A0u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006A0A0(p0,p1);
        break;
    }
    case 0x8006A258u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006A258(p0,p1);
        break;
    }
    case 0x8006A948u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006A948(p0,p1);
        break;
    }
    case 0x8006ABE8u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006ABE8(p0,p1);
        break;
    }
    case 0x8006AF08u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006AF08(p0);
        break;
    }
    case 0x8006AFF4u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006AFF4(p0);
        break;
    }
    case 0x8006B198u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006B198(p0,p1);
        break;
    }
    case 0x8006B410u: {
        native_dispatch_require(target,argument_count,4u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        uint32 p3=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006B410(p0,p1,p2,p3);
        break;
    }
    case 0x8006BA1Cu: {
        native_dispatch_require(target,argument_count,3u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006BA1C(p0,p1,p2);
        break;
    }
    case 0x8006BC98u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006BC98(p0,p1);
        break;
    }
    case 0x8006BD08u: {
        native_dispatch_require(target,argument_count,5u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        uint32 p3=(uint32)va_arg(args,uint32);
        uint32 p4=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006BD08(p0,p1,p2,p3,p4);
        break;
    }
    case 0x8006C094u: {
        native_dispatch_require(target,argument_count,10u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        uint32 p3=(uint32)va_arg(args,uint32);
        uint32 p4=(uint32)va_arg(args,uint32);
        uint32 p5=(uint32)va_arg(args,uint32);
        uint32 p6=(uint32)va_arg(args,uint32);
        uint32 p7=(uint32)va_arg(args,uint32);
        uint32 p8=(uint32)va_arg(args,uint32);
        uint32 p9=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006C094(p0,p1,p2,p3,p4,p5,p6,p7,p8,p9);
        break;
    }
    case 0x8006C3D4u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006C3D4(p0);
        break;
    }
    case 0x8006C714u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006C714(p0,p1);
        break;
    }
    case 0x8006DF90u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006DF90(p0);
        break;
    }
    case 0x8006E06Cu: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_8006E06C();
        break;
    }
    case 0x8006E490u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006E490(p0);
        break;
    }
    case 0x8006E520u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006E520(p0);
        break;
    }
    case 0x8006E5B4u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006E5B4(p0);
        break;
    }
    case 0x8006E5DCu: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006E5DC(p0);
        break;
    }
    case 0x8006E62Cu: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006E62C(p0);
        break;
    }
    case 0x8006E6ACu: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006E6AC(p0,p1);
        break;
    }
    case 0x8006E708u: {
        native_dispatch_require(target,argument_count,3u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006E708(p0,p1,p2);
        break;
    }
    case 0x8006E748u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006E748(p0,p1);
        break;
    }
    case 0x8006E790u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006E790(p0);
        break;
    }
    case 0x8006E7BCu: {
        native_dispatch_require(target,argument_count,3u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006E7BC(p0,p1,p2);
        break;
    }
    case 0x8006E7D8u: {
        native_dispatch_require(target,argument_count,4u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        uint32 p3=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006E7D8(p0,p1,p2,p3);
        break;
    }
    case 0x8006E8A4u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        sub_8006E8A4(p0); result=0;
        break;
    }
    case 0x8006EA04u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006EA04(p0,p1);
        break;
    }
    case 0x8006EA48u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006EA48(p0);
        break;
    }
    case 0x8006EB64u: {
        native_dispatch_require(target,argument_count,3u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006EB64(p0,p1,p2);
        break;
    }
    case 0x8006ED00u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006ED00(p0);
        break;
    }
    case 0x8006F050u: {
        native_dispatch_require(target,argument_count,0u);
        GameMainCallContext p0={0};
        p0.stack_pointer=native_dispatch_stack(target,argument_count,0u,args);
        sub_8006F050(&p0); result=0;
        break;
    }
    case 0x8006F0CCu: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        GameMainCallContext p1={0};
        p1.stack_pointer=native_dispatch_stack(target,argument_count,1u,args);
        sub_8006F0CC(p0,&p1); result=0;
        break;
    }
    case 0x8006F150u: {
        native_dispatch_require(target,argument_count,0u);
        GameMainCallContext p0={0};
        p0.stack_pointer=native_dispatch_stack(target,argument_count,0u,args);
        sub_8006F150(&p0); result=0;
        break;
    }
    case 0x8006F178u: {
        native_dispatch_require(target,argument_count,0u);
        sub_8006F178(); result=0;
        break;
    }
    case 0x8006F1D0u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006F1D0(p0);
        break;
    }
    case 0x8006F22Cu: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_8006F22C();
        break;
    }
    case 0x8006F23Cu: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_8006F23C();
        break;
    }
    case 0x8006F27Cu: {
        native_dispatch_require(target,argument_count,0u);
        sub_8006F27C(); result=0;
        break;
    }
    case 0x8006F2B0u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_8006F2B0();
        break;
    }
    case 0x8006F2F4u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006F2F4(p0);
        break;
    }
    case 0x8006F338u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_8006F338();
        break;
    }
    case 0x8006F554u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006F554(p0,p1);
        break;
    }
    case 0x8006F58Cu: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_8006F58C();
        break;
    }
    case 0x8006F6E8u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006F6E8(p0);
        break;
    }
    case 0x8006F710u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_8006F710();
        break;
    }
    case 0x8006F738u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_8006F738();
        break;
    }
    case 0x8006F790u: {
        native_dispatch_require(target,argument_count,0u);
        sub_8006F790(); result=0;
        break;
    }
    case 0x8006F7A8u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_8006F7A8();
        break;
    }
    case 0x8006F818u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006F818(p0);
        break;
    }
    case 0x8006F950u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8006F950(p0);
        break;
    }
    case 0x8006FB78u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_8006FB78();
        break;
    }
    case 0x8006FCB4u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_8006FCB4();
        break;
    }
    case 0x800702D4u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_800702D4();
        break;
    }
    case 0x800703B4u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_800703B4();
        break;
    }
    case 0x8007040Cu: {
        native_dispatch_require(target,argument_count,0u);
        sub_8007040C(); result=0;
        break;
    }
    case 0x80070428u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_80070428();
        break;
    }
    case 0x8007044Cu: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_8007044C();
        break;
    }
    case 0x800704B4u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_800704B4();
        break;
    }
    case 0x800704E8u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_800704E8();
        break;
    }
    case 0x80070518u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_80070518();
        break;
    }
    case 0x80070540u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_80070540();
        break;
    }
    case 0x80070568u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_80070568();
        break;
    }
    case 0x80070634u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_80070634();
        break;
    }
    case 0x80070788u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80070788(p0);
        break;
    }
    case 0x800707D4u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_800707D4(p0);
        break;
    }
    case 0x80070A0Cu: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80070A0C(p0);
        break;
    }
    case 0x80070B88u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80070B88(p0);
        break;
    }
    case 0x80070C48u: {
        native_dispatch_require(target,argument_count,8u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        uint32 p3=(uint32)va_arg(args,uint32);
        uint32 p4=(uint32)va_arg(args,uint32);
        uint32 p5=(uint32)va_arg(args,uint32);
        uint32 p6=(uint32)va_arg(args,uint32);
        uint32 p7=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80070C48(p0,p1,p2,p3,p4,p5,p6,p7);
        break;
    }
    case 0x80070CF4u: {
        native_dispatch_require(target,argument_count,4u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        uint32 p3=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80070CF4(p0,p1,p2,p3);
        break;
    }
    case 0x80070D6Cu: {
        native_dispatch_require(target,argument_count,5u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        uint32 p3=(uint32)va_arg(args,uint32);
        uint32 p4=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80070D6C(p0,p1,p2,p3,p4);
        break;
    }
    case 0x80070FFCu: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80070FFC(p0);
        break;
    }
    case 0x80071050u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80071050(p0,p1);
        break;
    }
    case 0x80071148u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        sub_80071148(p0); result=0;
        break;
    }
    case 0x800714A4u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        sub_800714A4(p0); result=0;
        break;
    }
    case 0x800717A8u: {
        native_dispatch_require(target,argument_count,4u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        uint32 p3=(uint32)va_arg(args,uint32);
        result=(uint64)sub_800717A8(p0,p1,p2,p3);
        break;
    }
    case 0x80071960u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80071960(p0,p1);
        break;
    }
    case 0x80071B4Cu: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80071B4C(p0);
        break;
    }
    case 0x80071DC8u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80071DC8(p0);
        break;
    }
    case 0x80072388u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80072388(p0);
        break;
    }
    case 0x800723C4u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_800723C4();
        break;
    }
    case 0x800725D0u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_800725D0(p0);
        break;
    }
    case 0x800727B0u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_800727B0();
        break;
    }
    case 0x800732F8u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        GameGeometryCallContext p1={0};
        p1.stack_pointer=native_dispatch_stack(target,argument_count,1u,args);
        result=(uint64)sub_800732F8(p0,&p1);
        break;
    }
    case 0x80073438u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_80073438();
        break;
    }
    case 0x800734C0u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_800734C0();
        break;
    }
    case 0x80073574u: {
        native_dispatch_require(target,argument_count,0u);
        GameGeometryCallContext p0={0};
        p0.stack_pointer=native_dispatch_stack(target,argument_count,0u,args);
        result=(uint64)sub_80073574(&p0);
        break;
    }
    case 0x8007361Cu: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        GameGeometryCallContext p1={0};
        p1.stack_pointer=native_dispatch_stack(target,argument_count,1u,args);
        result=(uint64)sub_8007361C(p0,&p1);
        break;
    }
    case 0x80073B78u: {
        native_dispatch_require(target,argument_count,0u);
        GameGeometryCallContext p0={0};
        p0.stack_pointer=native_dispatch_stack(target,argument_count,0u,args);
        result=(uint64)sub_80073B78(&p0);
        break;
    }
    case 0x80073C48u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        GameGeometryCallContext p1={0};
        p1.stack_pointer=native_dispatch_stack(target,argument_count,1u,args);
        result=(uint64)sub_80073C48(p0,&p1);
        break;
    }
    case 0x80076ED4u: {
        native_dispatch_require(target,argument_count,0u);
        GameGeometryCallContext p0={0};
        p0.stack_pointer=native_dispatch_stack(target,argument_count,0u,args);
        result=(uint64)sub_80076ED4(&p0);
        break;
    }
    case 0x80077A20u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80077A20(p0,p1);
        break;
    }
    case 0x80077AC0u: {
        native_dispatch_require(target,argument_count,4u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        uint32 p3=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80077AC0(p0,p1,p2,p3);
        break;
    }
    case 0x800782D8u: {
        native_dispatch_require(target,argument_count,5u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        uint32 p3=(uint32)va_arg(args,uint32);
        uint32 p4=(uint32)va_arg(args,uint32);
        result=(uint64)sub_800782D8(p0,p1,p2,p3,p4);
        break;
    }
    case 0x800784F4u: {
        native_dispatch_require(target,argument_count,3u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        result=(uint64)sub_800784F4(p0,p1,p2);
        break;
    }
    case 0x80078830u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_80078830();
        break;
    }
    case 0x80078854u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80078854(p0);
        break;
    }
    case 0x800788D4u: {
        native_dispatch_require(target,argument_count,7u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        uint32 p3=(uint32)va_arg(args,uint32);
        uint32 p4=(uint32)va_arg(args,uint32);
        uint32 p5=(uint32)va_arg(args,uint32);
        uint32 p6=(uint32)va_arg(args,uint32);
        result=(uint64)sub_800788D4(p0,p1,p2,p3,p4,p5,p6);
        break;
    }
    case 0x80078D70u: {
        native_dispatch_require(target,argument_count,0u);
        GameCallbackCallContext p0={0};
        p0.stack_pointer=native_dispatch_stack(target,argument_count,0u,args);
        result=(uint64)sub_80078D70(&p0);
        break;
    }
    case 0x80078DB8u: {
        native_dispatch_require(target,argument_count,0u);
        GameCallbackCallContext p0={0};
        p0.stack_pointer=native_dispatch_stack(target,argument_count,0u,args);
        result=(uint64)sub_80078DB8(&p0);
        break;
    }
    case 0x800796DCu: {
        native_dispatch_require(target,argument_count,0u);
        GameMainCallContext p0={0};
        p0.stack_pointer=native_dispatch_stack(target,argument_count,0u,args);
        sub_800796DC(&p0); result=0;
        break;
    }
    case 0x80079C20u: {
        native_dispatch_require(target,argument_count,0u);
        GameMainCallContext p0={0};
        p0.stack_pointer=native_dispatch_stack(target,argument_count,0u,args);
        sub_80079C20(&p0); result=0;
        break;
    }
    case 0x8007A438u: {
        native_dispatch_require(target,argument_count,3u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8007A438(p0,p1,p2);
        break;
    }
    case 0x8007A53Cu: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8007A53C(p0,p1);
        break;
    }
    case 0x8007A7ACu: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8007A7AC(p0);
        break;
    }
    case 0x8007B350u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8007B350(p0);
        break;
    }
    case 0x8007B368u: {
        native_dispatch_require(target,argument_count,3u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8007B368(p0,p1,p2);
        break;
    }
    case 0x8007B5CCu: {
        native_dispatch_require(target,argument_count,3u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8007B5CC(p0,p1,p2);
        break;
    }
    case 0x8007B730u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        GameSceneCallContext p2={0};
        p2.stack_pointer=native_dispatch_stack(target,argument_count,2u,args);
        result=(uint64)sub_8007B730(p0,p1,&p2);
        break;
    }
    case 0x8007B8B8u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8007B8B8(p0);
        break;
    }
    case 0x8007CE2Cu: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8007CE2C(p0,p1);
        break;
    }
    case 0x8007D110u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_8007D110();
        break;
    }
    case 0x8007D230u: {
        native_dispatch_require(target,argument_count,0u);
        GameMainCallContext p0={0};
        p0.stack_pointer=native_dispatch_stack(target,argument_count,0u,args);
        sub_8007D230(&p0); result=0;
        break;
    }
    case 0x8007D2B4u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8007D2B4(p0);
        break;
    }
    case 0x8007D368u: {
        native_dispatch_require(target,argument_count,4u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        uint32 p3=(uint32)va_arg(args,uint32);
        uint32 p4=native_dispatch_stack(target,argument_count,4u,args);
        sub_8007D368(p0,p1,p2,p3,p4); result=0;
        break;
    }
    case 0x8007D3F0u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8007D3F0(p0,p1);
        break;
    }
    case 0x8007E9B0u: {
        native_dispatch_require(target,argument_count,3u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        uint32 p2=(uint32)va_arg(args,uint32);
        sub_8007E9B0(p0,p1,p2); result=0;
        break;
    }
    case 0x8007E9D0u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        sub_8007E9D0(p0,p1); result=0;
        break;
    }
    case 0x8007EA60u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8007EA60(p0,p1);
        break;
    }
    case 0x8007EC14u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8007EC14(p0);
        break;
    }
    case 0x8007ECE0u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8007ECE0(p0);
        break;
    }
    case 0x8007F438u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8007F438(p0);
        break;
    }
    case 0x80080230u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80080230(p0,p1);
        break;
    }
    case 0x80080474u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80080474(p0,p1);
        break;
    }
    case 0x8008056Cu: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        sub_8008056C(p0); result=0;
        break;
    }
    case 0x80082B68u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_80082B68();
        break;
    }
    case 0x8008355Cu: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        sub_8008355C(p0); result=0;
        break;
    }
    case 0x8008358Cu: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        sub_8008358C(p0); result=0;
        break;
    }
    case 0x800836DCu: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        sub_800836DC(p0,p1); result=0;
        break;
    }
    case 0x80083868u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        sub_80083868(p0); result=0;
        break;
    }
    case 0x80083898u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        sub_80083898(p0,p1); result=0;
        break;
    }
    case 0x80085BFCu: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        GameMainCallContext p1={0};
        p1.stack_pointer=native_dispatch_stack(target,argument_count,1u,args);
        sub_80085BFC(p0,&p1); result=0;
        break;
    }
    case 0x80085C54u: {
        native_dispatch_require(target,argument_count,0u);
        GameMainCallContext p0={0};
        p0.stack_pointer=native_dispatch_stack(target,argument_count,0u,args);
        sub_80085C54(&p0); result=0;
        break;
    }
    case 0x80085CC4u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_80085CC4();
        break;
    }
    case 0x800861E4u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        sub_800861E4(p0); result=0;
        break;
    }
    case 0x80086214u: {
        native_dispatch_require(target,argument_count,0u);
        sub_80086214(); result=0;
        break;
    }
    case 0x800863C4u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        sub_800863C4(p0); result=0;
        break;
    }
    case 0x80086530u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80086530(p0,p1);
        break;
    }
    case 0x800865ACu: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_800865AC(p0,p1);
        break;
    }
    case 0x80086668u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80086668(p0);
        break;
    }
    case 0x80086B58u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        result=(uint64)sub_80086B58(p0,p1);
        break;
    }
    case 0x8008757Cu: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8008757C(p0);
        break;
    }
    case 0x800891B0u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=va_arg(args,uint32),p1=va_arg(args,uint32);
        result=(uint64)sub_800891B0(p0,p1);
        break;
    }
    case 0x8008A1DCu: {
        native_dispatch_require(target,argument_count,4u);
        uint32 p0=va_arg(args,uint32),p1=va_arg(args,uint32),p2=va_arg(args,uint32),p3=va_arg(args,uint32);
        result=(uint64)sub_8008A1DC(p0,p1,p2,p3);
        break;
    }
    case 0x80089118u: {
        native_dispatch_require(target,argument_count,0u);
        result=(uint64)sub_80089118();
        break;
    }
    case 0x80089218u: {
        native_dispatch_require(target,argument_count,0u);
        GameGeometryCallContext p0={0};
        p0.stack_pointer=native_dispatch_stack(target,argument_count,0u,args);
        result=(uint64)sub_80089218(&p0);
        break;
    }
    case 0x80089490u: {
        native_dispatch_require(target,argument_count,2u);
        uint32 p0=(uint32)va_arg(args,uint32);
        uint32 p1=(uint32)va_arg(args,uint32);
        GameGeometryCallContext p2={0};
        p2.stack_pointer=native_dispatch_stack(target,argument_count,2u,args);
        result=(uint64)sub_80089490(p0,p1,&p2);
        break;
    }
    case 0x8008A3E4u: {
        native_dispatch_require(target,argument_count,1u);
        uint32 p0=(uint32)va_arg(args,uint32);
        result=(uint64)sub_8008A3E4(p0);
        break;
    }
    default: abort();
    }
    return result;
}
