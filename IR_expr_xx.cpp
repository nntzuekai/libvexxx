#include "IR_expr_xx.h"

#include <cassert>
#include <cstdint>
#include <cstring>
#include <iomanip>
#include <ostream>
#include <vector>

namespace libvexxx {

std::unique_ptr<IR_const_xx> IR_const_xx::from_c(const IRConst *s) {
	auto rtv = std::make_unique<IR_const_xx>();

	auto base = static_cast<IRConst *>(rtv.get());

	/// TODO:can I simply memcpy?
	std::memcpy(base, s, sizeof(IRConst));

	// *base=*s;

	return rtv;
}

std::unique_ptr<IR_callee_xx> IR_callee_xx::from_c(const IRCallee *ce) {
	auto ce2 = std::make_unique<IR_callee_xx>();
	ce2->regparms = ce->regparms;
	ce2->name = ce->name;
	ce2->addr = ce->addr;

	assert(ce->regparms >= 0 && ce->regparms <= 3);
	assert(ce->name != nullptr);
	assert(ce->addr != nullptr);

	ce2->mcx_mask = ce->mcx_mask;

	return ce2;
}

void copy_IRRegArray(IRRegArray *dst, const IRRegArray *src) {
	*dst = *src;

	assert(!(dst->base < 0 || dst->base > 10000));
	assert(!(dst->elemTy == Ity_I1));
	assert(!(dst->nElems <= 0 || dst->nElems > 500));
}

std::unique_ptr<IR_expr_xx> IR_expr_xx::from_c(const IRExpr *e) {
	switch (e->tag) {
	case Iex_Get:
		return ir_expr_types::get_R::from_c(e);
	case Iex_GetI:
		return ir_expr_types::get_I::from_c(e);
	case Iex_RdTmp:
		return ir_expr_types::rd_tmp::from_c(e);
	case Iex_Qop:
		return ir_expr_types::Q_op::from_c(e);
	case Iex_Triop:
		return ir_expr_types::tri_op::from_c(e);
	case Iex_Binop:
		return ir_expr_types::bin_op::from_c(e);
	case Iex_Unop:
		return ir_expr_types::un_op::from_c(e);
	case Iex_Load:
		return ir_expr_types::load::from_c(e);
	case Iex_Const:
		return ir_expr_types::constant::from_c(e);
	case Iex_CCall:
		return ir_expr_types::C_call::from_c(e);
	case Iex_ITE:
		return ir_expr_types::ITE::from_c(e);
	case Iex_VECRET:
		return ir_expr_types::VECRET::from_c(e);
	case Iex_GSPTR:
		return ir_expr_types::GSPTR::from_c(e);
	case Iex_Binder:
		return ir_expr_types::binder::from_c(e);
	default:
		throw "IR_expr_xx::from_c";
	}
}

namespace ir_expr_types {

std::unique_ptr<binder> binder::from_c(const IRExpr *e) {
	auto rtv = std::make_unique<binder>();

	rtv->tag = Iex_Binder;
	rtv->bd = e->Iex.Binder.binder;

	return rtv;
}

std::unique_ptr<get_R> get_R::from_c(const IRExpr *e) {
	auto rtv = std::make_unique<get_R>();

	rtv->tag = Iex_Get;
	rtv->offset = e->Iex.Get.offset;
	rtv->ty = IR_type_xx{e->Iex.Get.ty};

	return rtv;
}

std::unique_ptr<get_I> get_I::from_c(const IRExpr *e) {
	auto rtv = std::make_unique<get_I>();

	rtv->tag = Iex_GetI;
	copy_IRRegArray(&(rtv->descr), e->Iex.GetI.descr);
	rtv->ix = IR_expr_xx::from_c(e->Iex.GetI.ix);
	rtv->bias = e->Iex.GetI.bias;

	return rtv;
}

std::unique_ptr<rd_tmp> rd_tmp::from_c(const IRExpr *e) {
	auto rtv = std::make_unique<rd_tmp>();

	rtv->tag = Iex_RdTmp;
	rtv->tmp = IR_temp_xx{e->Iex.RdTmp.tmp};

	return rtv;
}

std::unique_ptr<Q_op> Q_op::from_c(const IRExpr *e) {
	auto rtv = std::make_unique<Q_op>();

	rtv->tag = Iex_Qop;

	auto *qop = e->Iex.Qop.details;
	rtv->op = IR_op_xx{qop->op};
	rtv->arg1 = IR_expr_xx::from_c(qop->arg1);
	rtv->arg2 = IR_expr_xx::from_c(qop->arg2);
	rtv->arg3 = IR_expr_xx::from_c(qop->arg3);
	rtv->arg4 = IR_expr_xx::from_c(qop->arg4);

	return rtv;
}

std::unique_ptr<tri_op> tri_op::from_c(const IRExpr *e) {
	auto rtv = std::make_unique<tri_op>();

	rtv->tag = Iex_Triop;

	auto *triop = e->Iex.Triop.details;
	rtv->op = IR_op_xx{triop->op};
	rtv->arg1 = IR_expr_xx::from_c(triop->arg1);
	rtv->arg2 = IR_expr_xx::from_c(triop->arg2);
	rtv->arg3 = IR_expr_xx::from_c(triop->arg3);

	return rtv;
}

std::unique_ptr<bin_op> bin_op::from_c(const IRExpr *e) {
	auto rtv = std::make_unique<bin_op>();

	rtv->tag = Iex_Binop;

	auto *binop = &(e->Iex.Binop);
	rtv->op = IR_op_xx{binop->op};
	rtv->arg1 = IR_expr_xx::from_c(binop->arg1);
	rtv->arg2 = IR_expr_xx::from_c(binop->arg2);

	return rtv;
}

std::unique_ptr<un_op> un_op::from_c(const IRExpr *e) {
	auto rtv = std::make_unique<un_op>();

	rtv->tag = Iex_Unop;

	rtv->op = IR_op_xx{e->Iex.Unop.op};
	rtv->arg = IR_expr_xx::from_c(e->Iex.Unop.arg);

	return rtv;
}

std::unique_ptr<load> load::from_c(const IRExpr *e) {
	auto rtv = std::make_unique<load>();

	rtv->tag = Iex_Load;
	rtv->end = IR_endness_xx{e->Iex.Load.end};
	rtv->ty = IR_type_xx{e->Iex.Load.ty};
	rtv->addr = IR_expr_xx::from_c(e->Iex.Load.addr);

	assert(rtv->end == IR_endness_xx::Iend_LE ||
	       rtv->end == IR_endness_xx::Iend_BE);

	return rtv;
}

std::unique_ptr<constant> constant::from_c(const IRExpr *e) {
	auto rtv = std::make_unique<constant>();

	rtv->tag = Iex_Const;
	rtv->con = IR_const_xx::from_c(e->Iex.Const.con);

	return rtv;
}

std::unique_ptr<C_call> C_call::from_c(const IRExpr *e) {
	auto rtv = std::make_unique<C_call>();

	rtv->tag = Iex_CCall;
	rtv->cee = IR_callee_xx::from_c(e->Iex.CCall.cee);
	rtv->ret_ty = IR_type_xx{e->Iex.CCall.retty};

	for (auto i = 0; e->Iex.CCall.args[i]; ++i) {
		rtv->args.push_back(IR_expr_xx::from_c(e->Iex.CCall.args[i]));
	}

	return rtv;
}

std::unique_ptr<ITE> ITE::from_c(const IRExpr *e) {
	auto rtv = std::make_unique<ITE>();

	rtv->tag = Iex_ITE;
	rtv->cond = IR_expr_xx::from_c(e->Iex.ITE.cond);
	rtv->if_true = IR_expr_xx::from_c(e->Iex.ITE.iftrue);
	rtv->if_false = IR_expr_xx::from_c(e->Iex.ITE.iffalse);

	return rtv;
}

std::unique_ptr<VECRET> VECRET::from_c(const IRExpr *e) {
	auto rtv = std::make_unique<VECRET>();

	rtv->tag = Iex_VECRET;

	return rtv;
}

std::unique_ptr<GSPTR> GSPTR::from_c(const IRExpr *e) {
	auto rtv = std::make_unique<GSPTR>();

	rtv->tag = Iex_GSPTR;

	return rtv;
}

} // namespace ir_expr_types

/*
std::ostream &operator<<(std::ostream &os, const IR_expr_xx &e) {
    return e.pretty_print(os);
}
*/

std::ostream &IR_callee_xx::pretty_print(std::ostream &os) const {
	os << name;
	if (regparms > 0) {
		os << "[rp=" << regparms << "]";
	}
	if (mcx_mask > 0) {
		os << "[mcx=0x" << std::hex << mcx_mask << std::dec << "]";
	}

	os << "{" << addr << "}";

	return os;
}

std::ostream &operator<<(std::ostream &os, const IR_callee_xx &cee) {
	cee.pretty_print(os);

	return os;
}

std::ostream &operator<<(std::ostream &os, const IRRegArray &arr) {
	os << "(" << arr.base << ":" << arr.nElems << "x" << arr.elemTy << ")";

	return os;
}

std::ostream &operator<<(std::ostream &os, const IR_const_xx &e) {
	e.pretty_print(os);

	return os;
}

std::ostream &IR_const_xx::pretty_print(std::ostream &os) const {
	switch (tag) {
	case Ico_U1:
		os << static_cast<unsigned>(Ico.U1) << ":I1";
		break;
	case Ico_U8:
		os << "0x" << std::hex << static_cast<uint8_t>(Ico.U8) << std::dec
		   << ":I8";
		break;
	case Ico_U16:
		os << "0x" << std::hex << static_cast<uint16_t>(Ico.U16) << std::dec
		   << ":I16";
		break;
	case Ico_U32:
		os << "0x" << std::hex << static_cast<uint32_t>(Ico.U32) << std::dec
		   << ":I32";
		break;
	case Ico_U64:
		os << "0x" << std::hex << static_cast<uint64_t>(Ico.U64) << std::dec
		   << ":I64";
		break;
	case Ico_F32:
		os << "F32{0x" << std::hex << Ico.F32i << std::dec << "," << Ico.F32
		   << "}";
		break;
	case Ico_F32i:
		os << "F32i{0x" << std::hex << Ico.F32i << std::dec << "}";
		break;
	case Ico_F64:
		os << "F64{0x" << std::hex << Ico.F64i << std::dec << "," << Ico.F64
		   << "}";
		break;
	case Ico_F64i:
		os << "F64i{0x" << std::hex << Ico.F64i << std::dec << "}";
		break;
	case Ico_V128:
		os << "V128{0x" << std::hex << Ico.V128 << std::dec << "}";
		break;
	case Ico_V256:
		os << "V256{0x" << std::hex << Ico.V256 << std::dec << "}";
		break;
	default:
		throw "ppIRConst";
	}

	return os;
}

namespace ir_expr_types {

std::ostream &binder::pretty_print(std::ostream &os, arch_type) const {
	os << "BIND-" << bd;
	return os;
}

std::ostream &get_R::pretty_print(std::ostream &os, arch_type arch) const {
	os << "GET:" << ty << "(";

	auto *name = guest_register_name(offset, arch);
	if (name) {
		os << name;
	} else {
		os << "%" << offset;
	}

	os << ")";
	return os;
}

std::ostream &get_I::pretty_print(std::ostream &os, arch_type arch) const {
	os << "GETI" << descr << "[";
	ix->pretty_print(os, arch);
	os << "," << bias << "]";
	return os;
}

std::ostream &rd_tmp::pretty_print(std::ostream &os, arch_type) const {
	os << tmp;
	return os;
}

std::ostream &Q_op::pretty_print(std::ostream &os, arch_type arch) const {
	os << op << "(";
	arg1->pretty_print(os, arch);
	os << ",";
	arg2->pretty_print(os, arch);
	os << ",";
	arg3->pretty_print(os, arch);
	os << ",";
	arg4->pretty_print(os, arch);
	os << ")";
	return os;
}

std::ostream &tri_op::pretty_print(std::ostream &os, arch_type arch) const {
	os << op << "(";
	arg1->pretty_print(os, arch);
	os << ",";
	arg2->pretty_print(os, arch);
	os << ",";
	arg3->pretty_print(os, arch);
	os << ")";
	return os;
}

std::ostream &bin_op::pretty_print(std::ostream &os, arch_type arch) const {
	os << op << "(";
	arg1->pretty_print(os, arch);
	os << ",";
	arg2->pretty_print(os, arch);
	os << ")";
	return os;
}

std::ostream &un_op::pretty_print(std::ostream &os, arch_type arch) const {
	os << op << "(";
	arg->pretty_print(os, arch);
	os << ")";
	return os;
}

std::ostream &load::pretty_print(std::ostream &os, arch_type arch) const {
	os << "LD" << end << ":" << ty << "(";
	addr->pretty_print(os, arch);
	os << ")";
	return os;
}

std::ostream &constant::pretty_print(std::ostream &os, arch_type) const {
	os << *con;
	return os;
}

std::ostream &C_call::pretty_print(std::ostream &os, arch_type arch) const {
	os << *cee << "(";
	for (auto &&arg : args) {
		arg->pretty_print(os, arch);
		os << ",";
	}
	os << "):" << ret_ty;
	return os;
}

std::ostream &ITE::pretty_print(std::ostream &os, arch_type arch) const {
	os << "ITE(";
	cond->pretty_print(os, arch);
	os << ",";
	if_true->pretty_print(os, arch);
	os << ",";
	if_false->pretty_print(os, arch);
	os << ")";
	return os;
}

std::ostream &VECRET::pretty_print(std::ostream &os, arch_type) const {
	os << "VECRET";
	return os;
}

std::ostream &GSPTR::pretty_print(std::ostream &os, arch_type) const {
	os << "GSPTR";
	return os;
}

} // namespace ir_expr_types

} // namespace libvexxx