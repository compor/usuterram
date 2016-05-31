#ifndef PLUGINREGISTRY_HPP
#define PLUGINREGISTRY_HPP

#include <memory>
#include <map>

#include "PluginBase.hpp"

// TODO remove
//#include <iostream>

template<typename PluginT>
using PluginRegistryT = std::map<typename PluginT::id_t, std::shared_ptr<PluginT>>;

PluginRegistryT<PluginBase> &GetRegistry();

//decltype(auto) GetRegistry() {
  //static PluginRegistryT<PluginBase> TheRegistry;
  //auto &r = TheRegistry;

  //std::cerr << "registry ptr: " << &TheRegistry << std::endl;

  //return r;
//}

#endif // PLUGINREGISTRY_HPP

