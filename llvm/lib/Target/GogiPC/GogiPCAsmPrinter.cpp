#include "MCTargetDesc/GogiPCInstPrinter.h"
#include "GogiPC.h"
#include "GogiPCSubtarget.h"
#include "GogiPCTargetMachine.h"
#include "TargetInfo/GogiPCTargetInfo.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/CodeGen/AsmPrinter.h"
#include "llvm/CodeGen/MachineConstantPool.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstr.h"
#include "llvm/CodeGen/MachineModuleInfo.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "asm-printer"

namespace {

class GogiPCAsmPrinter : public AsmPrinter {
  const MCSubtargetInfo *STI;

public:
  explicit GogiPCAsmPrinter(TargetMachine &TM,
                         std::unique_ptr<MCStreamer> Streamer)
      : AsmPrinter(TM, std::move(Streamer)), STI(TM.getMCSubtargetInfo()) {
    GOGIPC_DUMP_GREEN
  }

  void emitInstruction(const MachineInstr *MI) override;

  StringRef getPassName() const override { return "GogiPC Assembly Printer"; }

  bool lowerPseudoInstExpansion(const MachineInstr *MI, MCInst &Inst);
};

} // end anonymous namespace

// GogiPCple pseudo-instructions have their lowering (with expansion to real
// instructions) auto-generated.
#include "GogiPCGenMCPseudoLowering.inc"

void GogiPCAsmPrinter::emitInstruction(const MachineInstr *MI) {
  GOGIPC_DUMP_GREEN
  // Do any auto-generated pseudo lowerings.
  if (MCInst OutInst; lowerPseudoInstExpansion(MI, OutInst)) {
    EmitToStreamer(*OutStreamer, OutInst);
    return;
  }
}

// Force static initialization.
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeGogiPCAsmPrinter() {
  RegisterAsmPrinter<GogiPCAsmPrinter> X(getTheGogiPCTarget());
}

