//
// Created by yeluo on 24-6-16.
//


#pragma once

#include "Epoll.h"
#include "Channel.h"

class EventLoop {
private:
    Epoll *ep;
    bool is_quit;

public:
    EventLoop();

    ~EventLoop();

    void loop();

    void update_channel(Channel *);
};