#include "IR_enums.h"
#include <iostream>
#include <iomanip>

namespace libvexxx{

std::ostream &operator<<(std::ostream &os, IR_jump_kind_xx kind) {
	switch (kind) {
	case IR_jump_kind_xx::Ijk_Boring:
		os << "Boring";
		break;
	case IR_jump_kind_xx::Ijk_Call:
		os << "Call";
		break;
	case IR_jump_kind_xx::Ijk_Ret:
		os << "Return";
		break;
	case IR_jump_kind_xx::Ijk_ClientReq:
		os << "ClientReq";
		break;
	case IR_jump_kind_xx::Ijk_Yield:
		os << "Yield";
		break;
	case IR_jump_kind_xx::Ijk_EmWarn:
		os << "EmWarn";
		break;
	case IR_jump_kind_xx::Ijk_EmFail:
		os << "EmFail";
		break;
	case IR_jump_kind_xx::Ijk_NoDecode:
		os << "NoDecode";
		break;
	case IR_jump_kind_xx::Ijk_MapFail:
		os << "MapFail";
		break;
	case IR_jump_kind_xx::Ijk_InvalICache:
		os << "InvalICache";
		break;
	case IR_jump_kind_xx::Ijk_FlushDCache:
		os << "FlushDCache";
		break;
	case IR_jump_kind_xx::Ijk_NoRedir:
		os << "NoRedir";
		break;
	case IR_jump_kind_xx::Ijk_SigILL:
		os << "SigILL";
		break;
	case IR_jump_kind_xx::Ijk_SigTRAP:
		os << "SigTRAP";
		break;
	case IR_jump_kind_xx::Ijk_SigSEGV:
		os << "SigSEGV";
		break;
	case IR_jump_kind_xx::Ijk_SigBUS:
		os << "SigBUS";
		break;
	case IR_jump_kind_xx::Ijk_SigFPE:
		os << "SigFPE";
		break;
	case IR_jump_kind_xx::Ijk_SigFPE_IntDiv:
		os << "SigFPE_IntDiv";
		break;
	case IR_jump_kind_xx::Ijk_SigFPE_IntOvf:
		os << "SigFPE_IntOvf";
		break;
	case IR_jump_kind_xx::Ijk_Sys_syscall:
		os << "Sys_syscall";
		break;
	case IR_jump_kind_xx::Ijk_Sys_int32:
		os << "Sys_int32";
		break;
	case IR_jump_kind_xx::Ijk_Sys_int128:
		os << "Sys_int128";
		break;
	case IR_jump_kind_xx::Ijk_Sys_int129:
		os << "Sys_int129";
		break;
	case IR_jump_kind_xx::Ijk_Sys_int130:
		os << "Sys_int130";
		break;
	case IR_jump_kind_xx::Ijk_Sys_int145:
		os << "Sys_int145";
		break;
	case IR_jump_kind_xx::Ijk_Sys_int210:
		os << "Sys_int210";
		break;
	case IR_jump_kind_xx::Ijk_Sys_sysenter:
		os << "Sys_sysenter";
		break;
	default:
		throw "ppIRJumpKind";
	}

	return os;
}

std::ostream &operator<<(std::ostream &os, IR_type_xx ty) {
	switch (ty) {
	case IR_type_xx::Ity_INVALID:
		os << "Ity_INVALID";
		break;
	case IR_type_xx::Ity_I1:
		os << "I1";
		break;
	case IR_type_xx::Ity_I8:
		os << "I8";
		break;
	case IR_type_xx::Ity_I16:
		os << "I16";
		break;
	case IR_type_xx::Ity_I32:
		os << "I32";
		break;
	case IR_type_xx::Ity_I64:
		os << "I64";
		break;
	case IR_type_xx::Ity_I128:
		os << "I128";
		break;
	case IR_type_xx::Ity_F16:
		os << "F16";
		break;
	case IR_type_xx::Ity_F32:
		os << "F32";
		break;
	case IR_type_xx::Ity_F64:
		os << "F64";
		break;
	case IR_type_xx::Ity_F128:
		os << "F128";
		break;
	case IR_type_xx::Ity_D32:
		os << "D32";
		break;
	case IR_type_xx::Ity_D64:
		os << "D64";
		break;
	case IR_type_xx::Ity_D128:
		os << "D128";
		break;
	case IR_type_xx::Ity_V128:
		os << "V128";
		break;
	case IR_type_xx::Ity_V256:
		os << "V256";
		break;
	default:
		throw "ppIRType ty=" + std::to_string(static_cast<uint>(ty));
	}

	return os;
}


std::ostream &operator<<(std::ostream &os, IR_load_G_op_xx cvt) {
	switch (cvt) {
	case IR_load_G_op_xx::ILGop_INVALID:
		os << "ILGop_INVALID";
		break;
	case IR_load_G_op_xx::ILGop_IdentV128:
		os << "IdentV128";
		break;
	case IR_load_G_op_xx::ILGop_Ident64:
		os << "Ident64";
		break;
	case IR_load_G_op_xx::ILGop_Ident32:
		os << "Ident32";
		break;
	case IR_load_G_op_xx::ILGop_16Uto32:
		os << "16Uto32";
		break;
	case IR_load_G_op_xx::ILGop_16Sto32:
		os << "16Sto32";
		break;
	case IR_load_G_op_xx::ILGop_8Uto32:
		os << "8Uto32";
		break;
	case IR_load_G_op_xx::ILGop_8Sto32:
		os << "8Sto32";
		break;
	default:
		throw "ppIRLoadGOp";
	}

	return os;
}

std::ostream &operator<<(std::ostream &os, IR_endness_xx e) {
	os << ((e == IR_endness_xx::Iend_LE) ? "le" : "be");
	return os;
}


std::ostream &operator<<(std::ostream &os, IR_effect_xx fx) {
	switch (fx) {
	case IR_effect_xx::Ifx_None:
		os << "noFX";
		return os;
	case IR_effect_xx::Ifx_Read:
		os << "RdFX";
		return os;
	case IR_effect_xx::Ifx_Write:
		os << "WrFX";
		return os;
	case IR_effect_xx::Ifx_Modify:
		os << "MoFX";
		return os;
	default:
		throw "ppIREffect";
	}

	return os;
}

std::ostream &operator<<(std::ostream &os, IR_MBUS_event_xx eve) {
	switch (eve) {
	case IR_MBUS_event_xx::Imbe_Fence:
		os << "Fence";
		break;
	case IR_MBUS_event_xx::Imbe_CancelReservation:
		os << "CancelReservation";
		break;
	default:
		throw "ppIRMBusEvent";
	}

	return os;
}

std::ostream &operator<<(std::ostream &os, IR_temp_xx tmp){
	if(tmp==IR_temp_xx::invalid){
		os<<"IRTemp_INVALID";
	}
	else{
		os<<"t"<<static_cast<unsigned int>(tmp);
	}

	return os;
}

}