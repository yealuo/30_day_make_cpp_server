//
// Created by yeluo on 24-6-16.
//

#include <functional>

#include "Server.h"

Server::Server(EventLoop *_loop) : loop(_loop),acceptor(nullptr) {
    acceptor=new Acceptor(loop);
    std::function<void(Socket*)> callback=[this](Socket* sock){ new_connection(sock);};
    acceptor->set_new_connection_callback(std::move(callback));
}

Server::~Server() {
    delete acceptor;
}

void Server::new_connection(Socket *serv_sock) {
    auto *conn=new Connection(loop, serv_sock);
    std::function<void(Socket*)> callback=[this](Socket *clnt_sock){ delete_connection(clnt_sock);};
    conn->set_delete_connection_callback(std::move(callback));
    connections[serv_sock->get_fd()]=conn;
}

void Server::delete_connection(Socket *clnt_sock) {
    std::lock_guard<std::mutex> lock(mtx);
    auto con=connections[clnt_sock->get_fd()];
    connections.erase(clnt_sock->get_fd());
    delete con;
    //close(clnt_sock->get_fd());
}
