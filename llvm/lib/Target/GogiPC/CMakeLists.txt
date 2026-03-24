add_llvm_component_group(GogiPC)

set(LLVM_TARGET_DEFINITIONS GogiPC.td)

tablegen(LLVM GogiPCGenRegisterInfo.inc -gen-register-info)

add_public_tablegen_target(GogiPCCommonTableGen)

add_llvm_target(GogiPCCodeGen
  GogiPCTargetMachine.cpp
  GogiPCRegisterInfo.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  GogiPCInfo

  ADD_TO_COMPONENT
  GogiPC
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
