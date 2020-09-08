#include "libvexxx.h"
#include <iomanip>

namespace libvexxx {

std::unique_ptr<IR_type_env_xx> IR_type_env_xx::from_c(const IRTypeEnv *src) {
	auto rtv = std::make_unique<IR_type_env_xx>();

	rtv->envs.resize(src->types_used);
	for (auto i = 0; i < src->types_used; ++i) {
		rtv->envs[i] = IR_type_xx{src->types[i]};
	}

	return rtv;
}

std::unique_ptr<IRSB_xx> IRSB_xx::from_c(const IRSB *bb) {
	auto rtv = std::make_unique<IRSB_xx>();
	rtv->tyenv = IR_type_env_xx::from_c(bb->tyenv);
	rtv->jumpkind = IR_jump_kind_xx{bb->jumpkind};
	rtv->offs_IP = bb->offsIP;
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
	st->tmp = IR_temp_xx{s->Ist.WrTmp.tmp};
	st->data = IR_expr_xx::from_c(s->Ist.WrTmp.data);

	return st;
}

std::unique_ptr<IR_stmt_types::store>
IR_stmt_types::store::from_c(const IRStmt *s) {
	auto st = std::make_unique<store>();

	st->tag = Ist_Store;
	st->end = IR_endness_xx{s->Ist.Store.end};
	st->addr = IR_expr_xx::from_c(s->Ist.Store.addr);
	st->data = IR_expr_xx::from_c(s->Ist.Store.data);

	assert(st->end == IR_endness_xx::Iend_LE ||
	       st->end == IR_endness_xx::Iend_BE);

	return st;
}

std::unique_ptr<IR_stmt_types::store_G>
IR_stmt_types::store_G::from_c(const IRStmt *s) {
	auto st = std::make_unique<store_G>();

	st->tag = Ist_StoreG;

	auto &&det = s->Ist.StoreG.details;
	st->end = IR_endness_xx{det->end};
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
	st->end = IR_endness_xx{det->end};
	st->cvt = IR_load_G_op_xx{det->cvt};
	st->dst = IR_temp_xx{det->dst};
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
	rtv->old_hi = IR_temp_xx{det->oldHi};
	rtv->old_lo = IR_temp_xx{det->oldLo};
	rtv->end = IR_endness_xx{det->end};
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
	rtv->end = IR_endness_xx{llsc.end};
	rtv->result = IR_temp_xx{llsc.result};
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

	rtv->tmp = IR_temp_xx{det->tmp};
	rtv->m_fx = IR_effect_xx{det->mFx};
	if (det->mAddr) {
		rtv->m_addr = IR_expr_xx::from_c(det->mAddr);
	}
	rtv->m_size = det->mSize;
	rtv->n_fx_state = det->nFxState;

	for (auto i = 0; i < rtv->n_fx_state; ++i) {
		auto &&l = rtv->fx_state[i];
		auto &&r = det->fxState[i];

		l.fx = IR_effect_xx{r.fx};
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
	rtv->event = IR_MBUS_event_xx{s->Ist.MBE.event};

	return rtv;
}

std::unique_ptr<IR_stmt_types::exit>
IR_stmt_types::exit::from_c(const IRStmt *s) {
	auto rtv = std::make_unique<exit>();

	rtv->tag = Ist_Exit;
	rtv->guard = IR_expr_xx::from_c(s->Ist.Exit.guard);
	rtv->jk = IR_jump_kind_xx{s->Ist.Exit.jk};
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

std::ostream &IRSB_xx::pretty_print(std::ostream &os, arch_type arch) const {
	os << "IRSB_xx {\n";
	this->tyenv->pretty_print(os);
	os << "\n";
	for (auto &&s : this->stmts) {
		os << "\t";
		s->pretty_print(os);
		os << "\n";
	}
	os << "\tPUT(";

	auto *name=guest_register_name(offs_IP,arch);
	if(name){
		os<<"%"<<name;
	}
	else{
		os<<offs_IP;
	}
	
	os<< ") = ";
	next->pretty_print(os, arch);
	os << "; exit-" << this->jumpkind;
	os << "\n}\n";
}

std::ostream &operator<<(std::ostream &os, const IRSB_xx &irsb) {
	irsb.pretty_print(os);

	return os;
}

std::ostream &IR_type_env_xx::pretty_print(std::ostream &os) const {
	os << "\t";
	for (unsigned int i = 0, n = this->envs.size(); i < n; ++i) {
		os << IR_temp_xx{i} << ":" << envs[i] << "  ";
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

/*
std::ostream &IR_load_G_xx::pretty_print(std::ostream &os) const {
    os << this->dst << " = if-strict (" << *this->guard << ") " << this->cvt;
    os << "(LD" << this->end << "(" << *this->addr << ")) else ";
    os << *this->alt;

    return os;
}
*/

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

namespace IR_stmt_types {

std::ostream &no_op::pretty_print(std::ostream &os, arch_type) const {
	return os << "IR-NoOp";
}

std::ostream &I_mark::pretty_print(std::ostream &os, arch_type) const {
	os << "------ IMark(0x" << std::hex << addr << std::dec << ", " << len
	   << ", " << static_cast<unsigned>(delta) << ") ------";
	return os;
}

std::ostream &ABI_hint::pretty_print(std::ostream &os, arch_type arch) const {
	os << "====== AbiHint(";
	base->pretty_print(os, arch);
	os << ", " << len << ", ";
	nia->pretty_print(os, arch);
	os << ") ======";
	return os;
}

std::ostream &put::pretty_print(std::ostream &os, arch_type arch) const {
	os << "PUT(";
	auto name = guest_register_name(offset, arch);
	if (name) {
		os <<"%"<< name;
	} else {
		os << offset;
	}

	os << ") = ";
	data->pretty_print(os, arch);
	return os;
}

std::ostream &put_I::pretty_print(std::ostream &os, arch_type) const {
	os << "PUTI" << this->descr << "[";
	this->ix->pretty_print(os);
	os << "," << this->bias << "] = ";
	this->data->pretty_print(os);

	return os;
}

std::ostream &wr_tmp::pretty_print(std::ostream &os, arch_type arch) const {
	os << tmp << " = ";
	data->pretty_print(os, arch);

	return os;
}
std::ostream &store::pretty_print(std::ostream &os, arch_type arch) const {
	os << "ST" << end << "(";
	addr->pretty_print(os, arch);
	os << ") = ";
	data->pretty_print(os, arch);

	return os;
}

std::ostream &store_G::pretty_print(std::ostream &os, arch_type arch) const {
	os << "if (";
	this->guard->pretty_print(os, arch);
	os << ") { ST";
	os << this->end << "(";
	this->addr->pretty_print(os, arch);
	os << ") = ";
	this->data->pretty_print(os, arch);
	os << " }";

	return os;
}

std::ostream &load_G::pretty_print(std::ostream &os, arch_type arch) const {
	os << this->dst << " = if-strict (";
	this->guard->pretty_print(os, arch);
	os << ") " << this->cvt;
	os << "(LD" << this->end << "(";
	this->addr->pretty_print(os, arch);
	os << ")) else ";
	this->alt->pretty_print(os, arch);

	return os;
}

std::ostream &CAS::pretty_print(std::ostream &os, arch_type arch) const {
	if (this->old_hi != IR_temp_xx::invalid) {
		os << this->old_hi << ",";
	}

	os << this->old_lo << " = =CAS" << this->end << "(";
	this->addr->pretty_print(os, arch);
	os << "::";
	if (this->expd_hi) {
		this->expd_hi->pretty_print(os, arch);
		os << ",";
	}
	this->expd_lo->pretty_print(os, arch);
	os << "->";
	if (this->data_hi) {
		this->data_hi->pretty_print(os, arch);
		os << ",";
	}
	this->data_lo->pretty_print(os, arch);
	os << ")";

	return os;
}
std::ostream &LLSC::pretty_print(std::ostream &os, arch_type arch) const {
	if (!store_data) {
		os << result << " = LD" << end << "-Linked(";
		addr->pretty_print(os, arch);
		os << ")";
	} else {
		os << result << " = ( ST" << end << "-Cond(";
		addr->pretty_print(os, arch);
		os << ") = ";
		store_data->pretty_print(os, arch);
		os << " )";
	}

	return os;
}

std::ostream &dirty::pretty_print(std::ostream &os, arch_type arch) const {
	if (tmp != IR_temp_xx::invalid) {
		os << tmp << " = ";
	}
	os << "DIRTY ";
	guard->pretty_print(os, arch);
	if (m_fx != IR_effect_xx::Ifx_None) {
		os << m_fx << "-mem(";
		m_addr->pretty_print(os, arch);
		os << "," << m_size << ")";
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
		e->pretty_print(os, arch);
		os << ",";
	}
	os << ")";

	return os;
}
std::ostream &MBE::pretty_print(std::ostream &os, arch_type) const {
	os << "IR-" << event;

	return os;
}

std::ostream &exit::pretty_print(std::ostream &os, arch_type arch) const {
	os << "if (";
	guard->pretty_print(os, arch);
	os << ") { PUT(";

	auto *name=guest_register_name(offs_IP,arch);
	if(name){
		os<<"%"<<name;
	}
	else{
		os<<offs_IP;
	}
	
	os<< ") = ";
	dst->pretty_print(os);
	os << "; exit-" << jk << " } ";

	return os;
}

} // namespace IR_stmt_types

} // namespace libvexxx
