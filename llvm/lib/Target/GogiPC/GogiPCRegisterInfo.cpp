#include "GogiPCRegisterInfo.h"
#include "GogiPC.h"
#include "GogiPCFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "GogiPCGenRegisterInfo.inc"

GogiPCRegisterInfo::GogiPCRegisterInfo() : GogiPCGenRegisterInfo(GogiPC::R0) {
  GOGIPC_DUMP_GREEN
}
