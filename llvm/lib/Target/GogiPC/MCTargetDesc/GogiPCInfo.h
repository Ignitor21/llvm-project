#ifndef LLVM_LIB_TARGET_GOGIPC_MCTARGETDESC_GOGIPCINFO_H
#define LLVM_LIB_TARGET_GOGIPC_MCTARGETDESC_GOGIPCINFO_H

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace GogiPCOp {
enum OperandType : unsigned {
  OPERAND_GOGIPCM16 = MCOI::OPERAND_FIRST_TARGET,
};
} // namespace GogiPCOp

} // end namespace llvm

#endif
