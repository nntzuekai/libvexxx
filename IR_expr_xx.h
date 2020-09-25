#pragma once

#ifndef INCLUDE_IR_EXPR_XX_H
#define INCLUDE_IR_EXPR_XX_H

extern "C" {
#include "pyvex.h"
// #include "libvex.h"
}
#include "IR_enums.h"
#include "guest_register_list.h"

#include <memory>
#include <vector>

namespace libvexxx {

struct IR_callee_xx {
	Int regparms;
	std::string name;

	void *addr;
	UInt mcx_mask;

	friend std::ostream &operator<<(std::ostream &os, const IR_callee_xx &cee);

	std::ostream &pretty_print(std::ostream &os) const;
	static std::unique_ptr<IR_callee_xx> from_c(const IRCallee *ce);
};

std::ostream &operator<<(std::ostream &os, const IR_callee_xx &cee);

struct IR_const_xx : public IRConst {
	// IRConstTag tag;

	// union {
	// 	Bool U1;
	// 	UChar U8;
	// 	UShort U16;
	// 	UInt U32;
	// 	ULong U64;
	// 	Float F32;
	// 	UInt F32i;
	// 	Double F64;
	// 	ULong F64i;
	// 	UShort V128;
	// 	UInt V256;
	// } Ico;
	std::ostream &pretty_print(std::ostream &os) const;
	friend std::ostream &operator<<(std::ostream &os, const IR_const_xx &e);

	static std::unique_ptr<IR_const_xx> from_c(const IRConst *s);
};

std::ostream &operator<<(std::ostream &os, const IR_const_xx &e);

void copy_IRRegArray(IRRegArray *dst, const IRRegArray *src);

std::ostream &operator<<(std::ostream &os, const IRRegArray &arr);

struct IR_expr_xx {
#ifdef LIBVEXXX_TAGGED
	IRExprTag tag;
#endif

	virtual std::ostream &pretty_print(std::ostream &os, arch_type arch=arch_type::amd64) const = 0;

	/*
	friend std::ostream &operator<<(std::ostream &os, const IR_expr_xx &e);
	*/

	static std::unique_ptr<IR_expr_xx> from_c(const IRExpr *e);
	virtual IRExprTag type_tag() const=0;
};

/*
std::ostream &operator<<(std::ostream &os, const IR_expr_xx &e);
*/

/*
struct IR_Q_op_xx{
    IR_op_xx op;
    std::unique_ptr<IR_expr_xx> arg1;
    std::unique_ptr<IR_expr_xx> arg2;
    std::unique_ptr<IR_expr_xx> arg3;
    std::unique_ptr<IR_expr_xx> arg4;

    static std::unique_ptr<IR_Q_op_xx> from_c(const IRQop *e);
};

struct IR_tri_op_xx{
    IR_op_xx op;
    std::unique_ptr<IR_expr_xx> arg1;
    std::unique_ptr<IR_expr_xx> arg2;
    std::unique_ptr<IR_expr_xx> arg3;

    static std::unique_ptr<IR_tri_op_xx> from_c(const IRTriop *e);
};
*/

namespace ir_expr_types {

struct binder : public IR_expr_xx {
	Int bd;

	virtual std::ostream &pretty_print(std::ostream &os, arch_type arch=arch_type::amd64) const override;
	static std::unique_ptr<binder> from_c(const IRExpr *e);
	virtual IRExprTag type_tag() const override;
};

struct get_R : public IR_expr_xx {
	Int offset;
	IR_type_xx ty;

	virtual std::ostream &pretty_print(std::ostream &os, arch_type arch=arch_type::amd64) const override;
	static std::unique_ptr<get_R> from_c(const IRExpr *e);
	virtual IRExprTag type_tag() const override;
};

struct get_I : public IR_expr_xx {
	IRRegArray descr;
	std::unique_ptr<IR_expr_xx> ix;
	Int bias;

	virtual std::ostream &pretty_print(std::ostream &os, arch_type arch=arch_type::amd64) const override;
	static std::unique_ptr<get_I> from_c(const IRExpr *e);
	virtual IRExprTag type_tag() const override;
};

struct rd_tmp : public IR_expr_xx {
	IR_temp_xx tmp;

	virtual std::ostream &pretty_print(std::ostream &os, arch_type arch=arch_type::amd64) const override;
	static std::unique_ptr<rd_tmp> from_c(const IRExpr *e);
	virtual IRExprTag type_tag() const override;
};

struct Q_op : public IR_expr_xx {
	// std::unique_ptr<IR_Q_op_xx> details;
	IR_op_xx op;
	std::unique_ptr<IR_expr_xx> arg1;
	std::unique_ptr<IR_expr_xx> arg2;
	std::unique_ptr<IR_expr_xx> arg3;
	std::unique_ptr<IR_expr_xx> arg4;

	virtual std::ostream &pretty_print(std::ostream &os, arch_type arch=arch_type::amd64) const override;
	static std::unique_ptr<Q_op> from_c(const IRExpr *e);
	virtual IRExprTag type_tag() const override;
};

struct tri_op : public IR_expr_xx {
	// std::unique_ptr<IR_tri_op_xx> details;
	IR_op_xx op;
	std::unique_ptr<IR_expr_xx> arg1;
	std::unique_ptr<IR_expr_xx> arg2;
	std::unique_ptr<IR_expr_xx> arg3;

	virtual std::ostream &pretty_print(std::ostream &os, arch_type arch=arch_type::amd64) const override;
	static std::unique_ptr<tri_op> from_c(const IRExpr *e);
	virtual IRExprTag type_tag() const override;
};

struct bin_op : public IR_expr_xx {
	IR_op_xx op;
	std::unique_ptr<IR_expr_xx> arg1;
	std::unique_ptr<IR_expr_xx> arg2;

	virtual std::ostream &pretty_print(std::ostream &os, arch_type arch=arch_type::amd64) const override;
	static std::unique_ptr<bin_op> from_c(const IRExpr *e);
	virtual IRExprTag type_tag() const override;
};

struct un_op : public IR_expr_xx {
	IR_op_xx op;
	std::unique_ptr<IR_expr_xx> arg;

	virtual std::ostream &pretty_print(std::ostream &os, arch_type arch=arch_type::amd64) const override;
	static std::unique_ptr<un_op> from_c(const IRExpr *e);
	virtual IRExprTag type_tag() const override;
};

struct load : public IR_expr_xx {
	IR_endness_xx end;
	IR_type_xx ty;
	std::unique_ptr<IR_expr_xx> addr;

	virtual std::ostream &pretty_print(std::ostream &os, arch_type arch=arch_type::amd64) const override;
	static std::unique_ptr<load> from_c(const IRExpr *e);
	virtual IRExprTag type_tag() const override;
};

struct constant : public IR_expr_xx {
	std::unique_ptr<IR_const_xx> con;

	virtual std::ostream &pretty_print(std::ostream &os, arch_type arch=arch_type::amd64) const override;
	static std::unique_ptr<constant> from_c(const IRExpr *e);
	virtual IRExprTag type_tag() const override;
};

struct C_call : public IR_expr_xx {
	std::unique_ptr<IR_callee_xx> cee;
	IR_type_xx ret_ty;
	std::vector<std::unique_ptr<IR_expr_xx>> args;

	virtual std::ostream &pretty_print(std::ostream &os, arch_type arch=arch_type::amd64) const override;
	static std::unique_ptr<C_call> from_c(const IRExpr *e);
	virtual IRExprTag type_tag() const override;
};

struct ITE : public IR_expr_xx {
	std::unique_ptr<IR_expr_xx> cond;
	std::unique_ptr<IR_expr_xx> if_true;
	std::unique_ptr<IR_expr_xx> if_false;

	virtual std::ostream &pretty_print(std::ostream &os, arch_type arch=arch_type::amd64) const override;
	static std::unique_ptr<ITE> from_c(const IRExpr *e);
	virtual IRExprTag type_tag() const override;
};

struct VECRET : public IR_expr_xx {
	virtual std::ostream &pretty_print(std::ostream &os, arch_type arch=arch_type::amd64) const override;
	static std::unique_ptr<VECRET> from_c(const IRExpr *e);
	virtual IRExprTag type_tag() const override;
};

struct GSPTR : public IR_expr_xx {
	virtual std::ostream &pretty_print(std::ostream &os, arch_type arch=arch_type::amd64) const override;
	static std::unique_ptr<GSPTR> from_c(const IRExpr *e);
	virtual IRExprTag type_tag() const override;
};

} // namespace ir_expr_types

} // namespace libvexxx

#endif