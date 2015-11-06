#ifndef HELLOWORLDPASS_HPP
#define HELLOWORLDPASS_HPP


#include <memory>

#include "llvm/Pass.h"
#include "llvm/IR/Function.h"


namespace compor {

class HelloWorldPassImpl;


struct HelloWorldPass : public llvm::FunctionPass {
  HelloWorldPass();
  virtual bool runOnFunction(llvm::Function &f) override;

  static char ID;
  std::unique_ptr<HelloWorldPassImpl> m_pimpl;
};


} // namespace compor end


#endif // HELLOWORLDPASS_HPP

