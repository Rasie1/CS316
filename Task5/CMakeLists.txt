project(Types)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")
cmake_minimum_required(VERSION 3.0)

file(GLOB SRC_DEMO  . Classes/Demo/*.cpp)
file(GLOB INC_DEMO  ./Classes/Types Classes/Types)
file(GLOB SRC_TYPES . Classes/Types/*.cpp)
file(GLOB INC_TYPES . Classes/Types)

include_directories(${INC_TYPES})
include_directories(${INC_DEMO})

add_executable(Types ${SRC_DEMO} ${INC_DEMO} ${INC_TYPES})

