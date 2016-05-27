
#include "llvm/Pass.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"

#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"


using namespace llvm;

namespace {

class Pass2;
class Pass3;

struct Pass1Result {
  int foo;
};

struct Pass1 : public FunctionPass {
    static char ID;

    Pass1() : FunctionPass(ID) {}

    bool runOnFunction(Function &f) override {
        errs() << "Pass1 pass : ";
        errs() << " function name : ";
        errs().write_escaped(f.getName());
        auto ret_type = f.getReturnType();
        errs() << "\twith ret type : ";
        ret_type->print(errs());
        errs() << "\n";

        return false;
    }

    const char *getPassName() const override {
      return "Pass1";
    }

    void getAnalysisUsage(llvm::AnalysisUsage &Info) const override {
      //Info.addRequired<Pass2>();
      //Info.addRequired<Pass3>();
      Info.setPreservesAll();
    }

    Pass1Result result;

    Pass1Result &getResult() {
      return result;
    }
};


struct Pass2 : public ModulePass {
    static char ID;

    Pass2() : ModulePass(ID) {}

    bool runOnModule(Module &m) override {
        errs() << "Pass2 pass : ";

        //auto &pass1 = llvm::Pass::getAnalysis<Pass1>(*(m.begin()));
        //auto &pass1result = pass1.getResult();

        return false;
    }

    const char *getPassName() const override {
      return "Pass2";
    }

    void getAnalysisUsage(llvm::AnalysisUsage &Info) const override {
      Info.setPreservesAll();
      //Info.addRequired<Pass1>();
    }
};


struct Pass3 : public ModulePass {
    static char ID;

    Pass3() : ModulePass(ID) {}

    bool runOnModule(Module &m) override {
        errs() << "Pass3 pass : ";

        return false;
    }

    const char *getPassName() const override {
      return "Pass3";
    }

    void getAnalysisUsage(llvm::AnalysisUsage &Info) const override {
      Info.setPreservesAll();
    }
};

} // namespace unnamed end


// pass1 registration

char Pass1::ID = 0;
static RegisterPass<Pass1> X("pass1", "Pass1 Pass", false, false);


static void registerPass1Pass(const PassManagerBuilder &Builder,
                              legacy::PassManagerBase &PM) {
  PM.add(new Pass1());

  return;
}


static RegisterStandardPasses RegisterPass1Pass(PassManagerBuilder::EP_EarlyAsPossible,
                                                registerPass1Pass);


// pass2 registration

char Pass2::ID = 0;
static RegisterPass<Pass2> Y("pass2", "Pass2 Pass", false, false);


static void registerPass2Pass(const PassManagerBuilder &Builder,
                              legacy::PassManagerBase &PM) {
  PM.add(new Pass2());

  return;
}


static RegisterStandardPasses RegisterPass2Pass(PassManagerBuilder::EP_EarlyAsPossible,
                                                registerPass2Pass);


// pass3 registration

char Pass3::ID = 0;
static RegisterPass<Pass3> Z("pass3", "Pass3 Pass", false, false);


static void registerPass3Pass(const PassManagerBuilder &Builder,
                              legacy::PassManagerBase &PM) {
  PM.add(new Pass3());

  return;
}


static RegisterStandardPasses RegisterPass3Pass(PassManagerBuilder::EP_EarlyAsPossible,
                                                registerPass3Pass);

