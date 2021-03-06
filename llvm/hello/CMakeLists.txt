# cmake file

cmake_minimum_required(VERSION 2.8.0)
project(HelloPass)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")

find_package(LLVM REQUIRED CONFIG)

if(${LLVM_FOUND})
    message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
    message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
else()
    message(FATAL_ERROR "Could not find LLVM")
endif()

add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})

add_library(LLVMHelloPass MODULE HelloPass.cpp)

llvm_map_components_to_libnames(llvm_libs support passes)
target_link_libraries(LLVMHelloPass ${llvm_libs})

