include "llvm/Target/Target.td"
include "GogiPCRegisterInfo.td"
include "GogiPCInstrInfo.td"

def GogiPCInstrInfo : InstrInfo;
def GogiPC : Target {
  let InstructionSet = GogiPCInstrInfo;
}
