#pragma once

#ifndef LIBVEXXXX_INCLUDED
#define LIBVEXXXX_INCLUDED

extern "C" {
// #include "pyvex.h"
#include "libvex.h"
}
#include "IR_enums.h"
#include "IR_expr_xx.h"

#include <cassert>
#include <cstring>
#include <iostream>
#include <memory>
#include <vector>

namespace libvexxx {

struct IR_type_env_xx {
	std::vector<IR_type_xx> envs;

	static std::unique_ptr<IR_type_env_xx> from_c(const IRTypeEnv *src);

	std::ostream &pretty_print(std::ostream &os) const;
};

/*
struct IR_put_I_xx {
    IRRegArray descr;
    std::unique_ptr<IR_expr_xx> ix;
    Int bias;
    std::unique_ptr<IR_expr_xx> data;

    static std::unique_ptr<IR_put_I_xx> from_c(const IRPutI *s);
    std::ostream& pretty_print(std::ostream &os) const;
};

struct IR_store_G_xx {
    IR_endness_xx end;
    std::unique_ptr<IR_expr_xx> addr;
    std::unique_ptr<IR_expr_xx> data;
    std::unique_ptr<IR_expr_xx> guard;

    std::ostream& pretty_print(std::ostream &os) const;
    static std::unique_ptr<IR_store_G_xx> from_c(const IRStoreG *s);
};

struct IR_load_G_xx {
    IR_endness_xx end;
    IR_load_G_op_xx cvt;
    IR_temp_xx dst;
    std::unique_ptr<IR_expr_xx> addr;
    std::unique_ptr<IR_expr_xx> alt;
    std::unique_ptr<IR_expr_xx> guard;

    std::ostream& pretty_print(std::ostream &os) const;
    static std::unique_ptr<IR_load_G_xx> from_c(const IRLoadG *s);
};

struct IR_CAS_xx {
    IR_temp_xx old_hi;
    IR_temp_xx old_lo;
    IR_endness_xx end;
    std::unique_ptr<IR_expr_xx> addr;
    std::unique_ptr<IR_expr_xx> expd_hi;
    std::unique_ptr<IR_expr_xx> expd_lo;
    std::unique_ptr<IR_expr_xx> data_hi;
    std::unique_ptr<IR_expr_xx> data_lo;

    std::ostream& pretty_print(std::ostream &os) const;
    static std::unique_ptr<IR_CAS_xx> from_c(const IRCAS *s);
};

struct IR_dirty_xx {
    std::unique_ptr<IR_callee_xx> cee;

    std::unique_ptr<IR_expr_xx> guard;
    std::vector<std::unique_ptr<IR_expr_xx>> args;
    IR_temp_xx tmp = IR_temp_xx_INVALID;

    IR_effect_xx m_fx = Ifx_None;
    std::unique_ptr<IR_expr_xx> m_addr;
    Int m_size = 0;

    Int n_fx_state = 0;

    struct t_fx_state {
        IR_effect_xx fx;
        UShort offset;
        UShort size;
        UChar n_repeats;
        UChar repeat_len;
    };

    t_fx_state fx_state[VEX_N_FXSTATE];

    std::ostream& pretty_print(std::ostream &os) const;
    static std::unique_ptr<IR_dirty_xx> from_c(const IRDirty *s);
};
*/

struct IR_stmt_xx {
	IRStmtTag tag;

	virtual std::ostream &pretty_print(std::ostream &os) const = 0;
	static std::unique_ptr<IR_stmt_xx> from_c(const IRStmt *s);
};
std::ostream &operator<<(std::ostream &os, const IR_stmt_xx &stmt);

namespace IR_stmt_types {
struct no_op : public IR_stmt_xx {

	std::ostream &pretty_print(std::ostream &os) const override;
	static std::unique_ptr<no_op> from_c(const IRStmt *s);
};

struct I_mark : public IR_stmt_xx {
	Addr addr;
	UInt len;
	UChar delta;

	std::ostream &pretty_print(std::ostream &os) const override;
	static std::unique_ptr<I_mark> from_c(const IRStmt *s);
};

struct ABI_hint : public IR_stmt_xx {
	std::unique_ptr<IR_expr_xx> base;
	Int len;
	std::unique_ptr<IR_expr_xx> nia;

	std::ostream &pretty_print(std::ostream &os) const override;
	static std::unique_ptr<ABI_hint> from_c(const IRStmt *s);
};

struct put : public IR_stmt_xx {
	Int offset;
	std::unique_ptr<IR_expr_xx> data;

	std::ostream &pretty_print(std::ostream &os) const override;
	static std::unique_ptr<put> from_c(const IRStmt *s);
};

struct put_I : public IR_stmt_xx {
	IRRegArray descr;
	std::unique_ptr<IR_expr_xx> ix;
	Int bias;
	std::unique_ptr<IR_expr_xx> data;

	std::ostream &pretty_print(std::ostream &os) const override;
	static std::unique_ptr<put_I> from_c(const IRStmt *s);
};

struct wr_tmp : public IR_stmt_xx {
	IR_temp_xx tmp;
	std::unique_ptr<IR_expr_xx> data;

	std::ostream &pretty_print(std::ostream &os) const override;
	static std::unique_ptr<wr_tmp> from_c(const IRStmt *s);
};

struct store : public IR_stmt_xx {
	IR_endness_xx end;
	std::unique_ptr<IR_expr_xx> addr;
	std::unique_ptr<IR_expr_xx> data;

	std::ostream &pretty_print(std::ostream &os) const override;
	static std::unique_ptr<store> from_c(const IRStmt *s);
};

struct store_G : public IR_stmt_xx {
	IR_endness_xx end;
	std::unique_ptr<IR_expr_xx> addr;
	std::unique_ptr<IR_expr_xx> data;
	std::unique_ptr<IR_expr_xx> guard;

	std::ostream &pretty_print(std::ostream &os) const override;
	static std::unique_ptr<store_G> from_c(const IRStmt *s);
};

struct load_G : public IR_stmt_xx {
	IR_endness_xx end;
	IR_load_G_op_xx cvt;
	IR_temp_xx dst;
	std::unique_ptr<IR_expr_xx> addr;
	std::unique_ptr<IR_expr_xx> alt;
	std::unique_ptr<IR_expr_xx> guard;
	// std::unique_ptr<IR_load_G_xx> details;

	std::ostream &pretty_print(std::ostream &os) const override;
	static std::unique_ptr<load_G> from_c(const IRStmt *s);
};

struct CAS : public IR_stmt_xx {
	IR_temp_xx old_hi;
	IR_temp_xx old_lo;
	IR_endness_xx end;
	std::unique_ptr<IR_expr_xx> addr;
	std::unique_ptr<IR_expr_xx> expd_hi;
	std::unique_ptr<IR_expr_xx> expd_lo;
	std::unique_ptr<IR_expr_xx> data_hi;
	std::unique_ptr<IR_expr_xx> data_lo;

	// std::unique_ptr<IR_CAS_xx> details;

	std::ostream &pretty_print(std::ostream &os) const override;
	static std::unique_ptr<CAS> from_c(const IRStmt *s);
};

struct LLSC : public IR_stmt_xx {
	IR_endness_xx end;
	IR_temp_xx result;
	std::unique_ptr<IR_expr_xx> addr;
	std::unique_ptr<IR_expr_xx> store_data;

	std::ostream &pretty_print(std::ostream &os) const override;
	static std::unique_ptr<LLSC> from_c(const IRStmt *s);
};

struct dirty : public IR_stmt_xx {
	std::unique_ptr<IR_callee_xx> cee;

	std::unique_ptr<IR_expr_xx> guard;
	std::vector<std::unique_ptr<IR_expr_xx>> args;
	IR_temp_xx tmp = IR_temp_xx::invalid;

	IR_effect_xx m_fx = IR_effect_xx::Ifx_None;
	std::unique_ptr<IR_expr_xx> m_addr;
	Int m_size = 0;

	Int n_fx_state = 0;

	struct t_fx_state {
		IR_effect_xx fx;
		UShort offset;
		UShort size;
		UChar n_repeats;
		UChar repeat_len;
	};

	t_fx_state fx_state[VEX_N_FXSTATE];

	// std::unique_ptr<IR_dirty_xx> details;

	std::ostream &pretty_print(std::ostream &os) const override;
	static std::unique_ptr<dirty> from_c(const IRStmt *s);
};

struct MBE : public IR_stmt_xx {
	IR_MBUS_event_xx event;

	std::ostream &pretty_print(std::ostream &os) const override;
	static std::unique_ptr<MBE> from_c(const IRStmt *s);
};

struct exit : public IR_stmt_xx {
	std::unique_ptr<IR_expr_xx> guard;
	std::unique_ptr<IR_const_xx> dst;
	IR_jump_kind_xx jk;
	Int offs_IP;

	std::ostream &pretty_print(std::ostream &os) const override;
	static std::unique_ptr<exit> from_c(const IRStmt *s);
};

} // namespace IR_stmt_types

struct IRSB_xx {

	std::unique_ptr<IR_type_env_xx> tyenv;
	std::vector<std::unique_ptr<IR_stmt_xx>> stmts;
	std::unique_ptr<IR_expr_xx> next;
	IR_jump_kind_xx jumpkind;
	Int offsIP;

	static std::unique_ptr<IRSB_xx> from_c(const IRSB *bb);
	friend std::ostream &operator<<(std::ostream &os, const IRSB_xx &irsb);
	std::ostream &pretty_print(std::ostream &os) const;
};

std::ostream &operator<<(std::ostream &os, const IRSB_xx &irsb);

} // namespace libvexxx

#endif