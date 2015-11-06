
#include <memory>

#include "HelloWorldPassImpl.hpp"

#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include <llvm/Support/raw_ostream.h>


namespace compor {

//class HelloWorldPassImpl;


struct HelloWorldPass : public llvm::FunctionPass {
  HelloWorldPass() : llvm::FunctionPass(ID) {}
  ~HelloWorldPass() {}

  virtual bool runOnFunction(llvm::Function &f) override {
    llvm::errs() << "HelloWorld pass\n";
    m_pimpl = std::make_unique<HelloWorldPassImpl>(this);
    return m_pimpl->runOnFunction(f);
  }

  static char ID;
  std::unique_ptr<HelloWorldPassImpl> m_pimpl;
};


} // namespace compor end

//

char compor::HelloWorldPass::ID = 0;
static llvm::RegisterPass<compor::HelloWorldPass> X("helloworld",
                                   "Hello World Pass PIMPL", false, false);

