//
// Created by yeluo on 24-6-12.
//

#pragma once

#include <sys/epoll.h>
#include <vector>
#include <memory>

#include "Socket.h"

class Epoll {
private:
    int epfd;
    uint max_event_num;
    std::unique_ptr<epoll_event[]> events;

public:
    explicit Epoll(int max_event_num = 648);

    ~Epoll();

    void add_fd(int, uint);

    void add_sock(Socket *, uint);

    std::vector<epoll_event> poll(int timeout = -1);
};
