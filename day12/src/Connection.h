//
// Created by yeluo on 24-6-19.
//


#pragma once

#include "EventLoop.h"
#include "Socket.h"
#include "Channel.h"

#include <functional>
#include <string>

class Connection {
private:
    EventLoop *loop;
    Socket *sock;
    Channel *channel;
    std::function<void(int)> delete_connection_callback;
    std::string buf;

public:
    Connection(EventLoop *, Socket *);

    ~Connection();

    void echo(int clnt_fd);

    void set_delete_connection_callback(std::function<void(int)> &&);

    void send(int clnt_fd);

};