
#include <iostream>
#include <cstdint>
#include <map>

#include <string>
#include <sstream>
#include <cstring>

#include <cstdio>
#include <memory>

class File {
public:
  File(const char *filename, const char *mode) : m_fp(std::fopen(filename, mode)) {
    std::cout << "ctor\n";
    return;
  }

  ~File() {
    std::cout << "dtor\n";
    if (m_fp) {
      std::cout << "closing fp\n";
      std::fclose(m_fp);
      m_fp = nullptr;
    }
  }
private:
  FILE *m_fp;
};

//

class Node {
public:
  Node(std::string,
       std::unique_ptr<Node> left,
       std::unique_ptr<Node> right)
    : m_name(name), m_left(std::move(left)), m_right(std::move(right)) {}

private:
  std::string m_name;
  std::unique_ptr<Node> left, right;
};

int main(int argc, const char *argv[]) {
  //File f("lol.txt", "r");

  return 0;
}

