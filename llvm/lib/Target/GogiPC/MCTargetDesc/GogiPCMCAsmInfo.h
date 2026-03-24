#ifndef LLVM_LIB_TARGET_GOGIPC_MCTARGETDESC_GOGIPCMCASMINFO_H
#define LLVM_LIB_TARGET_GOGIPC_MCTARGETDESC_GOGIPCMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class GogiPCELFMCAsmInfo : public MCAsmInfoELF {
public:
  explicit GogiPCELFMCAsmInfo(const Triple &TheTriple);
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_GOGIPC_MCTARGETDESC_GOGIPCMCASMINFO_H

