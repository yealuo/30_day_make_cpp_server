cmake_minimum_required(VERSION 3.28)
project(day06)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCE "src/*.cpp")

add_executable(main_server main_server.cpp ${SOURCE})
