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
    events = std::make_unique<epoll_event[]>(max_event_num);
    for (int i = 0; i < max_event_num; ++i)
        events[i] = epoll_event{};
}

Epoll::~Epoll() {
    if (epfd != -1) {
        close(epfd);
        epfd = -1;
    }
}

void Epoll::add_fd(int fd, uint op) {
    epoll_event ev{};
    ev.data.fd = fd;
    ev.events = op;
    int flag = epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &ev);
    error_handle(flag == -1, "epoll add error!");
}

void Epoll::add_sock(Socket *sock, uint op) {
    epoll_event ev{};
    ev.data.ptr = sock;
    ev.events = op;
    int flag = epoll_ctl(epfd, EPOLL_CTL_ADD, sock->get_fd(), &ev);
    error_handle(flag == -1, "epoll add error!");
}

std::vector<epoll_event> Epoll::poll(int timeout) {
    int event_num = epoll_wait(epfd, events.get(), max_event_num, timeout);
    error_handle(event_num == -1, "epoll wait error!");

    std::vector<epoll_event> ret;
    ret.reserve(event_num);

    for (int i = 0; i < event_num; ++i) {
        ret.emplace_back(events[i]);
    }

    return ret;
}

