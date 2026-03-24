#ifndef LLVM_LIB_TARGET_GOGIPC_GOGIPCTARGETMACHINE_H
#define LLVM_LIB_TARGET_GOGIPC_GOGIPCTARGETMACHINE_H

#include "GogiPCSubtarget.h"
#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>

namespace llvm {
extern Target TheGogiPCTarget;

class GogiPCTargetMachine : public CodeGenTargetMachineImpl {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  GogiPCSubtarget Subtarget;

public:
  GogiPCTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                   StringRef FS, const TargetOptions &Options,
                   std::optional<Reloc::Model> RM,
                   std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                   bool JIT);

  const GogiPCSubtarget *getSubtargetImpl(const Function &) const override {
    GOGIPC_DUMP_CYAN
    return &Subtarget;
  }
  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override;
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_GOGIPC_GOGIPCTARGETMACHINE_H
