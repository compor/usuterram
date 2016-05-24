
#include "llvm/Pass.h"
//#include "llvm/IR/Type.h"
#include "llvm/Analysis/LoopPass.h"
#include "llvm/Support/raw_ostream.h"


namespace compor {

struct Looper : public llvm::LoopPass {
  static char ID;

  Looper() : llvm::LoopPass(ID) {}

  bool runOnLoop(llvm::Loop *L, llvm::LPPassManager &LPM) override {
    L->dump();
    llvm::errs() << "loop depth : " << L->getLoopDepth() << "\n";
    llvm::errs() << "loop blocks : " << L->getNumBlocks() << "\n";
    llvm::errs() << "loop id present : " << (L->getLoopID() ? "true" : "false") << "\n";
    llvm::errs() << "###\n\n";

    return false;
  }
};

} // namespace compor end

char compor::Looper::ID = 0;
static llvm::RegisterPass<compor::Looper> X("looper", "Looper Pass", false, false);

