add_llvm_component_group(GogiPC)

add_llvm_target(GogiPCCodeGen
  GogiPCTargetMachine.cpp

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
