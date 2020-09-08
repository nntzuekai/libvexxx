#pragma once

#ifndef GUEST_REGISTER_LIST_H_INCLUDED
#define GUEST_REGISTER_LIST_H_INCLUDED

#include <map>

extern "C" {
#include "libvex.h"
}

namespace libvexxx {

extern const std::map<int, const char *> x86_reg_list;
extern const std::map<int, const char *> amd64_reg_list;
extern const std::map<int, const char *> ppc32_reg_list;
extern const std::map<int, const char *> ppc64_reg_list;
extern const std::map<int, const char *> arm_reg_list;
extern const std::map<int, const char *> arm64_reg_list;
extern const std::map<int, const char *> s390x_reg_list;
extern const std::map<int, const char *> mips32_reg_list;
extern const std::map<int, const char *> mips64_reg_list;
extern const std::map<int, const char *> tilegx_reg_list;

enum struct arch_type {
	x86,
	amd64,
	ppc32,
	ppc64,
	arm,
	arm64,
	s390x,
	mips32,
	mips64,
	tilegx,
};

const char *guest_register_name(Int offset, arch_type arch = arch_type::amd64);

} // namespace libvexxx

#endif