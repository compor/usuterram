
// TODO to be removed
#include <iostream>

#include "PluginBase.hpp"
#include "PluginRegistrar.hpp"


class UnitBase;

class Plugin2 : public PluginBase {
public:
  Plugin2() : PluginBase() {}
  ~Plugin2() {}

  bool runOn(UnitBase &unit) {
    std::cerr << "called in plugin2" << std::endl;
    return false;
  }
};



static PluginRegistrar<Plugin2> X;


