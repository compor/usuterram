
// TODO to be removed
#include <iostream>

#include "PluginBase.hpp"
#include "PluginRegistrar.hpp"


class UnitBase;

class Plugin1 : public PluginBase {
public:
  Plugin1() : PluginBase() {}
  ~Plugin1() {}

  bool runOn(UnitBase &unit) {
    std::cerr << "called in plugin1" << std::endl;
    return false;
  }
};



static PluginRegistrar<Plugin1> X;


