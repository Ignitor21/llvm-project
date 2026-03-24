include "llvm/Target/Target.td"
include "GogiPCRegisterInfo.td"
include "GogiPCInstrInfo.td"

class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, NoItineraries, Features>;

def : Proc<"generic", []>;

def GogiPCInstrInfo : InstrInfo;
def GogiPC : Target {
  let InstructionSet = GogiPCInstrInfo;
}
