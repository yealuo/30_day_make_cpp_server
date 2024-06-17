//
// Created by yeluo on 24-6-12.
//

#include <memory>
#include <unistd.h>

#include "util.h"
#include "Epoll.h"

Epoll::Epoll(int max_event_num) : max_event_num(max_event_num) {
    epfd = epoll_create1(0);
    error_handle(epfd == -1, "epoll create error!");
    events = new epoll_event[max_event_num];
    for (int i = 0; i < max_event_num; ++i)
        events[i] = epoll_event{};
}

Epoll::~Epoll() {
    if (epfd != -1) {
        close(epfd);
        epfd = -1;
    }

    delete[] events;
}

void Epoll::add_fd(int fd, uint op) {
    epoll_event ev{};
    ev.data.fd = fd;
    ev.events = op;
    int flag = epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &ev);
    error_handle(flag == -1, "epoll add error!");
}

std::vector<Channel *> Epoll::poll(int timeout) {
    int event_num = epoll_wait(epfd, events, max_event_num, timeout);
    error_handle(event_num == -1, "epoll wait error!");

    std::vector<Channel *> ret;
    ret.reserve(event_num);

    for (int i = 0; i < event_num; ++i) {
        Channel *ch = (Channel *) events[i].data.ptr;
        ch->set_ret_events(events[i].events);
        ret.emplace_back(ch);
    }

    return ret;
}

void Epoll::update_channel(Channel *ch) {
    int fd = ch->get_fd();
    epoll_event ev{};
    ev.data.ptr = ch;
    ev.events = ch->get_events();

    if (!ch->get_is_in_epoll()) {//不在epoll里
        int flag = epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &ev);
        error_handle(flag == -1, "epoll add error");
        ch->set_is_in_epoll();
    } else {//已经在epoll里
        int flag = epoll_ctl(epfd, EPOLL_CTL_MOD, fd, &ev);
        error_handle(flag == -1, "epoll modify error");
    }
}
