cmake_minimum_required(VERSION 3.22)
project(Revamped_Minecraft_Generation)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src/random/)

add_executable(Revamped_Minecraft_Generation src/main.cpp src/globvars.cpp src/globvars.h src/grid_system/Block.cpp src/grid_system/Block.h src/utils/directory/directory.h src/utils/directory/directory.cpp src/keybinds/keybinds.cpp src/keybinds/keybinds.h src/particle/particle.cpp src/particle/particle.h)
add_executable(Grid_System src/grid_system/grid_system.cpp src/globvars.cpp src/globvars.h src/grid_system/grid.cpp src/grid_system/grid.h src/grid_system/Block.cpp src/grid_system/Block.h src/utils/directory/directory.h src/utils/directory/directory.cpp src/keybinds/keybinds.cpp src/keybinds/keybinds.h )
add_executable(Convert_Coords_test src/grid_system/tests/grid_test.cpp src/globvars.h src/globvars.cpp src/grid_system/grid.cpp src/grid_system/grid.h src/utils/directory/directory.h src/utils/directory/directory.cpp)
add_executable(Util_directory src/utils/directory/directory.cpp src/utils/directory/directory.h)
add_executable(Vector_Utils_Test src/utils/vector_utils/tests/vector_utils_test.cpp src/utils/vector_utils/vector_utils.h src/utils/vector_utils/vector_utils.cpp src/globvars.h src/globvars.cpp src/grid_system/Block.h src/grid_system/Block.cpp src/grid_system/grid.h src/grid_system/grid.cpp)
add_executable(Particles_Test src/particle/tests/particles_test.cpp src/particle/particle.cpp src/particle/particle.h src/globvars.h src/globvars.cpp src/grid_system/grid.h src/grid_system/grid.cpp)

target_link_libraries(Revamped_Minecraft_Generation sfml-graphics sfml-window sfml-system)
target_link_libraries(Grid_System sfml-graphics sfml-window sfml-system)
target_link_libraries(Convert_Coords_test sfml-graphics sfml-window sfml-system)
target_link_libraries(Util_directory sfml-graphics sfml-window sfml-system)
target_link_libraries(Vector_Utils_Test sfml-graphics sfml-window sfml-system)
target_link_libraries(Particles_Test sfml-graphics sfml-window sfml-system effolkronium_random)