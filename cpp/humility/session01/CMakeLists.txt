# cmake file

cmake_minimum_required(VERSION 3.0.2)
project(humble_session01)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")

#find_package(Boost REQUIRED)

#if(NOT ${Boost_FOUND})
    #message(FATAL_ERROR "Could not find Boost")
#endif()

#include_directories(${Boost_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})


set(HUMBLE_SRC_FILES 
  ${HUMBLE_SRC_FILES}
  "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")


add_executable(humble ${HUMBLE_SRC_FILES})


