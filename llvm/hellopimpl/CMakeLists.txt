# cmake file

cmake_minimum_required(VERSION 2.8.0)
project(HelloWorldPassPimpl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
# move these after to use variables set by llvm cmake
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-exceptions")

find_package(LLVM REQUIRED CONFIG)

if(${LLVM_FOUND})
    message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
    message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
else()
    message(FATAL_ERROR "Could not find LLVM")
endif()

add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

######
#set(LLVM_RUNTIME_OUTPUT_INTDIR ${CMAKE_BINARY_DIR}/${CMAKE_CFG_INT_DIR})
#set(LLVM_LIBRARY_OUTPUT_INTDIR ${CMAKE_BINARY_DIR}/${CMAKE_CFG_INT_DIR})

#list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
#include(HandleLLVMOptions)
#include(AddLLVM)

#add_definitions(${LLVM_DEFINITIONS})
#include_directories(${LLVM_INCLUDE_DIRS})

#add_llvm_loadable_module(libLLVMHelloWorldPassPimpl
  #HelloWorldPass.cpp
  #HelloWorldPassImpl.cpp)
#######

add_library(LLVMHelloWorldPassPimpl MODULE 
  HelloWorldPass.cpp
  HelloWorldPassImpl.cpp)

llvm_map_components_to_libnames(llvm_libs support passes)
target_link_libraries(LLVMHelloWorldPassPimpl ${llvm_libs})

