//

#include <iostream>
#include <thread>
#include <utility>
#include <mutex>
#include <chrono>
using namespace std::chrono_literals;

std::mutex g_mtx;

int g_count;

void inc() {
  std::unique_lock<std::mutex> lk(g_mtx);
  for (int i = 0; i < 1000; i++) {
    g_count++;
  }
}



void foo(const int &n) {
  std::cerr << "foo called with n: " << n << "\n";
  std::cerr << "id: " << std::this_thread::get_id() << "\n";
}


int main(int argc, const char *argv[])
{
  std::cerr << "hw conc: " << std::thread::hardware_concurrency() << std::endl;
  //std::this_thread::sleep_for(2s);
  //std::this_thread::sleep_for(std::chrono::seconds(2));
  int n = 7;
  //std::thread t1(&foo, std::ref(n));
  //std::thread t1([&]() { foo(n); });

  std::thread t1(&inc);
  std::thread t2(&inc);

  t1.join();
  t2.join();
  //t1.detach();

  std::cerr << "count: " << g_count << std::endl;
  return 0;
}

