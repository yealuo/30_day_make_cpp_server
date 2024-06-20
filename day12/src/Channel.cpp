//
// Created by yeluo on 24-6-19.
//

#include "Channel.h"
#include "EventLoop.h"

#include <unistd.h>
#include <sys/epoll.h>

Channel::Channel(EventLoop *_loop, int _fd) : loop(_loop), fd(_fd), events(0), ret_events(0), is_in_epoll(false) {

}

Channel::~Channel() {
    if (fd != -1) {
        close(fd);
        fd = -1;
    }
}

void Channel::handle_event() {
    if (ret_events & (EPOLLIN | EPOLLPRI))
        read_callback();

    if (ret_events & EPOLLOUT)
        write_callback();

}

void Channel::enable_read() {
    events |= EPOLLIN | EPOLLPRI;
    loop->update_channel(this);
}

int Channel::get_fd() {
    return fd;
}

uint32_t Channel::get_events() {
    return events;
}

uint32_t Channel::get_ret_events() {
    return ret_events;
}

bool Channel::get_is_in_epoll() {
    return is_in_epoll;
}

void Channel::set_is_in_epoll(bool is) {
    is_in_epoll = is;
}

void Channel::set_et() {
    events |= EPOLLET;
    loop->update_channel(this);
}

void Channel::set_ret_events(uint32_t ret) {
    ret_events = ret;
}

void Channel::set_read_callback(std::function<void()> &&cb) {
    read_callback = cb;
}
