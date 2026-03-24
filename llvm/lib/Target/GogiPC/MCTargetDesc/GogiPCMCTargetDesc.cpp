#include "MCTargetDesc/GogiPCInfo.h"
#include "GogiPC.h"
#include "GogiPCInstPrinter.h"
#include "GogiPCMCAsmInfo.h"
#include "TargetInfo/GogiPCTargetInfo.h"
#include "llvm/MC/MCDwarf.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "GogiPCGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "GogiPCGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "GogiPCGenSubtargetInfo.inc"


static MCRegisterInfo *createGogiPCMCRegisterInfo(const Triple &TT) {
  GOGIPC_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitGogiPCMCRegisterInfo(X, GogiPC::R0);
  return X;
}

static MCInstrInfo *createGogiPCMCInstrInfo() {
  GOGIPC_DUMP_MAGENTA
  MCInstrInfo *X = new MCInstrInfo();
  InitGogiPCMCInstrInfo(X);
  return X;
}

static MCSubtargetInfo *createGogiPCMCSubtargetInfo(const Triple &TT,
                                                 StringRef CPU, StringRef FS) {
  GOGIPC_DUMP_MAGENTA
  return createGogiPCMCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

static MCAsmInfo *createGogiPCMCAsmInfo(const MCRegisterInfo &MRI,
                                     const Triple &TT,
                                     const MCTargetOptions &Options) {
  GOGIPC_DUMP_MAGENTA
  MCAsmInfo *MAI = new GogiPCELFMCAsmInfo(TT);
  unsigned SP = MRI.getDwarfRegNum(GogiPC::R1, true);
  MCCFIInstruction Inst = MCCFIInstruction::cfiDefCfa(nullptr, SP, 0);
  MAI->addInitialFrameState(Inst);
  return MAI;
}

static MCInstPrinter *createGogiPCMCInstPrinter(const Triple &T,
                                             unsigned SyntaxVariant,
                                             const MCAsmInfo &MAI,
                                             const MCInstrInfo &MII,
                                             const MCRegisterInfo &MRI) {
  GOGIPC_DUMP_MAGENTA
  return new GogiPCInstPrinter(MAI, MII, MRI);
}


// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeGogiPCTargetMC() {
  GOGIPC_DUMP_MAGENTA
  Target &TheGogiPCTarget = getTheGogiPCTarget();
  RegisterMCAsmInfoFn X(TheGogiPCTarget, createGogiPCMCAsmInfo);
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheGogiPCTarget, createGogiPCMCRegisterInfo);
  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheGogiPCTarget, createGogiPCMCInstrInfo);
  // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheGogiPCTarget,
                                          createGogiPCMCSubtargetInfo);
  // Register the MCInstPrinter
  TargetRegistry::RegisterMCInstPrinter(TheGogiPCTarget, createGogiPCMCInstPrinter);
}
