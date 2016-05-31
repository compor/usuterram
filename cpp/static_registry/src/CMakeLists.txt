# cmake lists file

cmake_minimum_required(VERSION 3.2)

project(static_registry)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -stdlib=libc++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic")


include_directories(include)

add_subdirectory(lib)
add_subdirectory(plugin1)
add_subdirectory(plugin2)
add_subdirectory(tool1)

