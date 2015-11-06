

#include "HelloWorldPass.hpp"
#include "HelloWorldPassImpl.hpp"


#include <memory>

#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include <llvm/Support/raw_ostream.h>

namespace compor {


HelloWorldPass::HelloWorldPass()
 : llvm::FunctionPass(ID) {}


bool HelloWorldPass::runOnFunction(llvm::Function &f) {
  llvm::errs() << "HelloWorld pass\n";
  m_pimpl = std::make_unique<HelloWorldPassImpl>(this);
  return m_pimpl->runOnFunction(f);
}

} // namespace compor end

//

char compor::HelloWorldPass::ID = 0;
static llvm::RegisterPass<compor::HelloWorldPass> X("helloworld",
                                   "Hello World Pass PIMPL", false, false);

