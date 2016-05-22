project(GameOfLife)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")
cmake_minimum_required(VERSION 3.0)

file(GLOB SRC_DEMO . Classes/Demo/*.cpp)
file(GLOB INC_DEMO ./Classes/GameOfLife Classes/GameOfLife)
file(GLOB SRC_LIFE . Classes/GameOfLife/*.cpp)
file(GLOB INC_LIFE . Classes/GameOfLife)

include_directories(${INC_LIFE})
include_directories(${INC_DEMO})

add_library(GameOfLifeLib ${SRC_LIFE} Classes/GameOfLife/World.cpp)
add_executable(GameOfLife ${SRC_DEMO} ${INC_DEMO})

target_link_libraries(GameOfLife GameOfLifeLib)
