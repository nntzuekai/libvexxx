#pragma once

#ifndef IR_ENUMS_H_INCLUDED
#define IR_ENUMS_H_INCLUDED

extern "C" {
#include "libvex.h"
}

#include <iostream>
#include "IR_op_xx.h"

namespace libvexxx {

enum struct IR_jump_kind_xx {
	Ijk_INVALID = 0x1A00,
	Ijk_Boring,        /* not interesting; just goto next */
	Ijk_Call,          /* guest is doing a call */
	Ijk_Ret,           /* guest is doing a return */
	Ijk_ClientReq,     /* do guest client req before continuing */
	Ijk_Yield,         /* client is yielding to thread scheduler */
	Ijk_EmWarn,        /* report emulation warning before continuing */
	Ijk_EmFail,        /* emulation critical (FATAL) error; give up */
	Ijk_NoDecode,      /* current instruction cannot be decoded */
	Ijk_MapFail,       /* Vex-provided address translation failed */
	Ijk_InvalICache,   /* Inval icache for range [CMSTART, +CMLEN) */
	Ijk_FlushDCache,   /* Flush dcache for range [CMSTART, +CMLEN) */
	Ijk_NoRedir,       /* Jump to un-redirected guest addr */
	Ijk_SigILL,        /* current instruction synths SIGILL */
	Ijk_SigTRAP,       /* current instruction synths SIGTRAP */
	Ijk_SigSEGV,       /* current instruction synths SIGSEGV */
	Ijk_SigBUS,        /* current instruction synths SIGBUS */
	Ijk_SigFPE,        /* current instruction synths generic SIGFPE */
	Ijk_SigFPE_IntDiv, /* current instruction synths SIGFPE - IntDiv */
	Ijk_SigFPE_IntOvf, /* current instruction synths SIGFPE - IntOvf */
	Ijk_Privileged,    /* current instruction should fail depending on privilege
	                      level */
	/* Unfortunately, various guest-dependent syscall kinds.  They
   all mean: do a syscall before continuing. */
	Ijk_Sys_syscall, /* amd64/x86 'syscall', ppc 'sc', arm 'svc #0' */
	Ijk_Sys_int32,   /* amd64/x86 'int $0x20' */
	Ijk_Sys_int128,  /* amd64/x86 'int $0x80' */
	Ijk_Sys_int129,  /* amd64/x86 'int $0x81' */
	Ijk_Sys_int130,  /* amd64/x86 'int $0x82' */
	Ijk_Sys_int145,  /* amd64/x86 'int $0x91' */
	Ijk_Sys_int210,  /* amd64/x86 'int $0xD2' */
	Ijk_Sys_sysenter /* x86 'sysenter'.  guest_EIP becomes
	                    invalid at the point this happens. */
};

enum struct IR_type_xx {
	Ity_INVALID = 0x1100,
	Ity_I1,
	Ity_I8,
	Ity_I16,
	Ity_I32,
	Ity_I64,
	Ity_I128, /* 128-bit scalar */
	Ity_F16,  /* 16 bit float */
	Ity_F32,  /* IEEE 754 float */
	Ity_F64,  /* IEEE 754 double */
	Ity_D32,  /* 32-bit Decimal floating point */
	Ity_D64,  /* 64-bit Decimal floating point */
	Ity_D128, /* 128-bit Decimal floating point */
	Ity_F128, /* 128-bit floating point; implementation defined */
	Ity_V128, /* 128-bit SIMD */
	Ity_V256  /* 256-bit SIMD */
};

enum struct IR_load_G_op_xx {
	ILGop_INVALID = 0x1D00,
	ILGop_IdentV128, /* 128 bit vector, no conversion */
	ILGop_Ident64,   /* 64 bit, no conversion */
	ILGop_Ident32,   /* 32 bit, no conversion */
	ILGop_16Uto32,   /* 16 bit load, Z-widen to 32 */
	ILGop_16Sto32,   /* 16 bit load, S-widen to 32 */
	ILGop_8Uto32,    /* 8 bit load, Z-widen to 32 */
	ILGop_8Sto32     /* 8 bit load, S-widen to 32 */
};

enum struct IR_endness_xx {
	Iend_LE = 0x1200, /* little endian */
	Iend_BE           /* big endian */
};

enum struct IR_effect_xx{
	Ifx_None = 0x1B00, /* no effect */
	Ifx_Read,          /* reads the resource */
	Ifx_Write,         /* writes the resource */
	Ifx_Modify,        /* modifies the resource */
};

enum struct IR_MBUS_event_xx{
	Imbe_Fence = 0x1C00,
	/* Needed only on ARM.  It cancels a reservation made by a
	   preceding Linked-Load, and needs to be handed through to the
	   back end, just as LL and SC themselves are. */
	Imbe_CancelReservation
};

enum struct IR_temp_xx:unsigned int{
	invalid=0xFFFFFFFF,
};


std::ostream &operator<<(std::ostream &os, IR_jump_kind_xx kind);
std::ostream &operator<<(std::ostream &os, IR_type_xx kind);
std::ostream &operator<<(std::ostream &os, IR_load_G_op_xx cvt);
std::ostream &operator<<(std::ostream &os, IR_endness_xx e);
std::ostream &operator<<(std::ostream &os, IR_effect_xx fx);
std::ostream &operator<<(std::ostream &os, IR_MBUS_event_xx eve);
std::ostream &operator<<(std::ostream &os, IR_temp_xx tmp);


} // namespace libvexxx

#endif