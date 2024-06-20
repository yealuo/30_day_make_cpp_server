//
// Created by yeluo on 24-6-19.
//


#include "Epoll.h"
#include "util.h"

#include <cstring>
#include <unistd.h>

#define MAX_EVENTS 1024

Epoll::Epoll() : epfd(-1), events(nullptr) {
    epfd = epoll_create1(0);
    error_handle(epfd == -1, "epoll create error");
    events = new epoll_event[MAX_EVENTS];
    bzero(events, sizeof(epoll_event) * MAX_EVENTS);
}

Epoll::~Epoll() {
    if (epfd != -1) {
        close(epfd);
        epfd = -1;
    }

    delete[] events;
}

void Epoll::update_channel(Channel *channel) {
    int fd = channel->get_fd();
    epoll_event event{};
    event.data.ptr = channel;
    event.events = channel->get_events();
    if (!channel->get_is_in_epoll()) {
        error_handle(epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &event) == -1, "epoll add error");
        channel->set_is_in_epoll(true);
    } else {
        error_handle(epoll_ctl(epfd, EPOLL_CTL_MOD, fd, &event) == -1, "epoll modify error");
    }
}

void Epoll::delete_channel(Channel *channel) {
    int fd = channel->get_fd();
    error_handle(epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL) == -1, "epoll delete error");
    channel->set_is_in_epoll(false);
}

std::vector<Channel *> Epoll::poll(int timeout) {
    int ac_fds = epoll_wait(epfd, events, MAX_EVENTS, timeout);
    error_handle(ac_fds == -1, "epoll wait error");
    std::vector<Channel *> active_channels;
    active_channels.reserve(ac_fds);

    for (int i = 0; i < ac_fds; ++i) {
        auto channel = static_cast<Channel *>(events[i].data.ptr);
        active_channels.emplace_back(channel);
        channel->set_ret_events(events[i].events);
    }

    return active_channels;
}
