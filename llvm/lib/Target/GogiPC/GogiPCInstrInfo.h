#ifndef LLVM_LIB_TARGET_GOGIPC_GOGIPCINSTRINFO_H
#define LLVM_LIB_TARGET_GOGIPC_GOGIPCINSTRINFO_H

#include "GogiPCRegisterInfo.h"
#include "MCTargetDesc/GogiPCInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "GogiPCGenInstrInfo.inc"

namespace llvm {

class GogiPCSubtarget;

class GogiPCInstrInfo : public GogiPCGenInstrInfo {
public:
  GogiPCInstrInfo();

};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_GOGIPC_GOGIPCINSTRINFO_H

