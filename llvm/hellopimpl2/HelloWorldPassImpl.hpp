#ifndef HELLOWORLDPASSIMPL_HPP
#define HELLOWORLDPASSIMPL_HPP

#include "llvm/IR/Function.h"


namespace compor {

class HelloWorldPass;


class HelloWorldPassImpl {
public:
  HelloWorldPassImpl(HelloWorldPass *pass);
  bool runOnFunction(llvm::Function &f);

private:
  HelloWorldPass *m_pass;
};


} // namespace compor end


#endif // HELLOWORLDPASSIMPL_HPP

