//
// Created by yeluo on 24-6-12.
//

#pragma once

#include <sys/epoll.h>
#include <vector>

#include "Socket.h"
#include "Channel.h"

class Epoll {
private:
    int epfd;
    uint max_event_num;
    epoll_event *events;

public:
    explicit Epoll(int max_event_num = 648);

    ~Epoll();

    void add_fd(int, uint);

    void update_channel(Channel *);

    std::vector<Channel *> poll(int timeout = -1);
};
