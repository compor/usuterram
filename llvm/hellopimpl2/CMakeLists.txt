# cmake file

cmake_minimum_required(VERSION 2.8.0)
project(HelloWorldPassPimpl2)

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

add_library(LLVMHelloWorldPassPimpl2 MODULE 
  HelloWorldPass.cpp
  HelloWorldPassImpl.cpp)

llvm_map_components_to_libnames(llvm_libs support passes)
target_link_libraries(LLVMHelloWorldPassPimpl2 ${llvm_libs})

