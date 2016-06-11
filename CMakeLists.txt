cmake_minimum_required(VERSION 3.5)
project(ex1)

set(CMAKE_CXX_FLAGS_DEBUG "-g3 -Wall -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O4 -fstrict-aliasing -ffast-math -mtune=native -march=native -funroll-loops ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmax-errors=3 -std=c++11  -Wstrict-aliasing=2 -fopenmp")

include(ispc.cmake)
create_ispc_library(nbody.ispc)

add_executable(ex1 main.cpp)
target_link_libraries(ex1 ispc)
