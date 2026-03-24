#include "GogiPCSubtarget.h"
#include "GogiPC.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "gogipc-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "GogiPCGenSubtargetInfo.inc"

GogiPCSubtarget::GogiPCSubtarget(const StringRef &CPU, const StringRef &TuneCPU,
                           const StringRef &FS, const TargetMachine &TM)
    : GogiPCGenSubtargetInfo(TM.getTargetTriple(), CPU, TuneCPU, FS) {
  GOGIPC_DUMP_CYAN
}
