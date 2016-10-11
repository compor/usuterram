
#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
//#include "llvm/IR/Type.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/DebugLoc.h"
#include "llvm/IR/DebugInfoMetadata.h"
#include "llvm/Analysis/LoopPass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Debug.h"

#include <map>
#include <string>

#define DEBUG_TYPE "looper"


namespace compor {

struct Looper : public llvm::FunctionPass {
  static char ID;

  std::map<std::string, int> toploops;
  std::map<std::string, int> parloops;
  std::map<std::string, int> loopmd;

  Looper() : llvm::FunctionPass(ID) {}

  void getAnalysisUsage(llvm::AnalysisUsage &AU) const override {
    AU.setPreservesCFG();
    AU.addRequired<llvm::LoopInfoWrapperPass>();
  }

  bool runOnFunction(llvm::Function &F) override {
    llvm::LoopInfo &LI = getAnalysis<llvm::LoopInfoWrapperPass>().getLoopInfo();
    int loop_count = 0;
    int toploop_count = 0;
    int parloop_count = 0;

    for(const auto L : LI) {
      if (L->getLoopDepth() == 1) {
        toploop_count++;
        loop_count++;
      }

      if (L->getLoopDepth() == 1 && L->isAnnotatedParallel()) {
        const auto LInst = L->getHeader()->getParent();
        llvm::outs() << "loop count: " << loop_count << "\n";
        llvm::outs() << "loop : " << *L << "\n";
        llvm::outs() << LInst->getName() << "\n";
        auto DbgLoc = L->getStartLoc();
        if (DbgLoc)
          llvm::outs() << DbgLoc->getLine() << "\n";

        for (auto BI = L->block_begin(), BE = L->block_end(); BI != BE; BI++) {
          for(auto &Inst : **BI) {
            if (llvm::isa<llvm::LoadInst>(Inst)
                || llvm::isa<llvm::StoreInst>(Inst)) {
              if (Inst.getMetadata("icsa.profile.loop.mem.access")) {
                llvm::outs() << "--" << llvm::cast<llvm::MDString>(Inst.getMetadata("icsa.profile.loop.mem.access")->getOperand(0))->getString();
                //auto mds = llvm::cast<llvm::MDString>(Inst.getMetadata("icsa.profile.loop.mem.access")->getOperand(0))->getString();
                //loopmd[mds] = 0;
              }
            }
          }
        }

        parloop_count++;
      }
    }

    parloops[F.getParent()->getName()] += parloop_count;
    toploops[F.getParent()->getName()] += toploop_count;

    return false;
  }

  ~Looper() {
    for(const auto &l : parloops)
      llvm::outs() << "### par " << l.first << " " << l.second << "\n";

    for(const auto &l : toploops)
      llvm::outs() << "### top " << l.first << " " << l.second << "\n";

    for(const auto &l : loopmd)
      llvm::outs() << "### md " << l.first << "\n";
  }
};

} // namespace compor end

char compor::Looper::ID = 0;
static llvm::RegisterPass<compor::Looper> X("looper", "Looper Pass", false, false);

