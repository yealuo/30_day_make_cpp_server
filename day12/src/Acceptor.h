//
// Created by yeluo on 24-6-19.
//


#pragma once

#include "EventLoop.h"
#include "Socket.h"
#include "Channel.h"

#include <functional>

class Acceptor {
private:
    EventLoop *loop;
    Socket *sock;
    Channel *accept_channel;
    std::function<void(Socket *)> new_connection_callback;

public:
    Acceptor(EventLoop *);

    ~Acceptor();

    void accept_connection();

    void set_new_connection_callback(std::function<void(Socket *)> &&);

};