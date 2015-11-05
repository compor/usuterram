
#include "llvm/Pass.h"
#include <llvm/IR/Type.h>
#include <llvm/IR/Function.h>
#include <llvm/Support/raw_ostream.h>

using namespace llvm;

namespace {

struct Hello : public FunctionPass {
  static char ID;

  Hello() : FunctionPass(ID) {}

  bool runOnFunction(Function &f) override {
    errs() << "Hello pass : ";
    errs() << "function name : ";
    errs().write_escaped(f.getName());

    auto ret_type = f.getReturnType();
    errs() << "ret type : ";
    ret_type->print(errs());

    errs() << "\n";

    return false;
  }
};

} // unnamed namespace end

char Hello::ID = 0;
static RegisterPass<Hello> X("hello", "Hello World Pass", false, false);

