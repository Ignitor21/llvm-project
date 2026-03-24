#include "GogiPCTargetMachine.h"
#include "GogiPC.h"
#include "TargetInfo/GogiPCTargetInfo.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"
#include <optional>

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeGogiPCTarget() {
  // Register the target.
  GOGIPC_DUMP_CYAN
  RegisterTargetMachine<GogiPCTargetMachine> A(getTheGogiPCTarget());
}

GogiPCTargetMachine::GogiPCTargetMachine(const Target &T, const Triple &TT,
                                   StringRef CPU, StringRef FS,
                                   const TargetOptions &Options,
                                   std::optional<Reloc::Model> RM,
                                   std::optional<CodeModel::Model> CM,
                                   CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(
          T, "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32", TT, CPU, FS, Options,
          Reloc::Static, getEffectiveCodeModel(CM, CodeModel::Small), OL) {
  GOGIPC_DUMP_CYAN
  initAsmInfo();
}

namespace {

/// GogiPC Code Generator Pass Configuration Options.
class GogiPCPassConfig : public TargetPassConfig {
public:
  GogiPCPassConfig(GogiPCTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  GogiPCTargetMachine &getGogiPCTargetMachine() const {
    return getTM<GogiPCTargetMachine>();
  }


  bool addInstSelector() override {
    GOGIPC_DUMP_CYAN
    addPass(createGogiPCISelDag(getGogiPCTargetMachine(), getOptLevel()));
    return false;
  }
};

} // end anonymous namespace

TargetPassConfig *GogiPCTargetMachine::createPassConfig(PassManagerBase &PM) {
  GOGIPC_DUMP_CYAN
  return new GogiPCPassConfig(*this, PM);
}
