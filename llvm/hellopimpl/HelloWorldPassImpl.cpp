
#include "HelloWorldPassImpl.hpp"
//#include "HelloWorldPass.hpp"

#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
//#include <llvm/Support/raw_ostream.h>

namespace compor {

HelloWorldPassImpl::HelloWorldPassImpl(HelloWorldPass *pass) : m_pass(pass) {}

bool HelloWorldPassImpl::runOnFunction(llvm::Function &f) {
  return true;
}


} // namespace compor end

