//
// Created by yeluo on 24-6-16.
//


#pragma once

#include "Epoll.h"
#include "Channel.h"
#include "../../thread_pool/Thread_pool.h"

class EventLoop {
private:
    Epoll *ep;
    Thread_pool *thread_pool;
    bool is_quit;

public:
    EventLoop();

    ~EventLoop();

    void loop();

    void update_channel(Channel *);

    void add_thread(std::function<void()>&&);
};