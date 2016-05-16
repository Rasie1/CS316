project(GameOfLife)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")
cmake_minimum_required(VERSION 3.0)

file(GLOB SRC_DEMO . Classes/Demo/*.cpp)
file(GLOB INC_DEMO ./Classes/GameOfLife Classes/GameOfLife)
file(GLOB SRC_MATR . Classes/GameOfLife/*.cpp)
file(GLOB INC_MATR . Classes/GameOfLife)

include_directories(${INC_MATR})
include_directories(${INC_DEMO})

add_library(GameOfLifeLib ${SRC_MATR} Classes/GameOfLife/GameOfLife.cpp)
add_executable(GameOfLife ${SRC_DEMO} ${INC_DEMO})

target_link_libraries(GameOfLife GameOfLifeLib)
