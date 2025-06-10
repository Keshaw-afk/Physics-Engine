cmake_minimum_required(VERSION 3.16)

project(ExperimentPhysicsEngine LANGUAGES CXX VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(cyclone STATIC
    physics/src/particle.cpp
)

target_include_directories(cyclone PUBLIC 
    ${CMAKE_SOURCE_DIR}/include
)
