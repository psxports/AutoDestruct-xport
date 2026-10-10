#include "native_call_dispatch.h"

uint64 native_dispatch_group_2(uint32 target, uint32 argument_count, va_list args)
{
    uint64 result;
    switch (target)
    {
        case 0x8004915Cu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8004915C(p0);
            break;
        }
        case 0x800494F4u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800494F4(p0, p1);
            break;
        }
        case 0x80049648u:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80049648(p0, p1, p2);
            break;
        }
        case 0x80049814u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80049814(p0);
            break;
        }
        case 0x800498D4u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800498D4(p0, p1);
            break;
        }
        case 0x80049AC0u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80049AC0(p0, p1);
            break;
        }
        case 0x80049FBCu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80049FBC(p0);
            break;
        }
        case 0x8004A17Cu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8004A17C(p0);
            break;
        }
        case 0x8004AA30u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8004AA30(p0);
            break;
        }
        case 0x8004AB4Cu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8004AB4C(p0);
            break;
        }
        case 0x8004BAA4u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8004BAA4(p0, p1);
            break;
        }
        case 0x8004BC94u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8004BC94(p0);
            break;
        }
        case 0x8004C8F4u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8004C8F4(p0, p1);
            break;
        }
        case 0x8004CAD4u:
        {
            native_dispatch_require(target, argument_count, 4u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8004CAD4(p0, p1, p2, p3);
            break;
        }
        case 0x8004D04Cu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8004D04C(p0);
            break;
        }
        case 0x8004D184u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8004D184(p0);
            break;
        }
        case 0x8004D730u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8004D730(p0);
            break;
        }
        case 0x8004D874u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8004D874(p0);
            break;
        }
        case 0x8004E4F4u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8004E4F4(p0, p1);
            break;
        }
        case 0x8004E53Cu:
        {
            native_dispatch_require(target, argument_count, 4u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8004E53C(p0, p1, p2, p3);
            break;
        }
        case 0x8004E6A4u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p2 = {0};
            p2.stack_pointer = native_dispatch_stack(target, argument_count, 2u, args);
            result = (uint64)sub_8004E6A4(p0, p1, &p2);
            break;
        }
        case 0x8004E80Cu:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8004E80C(p0, p1, p2);
            break;
        }
        case 0x8004E954u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8004E954(p0);
            break;
        }
        case 0x8004EC84u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8004EC84(p0);
            break;
        }
        case 0x8004ED64u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8004ED64(p0);
            break;
        }
        case 0x8004F2F8u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8004F2F8(p0);
            break;
        }
        case 0x8004F340u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p2 = {0};
            p2.stack_pointer = native_dispatch_stack(target, argument_count, 2u, args);
            result = (uint64)sub_8004F340(p0, p1, &p2);
            break;
        }
        case 0x8004F394u:
        {
            native_dispatch_require(target, argument_count, 4u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8004F394(p0, p1, p2, p3);
            break;
        }
        case 0x8004F47Cu:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p2 = {0};
            p2.stack_pointer = native_dispatch_stack(target, argument_count, 2u, args);
            result = (uint64)sub_8004F47C(p0, p1, &p2);
            break;
        }
        case 0x8004F8E4u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8004F8E4();
            break;
        }
        case 0x8004F938u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p1 = {0};
            p1.stack_pointer = native_dispatch_stack(target, argument_count, 1u, args);
            result = (uint64)sub_8004F938(p0, &p1);
            break;
        }
        case 0x800510D0u:
        {
            native_dispatch_require(target, argument_count, 0u);
            sub_800510D0();
            result = 0;
            break;
        }
        case 0x800510E0u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_800510E0(&p0);
            break;
        }
        case 0x80051328u:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80051328(p0, p1, p2);
            break;
        }
        case 0x800535DCu:
        {
            native_dispatch_require(target, argument_count, 4u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p4 = {0};
            p4.stack_pointer = native_dispatch_stack(target, argument_count, 4u, args);
            result = (uint64)sub_800535DC(p0, p1, p2, p3, &p4);
            break;
        }
        case 0x800537E8u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800537E8(p0, p1);
            break;
        }
        case 0x800538ECu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800538EC(p0);
            break;
        }
        case 0x800540E0u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800540E0(p0, p1);
            break;
        }
        case 0x80054D38u:
        {
            native_dispatch_require(target, argument_count, 4u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            GameSceneCallContext p4 = {0};
            p4.stack_pointer = native_dispatch_stack(target, argument_count, 4u, args);
            result = (uint64)sub_80054D38(p0, p1, p2, p3, &p4);
            break;
        }
        case 0x80054F40u:
        {
            native_dispatch_require(target, argument_count, 4u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80054F40(p0, p1, p2, p3);
            break;
        }
        case 0x80055134u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p2 = {0};
            p2.stack_pointer = native_dispatch_stack(target, argument_count, 2u, args);
            result = (uint64)sub_80055134(p0, p1, &p2);
            break;
        }
        case 0x80055168u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80055168(p0, p1);
            break;
        }
        case 0x800551CCu:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800551CC(p0, p1);
            break;
        }
        case 0x80055228u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80055228(p0, p1);
            break;
        }
        case 0x80055288u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80055288(p0, p1);
            break;
        }
        case 0x8005536Cu:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005536C(p0, p1, p2);
            break;
        }
        case 0x80055764u:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80055764(p0, p1, p2);
            break;
        }
        case 0x80055818u:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            sub_80055818(p0, p1, p2);
            result = 0;
            break;
        }
        case 0x80055A70u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80055A70(p0);
            break;
        }
        case 0x80055A9Cu:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80055A9C(p0, p1);
            break;
        }
        case 0x80055D54u:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80055D54(p0, p1, p2);
            break;
        }
        case 0x80055FA4u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80055FA4(p0, p1);
            break;
        }
        case 0x8005603Cu:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005603C(p0, p1);
            break;
        }
        case 0x8005612Cu:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005612C(p0, p1, p2);
            break;
        }
        case 0x80056288u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80056288(p0);
            break;
        }
        case 0x80056364u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80056364(p0);
            break;
        }
        case 0x800563ACu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800563AC(p0);
            break;
        }
        case 0x80056AA8u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80056AA8(p0);
            break;
        }
        case 0x800570DCu:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800570DC(p0, p1);
            break;
        }
        case 0x800574F4u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_800574F4(&p0);
            break;
        }
        case 0x80057528u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_80057528();
            break;
        }
        case 0x800576B0u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_800576B0();
            break;
        }
        case 0x800577F4u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            sub_800577F4(p0);
            result = 0;
            break;
        }
        case 0x8005780Cu:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005780C(p0, p1, p2);
            break;
        }
        case 0x8005792Cu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005792C(p0);
            break;
        }
        case 0x80057A90u:
        {
            native_dispatch_require(target, argument_count, 4u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80057A90(p0, p1, p2, p3);
            break;
        }
        case 0x80057AB0u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_80057AB0(&p0);
            break;
        }
        case 0x80057C7Cu:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_80057C7C(&p0);
            break;
        }
        case 0x80057CB8u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80057CB8(p0);
            break;
        }
        case 0x80057D14u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80057D14(p0);
            break;
        }
        case 0x80057DD8u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_80057DD8();
            break;
        }
        case 0x80057FFCu:
        {
            native_dispatch_require(target, argument_count, 4u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80057FFC(p0, p1, p2, p3);
            break;
        }
        case 0x80058418u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            sub_80058418(&p0);
            result = 0;
            break;
        }
        case 0x80058430u:
        {
            native_dispatch_require(target, argument_count, 12u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            uint32 p4 = (uint32)va_arg(args, uint32);
            uint32 p5 = (uint32)va_arg(args, uint32);
            uint32 p6 = (uint32)va_arg(args, uint32);
            uint32 p7 = (uint32)va_arg(args, uint32);
            uint32 p8 = (uint32)va_arg(args, uint32);
            uint32 p9 = (uint32)va_arg(args, uint32);
            uint32 p10 = (uint32)va_arg(args, uint32);
            uint32 p11 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80058430(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);
            break;
        }
        case 0x80058508u:
        {
            native_dispatch_require(target, argument_count, 13u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            uint32 p4 = (uint32)va_arg(args, uint32);
            uint32 p5 = (uint32)va_arg(args, uint32);
            uint32 p6 = (uint32)va_arg(args, uint32);
            uint32 p7 = (uint32)va_arg(args, uint32);
            uint32 p8 = (uint32)va_arg(args, uint32);
            uint32 p9 = (uint32)va_arg(args, uint32);
            uint32 p10 = (uint32)va_arg(args, uint32);
            uint32 p11 = (uint32)va_arg(args, uint32);
            uint32 p12 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80058508(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
            break;
        }
        case 0x80058600u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_80058600();
            break;
        }
        case 0x80059274u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_80059274();
            break;
        }
        case 0x800592D4u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_800592D4();
            break;
        }
        case 0x80059400u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_80059400();
            break;
        }
        case 0x80059420u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_80059420();
            break;
        }
        case 0x800595B8u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800595B8(p0);
            break;
        }
        case 0x800595F0u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800595F0(p0, p1);
            break;
        }
        case 0x80059610u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_80059610(&p0);
            break;
        }
        case 0x800596DCu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p1 = {0};
            p1.stack_pointer = native_dispatch_stack(target, argument_count, 1u, args);
            result = (uint64)sub_800596DC(p0, &p1);
            break;
        }
        case 0x8005982Cu:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_8005982C(&p0);
            break;
        }
        case 0x80059860u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80059860(p0);
            break;
        }
        case 0x800598CCu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p1 = {0};
            p1.stack_pointer = native_dispatch_stack(target, argument_count, 1u, args);
            result = (uint64)sub_800598CC(p0, &p1);
            break;
        }
        case 0x80059990u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p1 = {0};
            p1.stack_pointer = native_dispatch_stack(target, argument_count, 1u, args);
            result = (uint64)sub_80059990(p0, &p1);
            break;
        }
        case 0x80059A88u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80059A88(p0, p1);
            break;
        }
        case 0x80059C2Cu:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_80059C2C(&p0);
            break;
        }
        case 0x80059CE4u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p1 = {0};
            p1.stack_pointer = native_dispatch_stack(target, argument_count, 1u, args);
            result = (uint64)sub_80059CE4(p0, &p1);
            break;
        }
        case 0x80059E20u:
        {
            native_dispatch_require(target, argument_count, 0u);
            sub_80059E20();
            result = 0;
            break;
        }
        case 0x80059E2Cu:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameSceneCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_80059E2C(&p0);
            break;
        }
        case 0x80059E4Cu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p1 = {0};
            p1.stack_pointer = native_dispatch_stack(target, argument_count, 1u, args);
            result = (uint64)sub_80059E4C(p0, &p1);
            break;
        }
        case 0x8005A040u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_8005A040(&p0);
            break;
        }
        case 0x8005A0D8u:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p3 = {0};
            p3.stack_pointer = native_dispatch_stack(target, argument_count, 3u, args);
            result = (uint64)sub_8005A0D8(p0, p1, p2, &p3);
            break;
        }
        case 0x8005A130u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p2 = {0};
            p2.stack_pointer = native_dispatch_stack(target, argument_count, 2u, args);
            result = (uint64)sub_8005A130(p0, p1, &p2);
            break;
        }
        case 0x8005A1ECu:
        {
            native_dispatch_require(target, argument_count, 4u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p4 = {0};
            p4.stack_pointer = native_dispatch_stack(target, argument_count, 4u, args);
            result = (uint64)sub_8005A1EC(p0, p1, p2, p3, &p4);
            break;
        }
        case 0x8005A3E4u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p2 = {0};
            p2.stack_pointer = native_dispatch_stack(target, argument_count, 2u, args);
            result = (uint64)sub_8005A3E4(p0, p1, &p2);
            break;
        }
        case 0x8005A484u:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            GameSceneCallContext p3 = {0};
            p3.stack_pointer = native_dispatch_stack(target, argument_count, 3u, args);
            result = (uint64)sub_8005A484(p0, p1, p2, &p3);
            break;
        }
        case 0x8005A4D8u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            GameSceneCallContext p1 = {0};
            p1.stack_pointer = native_dispatch_stack(target, argument_count, 1u, args);
            result = (uint64)sub_8005A4D8(p0, &p1);
            break;
        }
        case 0x8005A54Cu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005A54C(p0);
            break;
        }
        case 0x8005A59Cu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p1 = {0};
            p1.stack_pointer = native_dispatch_stack(target, argument_count, 1u, args);
            result = (uint64)sub_8005A59C(p0, &p1);
            break;
        }
        case 0x8005A5F8u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p1 = {0};
            p1.stack_pointer = native_dispatch_stack(target, argument_count, 1u, args);
            sub_8005A5F8(p0, &p1);
            result = 0;
            break;
        }
        case 0x8005A69Cu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p1 = {0};
            p1.stack_pointer = native_dispatch_stack(target, argument_count, 1u, args);
            result = (uint64)sub_8005A69C(p0, &p1);
            break;
        }
        case 0x8005A7B8u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p1 = {0};
            p1.stack_pointer = native_dispatch_stack(target, argument_count, 1u, args);
            result = (uint64)sub_8005A7B8(p0, &p1);
            break;
        }
        case 0x8005A884u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_8005A884(&p0);
            break;
        }
        case 0x8005A8F0u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_8005A8F0(&p0);
            break;
        }
        case 0x8005A934u:
        {
            native_dispatch_require(target, argument_count, 0u);
            sub_8005A934();
            result = 0;
            break;
        }
        case 0x8005A944u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8005A944();
            break;
        }
        case 0x8005A9FCu:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_8005A9FC(&p0);
            break;
        }
        case 0x8005AAE0u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8005AAE0();
            break;
        }
        case 0x8005AB3Cu:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8005AB3C();
            break;
        }
        case 0x8005ABD8u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8005ABD8();
            break;
        }
        case 0x8005B2ACu:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005B2AC(p0, p1, p2);
            break;
        }
        case 0x8005B2ECu:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005B2EC(p0, p1, p2);
            break;
        }
        case 0x8005B364u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005B364(p0);
            break;
        }
        case 0x8005B47Cu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005B47C(p0);
            break;
        }
        case 0x8005B5D8u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005B5D8(p0, p1);
            break;
        }
        case 0x8005B614u:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005B614(p0, p1, p2);
            break;
        }
        case 0x8005B668u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            sub_8005B668(&p0);
            result = 0;
            break;
        }
        case 0x8005B694u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005B694(p0);
            break;
        }
        case 0x8005B6B4u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8005B6B4();
            break;
        }
        case 0x8005B70Cu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = native_dispatch_stack(target, argument_count, 1u, args);
            result = (uint64)sub_8005B70C(p0, p1);
            break;
        }
        case 0x8005B9A0u:
        {
            native_dispatch_require(target, argument_count, 5u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            uint32 p4 = (uint32)va_arg(args, uint32);
            sub_8005B9A0(p0, p1, p2, p3, p4);
            result = 0;
            break;
        }
        case 0x8005BA08u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005BA08(p0);
            break;
        }
        case 0x8005BA64u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005BA64(p0);
            break;
        }
        case 0x8005BD4Cu:
        {
            native_dispatch_require(target, argument_count, 7u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            uint32 p4 = (uint32)va_arg(args, uint32);
            uint32 p5 = (uint32)va_arg(args, uint32);
            uint32 p6 = (uint32)va_arg(args, uint32);
            sub_8005BD4C(p0, p1, p2, p3, p4, p5, p6);
            result = 0;
            break;
        }
        case 0x8005BEECu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005BEEC(p0);
            break;
        }
        case 0x8005BF3Cu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p1 = {0};
            p1.stack_pointer = native_dispatch_stack(target, argument_count, 1u, args);
            result = (uint64)sub_8005BF3C(p0, &p1);
            break;
        }
        case 0x8005C074u:
        {
            native_dispatch_require(target, argument_count, 4u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005C074(p0, p1, p2, p3);
            break;
        }
        case 0x8005C194u:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005C194(p0, p1, p2);
            break;
        }
        case 0x8005C270u:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005C270(p0, p1, p2);
            break;
        }
        case 0x8005C31Cu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005C31C(p0);
            break;
        }
        case 0x8005C560u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005C560(p0);
            break;
        }
        case 0x8005C5A4u:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005C5A4(p0, p1, p2);
            break;
        }
        case 0x8005C8A4u:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005C8A4(p0, p1, p2);
            break;
        }
        case 0x8005C8E4u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005C8E4(p0);
            break;
        }
        case 0x8005CA28u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p1 = {0};
            p1.stack_pointer = native_dispatch_stack(target, argument_count, 1u, args);
            sub_8005CA28(p0, &p1);
            result = 0;
            break;
        }
        case 0x8005CB04u:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005CB04(p0, p1, p2);
            break;
        }
        case 0x8005CB7Cu:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8005CB7C();
            break;
        }
        case 0x8005CBE8u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005CBE8(p0, p1);
            break;
        }
        case 0x8005CC60u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005CC60(p0);
            break;
        }
        case 0x8005D5A8u:
        {
            native_dispatch_require(target, argument_count, 4u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005D5A8(p0, p1, p2, p3);
            break;
        }
        case 0x8005D5E8u:
        {
            native_dispatch_require(target, argument_count, 4u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005D5E8(p0, p1, p2, p3);
            break;
        }
        case 0x8005D6CCu:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005D6CC(p0, p1);
            break;
        }
        case 0x8005D76Cu:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            sub_8005D76C(p0, p1, p2);
            result = 0;
            break;
        }
        case 0x8005D780u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8005D780();
            break;
        }
        case 0x8005D7C8u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005D7C8(p0);
            break;
        }
        case 0x8005D800u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005D800(p0);
            break;
        }
        case 0x8005D8D4u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005D8D4(p0, p1);
            break;
        }
        case 0x8005DAB4u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005DAB4(p0);
            break;
        }
        case 0x8005DB18u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005DB18(p0, p1);
            break;
        }
        case 0x8005DC0Cu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005DC0C(p0);
            break;
        }
        case 0x8005E114u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005E114(p0, p1);
            break;
        }
        case 0x8005E198u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005E198(p0);
            break;
        }
        case 0x8005E258u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005E258(p0);
            break;
        }
        case 0x8005E31Cu:
        {
            native_dispatch_require(target, argument_count, 0u);
            sub_8005E31C();
            result = 0;
            break;
        }
        case 0x8005E640u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8005E640();
            break;
        }
        case 0x8005E6CCu:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8005E6CC();
            break;
        }
        case 0x8005E758u:
        {
            native_dispatch_require(target, argument_count, 0u);
            GameGeometryCallContext p0 = {0};
            p0.stack_pointer = native_dispatch_stack(target, argument_count, 0u, args);
            result = (uint64)sub_8005E758(&p0);
            break;
        }
        case 0x8005E790u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            GameGeometryCallContext p1 = {0};
            p1.stack_pointer = native_dispatch_stack(target, argument_count, 1u, args);
            result = (uint64)sub_8005E790(p0, &p1);
            break;
        }
        case 0x8005E7C4u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005E7C4(p0);
            break;
        }
        case 0x8005E7DCu:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8005E7DC();
            break;
        }
        case 0x8005E818u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8005E818();
            break;
        }
        case 0x8005E89Cu:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005E89C(p0, p1);
            break;
        }
        case 0x8005E95Cu:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005E95C(p0, p1);
            break;
        }
        case 0x8005EAD8u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8005EAD8();
            break;
        }
        case 0x8005EB2Cu:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8005EB2C();
            break;
        }
        case 0x8005EBE4u:
        {
            native_dispatch_require(target, argument_count, 0u);
            result = (uint64)sub_8005EBE4();
            break;
        }
        case 0x8005EE38u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005EE38(p0, p1);
            break;
        }
        case 0x8005F080u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005F080(p0);
            break;
        }
        case 0x8005F1E0u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005F1E0(p0);
            break;
        }
        case 0x8005F2D8u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005F2D8(p0);
            break;
        }
        case 0x8005F3B8u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005F3B8(p0);
            break;
        }
        case 0x8005F478u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005F478(p0);
            break;
        }
        case 0x8005F4E4u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005F4E4(p0);
            break;
        }
        case 0x8005F568u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005F568(p0);
            break;
        }
        case 0x8005F598u:
        {
            native_dispatch_require(target, argument_count, 4u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005F598(p0, p1, p2, p3);
            break;
        }
        case 0x8005F920u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005F920(p0);
            break;
        }
        case 0x8005FA24u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005FA24(p0);
            break;
        }
        case 0x8005FC64u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            sub_8005FC64(p0);
            result = 0;
            break;
        }
        case 0x8005FD2Cu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            sub_8005FD2C(p0);
            result = 0;
            break;
        }
        case 0x8005FDFCu:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            sub_8005FDFC(p0, p1, p2);
            result = 0;
            break;
        }
        case 0x8005FEC0u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005FEC0(p0);
            break;
        }
        case 0x8005FF38u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8005FF38(p0);
            break;
        }
        case 0x8005FF80u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            sub_8005FF80(p0, p1);
            result = 0;
            break;
        }
        case 0x80061834u:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80061834(p0, p1, p2);
            break;
        }
        case 0x800618D4u:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800618D4(p0, p1);
            break;
        }
        case 0x80061938u:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80061938(p0, p1, p2);
            break;
        }
        case 0x8006197Cu:
        {
            native_dispatch_require(target, argument_count, 2u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8006197C(p0, p1);
            break;
        }
        case 0x800619FCu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800619FC(p0);
            break;
        }
        case 0x80061A78u:
        {
            native_dispatch_require(target, argument_count, 6u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            uint32 p4 = (uint32)va_arg(args, uint32);
            uint32 p5 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80061A78(p0, p1, p2, p3, p4, p5);
            break;
        }
        case 0x80061CE4u:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80061CE4(p0, p1, p2);
            break;
        }
        case 0x80061D90u:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80061D90(p0, p1, p2);
            break;
        }
        case 0x80061DD0u:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80061DD0(p0, p1, p2);
            break;
        }
        case 0x80061E1Cu:
        {
            native_dispatch_require(target, argument_count, 5u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            uint32 p4 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80061E1C(p0, p1, p2, p3, p4);
            break;
        }
        case 0x80061FACu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80061FAC(p0);
            break;
        }
        case 0x800620A4u:
        {
            native_dispatch_require(target, argument_count, 8u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            uint32 p4 = (uint32)va_arg(args, uint32);
            uint32 p5 = (uint32)va_arg(args, uint32);
            uint32 p6 = (uint32)va_arg(args, uint32);
            uint32 p7 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800620A4(p0, p1, p2, p3, p4, p5, p6, p7);
            break;
        }
        case 0x800621A4u:
        {
            native_dispatch_require(target, argument_count, 3u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800621A4(p0, p1, p2);
            break;
        }
        case 0x80062240u:
        {
            native_dispatch_require(target, argument_count, 7u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            uint32 p4 = (uint32)va_arg(args, uint32);
            uint32 p5 = (uint32)va_arg(args, uint32);
            uint32 p6 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80062240(p0, p1, p2, p3, p4, p5, p6);
            break;
        }
        case 0x800623F8u:
        {
            native_dispatch_require(target, argument_count, 4u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800623F8(p0, p1, p2, p3);
            break;
        }
        case 0x80062588u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80062588(p0);
            break;
        }
        case 0x8006268Cu:
        {
            native_dispatch_require(target, argument_count, 7u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            uint32 p1 = (uint32)va_arg(args, uint32);
            uint32 p2 = (uint32)va_arg(args, uint32);
            uint32 p3 = (uint32)va_arg(args, uint32);
            uint32 p4 = (uint32)va_arg(args, uint32);
            uint32 p5 = (uint32)va_arg(args, uint32);
            uint32 p6 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_8006268C(p0, p1, p2, p3, p4, p5, p6);
            break;
        }
        case 0x800628E4u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800628E4(p0);
            break;
        }
        case 0x80063008u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80063008(p0);
            break;
        }
        case 0x800630DCu:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800630DC(p0);
            break;
        }
        case 0x800631A4u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800631A4(p0);
            break;
        }
        case 0x80063258u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_80063258(p0);
            break;
        }
        case 0x800632D0u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800632D0(p0);
            break;
        }
        case 0x800633A0u:
        {
            native_dispatch_require(target, argument_count, 1u);
            uint32 p0 = (uint32)va_arg(args, uint32);
            result = (uint64)sub_800633A0(p0);
            break;
        }
        default:
            abort();
    }
    return result;
}
