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
    bool is_use_thread_pool;
    std::function<void()> read_callback;
    std::function<void()> write_callback;

public:
    Channel(EventLoop *, int);

    ~Channel();

    void handle_event();

    void enable_reading();

    void use_et();

    int get_fd();

    u_int32_t get_events();

    u_int32_t get_ret_events();

    bool get_is_in_epoll();

    void set_is_in_epoll();

    void set_ret_events(u_int32_t);

    void set_read_callback(std::function<void()>&&);

    void set_is_use_thread_pool(bool is_use);
};