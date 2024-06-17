//
// Created by yeluo on 24-6-16.
//

#include "Server.h"
#include "InetAddress.h"
#include "Channel.h"

#include <functional>
#include <unistd.h>

Server::Server(EventLoop *_loop) : loop(_loop),acceptor(nullptr) {
    acceptor=new Acceptor(loop);
    std::function<void(Socket*)> callback=[this](Socket* sock){ new_connection(sock);};
    acceptor->set_new_connection_callback(callback);
}

Server::~Server() {
    delete acceptor;
}

void Server::new_connection(Socket *serv_sock) {
    Connection *conn=new Connection(loop, serv_sock);
    std::function<void(Socket*)> callback=[this](Socket *clnt_sock){ delete_connection(clnt_sock);};
    conn->set_delete_connection_callback(callback);
    connections[serv_sock->get_fd()]=conn;
}

void Server::delete_connection(Socket *sock) {
    delete connections[sock->get_fd()];
    connections.erase(sock->get_fd());
}
