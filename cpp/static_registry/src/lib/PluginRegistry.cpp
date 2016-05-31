
#include <iostream>

#include "PluginRegistry.hpp"
#include "PluginBase.hpp"


//decltype(auto) GetRegistry() {
PluginRegistryT<PluginBase> &GetRegistry() {
  static PluginRegistryT<PluginBase> TheRegistry;
  auto &r = TheRegistry;

  std::cerr << "registry ptr: " << &TheRegistry << std::endl;

  return r;
}
