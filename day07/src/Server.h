//
// Created by yeluo on 24-6-16.
//


#pragma once

#include "EventLoop.h"
#include "Socket.h"
#include "Acceptor.h"

class Server {
private:
    EventLoop *loop;
    Acceptor *acceptor;

public:
    Server(EventLoop *);

    ~Server();

    void handle_read_event(int);

    void new_connect(Socket *serv_sock);
};