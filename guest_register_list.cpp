#include "guest_register_list.h"

namespace libvexxx {

const std::map<int, const char *> x86_reg_list = {
    {8, "eax"},        {12, "ecx"},
    {16, "edx"},       {20, "ebx"},
    {24, "esp"},       {28, "ebp"},
    {32, "esi"},       {36, "edi"},
    {40, "cc_op"},     {44, "cc_dep1"},
    {48, "cc_dep2"},   {52, "cc_ndep"},
    {56, "dflag"},     {60, "idflag"},
    {64, "acflag"},    {68, "eip"},
    {72, "fpreg"},     {136, "fptag"},
    {144, "fpround"},  {148, "fc3210"},
    {152, "ftop"},     {156, "sseround"},
    {160, "xmm0"},     {176, "xmm1"},
    {192, "xmm2"},     {208, "xmm3"},
    {224, "xmm4"},     {240, "xmm5"},
    {256, "xmm6"},     {272, "xmm7"},
    {288, "cs"},       {290, "ds"},
    {292, "es"},       {294, "fs"},
    {296, "gs"},       {298, "ss"},
    {304, "ldt"},      {312, "gdt"},
    {320, "emnote"},   {324, "cmstart"},
    {328, "cmlen"},    {332, "nraddr"},
    {336, "sc_class"}, {340, "ip_at_syscall"},
};

const std::map<int, const char *> amd64_reg_list{
    {16, "rax"},        {40, "rbx"},        {24, "rcx"},
    {32, "rdx"},        {64, "rsi"},        {72, "rdi"},
    {48, "rsp"},        {56, "rbp"},        {80, "r8"},
    {88, "r9"},         {96, "r10"},        {104, "r11"},
    {112, "r12"},       {120, "r13"},       {128, "r14"},
    {136, "r15"},       {184, "rip"},       {1040, "ip_at_syscall"},
    {144, "cc_op"},     {152, "cc_dep1"},   {160, "cc_dep2"},
    {168, "cc_ndep"},   {176, "dflag"},     {192, "acflag"},
    {200, "idflag"},    {208, "fs_const"},  {216, "sseround"},
    {224, "ymm0"},      {256, "ymm1"},      {288, "ymm2"},
    {320, "ymm3"},      {352, "ymm4"},      {384, "ymm5"},
    {416, "ymm6"},      {448, "ymm7"},      {480, "ymm8"},
    {512, "ymm9"},      {544, "ymm10"},     {576, "ymm11"},
    {608, "ymm12"},     {640, "ymm13"},     {672, "ymm14"},
    {704, "ymm15"},     {736, "ymm16"},     {768, "cr0"},
    {776, "cr1"},       {784, "cr2"},       {792, "cr3"},
    {800, "cr4"},       {808, "cr5"},       {816, "cr6"},
    {824, "cr7"},       {832, "cr8"},       {840, "cr9"},
    {848, "cr10"},      {856, "cr11"},      {864, "cr12"},
    {872, "cr13"},      {880, "cr14"},      {888, "cr15"},
    {896, "ftop"},      {904, "fpreg"},     {968, "fptag"},
    {976, "fpround"},   {984, "fc3210"},    {992, "emnote"},
    {1000, "cmstart"},  {1008, "cmlen"},    {1016, "nraddr"},
    {1024, "sc_class"}, {1032, "gs_const"},
};

const std::map<int, const char *> ppc32_reg_list{
    {16, "gpr0"},       {20, "gpr1"},          {24, "gpr2"},
    {28, "gpr3"},       {32, "gpr4"},          {36, "gpr5"},
    {40, "gpr6"},       {44, "gpr7"},          {48, "gpr8"},
    {52, "gpr9"},       {56, "gpr10"},         {60, "gpr11"},
    {64, "gpr12"},      {68, "gpr13"},         {72, "gpr14"},
    {76, "gpr15"},      {80, "gpr16"},         {84, "gpr17"},
    {88, "gpr18"},      {92, "gpr19"},         {96, "gpr20"},
    {100, "gpr21"},     {104, "gpr22"},        {108, "gpr23"},
    {112, "gpr24"},     {116, "gpr25"},        {120, "gpr26"},
    {124, "gpr27"},     {128, "gpr28"},        {132, "gpr29"},
    {136, "gpr30"},     {140, "gpr31"},        {144, "vsr0"},
    {160, "vsr1"},      {176, "vsr2"},         {192, "vsr3"},
    {208, "vsr4"},      {224, "vsr5"},         {240, "vsr6"},
    {256, "vsr7"},      {272, "vsr8"},         {288, "vsr9"},
    {304, "vsr10"},     {320, "vsr11"},        {336, "vsr12"},
    {352, "vsr13"},     {368, "vsr14"},        {384, "vsr15"},
    {400, "vsr16"},     {416, "vsr17"},        {432, "vsr18"},
    {448, "vsr19"},     {464, "vsr20"},        {480, "vsr21"},
    {496, "vsr22"},     {512, "vsr23"},        {528, "vsr24"},
    {544, "vsr25"},     {560, "vsr26"},        {576, "vsr27"},
    {592, "vsr28"},     {608, "vsr29"},        {624, "vsr30"},
    {640, "vsr31"},     {656, "vsr32"},        {672, "vsr33"},
    {688, "vsr34"},     {704, "vsr35"},        {720, "vsr36"},
    {736, "vsr37"},     {752, "vsr38"},        {768, "vsr39"},
    {784, "vsr40"},     {800, "vsr41"},        {816, "vsr42"},
    {832, "vsr43"},     {848, "vsr44"},        {864, "vsr45"},
    {880, "vsr46"},     {896, "vsr47"},        {912, "vsr48"},
    {928, "vsr49"},     {944, "vsr50"},        {960, "vsr51"},
    {976, "vsr52"},     {992, "vsr53"},        {1008, "vsr54"},
    {1024, "vsr55"},    {1040, "vsr56"},       {1056, "vsr57"},
    {1072, "vsr58"},    {1088, "vsr59"},       {1104, "vsr60"},
    {1120, "vsr61"},    {1136, "vsr62"},       {1152, "vsr63"},
    {1168, "cia"},      {1172, "lr"},          {1176, "ctr"},
    {1180, "xer_so"},   {1181, "xer_ov"},      {1182, "xer_ca"},
    {1183, "xer_bc"},   {1184, "cr0_321"},     {1185, "cr0_0"},
    {1186, "cr1_321"},  {1187, "cr1_0"},       {1188, "cr2_321"},
    {1189, "cr2_0"},    {1190, "cr3_321"},     {1191, "cr3_0"},
    {1192, "cr4_321"},  {1193, "cr4_0"},       {1194, "cr5_321"},
    {1195, "cr5_0"},    {1196, "cr6_321"},     {1197, "cr6_0"},
    {1198, "cr7_321"},  {1199, "cr7_0"},       {1200, "fpround"},
    {1201, "dfpround"}, {1202, "c_fpcc"},      {1204, "vrsave"},
    {1208, "vscr"},     {1212, "emnote"},      {1216, "cmstart"},
    {1220, "cmlen"},    {1224, "nraddr"},      {1228, "nraddr_gpr2"},
    {1232, "redir_sp"}, {1236, "redir_stack"}, {1364, "ip_at_syscall"},
    {1368, "sprg3_ro"}, {1376, "tfhar"},       {1384, "texasr"},
    {1392, "tfiar"},    {1400, "ppr"},         {1408, "texasru"},
    {1412, "pspb"},
};

const std::map<int, const char *> ppc64_reg_list{
    {16, "gpr0"},       {24, "gpr1"},          {32, "gpr2"},
    {40, "gpr3"},       {48, "gpr4"},          {56, "gpr5"},
    {64, "gpr6"},       {72, "gpr7"},          {80, "gpr8"},
    {88, "gpr9"},       {96, "gpr10"},         {104, "gpr11"},
    {112, "gpr12"},     {120, "gpr13"},        {128, "gpr14"},
    {136, "gpr15"},     {144, "gpr16"},        {152, "gpr17"},
    {160, "gpr18"},     {168, "gpr19"},        {176, "gpr20"},
    {184, "gpr21"},     {192, "gpr22"},        {200, "gpr23"},
    {208, "gpr24"},     {216, "gpr25"},        {224, "gpr26"},
    {232, "gpr27"},     {240, "gpr28"},        {248, "gpr29"},
    {256, "gpr30"},     {264, "gpr31"},        {272, "vsr0"},
    {288, "vsr1"},      {304, "vsr2"},         {320, "vsr3"},
    {336, "vsr4"},      {352, "vsr5"},         {368, "vsr6"},
    {384, "vsr7"},      {400, "vsr8"},         {416, "vsr9"},
    {432, "vsr10"},     {448, "vsr11"},        {464, "vsr12"},
    {480, "vsr13"},     {496, "vsr14"},        {512, "vsr15"},
    {528, "vsr16"},     {544, "vsr17"},        {560, "vsr18"},
    {576, "vsr19"},     {592, "vsr20"},        {608, "vsr21"},
    {624, "vsr22"},     {640, "vsr23"},        {656, "vsr24"},
    {672, "vsr25"},     {688, "vsr26"},        {704, "vsr27"},
    {720, "vsr28"},     {736, "vsr29"},        {752, "vsr30"},
    {768, "vsr31"},     {784, "vsr32"},        {800, "vsr33"},
    {816, "vsr34"},     {832, "vsr35"},        {848, "vsr36"},
    {864, "vsr37"},     {880, "vsr38"},        {896, "vsr39"},
    {912, "vsr40"},     {928, "vsr41"},        {944, "vsr42"},
    {960, "vsr43"},     {976, "vsr44"},        {992, "vsr45"},
    {1008, "vsr46"},    {1024, "vsr47"},       {1040, "vsr48"},
    {1056, "vsr49"},    {1072, "vsr50"},       {1088, "vsr51"},
    {1104, "vsr52"},    {1120, "vsr53"},       {1136, "vsr54"},
    {1152, "vsr55"},    {1168, "vsr56"},       {1184, "vsr57"},
    {1200, "vsr58"},    {1216, "vsr59"},       {1232, "vsr60"},
    {1248, "vsr61"},    {1264, "vsr62"},       {1280, "vsr63"},
    {1296, "cia"},      {1304, "lr"},          {1312, "ctr"},
    {1320, "xer_so"},   {1321, "xer_ov"},      {1322, "xer_ca"},
    {1323, "xer_bc"},   {1324, "cr0_321"},     {1325, "cr0_0"},
    {1326, "cr1_321"},  {1327, "cr1_0"},       {1328, "cr2_321"},
    {1329, "cr2_0"},    {1330, "cr3_321"},     {1331, "cr3_0"},
    {1332, "cr4_321"},  {1333, "cr4_0"},       {1334, "cr5_321"},
    {1335, "cr5_0"},    {1336, "cr6_321"},     {1337, "cr6_0"},
    {1338, "cr7_321"},  {1339, "cr7_0"},       {1340, "fpround"},
    {1341, "dfpround"}, {1342, "c_fpcc"},      {1344, "vrsave"},
    {1348, "vscr"},     {1352, "emnote"},      {1360, "cmstart"},
    {1368, "cmlen"},    {1376, "nraddr"},      {1384, "nraddr_gpr2"},
    {1392, "redir_sp"}, {1400, "redir_stack"}, {1656, "ip_at_syscall"},
    {1664, "sprg3_ro"}, {1672, "tfhar"},       {1680, "texasr"},
    {1688, "tfiar"},    {1696, "ppr"},         {1704, "texasru"},
    {1708, "pspb"},
};

const std::map<int, const char *> arm_reg_list{
    {8, "r0"},         {12, "r1"},       {16, "r2"},
    {20, "r3"},        {24, "r4"},       {28, "r5"},
    {32, "r6"},        {36, "r7"},       {40, "r8"},
    {44, "r9"},        {48, "r10"},      {52, "r11"},
    {56, "r12"},       {60, "r13"},      {64, "r14"},
    {68, "r15t"},      {72, "cc_op"},    {76, "cc_dep1"},
    {80, "cc_dep2"},   {84, "cc_ndep"},  {88, "qflag32"},
    {92, "geflag0"},   {96, "geflag1"},  {100, "geflag2"},
    {104, "geflag3"},  {108, "emnote"},  {112, "cmstart"},
    {116, "cmlen"},    {120, "nraddr"},  {124, "ip_at_syscall"},
    {128, "d0"},       {136, "d1"},      {144, "d2"},
    {152, "d3"},       {160, "d4"},      {168, "d5"},
    {176, "d6"},       {184, "d7"},      {192, "d8"},
    {200, "d9"},       {208, "d10"},     {216, "d11"},
    {224, "d12"},      {232, "d13"},     {240, "d14"},
    {248, "d15"},      {256, "d16"},     {264, "d17"},
    {272, "d18"},      {280, "d19"},     {288, "d20"},
    {296, "d21"},      {304, "d22"},     {312, "d23"},
    {320, "d24"},      {328, "d25"},     {336, "d26"},
    {344, "d27"},      {352, "d28"},     {360, "d29"},
    {368, "d30"},      {376, "d31"},     {384, "fpscr"},
    {388, "tpidruro"}, {392, "itstate"},
};

const std::map<int, const char *> arm64_reg_list{
    {16, "x0"},       {24, "x1"},
    {32, "x2"},       {40, "x3"},
    {48, "x4"},       {56, "x5"},
    {64, "x6"},       {72, "x7"},
    {80, "x8"},       {88, "x9"},
    {96, "x10"},      {104, "x11"},
    {112, "x12"},     {120, "x13"},
    {128, "x14"},     {136, "x15"},
    {144, "x16"},     {152, "x17"},
    {160, "x18"},     {168, "x19"},
    {176, "x20"},     {184, "x21"},
    {192, "x22"},     {200, "x23"},
    {208, "x24"},     {216, "x25"},
    {224, "x26"},     {232, "x27"},
    {240, "x28"},     {248, "x29"},
    {256, "x30"},     {264, "xsp"},
    {272, "pc"},      {280, "cc_op"},
    {288, "cc_dep1"}, {296, "cc_dep2"},
    {304, "cc_ndep"}, {312, "tpidr_el0"},
    {320, "q0"},      {336, "q1"},
    {352, "q2"},      {368, "q3"},
    {384, "q4"},      {400, "q5"},
    {416, "q6"},      {432, "q7"},
    {448, "q8"},      {464, "q9"},
    {480, "q10"},     {496, "q11"},
    {512, "q12"},     {528, "q13"},
    {544, "q14"},     {560, "q15"},
    {576, "q16"},     {592, "q17"},
    {608, "q18"},     {624, "q19"},
    {640, "q20"},     {656, "q21"},
    {672, "q22"},     {688, "q23"},
    {704, "q24"},     {720, "q25"},
    {736, "q26"},     {752, "q27"},
    {768, "q28"},     {784, "q29"},
    {800, "q30"},     {816, "q31"},
    {832, "qcflag"},  {848, "emnote"},
    {856, "cmstart"}, {864, "cmlen"},
    {872, "nraddr"},  {880, "ip_at_syscall"},
    {888, "fpcr"},
};

const std::map<int, const char *> s390x_reg_list{
    {0, "a0"},        {4, "a1"},
    {8, "a2"},        {12, "a3"},
    {16, "a4"},       {20, "a5"},
    {24, "a6"},       {28, "a7"},
    {32, "a8"},       {36, "a9"},
    {40, "a10"},      {44, "a11"},
    {48, "a12"},      {52, "a13"},
    {56, "a14"},      {60, "a15"},
    {64, "v0"},       {80, "v1"},
    {96, "v2"},       {112, "v3"},
    {128, "v4"},      {144, "v5"},
    {160, "v6"},      {176, "v7"},
    {192, "v8"},      {208, "v9"},
    {224, "v10"},     {240, "v11"},
    {256, "v12"},     {272, "v13"},
    {288, "v14"},     {304, "v15"},
    {320, "v16"},     {336, "v17"},
    {352, "v18"},     {368, "v19"},
    {384, "v20"},     {400, "v21"},
    {416, "v22"},     {432, "v23"},
    {448, "v24"},     {464, "v25"},
    {480, "v26"},     {496, "v27"},
    {512, "v28"},     {528, "v29"},
    {544, "v30"},     {560, "v31"},
    {576, "r0"},      {584, "r1"},
    {592, "r2"},      {600, "r3"},
    {608, "r4"},      {616, "r5"},
    {624, "r6"},      {632, "r7"},
    {640, "r8"},      {648, "r9"},
    {656, "r10"},     {664, "r11"},
    {672, "r12"},     {680, "r13"},
    {688, "r14"},     {696, "r15"},
    {704, "counter"}, {712, "fpc"},
    {720, "ia"},      {728, "sysno"},
    {736, "cc_op"},   {744, "cc_dep1"},
    {752, "cc_dep2"}, {760, "cc_ndep"},
    {768, "nraddr"},  {776, "cmstart"},
    {784, "cmlen"},   {792, "ip_at_syscall"},
    {800, "emnote"},
};

const std::map<int, const char *> mips32_reg_list{
    {8, "r0"},
    {12, "r1"},
    {16, "r2"},
    {20, "r3"},
    {24, "r4"},
    {28, "r5"},
    {32, "r6"},
    {36, "r7"},
    {40, "r8"},
    {44, "r9"},
    {48, "r10"},
    {52, "r11"},
    {56, "r12"},
    {60, "r13"},
    {64, "r14"},
    {68, "r15"},
    {72, "r16"},
    {76, "r17"},
    {80, "r18"},
    {84, "r19"},
    {88, "r20"},
    {92, "r21"},
    {96, "r22"},
    {100, "r23"},
    {104, "r24"},
    {108, "r25"},
    {112, "r26"},
    {116, "r27"},
    {120, "r28"},
    {124, "r29"},
    {128, "r30"},
    {132, "r31"},
    {136, "pc"},
    {140, "hi"},
    {144, "lo"},
    {152, "f0"},
    {160, "f1"},
    {168, "f2"},
    {176, "f3"},
    {184, "f4"},
    {192, "f5"},
    {200, "f6"},
    {208, "f7"},
    {216, "f8"},
    {224, "f9"},
    {232, "f10"},
    {240, "f11"},
    {248, "f12"},
    {256, "f13"},
    {264, "f14"},
    {272, "f15"},
    {280, "f16"},
    {288, "f17"},
    {296, "f18"},
    {304, "f19"},
    {312, "f20"},
    {320, "f21"},
    {328, "f22"},
    {336, "f23"},
    {344, "f24"},
    {352, "f25"},
    {360, "f26"},
    {368, "f27"},
    {376, "f28"},
    {384, "f29"},
    {392, "f30"},
    {400, "f31"},
    {408, "fir"},
    {412, "fccr"},
    {416, "fexr"},
    {420, "fenr"},
    {424, "fcsr"},
    {428, "ulr"},
    {432, "emnote"},
    {436, "cmstart"},
    {440, "cmlen"},
    {444, "nraddr"},
    {448, "cond"},
    {452, "dspcontrol"},
    {456, "ac0"},
    {464, "ac1"},
    {472, "ac2"},
    {480, "ac3"},
    {488, "cp0_status"},
    {492, "ip_at_syscall"},
};

const std::map<int, const char *> mips64_reg_list{
    {16, "r0"},          {24, "r1"},
    {32, "r2"},          {40, "r3"},
    {48, "r4"},          {56, "r5"},
    {64, "r6"},          {72, "r7"},
    {80, "r8"},          {88, "r9"},
    {96, "r10"},         {104, "r11"},
    {112, "r12"},        {120, "r13"},
    {128, "r14"},        {136, "r15"},
    {144, "r16"},        {152, "r17"},
    {160, "r18"},        {168, "r19"},
    {176, "r20"},        {184, "r21"},
    {192, "r22"},        {200, "r23"},
    {208, "r24"},        {216, "r25"},
    {224, "r26"},        {232, "r27"},
    {240, "r28"},        {248, "r29"},
    {256, "r30"},        {264, "r31"},
    {272, "pc"},         {280, "hi"},
    {288, "lo"},         {296, "f0"},
    {304, "f1"},         {312, "f2"},
    {320, "f3"},         {328, "f4"},
    {336, "f5"},         {344, "f6"},
    {352, "f7"},         {360, "f8"},
    {368, "f9"},         {376, "f10"},
    {384, "f11"},        {392, "f12"},
    {400, "f13"},        {408, "f14"},
    {416, "f15"},        {424, "f16"},
    {432, "f17"},        {440, "f18"},
    {448, "f19"},        {456, "f20"},
    {464, "f21"},        {472, "f22"},
    {480, "f23"},        {488, "f24"},
    {496, "f25"},        {504, "f26"},
    {512, "f27"},        {520, "f28"},
    {528, "f29"},        {536, "f30"},
    {544, "f31"},        {552, "fir"},
    {556, "fccr"},       {560, "fexr"},
    {564, "fenr"},       {568, "fcsr"},
    {572, "cp0_status"}, {576, "ulr"},
    {584, "emnote"},     {588, "cond"},
    {592, "cmstart"},    {600, "cmlen"},
    {608, "nraddr"},     {616, "ip_at_syscall"},
};

const std::map<int, const char *> tilegx_reg_list{
    {0, "r0"},
    {8, "r1"},
    {16, "r2"},
    {24, "r3"},
    {32, "r4"},
    {40, "r5"},
    {48, "r6"},
    {56, "r7"},
    {64, "r8"},
    {72, "r9"},
    {80, "r10"},
    {88, "r11"},
    {96, "r12"},
    {104, "r13"},
    {112, "r14"},
    {120, "r15"},
    {128, "r16"},
    {136, "r17"},
    {144, "r18"},
    {152, "r19"},
    {160, "r20"},
    {168, "r21"},
    {176, "r22"},
    {184, "r23"},
    {192, "r24"},
    {200, "r25"},
    {208, "r26"},
    {216, "r27"},
    {224, "r28"},
    {232, "r29"},
    {240, "r30"},
    {248, "r31"},
    {256, "r32"},
    {264, "r33"},
    {272, "r34"},
    {280, "r35"},
    {288, "r36"},
    {296, "r37"},
    {304, "r38"},
    {312, "r39"},
    {320, "r40"},
    {328, "r41"},
    {336, "r42"},
    {344, "r43"},
    {352, "r44"},
    {360, "r45"},
    {368, "r46"},
    {376, "r47"},
    {384, "r48"},
    {392, "r49"},
    {400, "r50"},
    {408, "r51"},
    {416, "r52"},
    {424, "r53"},
    {432, "r54"},
    {440, "r55"},
    {448, "r56"},
    {456, "r57"},
    {464, "r58"},
    {472, "r59"},
    {480, "r60"},
    {488, "r61"},
    {496, "r62"},
    {504, "r63"},
    {512, "pc"},
    {520, "spare"},
    {528, "emnote"},
    {536, "cmstart"},
    {544, "cmlen"},
    {552, "nraddr"},
    {560, "cmpexch"},
    {568, "zero"},
    {576, "ex_context_0"},
    {584, "ex_context_1"},
    {608, "cond"},
};

const char *guest_register_name(Int offset, arch_type arch) {
	const std::map<int, const char *> *reg_l = nullptr;

	switch (arch) {
	case arch_type::x86:
		reg_l = &x86_reg_list;
		break;
	case arch_type::amd64:
		reg_l = &amd64_reg_list;
		break;
	case arch_type::ppc32:
		reg_l = &ppc32_reg_list;
		break;
	case arch_type::ppc64:
		reg_l = &ppc64_reg_list;
		break;
	case arch_type::arm:
		reg_l = &arm_reg_list;
		break;
	case arch_type::arm64:
		reg_l = &arm64_reg_list;
		break;
	case arch_type::s390x:
		reg_l = &s390x_reg_list;
		break;
	case arch_type::mips32:
		reg_l = &mips32_reg_list;
		break;
	case arch_type::mips64:
		reg_l = &mips64_reg_list;
		break;
	case arch_type::tilegx:
		reg_l = &tilegx_reg_list;
		break;
	default:
		break;
	}

	if (!reg_l) {
		return nullptr;
	}

	if (reg_l->count(offset) == 0) {
		return nullptr;
	}

	return reg_l->at(offset);
}

} // namespace libvexxx