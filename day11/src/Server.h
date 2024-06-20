//
// Created by yeluo on 24-6-16.
//


#pragma once

#include <unordered_map>
#include <mutex>

#include "EventLoop.h"
#include "Socket.h"
#include "Acceptor.h"
#include "Connection.h"

class Server {
private:
    EventLoop *loop;
    Acceptor *acceptor;
    std::unordered_map<int,Connection*> connections;
    std::mutex mtx;

public:
    Server(EventLoop *);

    ~Server();

    void new_connection(Socket *serv_sock);

    void delete_connection(Socket *clnt_sock);
};