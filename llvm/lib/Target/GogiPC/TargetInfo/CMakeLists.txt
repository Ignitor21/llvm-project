add_llvm_component_library(LLVMGogiPCInfo
  GogiPCTargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  GogiPC
  )
