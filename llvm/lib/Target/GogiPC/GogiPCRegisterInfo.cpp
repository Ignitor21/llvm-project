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

const MCPhysReg *
GogiPCRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  GOGIPC_DUMP_GREEN
  return CSR_GogiPC_SaveList;
}

BitVector GogiPCRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  GOGIPC_DUMP_GREEN
  GogiPCFrameLowering const *TFI = getFrameLowering(MF);

  BitVector Reserved(getNumRegs());
  Reserved.set(GogiPC::R1);

  if (TFI->hasFP(MF)) {
    Reserved.set(GogiPC::R2);
  }
  return Reserved;
}

bool GogiPCRegisterInfo::requiresRegisterScavenging(
    const MachineFunction &MF) const {
  return false;
}

bool GogiPCRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                          int SPAdj, unsigned FIOperandNum,
                                          RegScavenger *RS) const {
  GOGIPC_DUMP_GREEN
  assert(SPAdj == 0 && "Unexpected non-zero SPAdj value");

  MachineInstr &MI = *II;
  MachineFunction &MF = *MI.getParent()->getParent();
  DebugLoc DL = MI.getDebugLoc();

  int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
  Register FrameReg;
  int Offset = getFrameLowering(MF)
                   ->getFrameIndexReference(MF, FrameIndex, FrameReg)
                   .getFixed();
  Offset += MI.getOperand(FIOperandNum + 1).getImm();

  if (!isInt<16>(Offset)) {
    llvm_unreachable("");
  }

  MI.getOperand(FIOperandNum).ChangeToRegister(FrameReg, false, false, false);
  MI.getOperand(FIOperandNum + 1).ChangeToImmediate(Offset);
  return false;
}

Register GogiPCRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  GOGIPC_DUMP_GREEN
  const TargetFrameLowering *TFI = getFrameLowering(MF);
  return TFI->hasFP(MF) ? GogiPC::R2 : GogiPC::R1;
}

const uint32_t *
GogiPCRegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                      CallingConv::ID CC) const {
  GOGIPC_DUMP_GREEN
  return CSR_GogiPC_RegMask;
}
