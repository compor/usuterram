# cmake lists file

add_executable(tool1 
  Tool1.cpp)

target_link_libraries(tool1 PUBLIC sr)
target_link_libraries(tool1 PUBLIC plugin1)
target_link_libraries(tool1 PUBLIC plugin2)

