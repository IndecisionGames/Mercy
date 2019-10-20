cmake_minimum_required (VERSION 3.0)

project(Mercy)
set (Mercy_VERSION_MAJOR 0)
set (Mercy_VERSION_MINOR 1)

# game
add_executable(Mercy main.cpp)

# engine
add_subdirectory(RQ-Engine)
target_link_libraries (Mercy RQ-Engine)

