#ifndef LLVM_LIB_TARGET_GogiPC_GogiPC_H
#define LLVM_LIB_TARGET_GogiPC_GogiPC_H

#include "MCTargetDesc/GogiPCMCTargetDesc.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"

#define GOGIPC_DUMP(Color)                                                     \
  {                                                                            \
    llvm::errs().changeColor(Color)                                            \
        << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
    llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
  }

#define GOGIPC_DUMP_RED GOGIPC_DUMP(llvm::raw_ostream::RED)
#define GOGIPC_DUMP_GREEN GOGIPC_DUMP(llvm::raw_ostream::GREEN)
#define GOGIPC_DUMP_YELLOW GOGIPC_DUMP(llvm::raw_ostream::YELLOW)
#define GOGIPC_DUMP_CYAN GOGIPC_DUMP(llvm::raw_ostream::CYAN)
#define GOGIPC_DUMP_MAGENTA GOGIPC_DUMP(llvm::raw_ostream::MAGENTA)
#define GOPIPC_DUMP_WHITE GOGIPC_DUMP(llvm::raw_ostream::WHITE)
namespace llvm {
class GogiPCTargetMachine;
class FunctionPass;
class GogiPCSubtarget;
class AsmPrinter;
class InstructionSelector;
class MCInst;
class MCOperand;
class MachineInstr;
class MachineOperand;
class PassRegistry;

bool lowerGogiPCMachineInstrToMCInst(const MachineInstr *MI, MCInst &OutMI,
                                  AsmPrinter &AP);
bool LowerGogiPCMachineOperandToMCOperand(const MachineOperand &MO,
                                       MCOperand &MCOp, const AsmPrinter &AP);

FunctionPass *createGogiPCISelDag(GogiPCTargetMachine &TM, CodeGenOptLevel OptLevel);

} // namespace llvm

#endif // LLVM_LIB_TARGET_GogiPC_GogiPC_H
