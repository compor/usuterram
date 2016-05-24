# cmake file

cmake_minimum_required(VERSION 3.0.2)
project(humble_session0x)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

#find_package(Boost REQUIRED)

#if(NOT ${Boost_FOUND})
    #message(FATAL_ERROR "Could not find Boost")
#endif()

#include_directories(${Boost_INCLUDE_DIRS})
#include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#file(GLOB SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/" "*.cpp")
#message(STATUS "")

#foreach(SRC_FILE ${SRC_FILES})
  #string(REGEX REPLACE "\.cpp$" ".out" EXE ${SRC_FILE})
  #get_filename_component(EXE ${EXE} NAME)

  #add_executable(${EXE} ${SRC_FILE})
  #target_link_libraries(${EXE})
#endforeach()

#set(HUMBLE_SRC_FILES 
  #${HUMBLE_SRC_FILES}
  #"${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")


#add_executable(session0x ${HUMBLE_SRC_FILES})


add_subdirectory(src)


