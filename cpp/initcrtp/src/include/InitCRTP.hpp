
#ifndef INITCRTP_HPP
#define INITCRTP_HPP

#include <iostream>
#include <type_traits>


// solution

template<typename T, T /*unnamed*/>
struct InstantiationHelper {};


template<typename T>
class InitHelper {
public:
  InitHelper() {
    std::cout << "called with POD: " << std::is_pod<T>::value << std::endl;
    return;
  }
};


template<typename T>
class InitCRTP {
public:
  static InitHelper<T> init;

private:
  typedef InstantiationHelper<InitHelper<T>&, init> dummy;
};

template<typename T> InitHelper<T> InitCRTP<T>::init;




#endif // INITCRTP_HPP

