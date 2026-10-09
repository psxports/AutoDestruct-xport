#include "native_call_dispatch.h"

void native_dispatch_require(uint32 target,uint32 count,uint32 minimum)
{
    if(count<minimum){fprintf(stderr,"Native call %08X needs %u arguments, received %u\n",target,minimum,count);abort();}
}
uint32 native_dispatch_stack(uint32 target,uint32 count,uint32 consumed,va_list args)
{
    uint32 local_bytes, frame, i;
    uint32 argument_bytes=count>4u?count*4u:16u;
    switch(target){
    case 0x800643ECu: local_bytes=120u; break;
    case 0x8001FF7Cu: local_bytes=48u; break;
    case 0x80020C60u: local_bytes=32u; break;
    case 0x80020D98u: local_bytes=0u; break;
    case 0x80021144u: local_bytes=24u; break;
    case 0x80021550u: local_bytes=0u; break;
    case 0x800215A0u: local_bytes=72u; break;
    case 0x800226E4u: local_bytes=24u; break;
    case 0x80022744u: local_bytes=24u; break;
    case 0x8002912Cu: local_bytes=40u; break;
    case 0x80029AF4u: local_bytes=48u; break;
    case 0x80029C80u: local_bytes=0u; break;
    case 0x8002E310u: local_bytes=40u; break;
    case 0x80035780u: local_bytes=24u; break;
    case 0x800358DCu: local_bytes=24u; break;
    case 0x80035A08u: local_bytes=24u; break;
    case 0x800360BCu: local_bytes=72u; break;
    case 0x800362B8u: local_bytes=32u; break;
    case 0x80036348u: local_bytes=72u; break;
    case 0x80036EA8u: local_bytes=64u; break;
    case 0x80037150u: local_bytes=40u; break;
    case 0x8003806Cu: local_bytes=24u; break;
    case 0x800380C8u: local_bytes=24u; break;
    case 0x8003893Cu: local_bytes=24u; break;
    case 0x800389A8u: local_bytes=24u; break;
    case 0x800392B4u: local_bytes=184u; break;
    case 0x800394B8u: local_bytes=40u; break;
    case 0x8003AD54u: local_bytes=24u; break;
    case 0x8003B574u: local_bytes=32u; break;
    case 0x8003B864u: local_bytes=24u; break;
    case 0x8003BA80u: local_bytes=64u; break;
    case 0x8003BE08u: local_bytes=64u; break;
    case 0x8003BEA8u: local_bytes=24u; break;
    case 0x8003BEFCu: local_bytes=24u; break;
    case 0x8003BF34u: local_bytes=24u; break;
    case 0x8003BFACu: local_bytes=48u; break;
    case 0x8003C058u: local_bytes=32u; break;
    case 0x8003C0C4u: local_bytes=24u; break;
    case 0x8003C114u: local_bytes=32u; break;
    case 0x8003C2B8u: local_bytes=24u; break;
    case 0x8003C374u: local_bytes=24u; break;
    case 0x8003C394u: local_bytes=24u; break;
    case 0x8003C3D4u: local_bytes=56u; break;
    case 0x8003C4B8u: local_bytes=56u; break;
    case 0x8003C5E4u: local_bytes=56u; break;
    case 0x8003C6D8u: local_bytes=80u; break;
    case 0x8003C87Cu: local_bytes=64u; break;
    case 0x8003C958u: local_bytes=56u; break;
    case 0x8003D0F4u: local_bytes=0u; break;
    case 0x8003D7F0u: local_bytes=88u; break;
    case 0x80041C9Cu: local_bytes=56u; break;
    case 0x80041E24u: local_bytes=88u; break;
    case 0x8004206Cu: local_bytes=0u; break;
    case 0x800420C4u: local_bytes=40u; break;
    case 0x80042130u: local_bytes=32u; break;
    case 0x80042290u: local_bytes=32u; break;
    case 0x80042318u: local_bytes=48u; break;
    case 0x80042424u: local_bytes=8u; break;
    case 0x800424BCu: local_bytes=40u; break;
    case 0x80042D64u: local_bytes=24u; break;
    case 0x80042E14u: local_bytes=24u; break;
    case 0x80042ED4u: local_bytes=32u; break;
    case 0x8004307Cu: local_bytes=32u; break;
    case 0x800431ECu: local_bytes=48u; break;
    case 0x8004328Cu: local_bytes=64u; break;
    case 0x800439A4u: local_bytes=80u; break;
    case 0x8004E6A4u: local_bytes=40u; break;
    case 0x8004F340u: local_bytes=40u; break;
    case 0x8004F47Cu: local_bytes=152u; break;
    case 0x8004F938u: local_bytes=200u; break;
    case 0x800510E0u: local_bytes=24u; break;
    case 0x800535DCu: local_bytes=72u; break;
    case 0x80054D38u: local_bytes=24u; break;
    case 0x80055134u: local_bytes=24u; break;
    case 0x800574F4u: local_bytes=24u; break;
    case 0x80057AB0u: local_bytes=72u; break;
    case 0x80057C7Cu: local_bytes=0u; break;
    case 0x80058418u: local_bytes=0u; break;
    case 0x80059610u: local_bytes=32u; break;
    case 0x800596DCu: local_bytes=48u; break;
    case 0x8005982Cu: local_bytes=24u; break;
    case 0x800598CCu: local_bytes=48u; break;
    case 0x80059990u: local_bytes=40u; break;
    case 0x80059C2Cu: local_bytes=40u; break;
    case 0x80059CE4u: local_bytes=40u; break;
    case 0x80059E2Cu: local_bytes=24u; break;
    case 0x80059E4Cu: local_bytes=40u; break;
    case 0x8005A040u: local_bytes=24u; break;
    case 0x8005A0D8u: local_bytes=32u; break;
    case 0x8005A130u: local_bytes=56u; break;
    case 0x8005A1ECu: local_bytes=40u; break;
    case 0x8005A3E4u: local_bytes=56u; break;
    case 0x8005A484u: local_bytes=24u; break;
    case 0x8005A4D8u: local_bytes=48u; break;
    case 0x8005A59Cu: local_bytes=24u; break;
    case 0x8005A5F8u: local_bytes=40u; break;
    case 0x8005A69Cu: local_bytes=56u; break;
    case 0x8005A7B8u: local_bytes=48u; break;
    case 0x8005A884u: local_bytes=40u; break;
    case 0x8005A8F0u: local_bytes=32u; break;
    case 0x8005A9FCu: local_bytes=48u; break;
    case 0x8005B668u: local_bytes=24u; break;
    case 0x8005B70Cu: local_bytes=16u; break;
    case 0x8005BF3Cu: local_bytes=72u; break;
    case 0x8005CA28u: local_bytes=24u; break;
    case 0x8005E758u: local_bytes=24u; break;
    case 0x8005E790u: local_bytes=24u; break;
    case 0x80063888u: local_bytes=24u; break;
    case 0x80063AFCu: local_bytes=16u; break;
    case 0x80063C3Cu: local_bytes=16u; break;
    case 0x80063E28u: local_bytes=16u; break;
    case 0x80064020u: local_bytes=16u; break;
    case 0x80064200u: local_bytes=16u; break;
    case 0x80064334u: local_bytes=24u; break;
    case 0x80064594u: local_bytes=32u; break;
    case 0x8006499Cu: local_bytes=24u; break;
    case 0x800649E4u: local_bytes=24u; break;
    case 0x80064A44u: local_bytes=24u; break;
    case 0x80064B04u: local_bytes=40u; break;
    case 0x800651ACu: local_bytes=24u; break;
    case 0x80069AD4u: local_bytes=24u; break;
    case 0x80069B38u: local_bytes=24u; break;
    case 0x80069B84u: local_bytes=24u; break;
    case 0x80069E54u: local_bytes=24u; break;
    case 0x8006F050u: local_bytes=24u; break;
    case 0x8006F0CCu: local_bytes=24u; break;
    case 0x8006F150u: local_bytes=24u; break;
    case 0x800732F8u: local_bytes=0u; break;
    case 0x80073574u: local_bytes=24u; break;
    case 0x8007361Cu: local_bytes=40u; break;
    case 0x80073B78u: local_bytes=32u; break;
    case 0x80073C48u: local_bytes=56u; break;
    case 0x80076ED4u: local_bytes=32u; break;
    case 0x80078D70u: local_bytes=8u; break;
    case 0x80078DB8u: local_bytes=24u; break;
    case 0x800796DCu: local_bytes=0u; break;
    case 0x80079C20u: local_bytes=0u; break;
    case 0x8007B730u: local_bytes=24u; break;
    case 0x8007D230u: local_bytes=24u; break;
    case 0x8007D368u: local_bytes=32u; break;
    case 0x80085BFCu: local_bytes=24u; break;
    case 0x80085C54u: local_bytes=24u; break;
    case 0x80089218u: local_bytes=24u; break;
    case 0x80089490u: local_bytes=24u; break;
    default:fprintf(stderr,"Unknown native callee frame %08X\n",target);abort();
    }
    frame=draft_scratch_adapter(local_bytes+argument_bytes)+local_bytes;
    for(i=consumed;i<count;++i){uint32 value=va_arg(args,uint32);if(i>=4u)w_u32(frame+16u+(i-4u)*4u,value);}
    return frame;
}

uint64 draft_call_adapter_counted(uint32 argument_count,uint32 target,...)
{
    uint32 mark=draft_scratch_mark();uint64 result;va_list args;
    if(argument_count>24u){fprintf(stderr,"Native call %08X exceeds 24 arguments\n",target);abort();}
    va_start(args,target);
    switch(target){
    case 0x800805E0u:
        native_dispatch_require(target, argument_count, 1u);
        result = sub_800805E0(va_arg(args, uint32));
        break;
    case 0x8007FAACu:
        native_dispatch_require(target, argument_count, 1u);
        result = sub_8007FAAC(va_arg(args, uint32));
        break;
    case 0x8003F5CCu:
        native_dispatch_require(target, argument_count, 1u);
        sub_8003F5CC(va_arg(args, uint32));
        result = 0u;
        break;
    case 0x8003F6D0u:
        native_dispatch_require(target, argument_count, 1u);
        result = sub_8003F6D0(va_arg(args, uint32));
        break;
    case 0x80040DACu:
    case 0x80061018u: {
        uint32 object;
        native_dispatch_require(target, argument_count, 1u);
        object = va_arg(args, uint32);
        result = target == 0x80040DACu ? sub_80040DAC(object) : sub_80061018(object);
        break;
    }
    case 0x80060F6Cu: {
        uint32 object, model, size;
        native_dispatch_require(target, argument_count, 3u);
        object = va_arg(args, uint32);
        model = va_arg(args, uint32);
        size = va_arg(args, uint32);
        result = sub_80060F6C(object, model, size);
        break;
    }
    case 0x80040478u: {
        uint32 object, ignored;
        native_dispatch_require(target, argument_count, 2u);
        object = va_arg(args, uint32);
        ignored = va_arg(args, uint32);
        result = sub_80040478(object, ignored);
        break;
    }
    case 0x80040500u:
    case 0x80040674u:
    case 0x80040754u: {
        uint32 object;
        native_dispatch_require(target, argument_count, 1u);
        object = va_arg(args, uint32);
        if (target == 0x80040500u) result = sub_80040500(object);
        else if (target == 0x80040674u) result = sub_80040674(object);
        else result = sub_80040754(object);
        break;
    }
    case 0x80040BC4u:
    case 0x80060E20u: {
        uint32 object;
        native_dispatch_require(target, argument_count, 1u);
        object = va_arg(args, uint32);
        result = target == 0x80040BC4u ? sub_80040BC4(object) : sub_80060E20(object);
        break;
    }
    case 0x80040B54u:
        native_dispatch_require(target, argument_count, 1u);
        result = sub_80040B54(va_arg(args, uint32));
        break;
    case 0x80060D20u: {
        uint32 object, previous;
        native_dispatch_require(target, argument_count, 2u);
        object = va_arg(args, uint32);
        previous = va_arg(args, uint32);
        result = sub_80060D20(object, previous);
        break;
    }
    case 0x8002E190u: {
        uint32 object, ignored, other, index;
        native_dispatch_require(target, argument_count, 4u);
        object = va_arg(args, uint32);
        ignored = va_arg(args, uint32);
        other = va_arg(args, uint32);
        index = va_arg(args, uint32);
        result = sub_8002E190(object, ignored, other, index);
        break;
    }
    case 0x8003DB40u: {
        uint32 object, mode;
        native_dispatch_require(target, argument_count, 2u);
        object = va_arg(args, uint32);
        mode = va_arg(args, uint32);
        result = sub_8003DB40(object, mode);
        break;
    }
    case 0x8003DC50u:
        native_dispatch_require(target, argument_count, 1u);
        result = sub_8003DC50(va_arg(args, uint32));
        break;
    case 0x8003FEB4u: {
        uint32 matrix, scales;
        native_dispatch_require(target, argument_count, 2u);
        matrix = va_arg(args, uint32);
        scales = va_arg(args, uint32);
        result = sub_8003FEB4(matrix, scales);
        break;
    }
    case 0x8003FFB4u:
    case 0x8003FFECu:
    case 0x8003FD78u:
    case 0x8003FE30u:
    case 0x8003FF08u: {
        uint32 object;
        native_dispatch_require(target, argument_count, 1u);
        object = va_arg(args, uint32);
        if (target == 0x8003FFB4u) result = sub_8003FFB4(object);
        else if (target == 0x8003FFECu) result = sub_8003FFEC(object);
        else if (target == 0x8003FD78u) result = sub_8003FD78(object);
        else if (target == 0x8003FE30u) result = sub_8003FE30(object);
        else result = sub_8003FF08(object);
        break;
    }
    case 0x8003D02Cu: {
        uint32 index, amount;
        native_dispatch_require(target, argument_count, 2u);
        index = va_arg(args, uint32);
        amount = va_arg(args, uint32);
        result = sub_8003D02C(index, amount);
        break;
    }
    case 0x8003CE7Cu:
        native_dispatch_require(target, argument_count, 1u);
        result = sub_8003CE7C(va_arg(args, uint32));
        break;
    case 0x8003F814u:
    case 0x8003FA50u:
    case 0x80022820u: {
        uint32 first, second;
        native_dispatch_require(target, argument_count, 2u);
        first = va_arg(args, uint32);
        second = va_arg(args, uint32);
        if (target == 0x8003F814u) result = sub_8003F814(first, second);
        else if (target == 0x8003FA50u) result = sub_8003FA50(first, second);
        else result = sub_80022820(first, second);
        break;
    }
    case 0x8003F79Cu: {
        uint32 object, mode, value;
        native_dispatch_require(target, argument_count, 3u);
        object = va_arg(args, uint32);
        mode = va_arg(args, uint32);
        value = va_arg(args, uint32);
        result = sub_8003F79C(object, mode, value);
        break;
    }
    case 0x8003F974u:
    case 0x80062CA0u:
    case 0x8005414Cu: {
        uint32 object;
        native_dispatch_require(target, argument_count, 1u);
        object = va_arg(args, uint32);
        if (target == 0x8003F974u) result = sub_8003F974(object);
        else if (target == 0x80062CA0u) result = sub_80062CA0(object);
        else result = sub_8005414C(object);
        break;
    }
    case 0x80062B3Cu: {
        uint32 position, material, scale, count;
        native_dispatch_require(target, argument_count, 4u);
        position = va_arg(args, uint32);
        material = va_arg(args, uint32);
        scale = va_arg(args, uint32);
        count = va_arg(args, uint32);
        result = sub_80062B3C(position, material, scale, count);
        break;
    }
    case 0x800542C0u: {
        uint32 object, mode, count;
        native_dispatch_require(target, argument_count, 3u);
        object = va_arg(args, uint32);
        mode = va_arg(args, uint32);
        count = va_arg(args, uint32);
        result = sub_800542C0(object, mode, count);
        break;
    }
    case 0x80054594u:
    case 0x800546D4u: {
        uint32 object;
        native_dispatch_require(target, argument_count, 1u);
        object = va_arg(args, uint32);
        result = target == 0x80054594u ? sub_80054594(object) : sub_800546D4(object);
        break;
    }
    case 0x80045510u:
    case 0x80062B08u:
    case 0x800548B0u:
    case 0x800547ECu:
    case 0x80054660u: {
        uint32 object;
        native_dispatch_require(target, argument_count, 1u);
        object = va_arg(args, uint32);
        if (target == 0x80045510u) result = sub_80045510(object);
        else if (target == 0x80062B08u) result = sub_80062B08(object);
        else if (target == 0x800548B0u) result = sub_800548B0(object);
        else if (target == 0x800547ECu) result = sub_800547EC(object);
        else result = sub_80054660(object);
        break;
    }
    case 0x8004D8B4u: {
        uint32 object;
        native_dispatch_require(target, argument_count, 1u);
        object = va_arg(args, uint32);
        result = sub_8004D8B4(object);
        break;
    }
    case 0x80054934u: {
        uint32 object, mode;
        native_dispatch_require(target, argument_count, 2u);
        object = va_arg(args, uint32);
        mode = va_arg(args, uint32);
        result = sub_80054934(object, mode);
        break;
    }
    case 0x8004BBBCu: {
        uint32 object, mode;
        native_dispatch_require(target, argument_count, 2u);
        object = va_arg(args, uint32);
        mode = va_arg(args, uint32);
        result = sub_8004BBBC(object, mode);
        break;
    }
    case 0x8004C8A8u: {
        native_dispatch_require(target, argument_count, 1u);
        result = sub_8004C8A8(va_arg(args, uint32));
        break;
    }
    case 0x8006080Cu:
    case 0x80060878u: {
        uint32 object;
        native_dispatch_require(target, argument_count, 1u);
        object = va_arg(args, uint32);
        result = target == 0x8006080Cu ? sub_8006080C(object) : sub_80060878(object);
        break;
    }
    case 0x800613D0u:
    case 0x800617A8u:
    case 0x80060738u: {
        uint32 object;
        native_dispatch_require(target, argument_count, 1u);
        object = va_arg(args, uint32);
        if (target == 0x800613D0u) result = sub_800613D0(object);
        else if (target == 0x800617A8u) result = sub_800617A8(object);
        else result = sub_80060738(object);
        break;
    }
    case 0x80061308u: {
        uint32 parameters[5], index;
        native_dispatch_require(target, argument_count, 5u);
        for (index = 0; index < 5u; ++index) parameters[index] = va_arg(args, uint32);
        sub_80061308(parameters[0], parameters[1], parameters[2], parameters[3], parameters[4]);
        result = 0u;
        break;
    }
    case 0x8006061Cu: {
        uint32 object, count;
        native_dispatch_require(target, argument_count, 2u);
        object = va_arg(args, uint32);
        count = va_arg(args, uint32);
        result = sub_8006061C(object, count);
        break;
    }
    case 0x80061738u:
    case 0x8005F7F0u: {
        uint32 object;
        native_dispatch_require(target, argument_count, 1u);
        object = va_arg(args, uint32);
        result = target == 0x80061738u ? sub_80061738(object) : sub_8005F7F0(object);
        break;
    }
    case 0x80061628u:
    case 0x80061174u:
    case 0x8005EFBCu:
    case 0x8005F774u:
    case 0x80060404u: {
        uint32 object;
        native_dispatch_require(target, argument_count, 1u);
        object = va_arg(args, uint32);
        if (target == 0x80061628u) result = sub_80061628(object);
        else if (target == 0x80061174u) result = sub_80061174(object);
        else if (target == 0x8005EFBCu) result = sub_8005EFBC(object);
        else if (target == 0x8005F774u) result = sub_8005F774(object);
        else result = sub_80060404(object);
        break;
    }
    case 0x8005EEC0u:
    case 0x8005F69Cu:
    case 0x80060320u: {
        uint32 object;
        native_dispatch_require(target, argument_count, 1u);
        object = va_arg(args, uint32);
        if (target == 0x8005EEC0u) result = sub_8005EEC0(object);
        else if (target == 0x8005F69Cu) result = sub_8005F69C(object);
        else result = sub_80060320(object);
        break;
    }
    case 0x80061500u:
    case 0x8006108Cu: {
        uint32 object;
        native_dispatch_require(target, argument_count, 1u);
        object = va_arg(args, uint32);
        result = target == 0x80061500u ? sub_80061500(object) : sub_8006108C(object);
        break;
    }
    case 0x80061418u: {
        uint32 object, parameter;
        native_dispatch_require(target, argument_count, 2u);
        object = va_arg(args, uint32);
        parameter = va_arg(args, uint32);
        result = sub_80061418(object, parameter);
        break;
    }
    case 0x8002CBD8u: {
        uint32 object, first_index, other, second_index;
        native_dispatch_require(target, argument_count, 4u);
        object = va_arg(args, uint32);
        first_index = va_arg(args, uint32);
        other = va_arg(args, uint32);
        second_index = va_arg(args, uint32);
        result = sub_8002CBD8(object, first_index, other, second_index);
        break;
    }
    case 0x80048D30u: {
        uint32 parameters[7], index;
        native_dispatch_require(target, argument_count, 7u);
        for (index = 0; index < 7u; ++index)
            parameters[index] = va_arg(args, uint32);
        result = sub_80048D30(parameters[0], parameters[1], parameters[2], parameters[3], parameters[4], parameters[5], parameters[6]);
        break;
    }
    case 0x8005B434u: {
        uint32 position, offset_x, offset_z;
        native_dispatch_require(target, argument_count, 3u);
        position = va_arg(args, uint32);
        offset_x = va_arg(args, uint32);
        offset_z = va_arg(args, uint32);
        result = sub_8005B434(position, offset_x, offset_z);
        break;
    }
    case 0x80049D98u: {
        native_dispatch_require(target, argument_count, 1u);
        result = sub_80049D98(va_arg(args, uint32));
        break;
    }
    case 0x8005E200u: {
        native_dispatch_require(target, argument_count, 1u);
        result = sub_8005E200(va_arg(args, uint32));
        break;
    }
    case 0x800557C0u: {
        uint32 destination, source, step;
        native_dispatch_require(target, argument_count, 3u);
        destination = va_arg(args, uint32);
        source = va_arg(args, uint32);
        step = va_arg(args, uint32);
        sub_800557C0(destination, source, step);
        result = 0u;
        break;
    }
    case 0x80080294u: {
        uint32 rectangle, buffer;
        native_dispatch_require(target, argument_count, 2u);
        rectangle = va_arg(args, uint32);
        buffer = va_arg(args, uint32);
        result = sub_80080294(rectangle, buffer);
        break;
    }
    case 0x8001F640u:
    case 0x80019854u:
    case 0x8001ABB0u:
    case 0x8001C4DCu: {
        uint32 parameters[8], index;
        native_dispatch_require(target, argument_count, 8u);
        for (index = 0; index < 8u; ++index)
            parameters[index] = va_arg(args, uint32);
        if (target == 0x8001F640u)
            result = sub_8001F640(parameters[0], parameters[1], parameters[2], parameters[3], parameters[4], parameters[5], parameters[6], parameters[7]);
        else if (target == 0x80019854u)
            result = sub_80019854(parameters[0], parameters[1], parameters[2], parameters[3], parameters[4], parameters[5], parameters[6], parameters[7]);
        else if (target == 0x8001ABB0u)
            result = sub_8001ABB0(parameters[0], parameters[1], parameters[2], parameters[3], parameters[4], parameters[5], parameters[6], parameters[7]);
        else
            result = sub_8001C4DC(parameters[0], parameters[1], parameters[2], parameters[3], parameters[4], parameters[5], parameters[6], parameters[7]);
        break;
    }
    case 0x800899C0u: {
        uint32 on_off, voice_mask;
        native_dispatch_require(target, argument_count, 2u);
        on_off = va_arg(args, uint32);
        voice_mask = va_arg(args, uint32);
        result = sub_800899C0(on_off, voice_mask);
        break;
    }
    case 0x80086EBCu: {
        native_dispatch_require(target, argument_count, 1u);
        result = sub_80086EBC(va_arg(args, uint32));
        break;
    }
    case 0x80086EE4u: {
        native_dispatch_require(target, argument_count, 1u);
        result = sub_80086EE4(va_arg(args, uint32));
        break;
    }
    case 0x80080D84u: {
        uint32 packet, rectangle;
        native_dispatch_require(target, argument_count, 2u);
        packet = va_arg(args, uint32);
        rectangle = va_arg(args, uint32);
        result = sub_80080D84(packet, rectangle);
        break;
    }
    case 0x80080800u: {
        native_dispatch_require(target, argument_count, 1u);
        result = sub_80080800(va_arg(args, uint32));
        break;
    }
    case 0x8007FF6Cu: {
        native_dispatch_require(target, argument_count, 1u);
        result = sub_8007FF6C(va_arg(args, uint32));
        break;
    }
    case 0x8007FED0u: {
        native_dispatch_require(target, argument_count, 1u);
        result = sub_8007FED0(va_arg(args, uint32));
        break;
    }
    case 0x8007F8C8u: {
        native_dispatch_require(target, argument_count, 1u);
        result = sub_8007F8C8(va_arg(args, uint32));
        break;
    }
    case 0x8007B4A0u: {
        native_dispatch_require(target, argument_count, 2u);
        uint32 command = va_arg(args, uint32);
        uint32 argument = va_arg(args, uint32);
        result = sub_8007B4A0(command, argument);
        break;
    }
    case 0x8007B7B4u: {
        native_dispatch_require(target, argument_count, 2u);
        uint32 sector = va_arg(args, uint32);
        uint32 position = va_arg(args, uint32);
        result = sub_8007B7B4(sector, position);
        break;
    }
    case 0x80014A68u: {
        native_dispatch_require(target, argument_count, 5u);
        uint32 object_address = va_arg(args, uint32);
        uint32 view_address = va_arg(args, uint32);
        uint32 clip_address = va_arg(args, uint32);
        uint32 render_context = va_arg(args, uint32);
        uint32 output_cursor = va_arg(args, uint32);
        result = sub_80014A68(object_address, view_address, clip_address, render_context, output_cursor);
        break;
    }
    case 0x8001545Cu:
    case 0x80015E0Cu:
    case 0x80016770u:
    case 0x800170D0u:
    case 0x80017550u:
    case 0x800176BCu:
    case 0x80017FD0u:
    case 0x800188E4u:
    case 0x80018D44u:
    case 0x80019220u:
    case 0x8001937Cu:
    case 0x8001998Cu:
    case 0x8001A110u:
    case 0x8001A660u:
    case 0x8001A838u:
    case 0x8001A9B4u:
    case 0x8001AE8Cu:
    case 0x8001B3B4u:
    case 0x8001B560u:
    case 0x8001B76Cu:
    case 0x8001BB70u:
    case 0x8001BF94u:
    case 0x8001C114u:
    case 0x8001C25Cu:
    case 0x8001C384u:
    case 0x8001C52Cu:
    case 0x8001CB7Cu:
    case 0x8001D204u:
    case 0x8001D870u:
    case 0x8001DDA4u:
    case 0x8001E2C0u:
    case 0x8001EABCu:
    case 0x8001F008u:
    case 0x8001F690u:
    case 0x8001F850u:
    case 0x8001F868u:
    case 0x8001F968u:
    case 0x8001FF7Cu:
    case 0x800202B0u:
    case 0x80020300u:
    case 0x800205C8u:
    case 0x8002062Cu:
    case 0x8002066Cu:
    case 0x80020764u:
    case 0x80020AB4u:
    case 0x80020C60u:
    case 0x80020D98u:
    case 0x80020E30u:
    case 0x80020E68u:
    case 0x80021144u:
    case 0x80021200u:
    case 0x800212ECu:
    case 0x8002133Cu:
    case 0x80021368u:
    case 0x800213F4u:
    case 0x800214C8u:
    case 0x80021550u:
    case 0x800215A0u:
    case 0x80021718u:
    case 0x800219E8u:
    case 0x80021BB0u:
    case 0x80021E94u:
    case 0x80021F80u:
    case 0x8002201Cu:
    case 0x800226E4u:
    case 0x80022744u:
    case 0x800227C4u:
    case 0x8002289Cu:
    case 0x800228DCu:
    case 0x80022908u:
    case 0x80022A68u:
    case 0x80022FF8u:
    case 0x80023228u:
    case 0x80023388u:
    case 0x8002349Cu:
    case 0x80023918u:
    case 0x80023A7Cu:
    case 0x80023C20u:
    case 0x800245ACu:
    case 0x80024820u:
    case 0x80024B28u:
    case 0x80024C9Cu:
    case 0x800255FCu:
    case 0x80025874u:
    case 0x80025924u:
    case 0x80026BC4u:
    case 0x80027024u:
    case 0x800283D4u:
    case 0x800284E8u:
    case 0x800287B4u:
    case 0x800290B8u:
    case 0x8002912Cu:
    case 0x800296B0u:
    case 0x80029758u:
    case 0x80029884u:
    case 0x800298A8u:
    case 0x80029968u:
    case 0x80029970u:
    case 0x80029A1Cu:
    case 0x80029AF4u:
    case 0x80029C80u:
    case 0x80029D44u:
    case 0x80029DDCu:
    case 0x80029EECu:
    case 0x8002A090u:
    case 0x8002A300u:
    case 0x8002A38Cu:
    case 0x8002A5DCu:
    case 0x8002A8F0u:
    case 0x8002A908u:
    case 0x8002AA2Cu:
    case 0x8002ACCCu:
    case 0x8002AF4Cu:
    case 0x8002B198u:
    case 0x8002B224u:
    case 0x8002B6A8u:
    case 0x8002B7FCu:
    case 0x8002B93Cu:
    case 0x8002BC6Cu:
    case 0x8002BE3Cu:
    case 0x8002C9D4u:
    case 0x8002CE90u:
    case 0x8002D348u:
    case 0x8002D7D4u:
    case 0x8002DA84u:
    case 0x8002DC94u:
    case 0x8002DFF8u:
    case 0x8002E310u:
    case 0x8002EAE4u:
    case 0x8002EDDCu:
    case 0x8002F3FCu:
    case 0x8002F7E0u:
    case 0x8002FC90u:
    case 0x80030040u:
    case 0x80030214u:
    case 0x80030678u:
    case 0x8003095Cu:
    case 0x80030BACu:
    case 0x80030E18u:
    case 0x80030F08u:
    case 0x80031290u:
    case 0x800313ECu:
    case 0x800314A8u:
    case 0x80031754u:
    case 0x80031A54u:
    case 0x80031B20u:
    case 0x80031B6Cu:
    case 0x80031BBCu:
    case 0x80031C1Cu:
    case 0x80031CC0u:
    case 0x80031CE8u:
    case 0x80031D50u:
    case 0x80031DC8u:
    case 0x80031E30u:
    case 0x80031EA8u:
    case 0x800327C8u:
    case 0x800329ECu:
    case 0x80032AD8u:
    case 0x80032B4Cu:
    case 0x80032D80u:
    case 0x80032F44u:
    case 0x800330D4u:
    case 0x800330E0u:
    case 0x80033100u:
    case 0x80033120u:
    case 0x8003315Cu:
    case 0x800331D8u:
    case 0x80033200u:
    case 0x800333C4u:
    case 0x80033400u:
    case 0x80033478u:
    case 0x800334A8u:
    case 0x800334D4u:
    case 0x80033724u:
    case 0x80033764u:
    case 0x800338D8u:
    case 0x800339D0u:
    case 0x80033B0Cu:
    case 0x80033D40u:
    case 0x80033E90u:
    case 0x80033EF8u:
        result=native_dispatch_group_0(target,argument_count,args);break;
    case 0x80034264u:
    case 0x8003438Cu:
    case 0x800345B0u:
    case 0x80034820u:
    case 0x80034868u:
    case 0x80034C88u:
    case 0x80034CA8u:
    case 0x800352C4u:
    case 0x80035664u:
    case 0x800356D8u:
    case 0x8003570Cu:
    case 0x80035758u:
    case 0x80035780u:
    case 0x800358DCu:
    case 0x80035988u:
    case 0x80035A08u:
    case 0x80035CD0u:
    case 0x80035FD8u:
    case 0x800360BCu:
    case 0x80036188u:
    case 0x800361FCu:
    case 0x800362B8u:
    case 0x80036348u:
    case 0x80036434u:
    case 0x80036584u:
    case 0x800369E0u:
    case 0x80036BE4u:
    case 0x80036CFCu:
    case 0x80036D6Cu:
    case 0x80036E10u:
    case 0x80036E9Cu:
    case 0x80036EA8u:
    case 0x80036EDCu:
    case 0x80036F0Cu:
    case 0x80036FE4u:
    case 0x8003708Cu:
    case 0x80037150u:
    case 0x80037320u:
    case 0x8003732Cu:
    case 0x80037490u:
    case 0x800374BCu:
    case 0x800375A4u:
    case 0x800375F0u:
    case 0x800376C0u:
    case 0x800376D0u:
    case 0x80037864u:
    case 0x800379BCu:
    case 0x800379FCu:
    case 0x80037BB8u:
    case 0x80037D50u:
    case 0x80037D8Cu:
    case 0x8003806Cu:
    case 0x800380A8u:
    case 0x800380C8u:
    case 0x8003893Cu:
    case 0x80038964u:
    case 0x80038970u:
    case 0x800389A8u:
    case 0x800389DCu:
    case 0x800389E8u:
    case 0x80038B78u:
    case 0x80038CDCu:
    case 0x800390E4u:
    case 0x8003915Cu:
    case 0x80039198u:
    case 0x80039224u:
    case 0x800392B4u:
    case 0x800394B8u:
    case 0x8003AB60u:
    case 0x8003ABE4u:
    case 0x8003ACE4u:
    case 0x8003AD54u:
    case 0x8003ADE0u:
    case 0x8003ADF4u:
    case 0x8003AF20u:
    case 0x8003B170u:
    case 0x8003B1ECu:
    case 0x8003B3B0u:
    case 0x8003B574u:
    case 0x8003B864u:
    case 0x8003B8E8u:
    case 0x8003B990u:
    case 0x8003BA80u:
    case 0x8003BD78u:
    case 0x8003BE08u:
    case 0x8003BEA8u:
    case 0x8003BEFCu:
    case 0x8003BF34u:
    case 0x8003BFACu:
    case 0x8003C058u:
    case 0x8003C0C4u:
    case 0x8003C114u:
    case 0x8003C2B8u:
    case 0x8003C374u:
    case 0x8003C394u:
    case 0x8003C3D4u:
    case 0x8003C4B8u:
    case 0x8003C5E4u:
    case 0x8003C6D8u:
    case 0x8003C87Cu:
    case 0x8003C958u:
    case 0x8003CA20u:
    case 0x8003CA68u:
    case 0x8003CAB4u:
    case 0x8003CAFCu:
    case 0x8003CB14u:
    case 0x8003CB54u:
    case 0x8003CB98u:
    case 0x8003CCE0u:
    case 0x8003CF6Cu:
    case 0x8003CF8Cu:
    case 0x8003CFECu:
    case 0x8003CFF8u:
    case 0x8003D0F4u:
    case 0x8003D270u:
    case 0x8003D27Cu:
    case 0x8003D324u:
    case 0x8003D338u:
    case 0x8003D654u:
    case 0x8003D67Cu:
    case 0x8003D688u:
    case 0x8003D694u:
    case 0x8003D6A0u:
    case 0x8003D6ACu:
    case 0x8003D6B8u:
    case 0x8003D6F0u:
    case 0x8003D7F0u:
    case 0x8003DB0Cu:
    case 0x8003E5C4u:
    case 0x8003E690u:
    case 0x8003E868u:
    case 0x8003E988u:
    case 0x8003EFDCu:
    case 0x8003F0F8u:
    case 0x8003F1B8u:
    case 0x8003F2C4u:
    case 0x8003F310u:
    case 0x8003F7D8u:
    case 0x8003FAD0u:
    case 0x800407C0u:
    case 0x80040840u:
    case 0x800408C0u:
    case 0x8004094Cu:
    case 0x80040964u:
    case 0x800409E4u:
    case 0x80040AECu:
    case 0x80040E78u:
    case 0x80040EF4u:
    case 0x80040F94u:
    case 0x800410E4u:
    case 0x80041604u:
    case 0x800416CCu:
    case 0x80041710u:
    case 0x800418E4u:
    case 0x80041C9Cu:
    case 0x80041D90u:
    case 0x80041DB4u:
    case 0x80041DE0u:
    case 0x80041DF8u:
    case 0x80041E1Cu:
    case 0x80041E24u:
    case 0x8004206Cu:
    case 0x800420C4u:
    case 0x80042130u:
    case 0x80042290u:
    case 0x80042318u:
    case 0x80042424u:
    case 0x800424BCu:
    case 0x80042598u:
    case 0x800428B0u:
    case 0x80042D64u:
    case 0x80042E14u:
    case 0x80042ED4u:
    case 0x8004307Cu:
    case 0x800431ECu:
    case 0x8004328Cu:
    case 0x800433D4u:
    case 0x800436D4u:
    case 0x80043820u:
    case 0x800439A4u:
    case 0x80043DF4u:
    case 0x800440E0u:
    case 0x800442ACu:
    case 0x800442FCu:
    case 0x80044534u:
    case 0x800445E0u:
    case 0x80044618u:
    case 0x80044C78u:
    case 0x80044E68u:
    case 0x80044F50u:
    case 0x80044F8Cu:
    case 0x8004510Cu:
    case 0x800451B4u:
    case 0x8004525Cu:
    case 0x80045280u:
    case 0x800452B8u:
    case 0x800452E8u:
    case 0x8004530Cu:
    case 0x80045340u:
    case 0x8004549Cu:
    case 0x8004557Cu:
    case 0x80045AD8u:
    case 0x80045DD4u:
    case 0x80045E18u:
    case 0x80045EB0u:
    case 0x80046004u:
    case 0x800461BCu:
    case 0x800461DCu:
    case 0x800463F0u:
    case 0x8004644Cu:
    case 0x800464B0u:
    case 0x800465A8u:
    case 0x800467A4u:
    case 0x800469E8u:
    case 0x80046A58u:
    case 0x80046E18u:
    case 0x80046E9Cu:
    case 0x80047124u:
    case 0x800473C8u:
    case 0x80047438u:
    case 0x80047480u:
    case 0x80047670u:
    case 0x800476D8u:
    case 0x80047718u:
    case 0x80047788u:
    case 0x80047CF0u:
    case 0x80048F9Cu:
        result=native_dispatch_group_1(target,argument_count,args);break;
    case 0x8004915Cu:
    case 0x800494F4u:
    case 0x80049648u:
    case 0x80049814u:
    case 0x800498D4u:
    case 0x80049AC0u:
    case 0x80049FBCu:
    case 0x8004A17Cu:
    case 0x8004AA30u:
    case 0x8004AB4Cu:
    case 0x8004BAA4u:
    case 0x8004BC94u:
    case 0x8004C8F4u:
    case 0x8004CAD4u:
    case 0x8004D04Cu:
    case 0x8004D184u:
    case 0x8004D730u:
    case 0x8004D874u:
    case 0x8004E4F4u:
    case 0x8004E53Cu:
    case 0x8004E6A4u:
    case 0x8004E80Cu:
    case 0x8004E954u:
    case 0x8004EC84u:
    case 0x8004ED64u:
    case 0x8004F2F8u:
    case 0x8004F340u:
    case 0x8004F394u:
    case 0x8004F47Cu:
    case 0x8004F8E4u:
    case 0x8004F938u:
    case 0x800510D0u:
    case 0x800510E0u:
    case 0x80051328u:
    case 0x800535DCu:
    case 0x800537E8u:
    case 0x800538ECu:
    case 0x800540E0u:
    case 0x80054D38u:
    case 0x80054F40u:
    case 0x80055134u:
    case 0x80055168u:
    case 0x800551CCu:
    case 0x80055228u:
    case 0x80055288u:
    case 0x8005536Cu:
    case 0x80055764u:
    case 0x80055818u:
    case 0x80055A70u:
    case 0x80055A9Cu:
    case 0x80055D54u:
    case 0x80055FA4u:
    case 0x8005603Cu:
    case 0x8005612Cu:
    case 0x80056288u:
    case 0x80056364u:
    case 0x800563ACu:
    case 0x80056AA8u:
    case 0x800570DCu:
    case 0x800574F4u:
    case 0x80057528u:
    case 0x800576B0u:
    case 0x800577F4u:
    case 0x8005780Cu:
    case 0x8005792Cu:
    case 0x80057A90u:
    case 0x80057AB0u:
    case 0x80057C7Cu:
    case 0x80057CB8u:
    case 0x80057D14u:
    case 0x80057DD8u:
    case 0x80057FFCu:
    case 0x80058418u:
    case 0x80058430u:
    case 0x80058508u:
    case 0x80058600u:
    case 0x80059274u:
    case 0x800592D4u:
    case 0x80059400u:
    case 0x80059420u:
    case 0x800595B8u:
    case 0x800595F0u:
    case 0x80059610u:
    case 0x800596DCu:
    case 0x8005982Cu:
    case 0x80059860u:
    case 0x800598CCu:
    case 0x80059990u:
    case 0x80059A88u:
    case 0x80059C2Cu:
    case 0x80059CE4u:
    case 0x80059E20u:
    case 0x80059E2Cu:
    case 0x80059E4Cu:
    case 0x8005A040u:
    case 0x8005A0D8u:
    case 0x8005A130u:
    case 0x8005A1ECu:
    case 0x8005A3E4u:
    case 0x8005A484u:
    case 0x8005A4D8u:
    case 0x8005A54Cu:
    case 0x8005A59Cu:
    case 0x8005A5F8u:
    case 0x8005A69Cu:
    case 0x8005A7B8u:
    case 0x8005A884u:
    case 0x8005A8F0u:
    case 0x8005A934u:
    case 0x8005A944u:
    case 0x8005A9FCu:
    case 0x8005AAE0u:
    case 0x8005AB3Cu:
    case 0x8005ABD8u:
    case 0x8005B2ACu:
    case 0x8005B2ECu:
    case 0x8005B364u:
    case 0x8005B47Cu:
    case 0x8005B5D8u:
    case 0x8005B614u:
    case 0x8005B668u:
    case 0x8005B694u:
    case 0x8005B6B4u:
    case 0x8005B70Cu:
    case 0x8005B9A0u:
    case 0x8005BA08u:
    case 0x8005BA64u:
    case 0x8005BD4Cu:
    case 0x8005BEECu:
    case 0x8005BF3Cu:
    case 0x8005C074u:
    case 0x8005C194u:
    case 0x8005C270u:
    case 0x8005C31Cu:
    case 0x8005C560u:
    case 0x8005C5A4u:
    case 0x8005C8A4u:
    case 0x8005C8E4u:
    case 0x8005CA28u:
    case 0x8005CB04u:
    case 0x8005CB7Cu:
    case 0x8005CBE8u:
    case 0x8005CC60u:
    case 0x8005D5A8u:
    case 0x8005D5E8u:
    case 0x8005D6CCu:
    case 0x8005D76Cu:
    case 0x8005D780u:
    case 0x8005D7C8u:
    case 0x8005D800u:
    case 0x8005D8D4u:
    case 0x8005DAB4u:
    case 0x8005DB18u:
    case 0x8005DC0Cu:
    case 0x8005E114u:
    case 0x8005E198u:
    case 0x8005E258u:
    case 0x8005E31Cu:
    case 0x8005E640u:
    case 0x8005E6CCu:
    case 0x8005E758u:
    case 0x8005E790u:
    case 0x8005E7C4u:
    case 0x8005E7DCu:
    case 0x8005E818u:
    case 0x8005E89Cu:
    case 0x8005E95Cu:
    case 0x8005EAD8u:
    case 0x8005EB2Cu:
    case 0x8005EBE4u:
    case 0x8005EE38u:
    case 0x8005F080u:
    case 0x8005F1E0u:
    case 0x8005F2D8u:
    case 0x8005F3B8u:
    case 0x8005F478u:
    case 0x8005F4E4u:
    case 0x8005F568u:
    case 0x8005F598u:
    case 0x8005F920u:
    case 0x8005FA24u:
    case 0x8005FC64u:
    case 0x8005FD2Cu:
    case 0x8005FDFCu:
    case 0x8005FEC0u:
    case 0x8005FF38u:
    case 0x8005FF80u:
    case 0x80061834u:
    case 0x800618D4u:
    case 0x80061938u:
    case 0x8006197Cu:
    case 0x800619FCu:
    case 0x80061A78u:
    case 0x80061CE4u:
    case 0x80061D90u:
    case 0x80061DD0u:
    case 0x80061E1Cu:
    case 0x80061FACu:
    case 0x800620A4u:
    case 0x800621A4u:
    case 0x80062240u:
    case 0x800623F8u:
    case 0x80062588u:
    case 0x8006268Cu:
    case 0x800628E4u:
    case 0x80063008u:
    case 0x800630DCu:
    case 0x800631A4u:
    case 0x80063258u:
    case 0x800632D0u:
    case 0x800633A0u:
        result=native_dispatch_group_2(target,argument_count,args);break;
    case 0x800643ECu:
    case 0x80063418u:
    case 0x80063590u:
    case 0x80063600u:
    case 0x80063654u:
    case 0x80063824u:
    case 0x80063888u:
    case 0x80063904u:
    case 0x80063AFCu:
    case 0x80063C3Cu:
    case 0x80063E28u:
    case 0x80064020u:
    case 0x80064200u:
    case 0x80064334u:
    case 0x80064594u:
    case 0x80064784u:
    case 0x800648A4u:
    case 0x8006499Cu:
    case 0x800649D4u:
    case 0x800649E4u:
    case 0x80064A44u:
    case 0x80064B04u:
    case 0x80064CECu:
    case 0x80064D60u:
    case 0x80064D80u:
    case 0x80064DCCu:
    case 0x80064DF4u:
    case 0x80064E78u:
    case 0x800650C4u:
    case 0x800650CCu:
    case 0x80065124u:
    case 0x800651ACu:
    case 0x80065244u:
    case 0x8006525Cu:
    case 0x800652C0u:
    case 0x80065D34u:
    case 0x80065DD0u:
    case 0x80065EB0u:
    case 0x80065EF8u:
    case 0x80065F68u:
    case 0x80065FD8u:
    case 0x80066048u:
    case 0x80066090u:
    case 0x800660D0u:
    case 0x800661CCu:
    case 0x8006623Cu:
    case 0x80066380u:
    case 0x80066958u:
    case 0x80066984u:
    case 0x80066AECu:
    case 0x80066D7Cu:
    case 0x8006706Cu:
    case 0x80067140u:
    case 0x80067160u:
    case 0x80067390u:
    case 0x80068F70u:
    case 0x80069018u:
    case 0x800697BCu:
    case 0x8006984Cu:
    case 0x800698C8u:
    case 0x80069974u:
    case 0x80069A04u:
    case 0x80069A50u:
    case 0x80069A70u:
    case 0x80069A98u:
    case 0x80069AD4u:
    case 0x80069B38u:
    case 0x80069B84u:
    case 0x80069BC0u:
    case 0x80069BE0u:
    case 0x80069C78u:
    case 0x80069D8Cu:
    case 0x80069DC4u:
    case 0x80069E54u:
    case 0x80069E94u:
    case 0x80069EFCu:
    case 0x80069F84u:
    case 0x8006A0A0u:
    case 0x8006A258u:
    case 0x8006A948u:
    case 0x8006ABE8u:
    case 0x8006AF08u:
    case 0x8006AFF4u:
    case 0x8006B198u:
    case 0x8006B410u:
    case 0x8006BA1Cu:
    case 0x8006BC98u:
    case 0x8006BD08u:
    case 0x8006C094u:
    case 0x8006C3D4u:
    case 0x8006C714u:
    case 0x8006DF90u:
    case 0x8006E06Cu:
    case 0x8006E490u:
    case 0x8006E520u:
    case 0x8006E5B4u:
    case 0x8006E5DCu:
    case 0x8006E62Cu:
    case 0x8006E6ACu:
    case 0x8006E708u:
    case 0x8006E748u:
    case 0x8006E790u:
    case 0x8006E7BCu:
    case 0x8006E7D8u:
    case 0x8006E8A4u:
    case 0x8006EA04u:
    case 0x8006EA48u:
    case 0x8006EB64u:
    case 0x8006ED00u:
    case 0x8006F050u:
    case 0x8006F0CCu:
    case 0x8006F150u:
    case 0x8006F178u:
    case 0x8006F1D0u:
    case 0x8006F22Cu:
    case 0x8006F23Cu:
    case 0x8006F27Cu:
    case 0x8006F2B0u:
    case 0x8006F2F4u:
    case 0x8006F338u:
    case 0x8006F554u:
    case 0x8006F58Cu:
    case 0x8006F6E8u:
    case 0x8006F710u:
    case 0x8006F738u:
    case 0x8006F790u:
    case 0x8006F7A8u:
    case 0x8006F818u:
    case 0x8006F950u:
    case 0x8006FB78u:
    case 0x8006FCB4u:
    case 0x800702D4u:
    case 0x800703B4u:
    case 0x8007040Cu:
    case 0x80070428u:
    case 0x8007044Cu:
    case 0x800704B4u:
    case 0x800704E8u:
    case 0x80070518u:
    case 0x80070540u:
    case 0x80070568u:
    case 0x80070634u:
    case 0x80070788u:
    case 0x800707D4u:
    case 0x80070A0Cu:
    case 0x80070B88u:
    case 0x80070C48u:
    case 0x80070CF4u:
    case 0x80070D6Cu:
    case 0x80070FFCu:
    case 0x80071050u:
    case 0x80071148u:
    case 0x800714A4u:
    case 0x800717A8u:
    case 0x80071960u:
    case 0x80071B4Cu:
    case 0x80071DC8u:
    case 0x80072388u:
    case 0x800723C4u:
    case 0x800725D0u:
    case 0x800727B0u:
    case 0x800732F8u:
    case 0x80073438u:
    case 0x800734C0u:
    case 0x80073574u:
    case 0x8007361Cu:
    case 0x80073B78u:
    case 0x80073C48u:
    case 0x80076ED4u:
    case 0x80077A20u:
    case 0x80077AC0u:
    case 0x800782D8u:
    case 0x800784F4u:
    case 0x80078830u:
    case 0x80078854u:
    case 0x800788D4u:
    case 0x80078D70u:
    case 0x80078DB8u:
    case 0x800796DCu:
    case 0x80079C20u:
    case 0x8007A438u:
    case 0x8007A53Cu:
    case 0x8007A7ACu:
    case 0x8007B350u:
    case 0x8007B368u:
    case 0x8007B5CCu:
    case 0x8007B730u:
    case 0x8007B8B8u:
    case 0x8007CE2Cu:
    case 0x8007D110u:
    case 0x8007D230u:
    case 0x8007D2B4u:
    case 0x8007D368u:
    case 0x8007D3F0u:
    case 0x8007E9B0u:
    case 0x8007E9D0u:
    case 0x8007EA60u:
    case 0x8007EC14u:
    case 0x8007ECE0u:
    case 0x8007F438u:
    case 0x80080230u:
    case 0x80080474u:
    case 0x8008056Cu:
    case 0x80082B68u:
    case 0x8008355Cu:
    case 0x8008358Cu:
    case 0x800836DCu:
    case 0x80083868u:
    case 0x80083898u:
    case 0x80085BFCu:
    case 0x80085C54u:
    case 0x80085CC4u:
    case 0x800861E4u:
    case 0x80086214u:
    case 0x800863C4u:
    case 0x80086530u:
    case 0x800865ACu:
    case 0x80086668u:
    case 0x80086B58u:
    case 0x8008757Cu:
    case 0x800891B0u:
    case 0x8008A1DCu:
    case 0x80089118u:
    case 0x80089218u:
    case 0x80089490u:
    case 0x8008A3E4u:
        result=native_dispatch_group_3(target,argument_count,args);break;
    default:fprintf(stderr,"Unbound native call %08X\n",target);abort();
    }
    va_end(args);draft_scratch_release(mark);return result;
}
