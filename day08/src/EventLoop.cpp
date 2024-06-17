//
// Created by yeluo on 24-6-16.
//

#include "EventLoop.h"
#include <vector>

EventLoop::EventLoop() : ep(new Epoll()), is_quit(false) {}

EventLoop::~EventLoop() {
    delete ep;
    ep = nullptr;
}

void EventLoop::loop() {
    while (!is_quit) {
        std::vector<Channel *> channels;
        channels = ep->poll();
        for (const auto channel: channels) {
            channel->handle_event();
        }
    }
}

void EventLoop::update_channel(Channel *ch) {
    ep->update_channel(ch);
}
