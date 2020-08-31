#include "IR_expr_xx.h"

#include <vector>
#include <cassert>
#include <cstring>

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
		return ir_expr_types::Get::from_c(e);
	case Iex_GetI:
		return ir_expr_types::Get_I::from_c(e);
	case Iex_RdTmp:
		return ir_expr_types::Rd_tmp::from_c(e);
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
		return ir_expr_types::Const::from_c(e);
	case Iex_CCall:
		return ir_expr_types::C_call::from_c(e);
	case Iex_ITE:
		return ir_expr_types::ITE::from_c(e);
	case Iex_VECRET:
		return ir_expr_types::VECRET::from_c(e);
	case Iex_GSPTR:
		return ir_expr_types::GSPTR::from_c(e);
	case Iex_Binder:
		return ir_expr_types::Binder::from_c(e);
	default:
		throw "IR_expr_xx::from_c";
	}
}

namespace ir_expr_types {

std::unique_ptr<Binder> Binder::from_c(const IRExpr *e) {
	auto rtv = std::make_unique<Binder>();

	rtv->tag = Iex_Binder;
	rtv->binder = e->Iex.Binder.binder;

	return rtv;
}

std::unique_ptr<Get> Get::from_c(const IRExpr *e) {
	auto rtv = std::make_unique<Get>();

	rtv->tag = Iex_Get;
	rtv->offset = e->Iex.Get.offset;
	rtv->ty = e->Iex.Get.ty;

	return rtv;
}

std::unique_ptr<Get_I> Get_I::from_c(const IRExpr *e) {
	auto rtv = std::make_unique<Get_I>();

	rtv->tag = Iex_GetI;
	copy_IRRegArray(&(rtv->descr), e->Iex.GetI.descr);
	rtv->ix = IR_expr_xx::from_c(e->Iex.GetI.ix);
	rtv->bias = e->Iex.GetI.bias;

	return rtv;
}

std::unique_ptr<Rd_tmp> Rd_tmp::from_c(const IRExpr *e) {
	auto rtv = std::make_unique<Rd_tmp>();

	rtv->tag = Iex_RdTmp;
	rtv->tmp = e->Iex.RdTmp.tmp;

	return rtv;
}

std::unique_ptr<Q_op> Q_op::from_c(const IRExpr *e) {
	auto rtv = std::make_unique<Q_op>();

	rtv->tag = Iex_Qop;

	auto *qop = e->Iex.Qop.details;
	rtv->op = qop->op;
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
	rtv->op = triop->op;
	rtv->arg1 = IR_expr_xx::from_c(triop->arg1);
	rtv->arg2 = IR_expr_xx::from_c(triop->arg2);
	rtv->arg3 = IR_expr_xx::from_c(triop->arg3);

	return rtv;
}

std::unique_ptr<bin_op> bin_op::from_c(const IRExpr *e) {
	auto rtv = std::make_unique<bin_op>();

	rtv->tag = Iex_Binop;

	auto *binop = &(e->Iex.Binop);
	rtv->op = binop->op;
	rtv->arg1 = IR_expr_xx::from_c(binop->arg1);
	rtv->arg2 = IR_expr_xx::from_c(binop->arg2);

	return rtv;
}

std::unique_ptr<un_op> un_op::from_c(const IRExpr *e) {
	auto rtv = std::make_unique<un_op>();

	rtv->tag = Iex_Unop;

	rtv->op = e->Iex.Unop.op;
	rtv->arg = IR_expr_xx::from_c(e->Iex.Unop.arg);

	return rtv;
}

std::unique_ptr<load> load::from_c(const IRExpr *e) {
	auto rtv = std::make_unique<load>();

	rtv->tag =Iex_Load;
	rtv->end=e->Iex.Load.end;
	rtv->ty=e->Iex.Load.ty;
	rtv->addr=IR_expr_xx::from_c(e->Iex.Load.addr);

	assert(rtv->end==Iend_LE||rtv->end==Iend_BE);
	
	return rtv;
}

std::unique_ptr<Const> Const::from_c(const IRExpr *e) {
	auto rtv = std::make_unique<Const>();

	rtv->tag =Iex_Const;
	rtv->con=IR_const_xx::from_c(e->Iex.Const.con);

	return rtv;
}

std::unique_ptr<C_call> C_call::from_c(const IRExpr *e) {
	auto rtv = std::make_unique<C_call>();

	rtv->tag =Iex_CCall;
	rtv->cee=IR_callee_xx::from_c(e->Iex.CCall.cee);
	rtv->ret_ty=e->Iex.CCall.retty;

	for (auto i = 0; e->Iex.CCall.args[i]; ++i) {
		rtv->args.push_back(IR_expr_xx::from_c(e->Iex.CCall.args[i]));
	}

	return rtv;
}

std::unique_ptr<ITE> ITE::from_c(const IRExpr *e) {
	auto rtv = std::make_unique<ITE>();

	rtv->tag =Iex_ITE;
	rtv->cond=IR_expr_xx::from_c(e->Iex.ITE.cond);
	rtv->if_true=IR_expr_xx::from_c(e->Iex.ITE.iftrue);
	rtv->if_false=IR_expr_xx::from_c(e->Iex.ITE.iffalse);

	return rtv;
}

std::unique_ptr<VECRET> VECRET::from_c(const IRExpr *e) {
	auto rtv = std::make_unique<VECRET>();

	rtv->tag =Iex_VECRET;

	return rtv;
}

std::unique_ptr<GSPTR> GSPTR::from_c(const IRExpr *e) {
	auto rtv = std::make_unique<GSPTR>();

	rtv->tag =Iex_GSPTR;

	return rtv;
}


} // namespace ir_expr_types


std::ostream& operator<<(std::ostream &os, const IR_expr_xx &e){
	return e.pretty_print(os);
}

} // namespace libvexxx