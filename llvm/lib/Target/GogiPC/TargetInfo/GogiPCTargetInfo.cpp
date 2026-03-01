#include "TargetInfo/GogiPCTargetInfo.h"
#include "GogiPC.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheGogiPCTarget() {
  GOGIPC_DUMP_YELLOW
  static Target TheGogiPCTarget;
  return TheGogiPCTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeGogiPCTargetInfo() {
  GOGIPC_DUMP_YELLOW
  RegisterTarget<Triple::gogipc> X(getTheGogiPCTarget(), "gogipc",
                                "Target architecture made by Gogi", "GOGIPC");
}
