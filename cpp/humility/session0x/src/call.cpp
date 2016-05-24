//

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std::chrono_literals;


int init_me;
std::once_flag init_flag;


void init(int n) {
  init_me = n;
}

void bar(int n) {
  std::call_once(init_flag, &init, n);
}

int main(int argc, const char *argv[])
{
  std::cerr << "hw conc: " << std::thread::hardware_concurrency() << std::endl;
  std::thread t1(&bar, 6);
  std::this_thread::sleep_for(2s);
  std::thread t2(&bar, 7);

  t1.join();
  t2.join();

  std::cerr << "init_me: " << init_me << std::endl;

  return 0;
}

