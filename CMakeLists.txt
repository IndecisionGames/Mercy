cmake_minimum_required (VERSION 3.0)

project(Mercy)
set (Mercy_VERSION_MAJOR 0)
set (Mercy_VERSION_MINOR 1)

set (CMAKE_CXX_STANDARD 14)


file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# game
add_executable(Mercy main.cpp src/Game.cpp)
# add_executable(Mercy lq_test.cpp)



# engine
add_subdirectory(RQ-Engine)
target_link_libraries (Mercy RQ-Engine)
