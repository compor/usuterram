
#include <iostream>

#include "InitCRTP.hpp"


class RequiresInitA : public InitCRTP<RequiresInitA> {
public:
  RequiresInitA() {
    std::cout << "requiresInitA ctor called" << std::endl;

    return;
  }

// workaround 1 - implicit instatiation via usage
//private:
  //void dummy() { init; }
};


// workaround 2 - explicit instantiation
//template
//class InitCRTP<RequiresInitA>;


int main(int argc, const char *argv[]) {
  std::cerr << "tool1: " << std::endl;
  RequiresInitA ria1;

  return 0;
}

