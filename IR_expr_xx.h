#ifndef INCLUDE_IR_EXPR_XX_H
#define INCLUDE_IR_EXPR_XX_H

extern "C" {
#include "pyvex.h"
// #include "libvex.h"
}
#include <memory>
#include <vector>

namespace libvexxx {


struct IR_callee_xx {
	Int regparms;
	std::string name;

	void *addr;
	UInt mcx_mask;

	std::ostream& pretty_print(std::ostream &os) const;
	static std::unique_ptr<IR_callee_xx> from_c(const IRCallee *ce);
};

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
	static std::unique_ptr<IR_const_xx> from_c(const IRConst *s);
};

void copy_IRRegArray(IRRegArray *dst,const IRRegArray *src);

std::ostream& operator<<(std::ostream &os, const IR_expr_xx &e);

struct IR_expr_xx {
	IRExprTag tag;

	std::ostream& pretty_print(std::ostream &os) const;
	friend std::ostream& operator<<(std::ostream &os, const IR_expr_xx &e);
	static std::unique_ptr<IR_expr_xx> from_c(const IRExpr *e);
};

/*
struct IR_Q_op_xx{
	IROp op;
	std::unique_ptr<IR_expr_xx> arg1;
	std::unique_ptr<IR_expr_xx> arg2;
	std::unique_ptr<IR_expr_xx> arg3;
	std::unique_ptr<IR_expr_xx> arg4;

	static std::unique_ptr<IR_Q_op_xx> from_c(const IRQop *e);
};

struct IR_tri_op_xx{
	IROp op;
	std::unique_ptr<IR_expr_xx> arg1;
	std::unique_ptr<IR_expr_xx> arg2;
	std::unique_ptr<IR_expr_xx> arg3;

	static std::unique_ptr<IR_tri_op_xx> from_c(const IRTriop *e);
};
*/

namespace ir_expr_types{

struct Binder:public IR_expr_xx{
	Int binder;

	static std::unique_ptr<Binder> from_c(const IRExpr *e);
};

struct Get:public IR_expr_xx{
	Int offset;
	IRType ty;

	static std::unique_ptr<Get> from_c(const IRExpr *e);
};

struct Get_I:public IR_expr_xx{
	IRRegArray descr;
	std::unique_ptr<IR_expr_xx> ix;
	Int bias;

	static std::unique_ptr<Get_I> from_c(const IRExpr *e);
};

struct Rd_tmp:public IR_expr_xx{
	IRTemp tmp;

	static std::unique_ptr<Rd_tmp> from_c(const IRExpr *e);
};

struct Q_op:public IR_expr_xx{
	// std::unique_ptr<IR_Q_op_xx> details;
	IROp op;
	std::unique_ptr<IR_expr_xx> arg1;
	std::unique_ptr<IR_expr_xx> arg2;
	std::unique_ptr<IR_expr_xx> arg3;
	std::unique_ptr<IR_expr_xx> arg4;

	static std::unique_ptr<Q_op> from_c(const IRExpr *e);
};

struct tri_op:public IR_expr_xx{
	// std::unique_ptr<IR_tri_op_xx> details;
	IROp op;
	std::unique_ptr<IR_expr_xx> arg1;
	std::unique_ptr<IR_expr_xx> arg2;
	std::unique_ptr<IR_expr_xx> arg3;

	static std::unique_ptr<tri_op> from_c(const IRExpr *e);
};

struct bin_op:public IR_expr_xx{
	IROp op;
	std::unique_ptr<IR_expr_xx> arg1;
	std::unique_ptr<IR_expr_xx> arg2;

	static std::unique_ptr<bin_op> from_c(const IRExpr *e);
};

struct un_op:public IR_expr_xx{
	IROp op;
	std::unique_ptr<IR_expr_xx> arg;

	static std::unique_ptr<un_op> from_c(const IRExpr *e);
};

struct load:public IR_expr_xx{
	IREndness end;
	IRType ty;
	std::unique_ptr<IR_expr_xx> addr;

	static std::unique_ptr<load> from_c(const IRExpr *e);
};

struct Const:public IR_expr_xx{
	std::unique_ptr<IR_const_xx> con;

	static std::unique_ptr<Const> from_c(const IRExpr *e);
};

struct C_call:public IR_expr_xx{
	std::unique_ptr<IR_callee_xx> cee;
	IRType ret_ty;
	std::vector<std::unique_ptr<IR_expr_xx>> args;

	static std::unique_ptr<C_call> from_c(const IRExpr *e);
};

struct ITE:public IR_expr_xx{
	std::unique_ptr<IR_expr_xx> cond;
	std::unique_ptr<IR_expr_xx> if_true;
	std::unique_ptr<IR_expr_xx> if_false;


	static std::unique_ptr<ITE> from_c(const IRExpr *e);
};

struct VECRET:public IR_expr_xx{
	static std::unique_ptr<VECRET> from_c(const IRExpr *e);
};

struct GSPTR:public IR_expr_xx{
	static std::unique_ptr<GSPTR> from_c(const IRExpr *e);
};

}


}

#endif