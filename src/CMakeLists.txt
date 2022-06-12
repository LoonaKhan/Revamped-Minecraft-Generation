cmake_minimum_required(VERSION 3.22)
project(Revamped_Minecraft_Generation)

set(CMAKE_CXX_STANDARD 14)

add_executable(Revamped_Minecraft_Generation main.cpp globvars.cpp globvars.h grid_system/Block.cpp grid_system/Block.h)
add_executable(Grid_System grid_system/grid_system.cpp globvars.cpp globvars.h grid_system/grid.cpp grid_system/grid.h grid_system/Block.cpp grid_system/Block.h)
add_executable(Convert_Coords_test grid_system/tests/grid_test.cpp globvars.h globvars.cpp grid_system/grid.cpp grid_system/grid.h)

target_link_libraries(Revamped_Minecraft_Generation sfml-graphics sfml-window sfml-system)
target_link_libraries(Grid_System sfml-graphics sfml-window sfml-system)