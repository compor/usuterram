//

#include <iostream>
#include <thread>
#include <utility>
//#include <fstream>
#include <chrono>
using namespace std::chrono_literals;

//void foo() {
  //std::cerr << "foo called\n";
  //std::ofstream fout;
  //fout.open("lol.txt");

  //for (size_t i = 0; i < 10; i++) {
    //std::this_thread::sleep_for(1s);
    //fout << i << "\n";
    //std::cerr << i << "\n";
    //fout.flush();
  //}

  //if (fout.is_open())
    //fout.close();

  //std::cerr << "foo terminated\n";
//}


//unsigned long long int operator "" _kib(unsigned long long int kib) {
  //return 1024 * kib;
//}


void foo() {
  std::cerr << "foo called\n";
  std::cerr << "foo terminated\n";
}

void bar(const int &n) {
  std::cerr << "bar called with n: " << n << std::endl;
}

struct qux {
  void foo(float d) {
    std::cerr << "qux::foo called with d: " << d << "and detail: " << detail << std::endl;
  }

  int detail;
};


int main(int argc, const char *argv[])
{
  std::cerr << "conc: " << std::thread::hardware_concurrency() << std::endl;

  //std::thread t1([](){ std::cout << "t1 called\n"; });
  //std::thread t1(foo);
  //t1.detach();
  //std::thread t2 = std::move(t1);

  //int n = 6;
  //std::thread t1(bar, n);
  qux q1{ 18 };
  std::thread t1(std::mem_fn(&qux::foo), &q1, 1.25f);
  auto ptr = &qux::foo;

  (q1.*ptr)(19);

  t1.joinable() && std::cerr << "i'm joinable\n";

  //std::this_thread::sleep_for(std::chrono::seconds(10));
  std::this_thread::sleep_for(10s);

  t1.join();

  return 0;
}

