project(MyMatrix)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")
cmake_minimum_required(VERSION 3.0)

file(GLOB SRC_DEMO . Classes/Demo/*.cpp)
file(GLOB INC_DEMO ./Classes/MyMatrix Classes/MyMatrix)
file(GLOB SRC_MATR . Classes/MyMatrix/*.cpp)
file(GLOB INC_MATR . Classes/MyMatrix)

include_directories(${INC_MATR})
include_directories(${INC_DEMO})

add_library(MyMatrixLib ${SRC_MATR} Classes/MyMatrix/Matrix.cpp)
add_executable(MyMatrix ${SRC_DEMO} ${INC_DEMO})

target_link_libraries(MyMatrix MyMatrixLib)
