#include "GogiPC.h"
#include "TargetInfo/GogiPCTargetInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "GogiPCGenRegisterInfo.inc"

static MCRegisterInfo *createGogiPCMCRegisterInfo(const Triple &TT) {
  GOGIPC_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitGogiPCMCRegisterInfo(X, GogiPC::R0);
  return X;
}
// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeGogiPCTargetMC() {
  GOGIPC_DUMP_MAGENTA
  Target &TheGogiPCTarget = getTheGogiPCTarget();
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheGogiPCTarget, createGogiPCMCRegisterInfo);
}
