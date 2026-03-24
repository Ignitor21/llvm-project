add_llvm_component_library(LLVMGogiPCDesc
  GogiPCMCTargetDesc.cpp
  GogiPCMCAsmInfo.cpp
  GogiPCInstPrinter.cpp

  LINK_COMPONENTS
  MC
  Support
  GogiPCInfo

  ADD_TO_COMPONENT
  GogiPC
)
