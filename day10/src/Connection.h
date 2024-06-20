//
// Created by yeluo on 24-6-17.
//

#pragma once

#include <functional>

#include "EventLoop.h"
#include "Socket.h"
#include "Channel.h"
#include "Buffer.h"

class Connection{
private:
    EventLoop *loop;
    Socket *sock;
    Channel *channel;
    std::function<void(Socket*)> delete_connection_callback;
    Buffer *read_buf;

public:
    Connection(EventLoop *_loop,Socket *_sock);
    ~Connection();

    void echo(int clnt_fd);
    void set_delete_connection_callback(std::function<void(Socket*)>);
};