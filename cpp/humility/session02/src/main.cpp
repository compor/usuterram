
#include <iostream>
#include <cstdint>
#include <map>

#include <string>
#include <sstream>
#include <cstring>


template<typename T>
class Arg {
public:
  Arg(const std::string &name) : m_name(name), m_data{} {}

  void parse(const std::string &name) {
    std::istringstream ss(name);
    ss >> m_data;

    return;
  }

private:
  std::string m_name;
  T m_data;
};


template<typename T>
class CmdOptions {
    std::map<std::string, T> m_optval;

public:
    CmdOptions() = default;

    CmdOptions(int argc, const T *argv[]) {
      parse(argc, argv);
    }

    bool parse(int argc, const char *argv[]) {
      int i = 0;

      if (argc % 2 != 0)
        return false;

      while(i < argc) {
        //std::cout << argv[i] << std::endl;

        if (strncmp(argv[i], "-", 1) == 0) {
          const auto *opt = argv[i] + 1;
          //std::cout << *opt << std::endl;
          i++;
          auto val = (argv[i]);
          //std::cout << val << std::endl;

          m_optval[std::string{opt}] = val;
        }

        i++;
      }

      return true;
    }

    bool find(const char *opt) {
      auto found = m_optval.find(std::string(opt));

      if (m_optval.end() == found)
        return false;

      return true;
    }

    bool find(const char opt) {
      auto s = std::string{opt};
      return this->find(s.c_str());
    }

    int value(const char *opt) {
      auto found = m_optval.find(std::string(opt));

      if (m_optval.end() != found)
        return found->second;

      return 0;
    }

    int size() {
      return m_optval.size();
    }

    friend std::ostream &operator<<(std::ostream &os, const CmdOptions &co);
};


std::ostream &
operator<<(std::ostream &os, const CmdOptions &co) {
  for (auto &&i : co.m_optval)
    os << "option key: " << i.first << " - option value: " << i.second << std::endl;

  return os;
}

//

int main(int argc, const char *argv[]) {
  CmdOptions opts(argc - 1, argv + 1);

  std::cout << opts << std::endl;

  return 0;
}

