#ifndef LLVM_LIB_TARGET_GOGIPC_GOGIPCREGISTERINFO_H
#define LLVM_LIB_TARGET_GOGIPC_GOGIPCREGISTERINFO_H

#define GET_REGINFO_HEADER
#include "GogiPCGenRegisterInfo.inc"

namespace llvm {

struct GogiPCRegisterInfo : public GogiPCGenRegisterInfo {
public:
  GogiPCRegisterInfo();
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_GOGIPC_GOGIPCREGISTERINFO_H
