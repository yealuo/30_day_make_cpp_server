//
// Created by yeluo on 24-6-19.
//

#include "Server.h"

Server::Server(EventLoop *_loop) : main_reactor(_loop), acceptor(nullptr) {
    acceptor = new Acceptor(main_reactor);
    acceptor->set_new_connection_callback(std::move([this](Socket *clnt_sock) { new_connection(clnt_sock); }));

    int size = std::thread::hardware_concurrency();
    thread_pool = new Thread_pool(size);
    for (int i = 0; i < size; ++i)
        sub_reactors.emplace_back(new EventLoop);

    for (int i = 0; i < size; ++i) {
        thread_pool->thread_pool_post([this, i] { sub_reactors[i]->loop(); });
    }
}

Server::~Server() {
    delete acceptor;
    delete thread_pool;
}

void Server::new_connection(Socket *clnt_sock) {
    if (clnt_sock->get_fd() != -1) {
        int random = clnt_sock->get_fd() % sub_reactors.size();
        auto conn = new Connection(sub_reactors[random], clnt_sock);
        conn->set_delete_connection_callback([this](int clnt_fd) { delete_connection(clnt_fd); });
        connections[clnt_sock->get_fd()] = conn;
    }
}

void Server::delete_connection(int clnt_fd) {
    if (clnt_fd != -1) {
        auto it = connections.find(clnt_fd);
        if (it != connections.end()) {
            auto conn = it->second;
            connections.erase(clnt_fd);
            //close(clnt_fd);       //正常
            delete conn;         //会Segmant fault
        }
    }
}
