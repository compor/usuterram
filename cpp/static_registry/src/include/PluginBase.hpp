
#ifndef PLUGINBASE_HPP
#define PLUGINBASE_HPP


class UnitBase;

class PluginBase {
public:
  typedef int id_t;
  id_t ID;

  virtual bool runOn(UnitBase &unit) = 0;
  virtual ~PluginBase() = 0;
};

PluginBase::~PluginBase() {}


#endif // PLUGINBASE_HPP

