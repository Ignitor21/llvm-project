#include "GogiPCISelLowering.h"
#include "GogiPC.h"
#include "GogiPCRegisterInfo.h"
#include "GogiPCSubtarget.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFunction.h"

#define DEBUG_TYPE "GogiPC-lower"

using namespace llvm;

GogiPCTargetLowering::GogiPCTargetLowering(const TargetMachine &TM,
                                     const GogiPCSubtarget &STI)
    : TargetLowering(TM), STI(STI) {
  GOGIPC_DUMP_RED
  addRegisterClass(MVT::i32, &GogiPC::GPRRegClass);
}

const char *GogiPCTargetLowering::getTargetNodeName(unsigned Opcode) const {
  GOGIPC_DUMP_RED
  switch (Opcode) {
  case GogiPCISD::CALL:
    return "GogiPCISD::CALL";
  case GogiPCISD::RET:
    return "GogiPCISD::RET";
  }
  return nullptr;
}

