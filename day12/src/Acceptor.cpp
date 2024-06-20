//
// Created by yeluo on 24-6-19.
//

#include "Acceptor.h"

#include <cstdio>

Acceptor::Acceptor(EventLoop *_loop) : loop(_loop), sock(nullptr), accept_channel(nullptr) {
    sock = new Socket();
    auto serv_addr = new InetAddress("127.0.0.1", 12345);
    sock->bind(serv_addr);
    sock->listen();
    accept_channel = new Channel(loop, sock->get_fd());
    accept_channel->set_read_callback(std::move([this] { accept_connection(); }));
    accept_channel->enable_read();
    delete serv_addr;
}

Acceptor::~Acceptor() {
    delete sock;
    delete accept_channel;
}

void Acceptor::accept_connection() {
    auto clnt_addr = new InetAddress();
    auto clnt_sock = new Socket(sock->accept(clnt_addr));
    printf("new client fd %d! IP: %s Port: %d\n", clnt_sock->get_fd(), clnt_addr->get_ip(), clnt_addr->get_port());
    clnt_sock->set_nonblocking();
    new_connection_callback(clnt_sock);
    delete clnt_addr;
}

void Acceptor::set_new_connection_callback(std::function<void(Socket *)> &&cb) {
    new_connection_callback = cb;
}
