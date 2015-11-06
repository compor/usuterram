
#include "HelloWorldPassImpl.hpp"

#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include <llvm/Support/raw_ostream.h>

namespace compor {

class HelloWorldPass;

HelloWorldPassImpl::HelloWorldPassImpl(HelloWorldPass *pass) : m_pass(pass) {}

bool HelloWorldPassImpl::runOnFunction(llvm::Function &f) {
  // this won't work because it's like a 2-way PIMPL and
  // a header/source file discipline must be followed
  //llvm::errs() << "pass : " << m_pass->getPassName() << "\n";
  llvm::errs() << "function name : ";
  llvm::errs().write_escaped(f.getName());
  llvm::errs() << " ";

  auto ret_type = f.getReturnType();
  llvm::errs() << "ret type : ";
  ret_type->print(llvm::errs());

  llvm::errs() << "\n";

  return false;
}


} // namespace compor end

