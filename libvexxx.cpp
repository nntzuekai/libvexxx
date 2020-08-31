#include "libvexxx.h"
#include <iomanip>

namespace libvexxx {

std::unique_ptr<IR_type_env_xx> IR_type_env_xx::from_c(const IRTypeEnv *src) {
	auto rtv = std::make_unique<IR_type_env_xx>();

	rtv->envs.assign(src->types, src->types + src->types_used);

	return rtv;
}

std::unique_ptr<IRSB_xx> IRSB_xx::from_c(const IRSB *bb) {
	auto rtv = std::make_unique<IRSB_xx>();
	rtv->tyenv = IR_type_env_xx::from_c(bb->tyenv);
	rtv->jumpkind = bb->jumpkind;
	rtv->offsIP = bb->offsIP;
	rtv->next = IR_expr_xx::from_c(bb->next);

	rtv->stmts.reserve(bb->stmts_used);
	for (auto i = 0; i < bb->stmts_used; ++i) {
		rtv->stmts.push_back(IR_stmt_xx::from_c(bb->stmts[i]));
	}

	return rtv;
}

std::unique_ptr<IR_stmt_types::no_op>
IR_stmt_types::no_op::from_c(const IRStmt *s) {
	auto rtv = std::make_unique<no_op>();

	rtv->tag = Ist_NoOp;

	return rtv;
}

std::unique_ptr<IR_stmt_types::ABI_hint>
IR_stmt_types::ABI_hint::from_c(const IRStmt *s) {
	auto st = std::make_unique<ABI_hint>();

	st->tag = Ist_AbiHint;
	st->base = IR_expr_xx::from_c(s->Ist.AbiHint.base);
	st->len = s->Ist.AbiHint.len;
	st->nia = IR_expr_xx::from_c(s->Ist.AbiHint.nia);

	return st;
}

std::unique_ptr<IR_stmt_types::I_mark>
IR_stmt_types::I_mark::from_c(const IRStmt *s) {
	auto st = std::make_unique<I_mark>();

	st->tag = Ist_IMark;
	st->addr = s->Ist.IMark.addr;
	st->len = s->Ist.IMark.len;
	st->delta = s->Ist.IMark.delta;

	return st;
}

std::unique_ptr<IR_stmt_types::put>
IR_stmt_types::put::from_c(const IRStmt *s) {
	auto st = std::make_unique<put>();

	st->tag = Ist_Put;
	st->offset = s->Ist.Put.offset;
	st->data = IR_expr_xx::from_c(s->Ist.Put.data);

	return st;
}

std::unique_ptr<IR_stmt_types::put_I>
IR_stmt_types::put_I::from_c(const IRStmt *s) {
	auto st = std::make_unique<put_I>();

	st->tag = Ist_PutI;

	auto &&det = s->Ist.PutI.details;

	copy_IRRegArray(&(st->descr), det->descr);
	st->ix = IR_expr_xx::from_c(det->ix);
	st->bias = det->bias;
	st->data = IR_expr_xx::from_c(det->data);

	return st;
}

/*
std::unique_ptr<IR_put_I_xx> IR_put_I_xx::from_c(const IRPutI *s) {
    auto st = std::make_unique<IR_put_I_xx>();

    // st->descr = *(s->descr);
    copy_IRRegArray(&(st->descr), s->descr);
    st->ix = IR_expr_xx::from_c(s->ix);
    st->bias = s->bias;
    st->data = IR_expr_xx::from_c(s->data);

    return st;
}
*/

std::unique_ptr<IR_stmt_types::wr_tmp>
IR_stmt_types::wr_tmp::from_c(const IRStmt *s) {
	auto st = std::make_unique<wr_tmp>();

	st->tag = Ist_WrTmp;
	st->tmp = s->Ist.WrTmp.tmp;
	st->data = IR_expr_xx::from_c(s->Ist.WrTmp.data);

	return st;
}

std::unique_ptr<IR_stmt_types::store>
IR_stmt_types::store::from_c(const IRStmt *s) {
	auto st = std::make_unique<store>();

	st->tag = Ist_Store;
	st->end = s->Ist.Store.end;
	st->addr = IR_expr_xx::from_c(s->Ist.Store.addr);
	st->data = IR_expr_xx::from_c(s->Ist.Store.data);

	assert(st->end == Iend_LE || st->end == Iend_BE);

	return st;
}

std::unique_ptr<IR_stmt_types::store_G>
IR_stmt_types::store_G::from_c(const IRStmt *s) {
	auto st = std::make_unique<store_G>();

	st->tag = Ist_StoreG;

	auto &&det = s->Ist.StoreG.details;
	st->end = det->end;
	st->addr = IR_expr_xx::from_c(det->addr);
	st->data = IR_expr_xx::from_c(det->data);
	st->guard = IR_expr_xx::from_c(det->guard);

	return st;
}

/*
std::unique_ptr<IR_store_G_xx> IR_store_G_xx::from_c(const IRStoreG *s) {
    auto st = std::make_unique<IR_store_G_xx>();
    st->end = s->end;
    st->addr = IR_expr_xx::from_c(s->addr);
    st->data = IR_expr_xx::from_c(s->data);
    st->guard = IR_expr_xx::from_c(s->guard);

    assert(st->end == Iend_LE || st->end == Iend_BE);
    return st;
}
*/

std::unique_ptr<IR_stmt_types::load_G>
IR_stmt_types::load_G::from_c(const IRStmt *s) {
	auto st = std::make_unique<load_G>();

	st->tag = Ist_LoadG;

	auto *det = s->Ist.LoadG.details;
	st->end = det->end;
	st->cvt = det->cvt;
	st->dst = det->dst;
	st->addr = IR_expr_xx::from_c(det->addr);
	st->alt = IR_expr_xx::from_c(det->alt);
	st->guard = IR_expr_xx::from_c(det->guard);

	// st->details = IR_load_G_xx::from_c(s->Ist.LoadG.details);

	return st;
}

/*
std::unique_ptr<IR_load_G_xx> IR_load_G_xx::from_c(const IRLoadG *s) {
    auto st = std::make_unique<IR_load_G_xx>();

    st->end = s->end;
    st->cvt = s->cvt;
    st->dst = s->dst;
    st->addr = IR_expr_xx::from_c(s->addr);
    st->alt = IR_expr_xx::from_c(s->alt);
    st->guard = IR_expr_xx::from_c(s->guard);

    return st;
}
*/

std::unique_ptr<IR_stmt_types::CAS>
IR_stmt_types::CAS::from_c(const IRStmt *s) {
	auto rtv = std::make_unique<CAS>();

	rtv->tag = Ist_CAS;

	auto *det = s->Ist.CAS.details;
	rtv->old_hi = det->oldHi;
	rtv->old_lo = det->oldLo;
	rtv->end = det->end;
	rtv->addr = IR_expr_xx::from_c(det->addr);
	rtv->expd_hi = IR_expr_xx::from_c(det->expdHi);
	rtv->expd_lo = IR_expr_xx::from_c(det->expdLo);
	rtv->data_hi = IR_expr_xx::from_c(det->dataHi);
	rtv->data_lo = IR_expr_xx::from_c(det->dataLo);

	// st->details = IR_CAS_xx::from_c(s->Ist.CAS.details);

	return rtv;
}

/*
std::unique_ptr<IR_CAS_xx> IR_CAS_xx::from_c(const IRCAS *s) {
    auto rtv = std::make_unique<IR_CAS_xx>();

    rtv->old_hi = s->oldHi;
    rtv->old_lo = s->oldLo;
    rtv->end = s->end;
    rtv->addr = IR_expr_xx::from_c(s->addr);
    rtv->expd_hi = IR_expr_xx::from_c(s->expdHi);
    rtv->expd_lo = IR_expr_xx::from_c(s->expdLo);
    rtv->data_hi = IR_expr_xx::from_c(s->dataHi);
    rtv->data_lo = IR_expr_xx::from_c(s->dataLo);

    return rtv;
}
*/

std::unique_ptr<IR_stmt_types::LLSC>
IR_stmt_types::LLSC::from_c(const IRStmt *s) {
	auto rtv = std::make_unique<LLSC>();
	auto &&llsc = s->Ist.LLSC;

	rtv->tag = Ist_LLSC;
	rtv->end = llsc.end;
	rtv->result = llsc.result;
	rtv->addr = IR_expr_xx::from_c(llsc.addr);
	if (llsc.storedata) {
		rtv->store_data = IR_expr_xx::from_c(llsc.storedata);
	}

	return rtv;
}

std::unique_ptr<IR_stmt_types::dirty>
IR_stmt_types::dirty::from_c(const IRStmt *s) {
	auto rtv = std::make_unique<dirty>();

	rtv->tag = Ist_Dirty;

	auto *det = s->Ist.Dirty.details;
	rtv->cee = IR_callee_xx::from_c(det->cee);
	rtv->guard = IR_expr_xx::from_c(det->guard);

	for (auto i = 0; det->args[i]; ++i) {
		rtv->args.push_back(IR_expr_xx::from_c(det->args[i]));
	}

	rtv->tmp = det->tmp;
	rtv->m_fx = det->mFx;
	if (det->mAddr) {
		rtv->m_addr = IR_expr_xx::from_c(det->mAddr);
	}
	rtv->m_size = det->mSize;
	rtv->n_fx_state = det->nFxState;

	for (auto i = 0; i < rtv->n_fx_state; ++i) {
		auto &&l = rtv->fx_state[i];
		auto &&r = det->fxState[i];

		l.fx = r.fx;
		l.offset = r.offset;
		l.size = r.size;
		l.n_repeats = r.nRepeats;
		l.repeat_len = r.repeatLen;
	}

	// rtv->details = IR_dirty_xx::from_c(s->Ist.Dirty.details);

	return rtv;
}

/*
std::unique_ptr<IR_dirty_xx> IR_dirty_xx::from_c(const IRDirty *s) {
    auto d2 = std::make_unique<IR_dirty_xx>();

    d2->cee = IR_callee_xx::from_c(s->cee);
    d2->guard = IR_expr_xx::from_c(s->guard);

    for (auto i = 0; s->args[i]; ++i) {
        d2->args.push_back(IR_expr_xx::from_c(s->args[i]));
    }

    d2->tmp = s->tmp;
    d2->m_fx = s->mFx;
    if (s->mAddr) {
        d2->m_addr = IR_expr_xx::from_c(s->mAddr);
    }
    d2->m_size = s->mSize;
    d2->n_fx_state = s->nFxState;

    for (auto i = 0; i < d2->n_fx_state; ++i) {
        auto &&l = d2->fx_state[i];
        auto &&r = s->fxState[i];

        l.fx = r.fx;
        l.offset = r.offset;
        l.size = r.size;
        l.n_repeats = r.nRepeats;
        l.repeat_len = r.repeatLen;
    }

    return d2;
}
*/

std::unique_ptr<IR_stmt_types::MBE>
IR_stmt_types::MBE::from_c(const IRStmt *s) {
	auto rtv = std::make_unique<MBE>();

	rtv->tag = Ist_MBE;
	rtv->event = s->Ist.MBE.event;

	return rtv;
}

std::unique_ptr<IR_stmt_types::exit>
IR_stmt_types::exit::from_c(const IRStmt *s) {
	auto rtv = std::make_unique<exit>();

	rtv->tag = Ist_Exit;
	rtv->guard = IR_expr_xx::from_c(s->Ist.Exit.guard);
	rtv->jk = s->Ist.Exit.jk;
	rtv->dst = IR_const_xx::from_c(s->Ist.Exit.dst);
	rtv->offs_IP = s->Ist.Exit.offsIP;

	return rtv;
}

std::unique_ptr<IR_stmt_xx> IR_stmt_xx::from_c(const IRStmt *s) {
	switch (s->tag) {
	case Ist_NoOp: {
		return IR_stmt_types::no_op::from_c(s);
	}
	case Ist_AbiHint: {
		return IR_stmt_types::ABI_hint::from_c(s);
	}
	case Ist_IMark: {
		return IR_stmt_types::I_mark::from_c(s);
	}
	case Ist_Put: {
		return IR_stmt_types::put::from_c(s);
	}
	case Ist_PutI: {
		return IR_stmt_types::put_I::from_c(s);
	}
	case Ist_WrTmp: {
		return IR_stmt_types::wr_tmp::from_c(s);
	}
	case Ist_Store: {
		return IR_stmt_types::store::from_c(s);
	}
	case Ist_StoreG: {
		return IR_stmt_types::store_G::from_c(s);
	}
	case Ist_LoadG: {
		return IR_stmt_types::load_G::from_c(s);
	}
	case Ist_CAS: {
		return IR_stmt_types::CAS::from_c(s);
	}
	case Ist_LLSC: {
		return IR_stmt_types::LLSC::from_c(s);
	}
	case Ist_Dirty: {
		return IR_stmt_types::dirty::from_c(s);
	}
	case Ist_MBE: {
		return IR_stmt_types::MBE::from_c(s);
	}
	case Ist_Exit: {
		return IR_stmt_types::exit::from_c(s);
	}
	default:
		throw "IR_stmt_xx::from_c";
	}
}
std::ostream &operator<<(std::ostream &os, IRType ty) {
	switch (ty) {
	case Ity_INVALID:
		os << "Ity_INVALID";
		break;
	case Ity_I1:
		os << "I1";
		break;
	case Ity_I8:
		os << "I8";
		break;
	case Ity_I16:
		os << "I16";
		break;
	case Ity_I32:
		os << "I32";
		break;
	case Ity_I64:
		os << "I64";
		break;
	case Ity_I128:
		os << "I128";
		break;
	case Ity_F16:
		os << "F16";
		break;
	case Ity_F32:
		os << "F32";
		break;
	case Ity_F64:
		os << "F64";
		break;
	case Ity_F128:
		os << "F128";
		break;
	case Ity_D32:
		os << "D32";
		break;
	case Ity_D64:
		os << "D64";
		break;
	case Ity_D128:
		os << "D128";
		break;
	case Ity_V128:
		os << "V128";
		break;
	case Ity_V256:
		os << "V256";
		break;
	default:
		throw "ppIRType ty=" + std::to_string(static_cast<uint>(ty));
	}

	return os;
}

std::ostream &operator<<(std::ostream &os, IRJumpKind kind) {
	switch (kind) {
	case Ijk_Boring:
		os << "Boring";
		break;
	case Ijk_Call:
		os << "Call";
		break;
	case Ijk_Ret:
		os << "Return";
		break;
	case Ijk_ClientReq:
		os << "ClientReq";
		break;
	case Ijk_Yield:
		os << "Yield";
		break;
	case Ijk_EmWarn:
		os << "EmWarn";
		break;
	case Ijk_EmFail:
		os << "EmFail";
		break;
	case Ijk_NoDecode:
		os << "NoDecode";
		break;
	case Ijk_MapFail:
		os << "MapFail";
		break;
	case Ijk_InvalICache:
		os << "InvalICache";
		break;
	case Ijk_FlushDCache:
		os << "FlushDCache";
		break;
	case Ijk_NoRedir:
		os << "NoRedir";
		break;
	case Ijk_SigILL:
		os << "SigILL";
		break;
	case Ijk_SigTRAP:
		os << "SigTRAP";
		break;
	case Ijk_SigSEGV:
		os << "SigSEGV";
		break;
	case Ijk_SigBUS:
		os << "SigBUS";
		break;
	case Ijk_SigFPE:
		os << "SigFPE";
		break;
	case Ijk_SigFPE_IntDiv:
		os << "SigFPE_IntDiv";
		break;
	case Ijk_SigFPE_IntOvf:
		os << "SigFPE_IntOvf";
		break;
	case Ijk_Sys_syscall:
		os << "Sys_syscall";
		break;
	case Ijk_Sys_int32:
		os << "Sys_int32";
		break;
	case Ijk_Sys_int128:
		os << "Sys_int128";
		break;
	case Ijk_Sys_int129:
		os << "Sys_int129";
		break;
	case Ijk_Sys_int130:
		os << "Sys_int130";
		break;
	case Ijk_Sys_int145:
		os << "Sys_int145";
		break;
	case Ijk_Sys_int210:
		os << "Sys_int210";
		break;
	case Ijk_Sys_sysenter:
		os << "Sys_sysenter";
		break;
	default:
		throw "ppIRJumpKind";
	}

	return os;
}

std::ostream &IRSB_xx::pretty_print(std::ostream &os) const {
	os << "IRSB {\n";
	this->tyenv->pretty_print(os);
	os << "\n";
	for (auto &&s : this->stmts) {
		os << "\t";
		s->pretty_print(os);
		os << "\n";
	}
	os << "\tPUT(" << this->offsIP << ") = "<<*next;
	os << "; exit-" << this->jumpkind;
	os << "\n}\n";
}

std::ostream &operator<<(std::ostream &os, const IRSB_xx &irsb){
	irsb.pretty_print(os);

	return os;
}

std::ostream &IR_type_env_xx::pretty_print(std::ostream &os) const {
	os << "\t";
	for (unsigned int i = 0, n = this->envs.size(); i < n; ++i) {
		os << "t" << i << ":" << envs[i] << "  ";
	}
	return os << '\n';
}
std::ostream &operator<<(std::ostream &os, const IR_stmt_xx &stmt) {
	return stmt.pretty_print(os);
}

/*
std::ostream &operator<<(std::ostream &os, const IRRegArray &arr) {
	os << "(" << arr.base << ":" << arr.nElems << "x" << arr.elemTy << ")";

	return os;
}
*/

/*
std::ostream &IR_put_I_xx::pretty_print(std::ostream &os) const {
    os << "PUTI" << this->descr << "[";
    this->ix->pretty_print(os);
    os << "," << this->bias << "] = ";
    this->data->pretty_print(os);

    return os;
}

std::ostream &IR_store_G_xx::pretty_print(std::ostream &os) const {
    os << "if (" << *this->guard << ") { ST";
    os << this->end << "(";
    os << *this->addr << ") = " << *this->data << " }";

    return os;
}
*/

std::ostream &operator<<(std::ostream &os, IRLoadGOp cvt) {
	switch (cvt) {
	case ILGop_INVALID:
		os << "ILGop_INVALID";
		break;
	case ILGop_IdentV128:
		os << "IdentV128";
		break;
	case ILGop_Ident64:
		os << "Ident64";
		break;
	case ILGop_Ident32:
		os << "Ident32";
		break;
	case ILGop_16Uto32:
		os << "16Uto32";
		break;
	case ILGop_16Sto32:
		os << "16Sto32";
		break;
	case ILGop_8Uto32:
		os << "8Uto32";
		break;
	case ILGop_8Sto32:
		os << "8Sto32";
		break;
	default:
		throw "ppIRLoadGOp";
	}

	return os;
}

/*
std::ostream &IR_load_G_xx::pretty_print(std::ostream &os) const {
    os << this->dst << " = if-strict (" << *this->guard << ") " << this->cvt;
    os << "(LD" << this->end << "(" << *this->addr << ")) else ";
    os << *this->alt;

    return os;
}
*/

std::ostream &operator<<(std::ostream &os, IREndness e) {
	os << (e == Iend_LE) ? "le" : "be";
	return os;
}

/*
std::ostream &IR_CAS_xx ::pretty_print(std::ostream &os) const {
    if (this->old_hi != IRTemp_INVALID) {
        os << this->old_hi << ",";
    }

    os << this->old_lo << " = =CAS" << this->end << "(" << *this->addr << "::";
    if (this->expd_hi) {
        os << *this->expd_hi << ",";
    }
    os << *this->expd_lo << "->";
    if (this->data_hi) {
        os << *this->data_hi << ",";
    }
    os << *this->data_lo << ")";

    return os;
}
*/

std::ostream &operator<<(std::ostream &os, IREffect fx) {
	switch (fx) {
	case Ifx_None:
		os << "noFX";
		return os;
	case Ifx_Read:
		os << "RdFX";
		return os;
	case Ifx_Write:
		os << "WrFX";
		return os;
	case Ifx_Modify:
		os << "MoFX";
		return os;
	default:
		throw "ppIREffect";
	}

	return os;
}

/*
std::ostream &IR_dirty_xx::pretty_print(std::ostream &os) const {
    if (tmp != IRTemp_INVALID) {
        os << tmp << " = ";
    }
    os << "DIRTY " << *guard;
    if (m_fx != Ifx_None) {
        os << m_fx << "-mem(" << *m_addr << "," << m_size << ")";
    }

    for (auto i = 0; i < n_fx_state; ++i) {
        auto &&s = fx_state[i];

        os << " " << s.fx << "-gst(" << s.offset << "," << s.size;

        if (s.n_repeats > 0) {
            os << ",reps" << static_cast<unsigned>(s.n_repeats) << ",step"
               << static_cast<unsigned>(s.repeat_len);
        }

        os << ")";
    }

    os << " ::: ";
    cee->pretty_print(os);
    os << "(";
    for (auto &&e : args) {
        os << *e << ",";
    }
    os << ")";

    return os;
}
*/

std::ostream &operator<<(std::ostream &os, IRMBusEvent eve) {
	switch (eve) {
	case Imbe_Fence:
		os << "Fence";
		break;
	case Imbe_CancelReservation:
		os << "CancelReservation";
		break;
	default:
		throw "ppIRMBusEvent";
	}

	return os;
}

namespace IR_stmt_types {

std::ostream &no_op::pretty_print(std::ostream &os) const {
	return os << "IR-NoOp";
}

std::ostream &I_mark::pretty_print(std::ostream &os) const {
	os << "------ IMark(0x" << std::hex << addr << std::dec << ", " << len << ", "
	   << static_cast<unsigned>(delta) << ")";
	return os;
}

std::ostream &ABI_hint::pretty_print(std::ostream &os) const {
	os << "====== AbiHint(" << *base << ", " << len << ", " << *nia
	   << ") ======";
	return os;
}

std::ostream &put::pretty_print(std::ostream &os) const {
	os << "PUT(" << offset << ") = " << *data;
	return os;
}

std::ostream &put_I::pretty_print(std::ostream &os) const {
	os << "PUTI" << this->descr << "[";
	this->ix->pretty_print(os);
	os << "," << this->bias << "] = ";
	this->data->pretty_print(os);

	return os;
}

std::ostream &wr_tmp::pretty_print(std::ostream &os) const {
	os << tmp << " = " << *data;

	return os;
}
std::ostream &store::pretty_print(std::ostream &os) const {
	os << "ST" << end << "(" << *addr << ") = " << *data;

	return os;
}

std::ostream &store_G::pretty_print(std::ostream &os) const {
	os << "if (" << *this->guard << ") { ST";
	os << this->end << "(";
	os << *this->addr << ") = " << *this->data << " }";

	return os;
}

std::ostream &load_G::pretty_print(std::ostream &os) const {
	os << this->dst << " = if-strict (" << *this->guard << ") " << this->cvt;
	os << "(LD" << this->end << "(" << *this->addr << ")) else ";
	os << *this->alt;

	return os;
}

std::ostream &CAS::pretty_print(std::ostream &os) const {
	if (this->old_hi != IRTemp_INVALID) {
		os << this->old_hi << ",";
	}

	os << this->old_lo << " = =CAS" << this->end << "(" << *this->addr << "::";
	if (this->expd_hi) {
		os << *this->expd_hi << ",";
	}
	os << *this->expd_lo << "->";
	if (this->data_hi) {
		os << *this->data_hi << ",";
	}
	os << *this->data_lo << ")";

	return os;
}
std::ostream &LLSC::pretty_print(std::ostream &os) const {
	if (!store_data) {
		os << result << " = LD" << end << "-Linked(" << *addr << ")";
	} else {
		os << result << " = ( ST" << end << "-Cond(" << *addr
		   << ") = " << *store_data << " )";
	}

	return os;
}

std::ostream &dirty::pretty_print(std::ostream &os) const {
	if (tmp != IRTemp_INVALID) {
		os << tmp << " = ";
	}
	os << "DIRTY " << *guard;
	if (m_fx != Ifx_None) {
		os << m_fx << "-mem(" << *m_addr << "," << m_size << ")";
	}

	for (auto i = 0; i < n_fx_state; ++i) {
		auto &&s = fx_state[i];

		os << " " << s.fx << "-gst(" << s.offset << "," << s.size;

		if (s.n_repeats > 0) {
			os << ",reps" << static_cast<unsigned>(s.n_repeats) << ",step"
			   << static_cast<unsigned>(s.repeat_len);
		}

		os << ")";
	}

	os << " ::: ";
	cee->pretty_print(os);
	os << "(";
	for (auto &&e : args) {
		os << *e << ",";
	}
	os << ")";

	return os;
}
std::ostream &MBE::pretty_print(std::ostream &os) const {
	os<<"IR-"<<event;

	return os;
}

std::ostream &exit::pretty_print(std::ostream &os) const{
	os<<"if ("<<*guard<<") { PUT("<<offs_IP<<") = ";
	dst->pretty_print(os);
	os<<"; exit-"<<jk<<" } ";

	return os;
}

} // namespace IR_stmt_types

} // namespace libvexxx
