cmake_minimum_required(VERSION 3.28)
project(day04)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(server
        server.cpp
        Epoll.cpp
        InetAddress.cpp
        Socket.cpp
        util.cpp
)

add_executable(client
        client.cpp
        util.cpp
)
