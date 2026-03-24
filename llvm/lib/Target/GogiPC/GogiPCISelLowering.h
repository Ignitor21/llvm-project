#ifndef LLVM_LIB_TARGET_GOGIPC_GOGIPCISELLOWERING_H
#define LLVM_LIB_TARGET_GOGIPC_GOGIPCISELLOWERING_H

#include "GogiPC.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class GogiPCSubtarget;
class GogiPCTargetMachine;

namespace GogiPCISD {

enum NodeType : unsigned {
  // Start the numbering where the builtin ops and target ops leave off.
  FIRST_NUMBER = ISD::BUILTIN_OP_END,
  RET,
  CALL,
  BR_CC,
};

} // namespace GogiPCISD

class GogiPCTargetLowering : public TargetLowering {
public:
  explicit GogiPCTargetLowering(const TargetMachine &TM, const GogiPCSubtarget &STI);

  /// This method returns the name of a target specific DAG node.
  const char *getTargetNodeName(unsigned Opcode) const override;

  GogiPCSubtarget const &getSubtarget() const { return STI; }

private:
  const GogiPCSubtarget &STI;
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_GOGIPC_GOGIPCISELLOWERING_H

