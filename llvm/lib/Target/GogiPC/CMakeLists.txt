add_llvm_component_group(GogiPC)

set(LLVM_TARGET_DEFINITIONS GogiPC.td)

tablegen(LLVM GogiPCGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM GogiPCGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM GogiPCGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM GogiPCGenMCPseudoLowering.inc -gen-pseudo-lowering)

add_public_tablegen_target(GogiPCCommonTableGen)

add_llvm_target(GogiPCCodeGen
  GogiPCTargetMachine.cpp
  GogiPCRegisterInfo.cpp
  GogiPCInstrInfo.cpp
  GogiPCSubtarget.cpp
  GogiPCAsmPrinter.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  GogiPCInfo
  AsmPrinter

  ADD_TO_COMPONENT
  GogiPC
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
