#include "IR_expr_xx.h"

#include <ostream>
#include <cassert>

namespace libvexxx{

std::ostream &operator<<(std::ostream &os, IROp op){
	const char *str=nullptr;
	IROp base;
	switch (op) {
	case Iop_Add8:
	case Iop_Add16:
	case Iop_Add32:
	case Iop_Add64:
		str = "Add";
		base = Iop_Add8;
		break;
	case Iop_Sub8:
	case Iop_Sub16:
	case Iop_Sub32:
	case Iop_Sub64:
		str = "Sub";
		base = Iop_Sub8;
		break;
	case Iop_Mul8:
	case Iop_Mul16:
	case Iop_Mul32:
	case Iop_Mul64:
		str = "Mul";
		base = Iop_Mul8;
		break;
	case Iop_Or8:
	case Iop_Or16:
	case Iop_Or32:
	case Iop_Or64:
		str = "Or";
		base = Iop_Or8;
		break;
	case Iop_And8:
	case Iop_And16:
	case Iop_And32:
	case Iop_And64:
		str = "And";
		base = Iop_And8;
		break;
	case Iop_Xor8:
	case Iop_Xor16:
	case Iop_Xor32:
	case Iop_Xor64:
		str = "Xor";
		base = Iop_Xor8;
		break;
	case Iop_Shl8:
	case Iop_Shl16:
	case Iop_Shl32:
	case Iop_Shl64:
		str = "Shl";
		base = Iop_Shl8;
		break;
	case Iop_Shr8:
	case Iop_Shr16:
	case Iop_Shr32:
	case Iop_Shr64:
		str = "Shr";
		base = Iop_Shr8;
		break;
	case Iop_Sar8:
	case Iop_Sar16:
	case Iop_Sar32:
	case Iop_Sar64:
		str = "Sar";
		base = Iop_Sar8;
		break;
	case Iop_CmpEQ8:
	case Iop_CmpEQ16:
	case Iop_CmpEQ32:
	case Iop_CmpEQ64:
		str = "CmpEQ";
		base = Iop_CmpEQ8;
		break;
	case Iop_CmpNE8:
	case Iop_CmpNE16:
	case Iop_CmpNE32:
	case Iop_CmpNE64:
		str = "CmpNE";
		base = Iop_CmpNE8;
		break;
	case Iop_CasCmpEQ8:
	case Iop_CasCmpEQ16:
	case Iop_CasCmpEQ32:
	case Iop_CasCmpEQ64:
		str = "CasCmpEQ";
		base = Iop_CasCmpEQ8;
		break;
	case Iop_CasCmpNE8:
	case Iop_CasCmpNE16:
	case Iop_CasCmpNE32:
	case Iop_CasCmpNE64:
		str = "CasCmpNE";
		base = Iop_CasCmpNE8;
		break;
	case Iop_ExpCmpNE8:
	case Iop_ExpCmpNE16:
	case Iop_ExpCmpNE32:
	case Iop_ExpCmpNE64:
		str = "ExpCmpNE";
		base = Iop_ExpCmpNE8;
		break;
	case Iop_Not8:
	case Iop_Not16:
	case Iop_Not32:
	case Iop_Not64:
		str = "Not";
		base = Iop_Not8;
		break;
	/* other cases must explicitly "return;" */
	case Iop_8Uto16:
		os<<"8Uto16";
		return os;
	case Iop_8Uto32:
		os<<"8Uto32";
		return os;
	case Iop_16Uto32:
		os<<"16Uto32";
		return os;
	case Iop_8Sto16:
		os<<"8Sto16";
		return os;
	case Iop_8Sto32:
		os<<"8Sto32";
		return os;
	case Iop_16Sto32:
		os<<"16Sto32";
		return os;
	case Iop_32Sto64:
		os<<"32Sto64";
		return os;
	case Iop_32Uto64:
		os<<"32Uto64";
		return os;
	case Iop_32to8:
		os<<"32to8";
		return os;
	case Iop_16Uto64:
		os<<"16Uto64";
		return os;
	case Iop_16Sto64:
		os<<"16Sto64";
		return os;
	case Iop_8Uto64:
		os<<"8Uto64";
		return os;
	case Iop_8Sto64:
		os<<"8Sto64";
		return os;
	case Iop_64to16:
		os<<"64to16";
		return os;
	case Iop_64to8:
		os<<"64to8";
		return os;

	case Iop_Not1:
		os<<"Not1";
		return os;
	case Iop_32to1:
		os<<"32to1";
		return os;
	case Iop_64to1:
		os<<"64to1";
		return os;
	case Iop_1Uto8:
		os<<"1Uto8";
		return os;
	case Iop_1Uto32:
		os<<"1Uto32";
		return os;
	case Iop_1Uto64:
		os<<"1Uto64";
		return os;
	case Iop_1Sto8:
		os<<"1Sto8";
		return os;
	case Iop_1Sto16:
		os<<"1Sto16";
		return os;
	case Iop_1Sto32:
		os<<"1Sto32";
		return os;
	case Iop_1Sto64:
		os<<"1Sto64";
		return os;

	case Iop_MullS8:
		os<<"MullS8";
		return os;
	case Iop_MullS16:
		os<<"MullS16";
		return os;
	case Iop_MullS32:
		os<<"MullS32";
		return os;
	case Iop_MullS64:
		os<<"MullS64";
		return os;
	case Iop_MullU8:
		os<<"MullU8";
		return os;
	case Iop_MullU16:
		os<<"MullU16";
		return os;
	case Iop_MullU32:
		os<<"MullU32";
		return os;
	case Iop_MullU64:
		os<<"MullU64";
		return os;

	case Iop_Clz64:
		os<<"Clz64";
		return os;
	case Iop_Clz32:
		os<<"Clz32";
		return os;
	case Iop_Ctz64:
		os<<"Ctz64";
		return os;
	case Iop_Ctz32:
		os<<"Ctz32";
		return os;

	case Iop_CmpLT32S:
		os<<"CmpLT32S";
		return os;
	case Iop_CmpLE32S:
		os<<"CmpLE32S";
		return os;
	case Iop_CmpLT32U:
		os<<"CmpLT32U";
		return os;
	case Iop_CmpLE32U:
		os<<"CmpLE32U";
		return os;

	case Iop_CmpLT64S:
		os<<"CmpLT64S";
		return os;
	case Iop_CmpLE64S:
		os<<"CmpLE64S";
		return os;
	case Iop_CmpLT64U:
		os<<"CmpLT64U";
		return os;
	case Iop_CmpLE64U:
		os<<"CmpLE64U";
		return os;

	case Iop_CmpNEZ8:
		os<<"CmpNEZ8";
		return os;
	case Iop_CmpNEZ16:
		os<<"CmpNEZ16";
		return os;
	case Iop_CmpNEZ32:
		os<<"CmpNEZ32";
		return os;
	case Iop_CmpNEZ64:
		os<<"CmpNEZ64";
		return os;

	case Iop_CmpwNEZ32:
		os<<"CmpwNEZ32";
		return os;
	case Iop_CmpwNEZ64:
		os<<"CmpwNEZ64";
		return os;

	case Iop_Left8:
		os<<"Left8";
		return os;
	case Iop_Left16:
		os<<"Left16";
		return os;
	case Iop_Left32:
		os<<"Left32";
		return os;
	case Iop_Left64:
		os<<"Left64";
		return os;
	case Iop_Max32U:
		os<<"Max32U";
		return os;

	case Iop_CmpORD32U:
		os<<"CmpORD32U";
		return os;
	case Iop_CmpORD32S:
		os<<"CmpORD32S";
		return os;

	case Iop_CmpORD64U:
		os<<"CmpORD64U";
		return os;
	case Iop_CmpORD64S:
		os<<"CmpORD64S";
		return os;

	case Iop_DivU32:
		os<<"DivU32";
		return os;
	case Iop_DivS32:
		os<<"DivS32";
		return os;
	case Iop_DivU64:
		os<<"DivU64";
		return os;
	case Iop_DivS64:
		os<<"DivS64";
		return os;
	case Iop_DivU64E:
		os<<"DivU64E";
		return os;
	case Iop_DivS64E:
		os<<"DivS64E";
		return os;
	case Iop_DivU32E:
		os<<"DivU32E";
		return os;
	case Iop_DivS32E:
		os<<"DivS32E";
		return os;

	case Iop_DivModU64to32:
		os<<"DivModU64to32";
		return os;
	case Iop_DivModS64to32:
		os<<"DivModS64to32";
		return os;

	case Iop_DivModU128to64:
		os<<"DivModU128to64";
		return os;
	case Iop_DivModS128to64:
		os<<"DivModS128to64";
		return os;

	case Iop_DivModS64to64:
		os<<"DivModS64to64";
		return os;

	case Iop_16HIto8:
		os<<"16HIto8";
		return os;
	case Iop_16to8:
		os<<"16to8";
		return os;
	case Iop_8HLto16:
		os<<"8HLto16";
		return os;

	case Iop_32HIto16:
		os<<"32HIto16";
		return os;
	case Iop_32to16:
		os<<"32to16";
		return os;
	case Iop_16HLto32:
		os<<"16HLto32";
		return os;

	case Iop_64HIto32:
		os<<"64HIto32";
		return os;
	case Iop_64to32:
		os<<"64to32";
		return os;
	case Iop_32HLto64:
		os<<"32HLto64";
		return os;

	case Iop_128HIto64:
		os<<"128HIto64";
		return os;
	case Iop_128to64:
		os<<"128to64";
		return os;
	case Iop_64HLto128:
		os<<"64HLto128";
		return os;

	case Iop_CmpF32:
		os<<"CmpF32";
		return os;
	case Iop_F32toI32S:
		os<<"F32toI32S";
		return os;
	case Iop_F32toI64S:
		os<<"F32toI64S";
		return os;
	case Iop_I32StoF32:
		os<<"I32StoF32";
		return os;
	case Iop_I64StoF32:
		os<<"I64StoF32";
		return os;

	case Iop_AddF64:
		os<<"AddF64";
		return os;
	case Iop_SubF64:
		os<<"SubF64";
		return os;
	case Iop_MulF64:
		os<<"MulF64";
		return os;
	case Iop_DivF64:
		os<<"DivF64";
		return os;
	case Iop_AddF64r32:
		os<<"AddF64r32";
		return os;
	case Iop_SubF64r32:
		os<<"SubF64r32";
		return os;
	case Iop_MulF64r32:
		os<<"MulF64r32";
		return os;
	case Iop_DivF64r32:
		os<<"DivF64r32";
		return os;
	case Iop_AddF32:
		os<<"AddF32";
		return os;
	case Iop_SubF32:
		os<<"SubF32";
		return os;
	case Iop_MulF32:
		os<<"MulF32";
		return os;
	case Iop_DivF32:
		os<<"DivF32";
		return os;

		/* 128 bit floating point */
	case Iop_AddF128:
		os<<"AddF128";
		return os;
	case Iop_SubF128:
		os<<"SubF128";
		return os;
	case Iop_MulF128:
		os<<"MulF128";
		return os;
	case Iop_DivF128:
		os<<"DivF128";
		return os;

	case Iop_TruncF128toI64S:
		os<<"TruncF128toI64S";
		return os;
	case Iop_TruncF128toI32S:
		os<<"TruncF128toI32S";
		return os;
	case Iop_TruncF128toI64U:
		os<<"TruncF128toI64U";
		return os;
	case Iop_TruncF128toI32U:
		os<<"TruncF128toI32U";
		return os;

	case Iop_MAddF128:
		os<<"MAddF128";
		return os;
	case Iop_MSubF128:
		os<<"MSubF128";
		return os;
	case Iop_NegMAddF128:
		os<<"NegMAddF128";
		return os;
	case Iop_NegMSubF128:
		os<<"NegMSubF128";
		return os;

	case Iop_AbsF128:
		os<<"AbsF128";
		return os;
	case Iop_NegF128:
		os<<"NegF128";
		return os;
	case Iop_SqrtF128:
		os<<"SqrtF128";
		return os;
	case Iop_CmpF128:
		os<<"CmpF128";
		return os;

	case Iop_F64HLtoF128:
		os<<"F64HLtoF128";
		return os;
	case Iop_F128HItoF64:
		os<<"F128HItoF64";
		return os;
	case Iop_F128LOtoF64:
		os<<"F128LOtoF64";
		return os;
	case Iop_I32StoF128:
		os<<"I32StoF128";
		return os;
	case Iop_I64StoF128:
		os<<"I64StoF128";
		return os;
	case Iop_I32UtoF128:
		os<<"I32UtoF128";
		return os;
	case Iop_I64UtoF128:
		os<<"I64UtoF128";
		return os;
	case Iop_F128toI32S:
		os<<"F128toI32S";
		return os;
	case Iop_F128toI64S:
		os<<"F128toI64S";
		return os;
	case Iop_F128toI32U:
		os<<"F128toI32U";
		return os;
	case Iop_F128toI64U:
		os<<"F128toI64U";
		return os;
	case Iop_F32toF128:
		os<<"F32toF128";
		return os;
	case Iop_F64toF128:
		os<<"F64toF128";
		return os;
	case Iop_F128toF64:
		os<<"F128toF64";
		return os;
	case Iop_F128toF32:
		os<<"F128toF32";
		return os;
	case Iop_F128toI128S:
		os<<"F128toI128";
		return os;
	case Iop_RndF128:
		os<<"RndF128";
		return os;

		/* s390 specific */
	case Iop_MAddF32:
		os<<"s390_MAddF32";
		return os;
	case Iop_MSubF32:
		os<<"s390_MSubF32";
		return os;

	case Iop_ScaleF64:
		os<<"ScaleF64";
		return os;
	case Iop_AtanF64:
		os<<"AtanF64";
		return os;
	case Iop_Yl2xF64:
		os<<"Yl2xF64";
		return os;
	case Iop_Yl2xp1F64:
		os<<"Yl2xp1F64";
		return os;
	case Iop_PRemF64:
		os<<"PRemF64";
		return os;
	case Iop_PRemC3210F64:
		os<<"PRemC3210F64";
		return os;
	case Iop_PRem1F64:
		os<<"PRem1F64";
		return os;
	case Iop_PRem1C3210F64:
		os<<"PRem1C3210F64";
		return os;
	case Iop_NegF64:
		os<<"NegF64";
		return os;
	case Iop_AbsF64:
		os<<"AbsF64";
		return os;
	case Iop_NegF32:
		os<<"NegF32";
		return os;
	case Iop_AbsF32:
		os<<"AbsF32";
		return os;
	case Iop_SqrtF64:
		os<<"SqrtF64";
		return os;
	case Iop_SqrtF32:
		os<<"SqrtF32";
		return os;
	case Iop_SinF64:
		os<<"SinF64";
		return os;
	case Iop_CosF64:
		os<<"CosF64";
		return os;
	case Iop_TanF64:
		os<<"TanF64";
		return os;
	case Iop_2xm1F64:
		os<<"2xm1F64";
		return os;

	case Iop_MAddF64:
		os<<"MAddF64";
		return os;
	case Iop_MSubF64:
		os<<"MSubF64";
		return os;
	case Iop_MAddF64r32:
		os<<"MAddF64r32";
		return os;
	case Iop_MSubF64r32:
		os<<"MSubF64r32";
		return os;

	case Iop_RSqrtEst5GoodF64:
		os<<"RSqrtEst5GoodF64";
		return os;
	case Iop_RoundF64toF64_NEAREST:
		os<<"RoundF64toF64_NEAREST";
		return os;
	case Iop_RoundF64toF64_NegINF:
		os<<"RoundF64toF64_NegINF";
		return os;
	case Iop_RoundF64toF64_PosINF:
		os<<"RoundF64toF64_PosINF";
		return os;
	case Iop_RoundF64toF64_ZERO:
		os<<"RoundF64toF64_ZERO";
		return os;

	case Iop_TruncF64asF32:
		os<<"TruncF64asF32";
		return os;

	case Iop_RecpExpF64:
		os<<"RecpExpF64";
		return os;
	case Iop_RecpExpF32:
		os<<"RecpExpF32";
		return os;

	case Iop_MaxNumF64:
		os<<"MaxNumF64";
		return os;
	case Iop_MinNumF64:
		os<<"MinNumF64";
		return os;
	case Iop_MaxNumF32:
		os<<"MaxNumF32";
		return os;
	case Iop_MinNumF32:
		os<<"MinNumF32";
		return os;

	case Iop_F16toF64:
		os<<"F16toF64";
		return os;
	case Iop_F64toF16:
		os<<"F64toF16";
		return os;
	case Iop_F16toF32:
		os<<"F16toF32";
		return os;
	case Iop_F32toF16:
		os<<"F32toF16";
		return os;

	case Iop_QAdd32S:
		os<<"QAdd32S";
		return os;
	case Iop_QSub32S:
		os<<"QSub32S";
		return os;
	case Iop_Add16x2:
		os<<"Add16x2";
		return os;
	case Iop_Sub16x2:
		os<<"Sub16x2";
		return os;
	case Iop_QAdd16Sx2:
		os<<"QAdd16Sx2";
		return os;
	case Iop_QAdd16Ux2:
		os<<"QAdd16Ux2";
		return os;
	case Iop_QSub16Sx2:
		os<<"QSub16Sx2";
		return os;
	case Iop_QSub16Ux2:
		os<<"QSub16Ux2";
		return os;
	case Iop_HAdd16Ux2:
		os<<"HAdd16Ux2";
		return os;
	case Iop_HAdd16Sx2:
		os<<"HAdd16Sx2";
		return os;
	case Iop_HSub16Ux2:
		os<<"HSub16Ux2";
		return os;
	case Iop_HSub16Sx2:
		os<<"HSub16Sx2";
		return os;

	case Iop_Add8x4:
		os<<"Add8x4";
		return os;
	case Iop_Sub8x4:
		os<<"Sub8x4";
		return os;
	case Iop_QAdd8Sx4:
		os<<"QAdd8Sx4";
		return os;
	case Iop_QAdd8Ux4:
		os<<"QAdd8Ux4";
		return os;
	case Iop_QSub8Sx4:
		os<<"QSub8Sx4";
		return os;
	case Iop_QSub8Ux4:
		os<<"QSub8Ux4";
		return os;
	case Iop_HAdd8Ux4:
		os<<"HAdd8Ux4";
		return os;
	case Iop_HAdd8Sx4:
		os<<"HAdd8Sx4";
		return os;
	case Iop_HSub8Ux4:
		os<<"HSub8Ux4";
		return os;
	case Iop_HSub8Sx4:
		os<<"HSub8Sx4";
		return os;
	case Iop_Sad8Ux4:
		os<<"Sad8Ux4";
		return os;

	case Iop_CmpNEZ16x2:
		os<<"CmpNEZ16x2";
		return os;
	case Iop_CmpNEZ8x4:
		os<<"CmpNEZ8x4";
		return os;

	case Iop_CmpF64:
		os<<"CmpF64";
		return os;

	case Iop_F64toI16S:
		os<<"F64toI16S";
		return os;
	case Iop_F64toI32S:
		os<<"F64toI32S";
		return os;
	case Iop_F64toI64S:
		os<<"F64toI64S";
		return os;
	case Iop_F64toI64U:
		os<<"F64toI64U";
		return os;
	case Iop_F32toI32U:
		os<<"F32toI32U";
		return os;
	case Iop_F32toI64U:
		os<<"F32toI64U";
		return os;

	case Iop_F64toI32U:
		os<<"F64toI32U";
		return os;

	case Iop_I32StoF64:
		os<<"I32StoF64";
		return os;
	case Iop_I64StoF64:
		os<<"I64StoF64";
		return os;
	case Iop_I64UtoF64:
		os<<"I64UtoF64";
		return os;
	case Iop_I32UtoF32:
		os<<"I32UtoF32";
		return os;
	case Iop_I64UtoF32:
		os<<"I64UtoF32";
		return os;

	case Iop_I32UtoF64:
		os<<"I32UtoF64";
		return os;

	case Iop_F32toF64:
		os<<"F32toF64";
		return os;
	case Iop_F64toF32:
		os<<"F64toF32";
		return os;

	case Iop_RoundF128toInt:
		os<<"RoundF128toInt";
		return os;
	case Iop_RoundF64toInt:
		os<<"RoundF64toInt";
		return os;
	case Iop_RoundF32toInt:
		os<<"RoundF32toInt";
		return os;
	case Iop_RoundF64toF32:
		os<<"RoundF64toF32";
		return os;

	case Iop_ReinterpF64asI64:
		os<<"ReinterpF64asI64";
		return os;
	case Iop_ReinterpI64asF64:
		os<<"ReinterpI64asF64";
		return os;
	case Iop_ReinterpF32asI32:
		os<<"ReinterpF32asI32";
		return os;
	case Iop_ReinterpI32asF32:
		os<<"ReinterpI32asF32";
		return os;

	case Iop_I32UtoFx4:
		os<<"I32UtoFx4";
		return os;
	case Iop_I32StoFx4:
		os<<"I32StoFx4";
		return os;

	case Iop_F32toF16x4:
		os<<"F32toF16x4";
		return os;
	case Iop_F16toF32x4:
		os<<"F16toF32x4";
		return os;
	case Iop_F16toF64x2:
		os<<"F16toF64x2";
		return os;
	case Iop_F64toF16x2:
		os<<"F64toF16x2";
		return os;

	case Iop_RSqrtEst32Fx4:
		os<<"RSqrtEst32Fx4";
		return os;
	case Iop_RSqrtEst32Ux4:
		os<<"RSqrtEst32Ux4";
		return os;
	case Iop_RSqrtEst32Fx2:
		os<<"RSqrtEst32Fx2";
		return os;
	case Iop_RSqrtEst32Ux2:
		os<<"RSqrtEst32Ux2";
		return os;

	case Iop_QFtoI32Ux4_RZ:
		os<<"QFtoI32Ux4_RZ";
		return os;
	case Iop_QFtoI32Sx4_RZ:
		os<<"QFtoI32Sx4_RZ";
		return os;

	case Iop_FtoI32Ux4_RZ:
		os<<"FtoI32Ux4_RZ";
		return os;
	case Iop_FtoI32Sx4_RZ:
		os<<"FtoI32Sx4_RZ";
		return os;

	case Iop_I32UtoFx2:
		os<<"I32UtoFx2";
		return os;
	case Iop_I32StoFx2:
		os<<"I32StoFx2";
		return os;

	case Iop_FtoI32Ux2_RZ:
		os<<"FtoI32Ux2_RZ";
		return os;
	case Iop_FtoI32Sx2_RZ:
		os<<"FtoI32Sx2_RZ";
		return os;

	case Iop_RoundF32x4_RM:
		os<<"RoundF32x4_RM";
		return os;
	case Iop_RoundF32x4_RP:
		os<<"RoundF32x4_RP";
		return os;
	case Iop_RoundF32x4_RN:
		os<<"RoundF32x4_RN";
		return os;
	case Iop_RoundF32x4_RZ:
		os<<"RoundF32x4_RZ";
		return os;

	case Iop_Abs8x8:
		os<<"Abs8x8";
		return os;
	case Iop_Abs16x4:
		os<<"Abs16x4";
		return os;
	case Iop_Abs32x2:
		os<<"Abs32x2";
		return os;
	case Iop_Add8x8:
		os<<"Add8x8";
		return os;
	case Iop_Add16x4:
		os<<"Add16x4";
		return os;
	case Iop_Add32x2:
		os<<"Add32x2";
		return os;
	case Iop_QAdd8Ux8:
		os<<"QAdd8Ux8";
		return os;
	case Iop_QAdd16Ux4:
		os<<"QAdd16Ux4";
		return os;
	case Iop_QAdd32Ux2:
		os<<"QAdd32Ux2";
		return os;
	case Iop_QAdd64Ux1:
		os<<"QAdd64Ux1";
		return os;
	case Iop_QAdd8Sx8:
		os<<"QAdd8Sx8";
		return os;
	case Iop_QAdd16Sx4:
		os<<"QAdd16Sx4";
		return os;
	case Iop_QAdd32Sx2:
		os<<"QAdd32Sx2";
		return os;
	case Iop_QAdd64Sx1:
		os<<"QAdd64Sx1";
		return os;
	case Iop_PwAdd8x8:
		os<<"PwAdd8x8";
		return os;
	case Iop_PwAdd16x4:
		os<<"PwAdd16x4";
		return os;
	case Iop_PwAdd32x2:
		os<<"PwAdd32x2";
		return os;
	case Iop_PwAdd32Fx2:
		os<<"PwAdd32Fx2";
		return os;
	case Iop_PwAddL8Ux8:
		os<<"PwAddL8Ux8";
		return os;
	case Iop_PwAddL16Ux4:
		os<<"PwAddL16Ux4";
		return os;
	case Iop_PwAddL32Ux2:
		os<<"PwAddL32Ux2";
		return os;
	case Iop_PwAddL8Sx8:
		os<<"PwAddL8Sx8";
		return os;
	case Iop_PwAddL16Sx4:
		os<<"PwAddL16Sx4";
		return os;
	case Iop_PwAddL32Sx2:
		os<<"PwAddL32Sx2";
		return os;
	case Iop_Sub8x8:
		os<<"Sub8x8";
		return os;
	case Iop_Sub16x4:
		os<<"Sub16x4";
		return os;
	case Iop_Sub32x2:
		os<<"Sub32x2";
		return os;
	case Iop_QSub8Ux8:
		os<<"QSub8Ux8";
		return os;
	case Iop_QSub16Ux4:
		os<<"QSub16Ux4";
		return os;
	case Iop_QSub32Ux2:
		os<<"QSub32Ux2";
		return os;
	case Iop_QSub64Ux1:
		os<<"QSub64Ux1";
		return os;
	case Iop_QSub8Sx8:
		os<<"QSub8Sx8";
		return os;
	case Iop_QSub16Sx4:
		os<<"QSub16Sx4";
		return os;
	case Iop_QSub32Sx2:
		os<<"QSub32Sx2";
		return os;
	case Iop_QSub64Sx1:
		os<<"QSub64Sx1";
		return os;
	case Iop_Mul8x8:
		os<<"Mul8x8";
		return os;
	case Iop_Mul16x4:
		os<<"Mul16x4";
		return os;
	case Iop_Mul32x2:
		os<<"Mul32x2";
		return os;
	case Iop_Mul32Fx2:
		os<<"Mul32Fx2";
		return os;
	case Iop_PolynomialMul8x8:
		os<<"PolynomialMul8x8";
		return os;
	case Iop_MulHi16Ux4:
		os<<"MulHi16Ux4";
		return os;
	case Iop_MulHi16Sx4:
		os<<"MulHi16Sx4";
		return os;
	case Iop_QDMulHi16Sx4:
		os<<"QDMulHi16Sx4";
		return os;
	case Iop_QDMulHi32Sx2:
		os<<"QDMulHi32Sx2";
		return os;
	case Iop_QRDMulHi16Sx4:
		os<<"QRDMulHi16Sx4";
		return os;
	case Iop_QRDMulHi32Sx2:
		os<<"QRDMulHi32Sx2";
		return os;
	case Iop_QDMull16Sx4:
		os<<"QDMull16Sx4";
		return os;
	case Iop_QDMull32Sx2:
		os<<"QDMull32Sx2";
		return os;
	case Iop_Avg8Ux8:
		os<<"Avg8Ux8";
		return os;
	case Iop_Avg16Ux4:
		os<<"Avg16Ux4";
		return os;
	case Iop_Max8Sx8:
		os<<"Max8Sx8";
		return os;
	case Iop_Max16Sx4:
		os<<"Max16Sx4";
		return os;
	case Iop_Max32Sx2:
		os<<"Max32Sx2";
		return os;
	case Iop_Max8Ux8:
		os<<"Max8Ux8";
		return os;
	case Iop_Max16Ux4:
		os<<"Max16Ux4";
		return os;
	case Iop_Max32Ux2:
		os<<"Max32Ux2";
		return os;
	case Iop_Min8Sx8:
		os<<"Min8Sx8";
		return os;
	case Iop_Min16Sx4:
		os<<"Min16Sx4";
		return os;
	case Iop_Min32Sx2:
		os<<"Min32Sx2";
		return os;
	case Iop_Min8Ux8:
		os<<"Min8Ux8";
		return os;
	case Iop_Min16Ux4:
		os<<"Min16Ux4";
		return os;
	case Iop_Min32Ux2:
		os<<"Min32Ux2";
		return os;
	case Iop_PwMax8Sx8:
		os<<"PwMax8Sx8";
		return os;
	case Iop_PwMax16Sx4:
		os<<"PwMax16Sx4";
		return os;
	case Iop_PwMax32Sx2:
		os<<"PwMax32Sx2";
		return os;
	case Iop_PwMax8Ux8:
		os<<"PwMax8Ux8";
		return os;
	case Iop_PwMax16Ux4:
		os<<"PwMax16Ux4";
		return os;
	case Iop_PwMax32Ux2:
		os<<"PwMax32Ux2";
		return os;
	case Iop_PwMin8Sx8:
		os<<"PwMin8Sx8";
		return os;
	case Iop_PwMin16Sx4:
		os<<"PwMin16Sx4";
		return os;
	case Iop_PwMin32Sx2:
		os<<"PwMin32Sx2";
		return os;
	case Iop_PwMin8Ux8:
		os<<"PwMin8Ux8";
		return os;
	case Iop_PwMin16Ux4:
		os<<"PwMin16Ux4";
		return os;
	case Iop_PwMin32Ux2:
		os<<"PwMin32Ux2";
		return os;
	case Iop_CmpEQ8x8:
		os<<"CmpEQ8x8";
		return os;
	case Iop_CmpEQ16x4:
		os<<"CmpEQ16x4";
		return os;
	case Iop_CmpEQ32x2:
		os<<"CmpEQ32x2";
		return os;
	case Iop_CmpGT8Ux8:
		os<<"CmpGT8Ux8";
		return os;
	case Iop_CmpGT16Ux4:
		os<<"CmpGT16Ux4";
		return os;
	case Iop_CmpGT32Ux2:
		os<<"CmpGT32Ux2";
		return os;
	case Iop_CmpGT8Sx8:
		os<<"CmpGT8Sx8";
		return os;
	case Iop_CmpGT16Sx4:
		os<<"CmpGT16Sx4";
		return os;
	case Iop_CmpGT32Sx2:
		os<<"CmpGT32Sx2";
		return os;
	case Iop_Cnt8x8:
		os<<"Cnt8x8";
		return os;
	case Iop_Clz8x8:
		os<<"Clz8x8";
		return os;
	case Iop_Clz16x4:
		os<<"Clz16x4";
		return os;
	case Iop_Clz32x2:
		os<<"Clz32x2";
		return os;
	case Iop_Cls8x8:
		os<<"Cls8x8";
		return os;
	case Iop_Cls16x4:
		os<<"Cls16x4";
		return os;
	case Iop_Cls32x2:
		os<<"Cls32x2";
		return os;
	case Iop_ShlN8x8:
		os<<"ShlN8x8";
		return os;
	case Iop_ShlN16x4:
		os<<"ShlN16x4";
		return os;
	case Iop_ShlN32x2:
		os<<"ShlN32x2";
		return os;
	case Iop_ShrN8x8:
		os<<"ShrN8x8";
		return os;
	case Iop_ShrN16x4:
		os<<"ShrN16x4";
		return os;
	case Iop_ShrN32x2:
		os<<"ShrN32x2";
		return os;
	case Iop_SarN8x8:
		os<<"SarN8x8";
		return os;
	case Iop_SarN16x4:
		os<<"SarN16x4";
		return os;
	case Iop_SarN32x2:
		os<<"SarN32x2";
		return os;
	case Iop_QNarrowBin16Sto8Ux8:
		os<<"QNarrowBin16Sto8Ux8";
		return os;
	case Iop_QNarrowBin16Sto8Sx8:
		os<<"QNarrowBin16Sto8Sx8";
		return os;
	case Iop_QNarrowBin32Sto16Sx4:
		os<<"QNarrowBin32Sto16Sx4";
		return os;
	case Iop_QNarrowBin64Sto32Sx4:
		os<<"QNarrowBin64Sto32Sx4";
		return os;
	case Iop_QNarrowBin64Uto32Ux4:
		os<<"QNarrowBin64Uto32Ux4";
		return os;
	case Iop_NarrowBin16to8x8:
		os<<"NarrowBin16to8x8";
		return os;
	case Iop_NarrowBin32to16x4:
		os<<"NarrowBin32to16x4";
		return os;
	case Iop_NarrowBin64to32x4:
		os<<"NarrowBin64to32x4";
		return os;
	case Iop_InterleaveHI8x8:
		os<<"InterleaveHI8x8";
		return os;
	case Iop_InterleaveHI16x4:
		os<<"InterleaveHI16x4";
		return os;
	case Iop_InterleaveHI32x2:
		os<<"InterleaveHI32x2";
		return os;
	case Iop_InterleaveLO8x8:
		os<<"InterleaveLO8x8";
		return os;
	case Iop_InterleaveLO16x4:
		os<<"InterleaveLO16x4";
		return os;
	case Iop_InterleaveLO32x2:
		os<<"InterleaveLO32x2";
		return os;
	case Iop_CatOddLanes8x8:
		os<<"CatOddLanes8x8";
		return os;
	case Iop_CatOddLanes16x4:
		os<<"CatOddLanes16x4";
		return os;
	case Iop_CatEvenLanes8x8:
		os<<"CatEvenLanes8x8";
		return os;
	case Iop_CatEvenLanes16x4:
		os<<"CatEvenLanes16x4";
		return os;
	case Iop_InterleaveOddLanes8x8:
		os<<"InterleaveOddLanes8x8";
		return os;
	case Iop_InterleaveOddLanes16x4:
		os<<"InterleaveOddLanes16x4";
		return os;
	case Iop_InterleaveEvenLanes8x8:
		os<<"InterleaveEvenLanes8x8";
		return os;
	case Iop_InterleaveEvenLanes16x4:
		os<<"InterleaveEvenLanes16x4";
		return os;
	case Iop_Shl8x8:
		os<<"Shl8x8";
		return os;
	case Iop_Shl16x4:
		os<<"Shl16x4";
		return os;
	case Iop_Shl32x2:
		os<<"Shl32x2";
		return os;
	case Iop_Shr8x8:
		os<<"Shr8x8";
		return os;
	case Iop_Shr16x4:
		os<<"Shr16x4";
		return os;
	case Iop_Shr32x2:
		os<<"Shr32x2";
		return os;
	case Iop_QShl8x8:
		os<<"QShl8x8";
		return os;
	case Iop_QShl16x4:
		os<<"QShl16x4";
		return os;
	case Iop_QShl32x2:
		os<<"QShl32x2";
		return os;
	case Iop_QShl64x1:
		os<<"QShl64x1";
		return os;
	case Iop_QSal8x8:
		os<<"QSal8x8";
		return os;
	case Iop_QSal16x4:
		os<<"QSal16x4";
		return os;
	case Iop_QSal32x2:
		os<<"QSal32x2";
		return os;
	case Iop_QSal64x1:
		os<<"QSal64x1";
		return os;
	case Iop_QShlNsatUU8x8:
		os<<"QShlNsatUU8x8";
		return os;
	case Iop_QShlNsatUU16x4:
		os<<"QShlNsatUU16x4";
		return os;
	case Iop_QShlNsatUU32x2:
		os<<"QShlNsatUU32x2";
		return os;
	case Iop_QShlNsatUU64x1:
		os<<"QShlNsatUU64x1";
		return os;
	case Iop_QShlNsatSU8x8:
		os<<"QShlNsatSU8x8";
		return os;
	case Iop_QShlNsatSU16x4:
		os<<"QShlNsatSU16x4";
		return os;
	case Iop_QShlNsatSU32x2:
		os<<"QShlNsatSU32x2";
		return os;
	case Iop_QShlNsatSU64x1:
		os<<"QShlNsatSU64x1";
		return os;
	case Iop_QShlNsatSS8x8:
		os<<"QShlNsatSS8x8";
		return os;
	case Iop_QShlNsatSS16x4:
		os<<"QShlNsatSS16x4";
		return os;
	case Iop_QShlNsatSS32x2:
		os<<"QShlNsatSS32x2";
		return os;
	case Iop_QShlNsatSS64x1:
		os<<"QShlNsatSS64x1";
		return os;
	case Iop_Sar8x8:
		os<<"Sar8x8";
		return os;
	case Iop_Sar16x4:
		os<<"Sar16x4";
		return os;
	case Iop_Sar32x2:
		os<<"Sar32x2";
		return os;
	case Iop_Sal8x8:
		os<<"Sal8x8";
		return os;
	case Iop_Sal16x4:
		os<<"Sal16x4";
		return os;
	case Iop_Sal32x2:
		os<<"Sal32x2";
		return os;
	case Iop_Sal64x1:
		os<<"Sal64x1";
		return os;
	case Iop_Perm8x8:
		os<<"Perm8x8";
		return os;
	case Iop_Reverse8sIn16_x4:
		os<<"Reverse8sIn16_x4";
		return os;
	case Iop_Reverse8sIn32_x2:
		os<<"Reverse8sIn32_x2";
		return os;
	case Iop_Reverse16sIn32_x2:
		os<<"Reverse16sIn32_x2";
		return os;
	case Iop_Reverse8sIn64_x1:
		os<<"Reverse8sIn64_x1";
		return os;
	case Iop_Reverse16sIn64_x1:
		os<<"Reverse16sIn64_x1";
		return os;
	case Iop_Reverse32sIn64_x1:
		os<<"Reverse32sIn64_x1";
		return os;
	case Iop_Abs32Fx2:
		os<<"Abs32Fx2";
		return os;
	case Iop_GetMSBs8x8:
		os<<"GetMSBs8x8";
		return os;
	case Iop_GetMSBs8x16:
		os<<"GetMSBs8x16";
		return os;

	case Iop_CmpNEZ32x2:
		os<<"CmpNEZ32x2";
		return os;
	case Iop_CmpNEZ16x4:
		os<<"CmpNEZ16x4";
		return os;
	case Iop_CmpNEZ8x8:
		os<<"CmpNEZ8x8";
		return os;

	case Iop_Add32Fx4:
		os<<"Add32Fx4";
		return os;
	case Iop_Add32Fx2:
		os<<"Add32Fx2";
		return os;
	case Iop_Add32F0x4:
		os<<"Add32F0x4";
		return os;
	case Iop_Add64Fx2:
		os<<"Add64Fx2";
		return os;
	case Iop_Add64F0x2:
		os<<"Add64F0x2";
		return os;

	case Iop_Div32Fx4:
		os<<"Div32Fx4";
		return os;
	case Iop_Div32F0x4:
		os<<"Div32F0x4";
		return os;
	case Iop_Div64Fx2:
		os<<"Div64Fx2";
		return os;
	case Iop_Div64F0x2:
		os<<"Div64F0x2";
		return os;

	case Iop_Max32Fx8:
		os<<"Max32Fx8";
		return os;
	case Iop_Max32Fx4:
		os<<"Max32Fx4";
		return os;
	case Iop_Max32Fx2:
		os<<"Max32Fx2";
		return os;
	case Iop_PwMax32Fx4:
		os<<"PwMax32Fx4";
		return os;
	case Iop_PwMax32Fx2:
		os<<"PwMax32Fx2";
		return os;
	case Iop_Max32F0x4:
		os<<"Max32F0x4";
		return os;
	case Iop_Max64Fx4:
		os<<"Max64Fx4";
		return os;
	case Iop_Max64Fx2:
		os<<"Max64Fx2";
		return os;
	case Iop_Max64F0x2:
		os<<"Max64F0x2";
		return os;

	case Iop_Min32Fx8:
		os<<"Min32Fx8";
		return os;
	case Iop_Min32Fx4:
		os<<"Min32Fx4";
		return os;
	case Iop_Min32Fx2:
		os<<"Min32Fx2";
		return os;
	case Iop_PwMin32Fx4:
		os<<"PwMin32Fx4";
		return os;
	case Iop_PwMin32Fx2:
		os<<"PwMin32Fx2";
		return os;
	case Iop_Min32F0x4:
		os<<"Min32F0x4";
		return os;
	case Iop_Min64Fx4:
		os<<"Min64Fx4";
		return os;
	case Iop_Min64Fx2:
		os<<"Min64Fx2";
		return os;
	case Iop_Min64F0x2:
		os<<"Min64F0x2";
		return os;

	case Iop_Mul32Fx4:
		os<<"Mul32Fx4";
		return os;
	case Iop_Mul32F0x4:
		os<<"Mul32F0x4";
		return os;
	case Iop_Mul64Fx2:
		os<<"Mul64Fx2";
		return os;
	case Iop_Mul64F0x2:
		os<<"Mul64F0x2";
		return os;

	case Iop_RecipEst32Ux2:
		os<<"RecipEst32Ux2";
		return os;
	case Iop_RecipEst32Fx2:
		os<<"RecipEst32Fx2";
		return os;
	case Iop_RecipEst32Fx4:
		os<<"RecipEst32Fx4";
		return os;
	case Iop_RecipEst32Fx8:
		os<<"RecipEst32Fx8";
		return os;
	case Iop_RecipEst32Ux4:
		os<<"RecipEst32Ux4";
		return os;
	case Iop_RecipEst32F0x4:
		os<<"RecipEst32F0x4";
		return os;
	case Iop_RecipStep32Fx2:
		os<<"RecipStep32Fx2";
		return os;
	case Iop_RecipStep32Fx4:
		os<<"RecipStep32Fx4";
		return os;
	case Iop_RecipEst64Fx2:
		os<<"RecipEst64Fx2";
		return os;
	case Iop_RecipStep64Fx2:
		os<<"RecipStep64Fx2";
		return os;

	case Iop_Abs32Fx4:
		os<<"Abs32Fx4";
		return os;
	case Iop_Abs64Fx2:
		os<<"Abs64Fx2";
		return os;
	case Iop_RSqrtStep32Fx4:
		os<<"RSqrtStep32Fx4";
		return os;
	case Iop_RSqrtStep64Fx2:
		os<<"RSqrtStep64Fx2";
		return os;
	case Iop_RSqrtStep32Fx2:
		os<<"RSqrtStep32Fx2";
		return os;
	case Iop_RSqrtEst64Fx2:
		os<<"RSqrtEst64Fx2";
		return os;

	case Iop_RSqrtEst32F0x4:
		os<<"RSqrtEst32F0x4";
		return os;
	case Iop_RSqrtEst32Fx8:
		os<<"RSqrtEst32Fx8";
		return os;

	case Iop_Sqrt32Fx4:
		os<<"Sqrt32Fx4";
		return os;
	case Iop_Sqrt32F0x4:
		os<<"Sqrt32F0x4";
		return os;
	case Iop_Sqrt64Fx2:
		os<<"Sqrt64Fx2";
		return os;
	case Iop_Sqrt64F0x2:
		os<<"Sqrt64F0x2";
		return os;
	case Iop_Sqrt32Fx8:
		os<<"Sqrt32Fx8";
		return os;
	case Iop_Sqrt64Fx4:
		os<<"Sqrt64Fx4";
		return os;

	case Iop_Sub32Fx4:
		os<<"Sub32Fx4";
		return os;
	case Iop_Sub32Fx2:
		os<<"Sub32Fx2";
		return os;
	case Iop_Sub32F0x4:
		os<<"Sub32F0x4";
		return os;
	case Iop_Sub64Fx2:
		os<<"Sub64Fx2";
		return os;
	case Iop_Sub64F0x2:
		os<<"Sub64F0x2";
		return os;

	case Iop_CmpEQ32Fx4:
		os<<"CmpEQ32Fx4";
		return os;
	case Iop_CmpLT32Fx4:
		os<<"CmpLT32Fx4";
		return os;
	case Iop_CmpLE32Fx4:
		os<<"CmpLE32Fx4";
		return os;
	case Iop_CmpGT32Fx4:
		os<<"CmpGT32Fx4";
		return os;
	case Iop_CmpGE32Fx4:
		os<<"CmpGE32Fx4";
		return os;
	case Iop_CmpUN32Fx4:
		os<<"CmpUN32Fx4";
		return os;
	case Iop_CmpEQ64Fx2:
		os<<"CmpEQ64Fx2";
		return os;
	case Iop_CmpLT64Fx2:
		os<<"CmpLT64Fx2";
		return os;
	case Iop_CmpLE64Fx2:
		os<<"CmpLE64Fx2";
		return os;
	case Iop_CmpUN64Fx2:
		os<<"CmpUN64Fx2";
		return os;
	case Iop_CmpGT32Fx2:
		os<<"CmpGT32Fx2";
		return os;
	case Iop_CmpEQ32Fx2:
		os<<"CmpEQ32Fx2";
		return os;
	case Iop_CmpGE32Fx2:
		os<<"CmpGE32Fx2";
		return os;

	case Iop_CmpEQ32F0x4:
		os<<"CmpEQ32F0x4";
		return os;
	case Iop_CmpLT32F0x4:
		os<<"CmpLT32F0x4";
		return os;
	case Iop_CmpLE32F0x4:
		os<<"CmpLE32F0x4";
		return os;
	case Iop_CmpUN32F0x4:
		os<<"CmpUN32F0x4";
		return os;
	case Iop_CmpEQ64F0x2:
		os<<"CmpEQ64F0x2";
		return os;
	case Iop_CmpLT64F0x2:
		os<<"CmpLT64F0x2";
		return os;
	case Iop_CmpLE64F0x2:
		os<<"CmpLE64F0x2";
		return os;
	case Iop_CmpUN64F0x2:
		os<<"CmpUN64F0x2";
		return os;

	case Iop_Neg64Fx2:
		os<<"Neg64Fx2";
		return os;
	case Iop_Neg32Fx4:
		os<<"Neg32Fx4";
		return os;
	case Iop_Neg32Fx2:
		os<<"Neg32Fx2";
		return os;

	case Iop_V128to64:
		os<<"V128to64";
		return os;
	case Iop_V128HIto64:
		os<<"V128HIto64";
		return os;
	case Iop_64HLtoV128:
		os<<"64HLtoV128";
		return os;

	case Iop_64UtoV128:
		os<<"64UtoV128";
		return os;
	case Iop_SetV128lo64:
		os<<"SetV128lo64";
		return os;

	case Iop_ZeroHI64ofV128:
		os<<"ZeroHI64ofV128";
		return os;
	case Iop_ZeroHI96ofV128:
		os<<"ZeroHI96ofV128";
		return os;
	case Iop_ZeroHI112ofV128:
		os<<"ZeroHI112ofV128";
		return os;
	case Iop_ZeroHI120ofV128:
		os<<"ZeroHI120ofV128";
		return os;

	case Iop_32UtoV128:
		os<<"32UtoV128";
		return os;
	case Iop_V128to32:
		os<<"V128to32";
		return os;
	case Iop_SetV128lo32:
		os<<"SetV128lo32";
		return os;

	case Iop_Dup8x16:
		os<<"Dup8x16";
		return os;
	case Iop_Dup16x8:
		os<<"Dup16x8";
		return os;
	case Iop_Dup32x4:
		os<<"Dup32x4";
		return os;
	case Iop_Dup8x8:
		os<<"Dup8x8";
		return os;
	case Iop_Dup16x4:
		os<<"Dup16x4";
		return os;
	case Iop_Dup32x2:
		os<<"Dup32x2";
		return os;

	case Iop_NotV128:
		os<<"NotV128";
		return os;
	case Iop_AndV128:
		os<<"AndV128";
		return os;
	case Iop_OrV128:
		os<<"OrV128";
		return os;
	case Iop_XorV128:
		os<<"XorV128";
		return os;

	case Iop_CmpNEZ8x16:
		os<<"CmpNEZ8x16";
		return os;
	case Iop_CmpNEZ16x8:
		os<<"CmpNEZ16x8";
		return os;
	case Iop_CmpNEZ32x4:
		os<<"CmpNEZ32x4";
		return os;
	case Iop_CmpNEZ64x2:
		os<<"CmpNEZ64x2";
		return os;
	case Iop_CmpNEZ128x1:
		os<<"CmpNEZ128x1";
		return os;

	case Iop_Abs8x16:
		os<<"Abs8x16";
		return os;
	case Iop_Abs16x8:
		os<<"Abs16x8";
		return os;
	case Iop_Abs32x4:
		os<<"Abs32x4";
		return os;
	case Iop_Abs64x2:
		os<<"Abs64x2";
		return os;

	case Iop_Add8x16:
		os<<"Add8x16";
		return os;
	case Iop_Add16x8:
		os<<"Add16x8";
		return os;
	case Iop_Add32x4:
		os<<"Add32x4";
		return os;
	case Iop_Add64x2:
		os<<"Add64x2";
		return os;
	case Iop_Add128x1:
		os<<"Add128x1";
		return os;
	case Iop_QAdd8Ux16:
		os<<"QAdd8Ux16";
		return os;
	case Iop_QAdd16Ux8:
		os<<"QAdd16Ux8";
		return os;
	case Iop_QAdd32Ux4:
		os<<"QAdd32Ux4";
		return os;
	case Iop_QAdd8Sx16:
		os<<"QAdd8Sx16";
		return os;
	case Iop_QAdd16Sx8:
		os<<"QAdd16Sx8";
		return os;
	case Iop_QAdd32Sx4:
		os<<"QAdd32Sx4";
		return os;
	case Iop_QAdd64Ux2:
		os<<"QAdd64Ux2";
		return os;
	case Iop_QAdd64Sx2:
		os<<"QAdd64Sx2";
		return os;

	case Iop_QAddExtUSsatSS8x16:
		os<<"QAddExtUSsatSS8x16";
		return os;
	case Iop_QAddExtUSsatSS16x8:
		os<<"QAddExtUSsatSS16x8";
		return os;
	case Iop_QAddExtUSsatSS32x4:
		os<<"QAddExtUSsatSS32x4";
		return os;
	case Iop_QAddExtUSsatSS64x2:
		os<<"QAddExtUSsatSS64x2";
		return os;
	case Iop_QAddExtSUsatUU8x16:
		os<<"QAddExtSUsatUU8x16";
		return os;
	case Iop_QAddExtSUsatUU16x8:
		os<<"QAddExtSUsatUU16x8";
		return os;
	case Iop_QAddExtSUsatUU32x4:
		os<<"QAddExtSUsatUU32x4";
		return os;
	case Iop_QAddExtSUsatUU64x2:
		os<<"QAddExtSUsatUU64x2";
		return os;

	case Iop_PwAdd8x16:
		os<<"PwAdd8x16";
		return os;
	case Iop_PwAdd16x8:
		os<<"PwAdd16x8";
		return os;
	case Iop_PwAdd32x4:
		os<<"PwAdd32x4";
		return os;
	case Iop_PwAddL8Ux16:
		os<<"PwAddL8Ux16";
		return os;
	case Iop_PwAddL16Ux8:
		os<<"PwAddL16Ux8";
		return os;
	case Iop_PwAddL32Ux4:
		os<<"PwAddL32Ux4";
		return os;
	case Iop_PwAddL64Ux2:
		os<<"PwAddL64Ux2";
		return os;
	case Iop_PwAddL8Sx16:
		os<<"PwAddL8Sx16";
		return os;
	case Iop_PwAddL16Sx8:
		os<<"PwAddL16Sx8";
		return os;
	case Iop_PwAddL32Sx4:
		os<<"PwAddL32Sx4";
		return os;

	case Iop_Sub8x16:
		os<<"Sub8x16";
		return os;
	case Iop_Sub16x8:
		os<<"Sub16x8";
		return os;
	case Iop_Sub32x4:
		os<<"Sub32x4";
		return os;
	case Iop_Sub64x2:
		os<<"Sub64x2";
		return os;
	case Iop_Sub128x1:
		os<<"Sub128x1";
		return os;
	case Iop_QSub8Ux16:
		os<<"QSub8Ux16";
		return os;
	case Iop_QSub16Ux8:
		os<<"QSub16Ux8";
		return os;
	case Iop_QSub32Ux4:
		os<<"QSub32Ux4";
		return os;
	case Iop_QSub8Sx16:
		os<<"QSub8Sx16";
		return os;
	case Iop_QSub16Sx8:
		os<<"QSub16Sx8";
		return os;
	case Iop_QSub32Sx4:
		os<<"QSub32Sx4";
		return os;
	case Iop_QSub64Ux2:
		os<<"QSub64Ux2";
		return os;
	case Iop_QSub64Sx2:
		os<<"QSub64Sx2";
		return os;

	case Iop_Mul8x16:
		os<<"Mul8x16";
		return os;
	case Iop_Mul16x8:
		os<<"Mul16x8";
		return os;
	case Iop_Mul32x4:
		os<<"Mul32x4";
		return os;
	case Iop_Mull8Ux8:
		os<<"Mull8Ux8";
		return os;
	case Iop_Mull8Sx8:
		os<<"Mull8Sx8";
		return os;
	case Iop_Mull16Ux4:
		os<<"Mull16Ux4";
		return os;
	case Iop_Mull16Sx4:
		os<<"Mull16Sx4";
		return os;
	case Iop_Mull32Ux2:
		os<<"Mull32Ux2";
		return os;
	case Iop_Mull32Sx2:
		os<<"Mull32Sx2";
		return os;
	case Iop_PolynomialMul8x16:
		os<<"PolynomialMul8x16";
		return os;
	case Iop_PolynomialMull8x8:
		os<<"PolynomialMull8x8";
		return os;
	case Iop_MulHi8Ux16:
		os<<"MulHi8Ux16";
		return os;
	case Iop_MulHi16Ux8:
		os<<"MulHi16Ux8";
		return os;
	case Iop_MulHi32Ux4:
		os<<"MulHi32Ux4";
		return os;
	case Iop_MulHi8Sx16:
		os<<"MulHi8Sx16";
		return os;
	case Iop_MulHi16Sx8:
		os<<"MulHi16Sx8";
		return os;
	case Iop_MulHi32Sx4:
		os<<"MulHi32Sx4";
		return os;
	case Iop_QDMulHi16Sx8:
		os<<"QDMulHi16Sx8";
		return os;
	case Iop_QDMulHi32Sx4:
		os<<"QDMulHi32Sx4";
		return os;
	case Iop_QRDMulHi16Sx8:
		os<<"QRDMulHi16Sx8";
		return os;
	case Iop_QRDMulHi32Sx4:
		os<<"QRDMulHi32Sx4";
		return os;

	case Iop_MullEven8Ux16:
		os<<"MullEven8Ux16";
		return os;
	case Iop_MullEven16Ux8:
		os<<"MullEven16Ux8";
		return os;
	case Iop_MullEven32Ux4:
		os<<"MullEven32Ux4";
		return os;
	case Iop_MullEven8Sx16:
		os<<"MullEven8Sx16";
		return os;
	case Iop_MullEven16Sx8:
		os<<"MullEven16Sx8";
		return os;
	case Iop_MullEven32Sx4:
		os<<"MullEven32Sx4";
		return os;

	case Iop_PolynomialMulAdd8x16:
		os<<"PolynomialMulAdd8x16";
		return os;
	case Iop_PolynomialMulAdd16x8:
		os<<"PolynomialMulAdd16x8";
		return os;
	case Iop_PolynomialMulAdd32x4:
		os<<"PolynomialMulAdd32x4";
		return os;
	case Iop_PolynomialMulAdd64x2:
		os<<"PolynomialMulAdd64x2";
		return os;

	case Iop_Avg8Ux16:
		os<<"Avg8Ux16";
		return os;
	case Iop_Avg16Ux8:
		os<<"Avg16Ux8";
		return os;
	case Iop_Avg32Ux4:
		os<<"Avg32Ux4";
		return os;
	case Iop_Avg64Ux2:
		os<<"Avg64Ux2";
		return os;
	case Iop_Avg8Sx16:
		os<<"Avg8Sx16";
		return os;
	case Iop_Avg16Sx8:
		os<<"Avg16Sx8";
		return os;
	case Iop_Avg32Sx4:
		os<<"Avg32Sx4";
		return os;
	case Iop_Avg64Sx2:
		os<<"Avg64Sx2";
		return os;

	case Iop_Max8Sx16:
		os<<"Max8Sx16";
		return os;
	case Iop_Max16Sx8:
		os<<"Max16Sx8";
		return os;
	case Iop_Max32Sx4:
		os<<"Max32Sx4";
		return os;
	case Iop_Max64Sx2:
		os<<"Max64Sx2";
		return os;
	case Iop_Max8Ux16:
		os<<"Max8Ux16";
		return os;
	case Iop_Max16Ux8:
		os<<"Max16Ux8";
		return os;
	case Iop_Max32Ux4:
		os<<"Max32Ux4";
		return os;
	case Iop_Max64Ux2:
		os<<"Max64Ux2";
		return os;

	case Iop_Min8Sx16:
		os<<"Min8Sx16";
		return os;
	case Iop_Min16Sx8:
		os<<"Min16Sx8";
		return os;
	case Iop_Min32Sx4:
		os<<"Min32Sx4";
		return os;
	case Iop_Min64Sx2:
		os<<"Min64Sx2";
		return os;
	case Iop_Min8Ux16:
		os<<"Min8Ux16";
		return os;
	case Iop_Min16Ux8:
		os<<"Min16Ux8";
		return os;
	case Iop_Min32Ux4:
		os<<"Min32Ux4";
		return os;
	case Iop_Min64Ux2:
		os<<"Min64Ux2";
		return os;

	case Iop_CmpEQ8x16:
		os<<"CmpEQ8x16";
		return os;
	case Iop_CmpEQ16x8:
		os<<"CmpEQ16x8";
		return os;
	case Iop_CmpEQ32x4:
		os<<"CmpEQ32x4";
		return os;
	case Iop_CmpEQ64x2:
		os<<"CmpEQ64x2";
		return os;
	case Iop_CmpGT8Sx16:
		os<<"CmpGT8Sx16";
		return os;
	case Iop_CmpGT16Sx8:
		os<<"CmpGT16Sx8";
		return os;
	case Iop_CmpGT32Sx4:
		os<<"CmpGT32Sx4";
		return os;
	case Iop_CmpGT64Sx2:
		os<<"CmpGT64Sx2";
		return os;
	case Iop_CmpGT8Ux16:
		os<<"CmpGT8Ux16";
		return os;
	case Iop_CmpGT16Ux8:
		os<<"CmpGT16Ux8";
		return os;
	case Iop_CmpGT32Ux4:
		os<<"CmpGT32Ux4";
		return os;
	case Iop_CmpGT64Ux2:
		os<<"CmpGT64Ux2";
		return os;

	case Iop_Cnt8x16:
		os<<"Cnt8x16";
		return os;
	case Iop_Clz8x16:
		os<<"Clz8x16";
		return os;
	case Iop_Clz16x8:
		os<<"Clz16x8";
		return os;
	case Iop_Clz32x4:
		os<<"Clz32x4";
		return os;
	case Iop_Clz64x2:
		os<<"Clz64x2";
		return os;
	case Iop_Cls8x16:
		os<<"Cls8x16";
		return os;
	case Iop_Cls16x8:
		os<<"Cls16x8";
		return os;
	case Iop_Cls32x4:
		os<<"Cls32x4";
		return os;
	case Iop_Ctz8x16:
		os<<"Iop_Ctz8x16";
		return os;
	case Iop_Ctz16x8:
		os<<"Iop_Ctz16x8";
		return os;
	case Iop_Ctz32x4:
		os<<"Iop_Ctz32x4";
		return os;
	case Iop_Ctz64x2:
		os<<"Iop_Ctz64x2";
		return os;

	case Iop_ShlV128:
		os<<"ShlV128";
		return os;
	case Iop_ShrV128:
		os<<"ShrV128";
		return os;
	case Iop_SarV128:
		os<<"SarV128";
		return os;

	case Iop_ShlN8x16:
		os<<"ShlN8x16";
		return os;
	case Iop_ShlN16x8:
		os<<"ShlN16x8";
		return os;
	case Iop_ShlN32x4:
		os<<"ShlN32x4";
		return os;
	case Iop_ShlN64x2:
		os<<"ShlN64x2";
		return os;
	case Iop_ShrN8x16:
		os<<"ShrN8x16";
		return os;
	case Iop_ShrN16x8:
		os<<"ShrN16x8";
		return os;
	case Iop_ShrN32x4:
		os<<"ShrN32x4";
		return os;
	case Iop_ShrN64x2:
		os<<"ShrN64x2";
		return os;
	case Iop_SarN8x16:
		os<<"SarN8x16";
		return os;
	case Iop_SarN16x8:
		os<<"SarN16x8";
		return os;
	case Iop_SarN32x4:
		os<<"SarN32x4";
		return os;
	case Iop_SarN64x2:
		os<<"SarN64x2";
		return os;

	case Iop_Shl8x16:
		os<<"Shl8x16";
		return os;
	case Iop_Shl16x8:
		os<<"Shl16x8";
		return os;
	case Iop_Shl32x4:
		os<<"Shl32x4";
		return os;
	case Iop_Shl64x2:
		os<<"Shl64x2";
		return os;
	case Iop_QSal8x16:
		os<<"QSal8x16";
		return os;
	case Iop_QSal16x8:
		os<<"QSal16x8";
		return os;
	case Iop_QSal32x4:
		os<<"QSal32x4";
		return os;
	case Iop_QSal64x2:
		os<<"QSal64x2";
		return os;
	case Iop_QShl8x16:
		os<<"QShl8x16";
		return os;
	case Iop_QShl16x8:
		os<<"QShl16x8";
		return os;
	case Iop_QShl32x4:
		os<<"QShl32x4";
		return os;
	case Iop_QShl64x2:
		os<<"QShl64x2";
		return os;
	case Iop_QShlNsatSS8x16:
		os<<"QShlNsatSS8x16";
		return os;
	case Iop_QShlNsatSS16x8:
		os<<"QShlNsatSS16x8";
		return os;
	case Iop_QShlNsatSS32x4:
		os<<"QShlNsatSS32x4";
		return os;
	case Iop_QShlNsatSS64x2:
		os<<"QShlNsatSS64x2";
		return os;
	case Iop_QShlNsatUU8x16:
		os<<"QShlNsatUU8x16";
		return os;
	case Iop_QShlNsatUU16x8:
		os<<"QShlNsatUU16x8";
		return os;
	case Iop_QShlNsatUU32x4:
		os<<"QShlNsatUU32x4";
		return os;
	case Iop_QShlNsatUU64x2:
		os<<"QShlNsatUU64x2";
		return os;
	case Iop_QShlNsatSU8x16:
		os<<"QShlNsatSU8x16";
		return os;
	case Iop_QShlNsatSU16x8:
		os<<"QShlNsatSU16x8";
		return os;
	case Iop_QShlNsatSU32x4:
		os<<"QShlNsatSU32x4";
		return os;
	case Iop_QShlNsatSU64x2:
		os<<"QShlNsatSU64x2";
		return os;
	case Iop_Shr8x16:
		os<<"Shr8x16";
		return os;
	case Iop_Shr16x8:
		os<<"Shr16x8";
		return os;
	case Iop_Shr32x4:
		os<<"Shr32x4";
		return os;
	case Iop_Shr64x2:
		os<<"Shr64x2";
		return os;
	case Iop_Sar8x16:
		os<<"Sar8x16";
		return os;
	case Iop_Sar16x8:
		os<<"Sar16x8";
		return os;
	case Iop_Sar32x4:
		os<<"Sar32x4";
		return os;
	case Iop_Sar64x2:
		os<<"Sar64x2";
		return os;
	case Iop_Sal8x16:
		os<<"Sal8x16";
		return os;
	case Iop_Sal16x8:
		os<<"Sal16x8";
		return os;
	case Iop_Sal32x4:
		os<<"Sal32x4";
		return os;
	case Iop_Sal64x2:
		os<<"Sal64x2";
		return os;
	case Iop_Rol8x16:
		os<<"Rol8x16";
		return os;
	case Iop_Rol16x8:
		os<<"Rol16x8";
		return os;
	case Iop_Rol32x4:
		os<<"Rol32x4";
		return os;
	case Iop_Rol64x2:
		os<<"Rol64x2";
		return os;

	case Iop_QandUQsh8x16:
		os<<"QandUQsh8x16";
		return os;
	case Iop_QandUQsh16x8:
		os<<"QandUQsh16x8";
		return os;
	case Iop_QandUQsh32x4:
		os<<"QandUQsh32x4";
		return os;
	case Iop_QandUQsh64x2:
		os<<"QandUQsh64x2";
		return os;
	case Iop_QandSQsh8x16:
		os<<"QandSQsh8x16";
		return os;
	case Iop_QandSQsh16x8:
		os<<"QandSQsh16x8";
		return os;
	case Iop_QandSQsh32x4:
		os<<"QandSQsh32x4";
		return os;
	case Iop_QandSQsh64x2:
		os<<"QandSQsh64x2";
		return os;
	case Iop_QandUQRsh8x16:
		os<<"QandUQRsh8x16";
		return os;
	case Iop_QandUQRsh16x8:
		os<<"QandUQRsh16x8";
		return os;
	case Iop_QandUQRsh32x4:
		os<<"QandUQRsh32x4";
		return os;
	case Iop_QandUQRsh64x2:
		os<<"QandUQRsh64x2";
		return os;
	case Iop_QandSQRsh8x16:
		os<<"QandSQRsh8x16";
		return os;
	case Iop_QandSQRsh16x8:
		os<<"QandSQRsh16x8";
		return os;
	case Iop_QandSQRsh32x4:
		os<<"QandSQRsh32x4";
		return os;
	case Iop_QandSQRsh64x2:
		os<<"QandSQRsh64x2";
		return os;

	case Iop_Sh8Sx16:
		os<<"Sh8Sx16";
		return os;
	case Iop_Sh16Sx8:
		os<<"Sh16Sx8";
		return os;
	case Iop_Sh32Sx4:
		os<<"Sh32Sx4";
		return os;
	case Iop_Sh64Sx2:
		os<<"Sh64Sx2";
		return os;
	case Iop_Sh8Ux16:
		os<<"Sh8Ux16";
		return os;
	case Iop_Sh16Ux8:
		os<<"Sh16Ux8";
		return os;
	case Iop_Sh32Ux4:
		os<<"Sh32Ux4";
		return os;
	case Iop_Sh64Ux2:
		os<<"Sh64Ux2";
		return os;
	case Iop_Rsh8Sx16:
		os<<"Rsh8Sx16";
		return os;
	case Iop_Rsh16Sx8:
		os<<"Rsh16Sx8";
		return os;
	case Iop_Rsh32Sx4:
		os<<"Rsh32Sx4";
		return os;
	case Iop_Rsh64Sx2:
		os<<"Rsh64Sx2";
		return os;
	case Iop_Rsh8Ux16:
		os<<"Rsh8Ux16";
		return os;
	case Iop_Rsh16Ux8:
		os<<"Rsh16Ux8";
		return os;
	case Iop_Rsh32Ux4:
		os<<"Rsh32Ux4";
		return os;
	case Iop_Rsh64Ux2:
		os<<"Rsh64Ux2";
		return os;

	case Iop_QandQShrNnarrow16Uto8Ux8:
		os<<"QandQShrNnarrow16Uto8Ux8";
		return os;
	case Iop_QandQShrNnarrow32Uto16Ux4:
		os<<"QandQShrNnarrow32Uto16Ux4";
		return os;
	case Iop_QandQShrNnarrow64Uto32Ux2:
		os<<"QandQShrNnarrow64Uto32Ux2";
		return os;
	case Iop_QandQSarNnarrow16Sto8Sx8:
		os<<"QandQSarNnarrow16Sto8Sx8";
		return os;
	case Iop_QandQSarNnarrow32Sto16Sx4:
		os<<"QandQSarNnarrow32Sto16Sx4";
		return os;
	case Iop_QandQSarNnarrow64Sto32Sx2:
		os<<"QandQSarNnarrow64Sto32Sx2";
		return os;
	case Iop_QandQSarNnarrow16Sto8Ux8:
		os<<"QandQSarNnarrow16Sto8Ux8";
		return os;
	case Iop_QandQSarNnarrow32Sto16Ux4:
		os<<"QandQSarNnarrow32Sto16Ux4";
		return os;
	case Iop_QandQSarNnarrow64Sto32Ux2:
		os<<"QandQSarNnarrow64Sto32Ux2";
		return os;
	case Iop_QandQRShrNnarrow16Uto8Ux8:
		os<<"QandQRShrNnarrow16Uto8Ux8";
		return os;
	case Iop_QandQRShrNnarrow32Uto16Ux4:
		os<<"QandQRShrNnarrow32Uto16Ux4";
		return os;
	case Iop_QandQRShrNnarrow64Uto32Ux2:
		os<<"QandQRShrNnarrow64Uto32Ux2";
		return os;
	case Iop_QandQRSarNnarrow16Sto8Sx8:
		os<<"QandQRSarNnarrow16Sto8Sx8";
		return os;
	case Iop_QandQRSarNnarrow32Sto16Sx4:
		os<<"QandQRSarNnarrow32Sto16Sx4";
		return os;
	case Iop_QandQRSarNnarrow64Sto32Sx2:
		os<<"QandQRSarNnarrow64Sto32Sx2";
		return os;
	case Iop_QandQRSarNnarrow16Sto8Ux8:
		os<<"QandQRSarNnarrow16Sto8Ux8";
		return os;
	case Iop_QandQRSarNnarrow32Sto16Ux4:
		os<<"QandQRSarNnarrow32Sto16Ux4";
		return os;
	case Iop_QandQRSarNnarrow64Sto32Ux2:
		os<<"QandQRSarNnarrow64Sto32Ux2";
		return os;

	case Iop_NarrowBin16to8x16:
		os<<"NarrowBin16to8x16";
		return os;
	case Iop_NarrowBin32to16x8:
		os<<"NarrowBin32to16x8";
		return os;
	case Iop_QNarrowBin16Uto8Ux16:
		os<<"QNarrowBin16Uto8Ux16";
		return os;
	case Iop_QNarrowBin32Sto16Ux8:
		os<<"QNarrowBin32Sto16Ux8";
		return os;
	case Iop_QNarrowBin16Sto8Ux16:
		os<<"QNarrowBin16Sto8Ux16";
		return os;
	case Iop_QNarrowBin32Uto16Ux8:
		os<<"QNarrowBin32Uto16Ux8";
		return os;
	case Iop_QNarrowBin16Sto8Sx16:
		os<<"QNarrowBin16Sto8Sx16";
		return os;
	case Iop_QNarrowBin32Sto16Sx8:
		os<<"QNarrowBin32Sto16Sx8";
		return os;
	case Iop_NarrowUn16to8x8:
		os<<"NarrowUn16to8x8";
		return os;
	case Iop_NarrowUn32to16x4:
		os<<"NarrowUn32to16x4";
		return os;
	case Iop_NarrowUn64to32x2:
		os<<"NarrowUn64to32x2";
		return os;
	case Iop_QNarrowUn16Uto8Ux8:
		os<<"QNarrowUn16Uto8Ux8";
		return os;
	case Iop_QNarrowUn32Uto16Ux4:
		os<<"QNarrowUn32Uto16Ux4";
		return os;
	case Iop_QNarrowUn64Uto32Ux2:
		os<<"QNarrowUn64Uto32Ux2";
		return os;
	case Iop_QNarrowUn16Sto8Sx8:
		os<<"QNarrowUn16Sto8Sx8";
		return os;
	case Iop_QNarrowUn32Sto16Sx4:
		os<<"QNarrowUn32Sto16Sx4";
		return os;
	case Iop_QNarrowUn64Sto32Sx2:
		os<<"QNarrowUn64Sto32Sx2";
		return os;
	case Iop_QNarrowUn16Sto8Ux8:
		os<<"QNarrowUn16Sto8Ux8";
		return os;
	case Iop_QNarrowUn32Sto16Ux4:
		os<<"QNarrowUn32Sto16Ux4";
		return os;
	case Iop_QNarrowUn64Sto32Ux2:
		os<<"QNarrowUn64Sto32Ux2";
		return os;
	case Iop_Widen8Uto16x8:
		os<<"Widen8Uto16x8";
		return os;
	case Iop_Widen16Uto32x4:
		os<<"Widen16Uto32x4";
		return os;
	case Iop_Widen32Uto64x2:
		os<<"Widen32Uto64x2";
		return os;
	case Iop_Widen8Sto16x8:
		os<<"Widen8Sto16x8";
		return os;
	case Iop_Widen16Sto32x4:
		os<<"Widen16Sto32x4";
		return os;
	case Iop_Widen32Sto64x2:
		os<<"Widen32Sto64x2";
		return os;

	case Iop_InterleaveHI8x16:
		os<<"InterleaveHI8x16";
		return os;
	case Iop_InterleaveHI16x8:
		os<<"InterleaveHI16x8";
		return os;
	case Iop_InterleaveHI32x4:
		os<<"InterleaveHI32x4";
		return os;
	case Iop_InterleaveHI64x2:
		os<<"InterleaveHI64x2";
		return os;
	case Iop_InterleaveLO8x16:
		os<<"InterleaveLO8x16";
		return os;
	case Iop_InterleaveLO16x8:
		os<<"InterleaveLO16x8";
		return os;
	case Iop_InterleaveLO32x4:
		os<<"InterleaveLO32x4";
		return os;
	case Iop_InterleaveLO64x2:
		os<<"InterleaveLO64x2";
		return os;

	case Iop_CatOddLanes8x16:
		os<<"CatOddLanes8x16";
		return os;
	case Iop_CatOddLanes16x8:
		os<<"CatOddLanes16x8";
		return os;
	case Iop_CatOddLanes32x4:
		os<<"CatOddLanes32x4";
		return os;
	case Iop_CatEvenLanes8x16:
		os<<"CatEvenLanes8x16";
		return os;
	case Iop_CatEvenLanes16x8:
		os<<"CatEvenLanes16x8";
		return os;
	case Iop_CatEvenLanes32x4:
		os<<"CatEvenLanes32x4";
		return os;

	case Iop_InterleaveOddLanes8x16:
		os<<"InterleaveOddLanes8x16";
		return os;
	case Iop_InterleaveOddLanes16x8:
		os<<"InterleaveOddLanes16x8";
		return os;
	case Iop_InterleaveOddLanes32x4:
		os<<"InterleaveOddLanes32x4";
		return os;
	case Iop_InterleaveEvenLanes8x16:
		os<<"InterleaveEvenLanes8x16";
		return os;
	case Iop_InterleaveEvenLanes16x8:
		os<<"InterleaveEvenLanes16x8";
		return os;
	case Iop_InterleaveEvenLanes32x4:
		os<<"InterleaveEvenLanes32x4";
		return os;

	case Iop_GetElem8x16:
		os<<"GetElem8x16";
		return os;
	case Iop_GetElem16x8:
		os<<"GetElem16x8";
		return os;
	case Iop_GetElem32x4:
		os<<"GetElem32x4";
		return os;
	case Iop_GetElem64x2:
		os<<"GetElem64x2";
		return os;

	case Iop_SetElem8x16:
		os<<"SetElem8x16";
		return os;
	case Iop_SetElem16x8:
		os<<"SetElem16x8";
		return os;
	case Iop_SetElem32x4:
		os<<"SetElem32x4";
		return os;
	case Iop_SetElem64x2:
		os<<"SetElem64x2";
		return os;

	case Iop_GetElem8x8:
		os<<"GetElem8x8";
		return os;
	case Iop_GetElem16x4:
		os<<"GetElem16x4";
		return os;
	case Iop_GetElem32x2:
		os<<"GetElem32x2";
		return os;
	case Iop_SetElem8x8:
		os<<"SetElem8x8";
		return os;
	case Iop_SetElem16x4:
		os<<"SetElem16x4";
		return os;
	case Iop_SetElem32x2:
		os<<"SetElem32x2";
		return os;

	case Iop_Slice64:
		os<<"Slice64";
		return os;
	case Iop_SliceV128:
		os<<"SliceV128";
		return os;

	case Iop_Perm8x16:
		os<<"Perm8x16";
		return os;
	case Iop_Perm32x4:
		os<<"Perm32x4";
		return os;
	case Iop_Perm8x16x2:
		os<<"Perm8x16x2";
		return os;
	case Iop_Reverse8sIn16_x8:
		os<<"Reverse8sIn16_x8";
		return os;
	case Iop_Reverse8sIn32_x4:
		os<<"Reverse8sIn32_x4";
		return os;
	case Iop_Reverse16sIn32_x4:
		os<<"Reverse16sIn32_x4";
		return os;
	case Iop_Reverse8sIn64_x2:
		os<<"Reverse8sIn64_x2";
		return os;
	case Iop_Reverse16sIn64_x2:
		os<<"Reverse16sIn64_x2";
		return os;
	case Iop_Reverse32sIn64_x2:
		os<<"Reverse32sIn64_x2";
		return os;
	case Iop_Reverse1sIn8_x16:
		os<<"Reverse1sIn8_x16";
		return os;

	case Iop_F32ToFixed32Ux4_RZ:
		os<<"F32ToFixed32Ux4_RZ";
		return os;
	case Iop_F32ToFixed32Sx4_RZ:
		os<<"F32ToFixed32Sx4_RZ";
		return os;
	case Iop_Fixed32UToF32x4_RN:
		os<<"Fixed32UToF32x4_RN";
		return os;
	case Iop_Fixed32SToF32x4_RN:
		os<<"Fixed32SToF32x4_RN";
		return os;
	case Iop_F32ToFixed32Ux2_RZ:
		os<<"F32ToFixed32Ux2_RZ";
		return os;
	case Iop_F32ToFixed32Sx2_RZ:
		os<<"F32ToFixed32Sx2_RZ";
		return os;
	case Iop_Fixed32UToF32x2_RN:
		os<<"Fixed32UToF32x2_RN";
		return os;
	case Iop_Fixed32SToF32x2_RN:
		os<<"Fixed32SToF32x2_RN";
		return os;

	case Iop_D32toD64:
		os<<"D32toD64";
		return os;
	case Iop_D64toD32:
		os<<"D64toD32";
		return os;
	case Iop_AddD64:
		os<<"AddD64";
		return os;
	case Iop_SubD64:
		os<<"SubD64";
		return os;
	case Iop_MulD64:
		os<<"MulD64";
		return os;
	case Iop_DivD64:
		os<<"DivD64";
		return os;
	case Iop_ShlD64:
		os<<"ShlD64";
		return os;
	case Iop_ShrD64:
		os<<"ShrD64";
		return os;
	case Iop_D64toI32S:
		os<<"D64toI32S";
		return os;
	case Iop_D64toI32U:
		os<<"D64toI32U";
		return os;
	case Iop_D64toI64S:
		os<<"D64toI64S";
		return os;
	case Iop_D64toI64U:
		os<<"D64toI64U";
		return os;
	case Iop_I32StoD64:
		os<<"I32StoD64";
		return os;
	case Iop_I32UtoD64:
		os<<"I32UtoD64";
		return os;
	case Iop_I64StoD64:
		os<<"I64StoD64";
		return os;
	case Iop_I64UtoD64:
		os<<"I64UtoD64";
		return os;
	case Iop_I32StoD128:
		os<<"I32StoD128";
		return os;
	case Iop_I32UtoD128:
		os<<"I32UtoD128";
		return os;
	case Iop_I64StoD128:
		os<<"I64StoD128";
		return os;
	case Iop_I64UtoD128:
		os<<"I64UtoD128";
		return os;
	case Iop_D64toD128:
		os<<"D64toD128";
		return os;
	case Iop_D128toD64:
		os<<"D128toD64";
		return os;
	case Iop_D128toI32S:
		os<<"D128toI32S";
		return os;
	case Iop_D128toI32U:
		os<<"D128toI32U";
		return os;
	case Iop_D128toI64S:
		os<<"D128toI64S";
		return os;
	case Iop_D128toI64U:
		os<<"D128toI64U";
		return os;
	case Iop_F32toD32:
		os<<"F32toD32";
		return os;
	case Iop_F32toD64:
		os<<"F32toD64";
		return os;
	case Iop_F32toD128:
		os<<"F32toD128";
		return os;
	case Iop_F64toD32:
		os<<"F64toD32";
		return os;
	case Iop_F64toD64:
		os<<"F64toD64";
		return os;
	case Iop_F64toD128:
		os<<"F64toD128";
		return os;
	case Iop_F128toD32:
		os<<"F128toD32";
		return os;
	case Iop_F128toD64:
		os<<"F128toD64";
		return os;
	case Iop_F128toD128:
		os<<"F128toD128";
		return os;
	case Iop_D32toF32:
		os<<"D32toF32";
		return os;
	case Iop_D32toF64:
		os<<"D32toF64";
		return os;
	case Iop_D32toF128:
		os<<"D32toF128";
		return os;
	case Iop_D64toF32:
		os<<"D64toF32";
		return os;
	case Iop_D64toF64:
		os<<"D64toF64";
		return os;
	case Iop_D64toF128:
		os<<"D64toF128";
		return os;
	case Iop_D128toF32:
		os<<"D128toF32";
		return os;
	case Iop_D128toF64:
		os<<"D128toF64";
		return os;
	case Iop_D128toF128:
		os<<"D128toF128";
		return os;
	case Iop_AddD128:
		os<<"AddD128";
		return os;
	case Iop_SubD128:
		os<<"SubD128";
		return os;
	case Iop_MulD128:
		os<<"MulD128";
		return os;
	case Iop_DivD128:
		os<<"DivD128";
		return os;
	case Iop_ShlD128:
		os<<"ShlD128";
		return os;
	case Iop_ShrD128:
		os<<"ShrD128";
		return os;
	case Iop_RoundD64toInt:
		os<<"RoundD64toInt";
		return os;
	case Iop_RoundD128toInt:
		os<<"RoundD128toInt";
		return os;
	case Iop_QuantizeD64:
		os<<"QuantizeD64";
		return os;
	case Iop_QuantizeD128:
		os<<"QuantizeD128";
		return os;
	case Iop_ExtractExpD64:
		os<<"ExtractExpD64";
		return os;
	case Iop_ExtractExpD128:
		os<<"ExtractExpD128";
		return os;
	case Iop_ExtractSigD64:
		os<<"ExtractSigD64";
		return os;
	case Iop_ExtractSigD128:
		os<<"ExtractSigD128";
		return os;
	case Iop_InsertExpD64:
		os<<"InsertExpD64";
		return os;
	case Iop_InsertExpD128:
		os<<"InsertExpD128";
		return os;
	case Iop_CmpD64:
		os<<"CmpD64";
		return os;
	case Iop_CmpD128:
		os<<"CmpD128";
		return os;
	case Iop_CmpExpD64:
		os<<"CmpExpD64";
		return os;
	case Iop_CmpExpD128:
		os<<"CmpExpD128";
		return os;
	case Iop_D64HLtoD128:
		os<<"D64HLtoD128";
		return os;
	case Iop_D128HItoD64:
		os<<"D128HItoD64";
		return os;
	case Iop_D128LOtoD64:
		os<<"D128LOtoD64";
		return os;
	case Iop_SignificanceRoundD64:
		os<<"SignificanceRoundD64";
		return os;
	case Iop_SignificanceRoundD128:
		os<<"SignificanceRoundD128";
		return os;
	case Iop_ReinterpI64asD64:
		os<<"ReinterpI64asD64";
		return os;
	case Iop_ReinterpD64asI64:
		os<<"ReinterpD64asI64";
		return os;
	case Iop_V256to64_0:
		os<<"V256to64_0";
		return os;
	case Iop_V256to64_1:
		os<<"V256to64_1";
		return os;
	case Iop_V256to64_2:
		os<<"V256to64_2";
		return os;
	case Iop_V256to64_3:
		os<<"V256to64_3";
		return os;
	case Iop_64x4toV256:
		os<<"64x4toV256";
		return os;
	case Iop_V256toV128_0:
		os<<"V256toV128_0";
		return os;
	case Iop_V256toV128_1:
		os<<"V256toV128_1";
		return os;
	case Iop_V128HLtoV256:
		os<<"V128HLtoV256";
		return os;
	case Iop_DPBtoBCD:
		os<<"DPBtoBCD";
		return os;
	case Iop_BCDtoDPB:
		os<<"BCDtoDPB";
		return os;
	case Iop_Add64Fx4:
		os<<"Add64Fx4";
		return os;
	case Iop_Sub64Fx4:
		os<<"Sub64Fx4";
		return os;
	case Iop_Mul64Fx4:
		os<<"Mul64Fx4";
		return os;
	case Iop_Div64Fx4:
		os<<"Div64Fx4";
		return os;
	case Iop_Add32Fx8:
		os<<"Add32Fx8";
		return os;
	case Iop_Sub32Fx8:
		os<<"Sub32Fx8";
		return os;
	case Iop_Mul32Fx8:
		os<<"Mul32Fx8";
		return os;
	case Iop_Div32Fx8:
		os<<"Div32Fx8";
		return os;
	case Iop_AndV256:
		os<<"AndV256";
		return os;
	case Iop_OrV256:
		os<<"OrV256";
		return os;
	case Iop_XorV256:
		os<<"XorV256";
		return os;
	case Iop_NotV256:
		os<<"NotV256";
		return os;
	case Iop_CmpNEZ64x4:
		os<<"CmpNEZ64x4";
		return os;
	case Iop_CmpNEZ32x8:
		os<<"CmpNEZ32x8";
		return os;
	case Iop_CmpNEZ16x16:
		os<<"CmpNEZ16x16";
		return os;
	case Iop_CmpNEZ8x32:
		os<<"CmpNEZ8x32";
		return os;

	case Iop_Add8x32:
		os<<"Add8x32";
		return os;
	case Iop_Add16x16:
		os<<"Add16x16";
		return os;
	case Iop_Add32x8:
		os<<"Add32x8";
		return os;
	case Iop_Add64x4:
		os<<"Add64x4";
		return os;
	case Iop_Sub8x32:
		os<<"Sub8x32";
		return os;
	case Iop_Sub16x16:
		os<<"Sub16x16";
		return os;
	case Iop_Sub32x8:
		os<<"Sub32x8";
		return os;
	case Iop_Sub64x4:
		os<<"Sub64x4";
		return os;
	case Iop_QAdd8Ux32:
		os<<"QAdd8Ux32";
		return os;
	case Iop_QAdd16Ux16:
		os<<"QAdd16Ux16";
		return os;
	case Iop_QAdd8Sx32:
		os<<"QAdd8Sx32";
		return os;
	case Iop_QAdd16Sx16:
		os<<"QAdd16Sx16";
		return os;
	case Iop_QSub8Ux32:
		os<<"QSub8Ux32";
		return os;
	case Iop_QSub16Ux16:
		os<<"QSub16Ux16";
		return os;
	case Iop_QSub8Sx32:
		os<<"QSub8Sx32";
		return os;
	case Iop_QSub16Sx16:
		os<<"QSub16Sx16";
		return os;

	case Iop_Mul16x16:
		os<<"Mul16x16";
		return os;
	case Iop_Mul32x8:
		os<<"Mul32x8";
		return os;
	case Iop_MulHi16Ux16:
		os<<"MulHi16Ux16";
		return os;
	case Iop_MulHi16Sx16:
		os<<"MulHi16Sx16";
		return os;

	case Iop_Avg8Ux32:
		os<<"Avg8Ux32";
		return os;
	case Iop_Avg16Ux16:
		os<<"Avg16Ux16";
		return os;

	case Iop_Max8Sx32:
		os<<"Max8Sx32";
		return os;
	case Iop_Max16Sx16:
		os<<"Max16Sx16";
		return os;
	case Iop_Max32Sx8:
		os<<"Max32Sx8";
		return os;
	case Iop_Max8Ux32:
		os<<"Max8Ux32";
		return os;
	case Iop_Max16Ux16:
		os<<"Max16Ux16";
		return os;
	case Iop_Max32Ux8:
		os<<"Max32Ux8";
		return os;

	case Iop_Min8Sx32:
		os<<"Min8Sx32";
		return os;
	case Iop_Min16Sx16:
		os<<"Min16Sx16";
		return os;
	case Iop_Min32Sx8:
		os<<"Min32Sx8";
		return os;
	case Iop_Min8Ux32:
		os<<"Min8Ux32";
		return os;
	case Iop_Min16Ux16:
		os<<"Min16Ux16";
		return os;
	case Iop_Min32Ux8:
		os<<"Min32Ux8";
		return os;

	case Iop_CmpEQ8x32:
		os<<"CmpEQ8x32";
		return os;
	case Iop_CmpEQ16x16:
		os<<"CmpEQ16x16";
		return os;
	case Iop_CmpEQ32x8:
		os<<"CmpEQ32x8";
		return os;
	case Iop_CmpEQ64x4:
		os<<"CmpEQ64x4";
		return os;
	case Iop_CmpGT8Sx32:
		os<<"CmpGT8Sx32";
		return os;
	case Iop_CmpGT16Sx16:
		os<<"CmpGT16Sx16";
		return os;
	case Iop_CmpGT32Sx8:
		os<<"CmpGT32Sx8";
		return os;
	case Iop_CmpGT64Sx4:
		os<<"CmpGT64Sx4";
		return os;

	case Iop_ShlN16x16:
		os<<"ShlN16x16";
		return os;
	case Iop_ShlN32x8:
		os<<"ShlN32x8";
		return os;
	case Iop_ShlN64x4:
		os<<"ShlN64x4";
		return os;
	case Iop_ShrN16x16:
		os<<"ShrN16x16";
		return os;
	case Iop_ShrN32x8:
		os<<"ShrN32x8";
		return os;
	case Iop_ShrN64x4:
		os<<"ShrN64x4";
		return os;
	case Iop_SarN16x16:
		os<<"SarN16x16";
		return os;
	case Iop_SarN32x8:
		os<<"SarN32x8";
		return os;

	case Iop_Perm32x8:
		os<<"Perm32x8";
		return os;

	case Iop_CipherV128:
		os<<"CipherV128";
		return os;
	case Iop_CipherLV128:
		os<<"CipherLV128";
		return os;
	case Iop_NCipherV128:
		os<<"NCipherV128";
		return os;
	case Iop_NCipherLV128:
		os<<"NCipherLV128";
		return os;
	case Iop_CipherSV128:
		os<<"CipherSV128";
		return os;

	case Iop_SHA256:
		os<<"SHA256";
		return os;
	case Iop_SHA512:
		os<<"SHA512";
		return os;
	case Iop_BCDAdd:
		os<<"BCDAdd";
		return os;
	case Iop_BCDSub:
		os<<"BCDSub";
		return os;
	case Iop_I128StoBCD128:
		os<<"bcdcfsq.";
		return os;
	case Iop_BCD128toI128S:
		os<<"bcdctsq.";
		return os;

	case Iop_PwBitMtxXpose64x2:
		os<<"BitMatrixTranspose64x2";
		return os;

	default:
		throw "ppIROp(1)";
	}

	assert(str);
	switch (op - base) {
	case 0:
		os<<str;
		os<<"8";
		break;
	case 1:
		os<<str;
		os<<"16";
		break;
	case 2:
		os<<str;
		os<<"32";
		break;
	case 3:
		os<<str;
		os<<"64";
		break;
	default:
		throw "ppIROp(2)";
	}

	return os;
}


}