//
// Created by yeluo on 24-6-16.
//

#include "EventLoop.h"
#include <vector>

EventLoop::EventLoop() : ep(nullptr),thread_pool(nullptr) ,is_quit(false) {
    ep=new Epoll();
    thread_pool=new Thread_pool(4);
}

EventLoop::~EventLoop() {
    delete ep;
    delete thread_pool;
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

void EventLoop::add_thread(std::function<void()> &&task) {
    thread_pool->thread_pool_post(task);
}


