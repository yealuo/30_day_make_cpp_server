//
// Created by yeluo on 24-6-19.
//


#pragma once

#include "Epoll.h"
#include "Channel.h"

#include <functional>

class EventLoop {
private:
    Epoll *ep;
    bool quit;

public:
    EventLoop();

    ~EventLoop();

    void loop();

    void update_channel(Channel *);
};