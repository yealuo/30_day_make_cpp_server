cmake_minimum_required(VERSION 3.28)
project(day11)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCE_SRC "src/*.cpp")
file(GLOB SOURCE_THREAD_POOL "../thread_pool/*.cpp")
set(SOURCE ${SOURCE_SRC} ${SOURCE_THREAD_POOL})

add_executable(main_server main_server.cpp ${SOURCE})
add_executable(stress_test stress_test.cpp ${SOURCE})
