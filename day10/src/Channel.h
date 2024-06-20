//
// Created by yeluo on 24-6-16.
//


#pragma once

#include <functional>

class EventLoop;

class Channel {
    EventLoop *loop;
    int fd;
    u_int32_t events;
    u_int32_t ret_events;
    bool is_in_epoll;
    std::function<void()> callback;

public:
    Channel(EventLoop *, int);

    ~Channel();

    void handle_event();

    void enable_reading();

    int get_fd();

    u_int32_t get_events();

    u_int32_t get_ret_events();

    bool get_is_in_epoll();

    void set_is_in_epoll();

    void set_ret_events(u_int32_t);

    void set_callback(std::function<void()>);
};