//
// Created by yeluo on 24-6-16.
//


#pragma once

#include <functional>

#include "EventLoop.h"
#include "Socket.h"
#include "InetAddress.h"
#include "Channel.h"

class Acceptor{
private:
    EventLoop *loop;
    Socket *sock;
    InetAddress *addr;
    Channel *accept_channel;
    std::function<void(Socket*)> new_connection_callback;

public:
    Acceptor(EventLoop *_loop);
    ~Acceptor();

    void accept_connection();
    void set_new_connection_callback(std::function<void(Socket*)>);
};