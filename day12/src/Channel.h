//
// Created by yeluo on 24-6-19.
//


#pragma once

#include "Socket.h"

#include <functional>

class EventLoop;

class Channel {
private:
    EventLoop *loop;
    int fd;
    uint32_t events;
    uint32_t ret_events;
    bool is_in_epoll;
    std::function<void()> read_callback;
    std::function<void()> write_callback;

public:
    Channel(EventLoop *, int);

    ~Channel();

    void handle_event();

    void enable_read();

    int get_fd();

    uint32_t get_events();

    uint32_t get_ret_events();

    bool get_is_in_epoll();

    void set_is_in_epoll(bool);

    void set_et();

    void set_ret_events(uint32_t);

    void set_read_callback(std::function<void()> &&);
};