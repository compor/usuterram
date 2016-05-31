
#include <iostream>

#include "UnitBase.hpp"
#include "PluginRegistry.hpp"

class MyUnit : public UnitBase {};


int main(int argc, const char *argv[]) {
  auto n = GetRegistry().size();
  std::cerr << "tool1: " << n << std::endl;

  MyUnit u;

  for (const auto &p : GetRegistry())
    p.second->runOn(u);

  return 0;
}

