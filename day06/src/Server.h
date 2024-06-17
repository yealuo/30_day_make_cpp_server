//
// Created by yeluo on 24-6-16.
//


#pragma once

#include "EventLoop.h"
#include "Socket.h"

class Server {
private:
    EventLoop *loop;

public:
    Server(EventLoop *);

    ~Server();

    void handle_read_event(int);

    void new_connect(Socket *);
};