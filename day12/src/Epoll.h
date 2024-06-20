//
// Created by yeluo on 24-6-19.
//


#pragma once

#include "Channel.h"

#include <vector>
#include <sys/epoll.h>

class Epoll {
private:
    int epfd;
    epoll_event *events;

public:
    Epoll();

    ~Epoll();

    void update_channel(Channel *);

    void delete_channel(Channel *);

    std::vector<Channel *> poll(int timeout = -1);
};