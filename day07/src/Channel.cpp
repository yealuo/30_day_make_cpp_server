//
// Created by yeluo on 24-6-16.
//

#include <sys/epoll.h>

#include "Channel.h"
#include "EventLoop.h"

Channel::Channel(EventLoop *_loop, int _fd) : loop(_loop), fd(_fd), events(0), ret_events(0), is_in_epoll(false) {}

Channel::~Channel() {}

void Channel::handle_event() {
    callback();
}

void Channel::enable_reading() {
    events = EPOLLIN | EPOLLET;
    loop->update_channel(this);
}

int Channel::get_fd() {
    return fd;
}

u_int32_t Channel::get_events() {
    return events;
}

u_int32_t Channel::get_ret_events() {
    return ret_events;
}

bool Channel::get_is_in_epoll() {
    return is_in_epoll;
}

void Channel::set_is_in_epoll() {
    is_in_epoll = true;
}

void Channel::set_ret_events(u_int32_t ev) {
    ret_events = ev;
}

void Channel::set_callback(std::function<void()> cb) {
    callback = cb;
}
