cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(RobotsTool LANGUAGES CXX)

add_compile_options(-g)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(firstTry src/main.cpp src/robot.cpp src/util.cpp)

