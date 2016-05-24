
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/" "*.cpp")
#message(STATUS "${SRC_FILES}")

foreach(SRC_FILE ${SRC_FILES})
  string(REGEX REPLACE ".cpp$" ".out" EXE ${SRC_FILE})
  get_filename_component(EXE ${EXE} NAME)

  add_executable(${EXE} ${SRC_FILE})
  #target_link_libraries(${EXE})
endforeach()

