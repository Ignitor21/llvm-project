add_llvm_component_library(LLVMGogiPCDesc
  GogiPCMCTargetDesc.cpp

  LINK_COMPONENTS
  MC
  Support
  GogiPCInfo

  ADD_TO_COMPONENT
  GogiPC
)
