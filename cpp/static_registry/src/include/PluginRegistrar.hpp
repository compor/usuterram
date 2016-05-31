#ifndef PLUGINREGISTRAR_HPP
#define PLUGINREGISTRAR_HPP


#include <utility>
#include <memory>

#include "PluginRegistry.hpp"


template<typename PluginT>
class PluginRegistrar {
public:
  PluginRegistrar() {
    auto &&pr = GetRegistry();

    auto p{ std::make_shared<PluginT>() };
    p->ID = pr.size();

    pr.insert(std::make_pair(p->ID, p));

    return;
  }
};


#endif // PLUGINREGISTRAR_HPP

