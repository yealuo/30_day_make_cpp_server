//
// Created by yeluo on 24-6-19.
//


#pragma once

#include "EventLoop.h"
#include "Socket.h"
#include "Acceptor.h"
#include "Connection.h"
#include "../../thread_pool/Thread_pool.h"

#include <unordered_map>
#include <vector>

class Server {
private:
    EventLoop *main_reactor;
    Acceptor *acceptor;
    std::unordered_map<int, Connection *> connections;
    std::vector<EventLoop *> sub_reactors;
    Thread_pool *thread_pool;

public:
    Server(EventLoop *);

    ~Server();

    void new_connection(Socket *);

    void delete_connection(int sock_fd);


};