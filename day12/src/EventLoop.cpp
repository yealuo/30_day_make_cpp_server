//
// Created by yeluo on 24-6-19.
//

#include "EventLoop.h"

#include <vector>

EventLoop::EventLoop() : ep(nullptr), quit(false) {
    ep = new Epoll();
}

EventLoop::~EventLoop() {
    delete ep;
}

void EventLoop::loop() {
    while (!quit) {
        std::vector<Channel *> active_channel;
        active_channel = ep->poll();

        for (const auto &ch: active_channel)
            ch->handle_event();
    }
}

void EventLoop::update_channel(Channel *channel) {
    ep->update_channel(channel);
}

