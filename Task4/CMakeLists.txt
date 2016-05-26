project(MagicRect)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")
cmake_minimum_required(VERSION 3.0)

file(GLOB SRC_DEMO . Classes/Demo/*.cpp)
file(GLOB INC_DEMO ./Classes/MagicRect Classes/MagicRect)
file(GLOB SRC_RECT . Classes/MagicRect/*.cpp)
file(GLOB INC_RECT . Classes/MagicRect)

include_directories(${INC_RECT})
include_directories(${INC_DEMO})

#add_library(MagicRectLib ${SRC_RECT} Classes/MagicRect/World.cpp)
add_executable(MagicRect ${SRC_DEMO} ${INC_DEMO})

#target_link_libraries(MagicRect MagicRectLib)
