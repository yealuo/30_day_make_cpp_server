//
// Created by yeluo on 24-6-16.
//

#include "Acceptor.h"

Acceptor::Acceptor(EventLoop *_loop):loop(_loop) {
    sock=new Socket();
    addr=new InetAddress("127.0.0.1",12345);
    sock->bind(addr);
    sock->listen(8);
    sock->set_non_blocking();
    accept_channel=new Channel(loop,sock->get_fd());
    std::function<void()> callback=[this] { accept_connection(); };
    accept_channel->set_callback(callback);
    accept_channel->enable_reading();
}

Acceptor::~Acceptor() {
    delete sock;
    delete addr;
    delete accept_channel;
}

void Acceptor::accept_connection() {
    InetAddress *clnt_addr=new InetAddress();
    Socket *clnt_sock=new Socket(sock->accept(clnt_addr));
    printf("new client connect!\nfd: %d\nIP: %s\nPort: %d\n", clnt_sock->get_fd(), inet_ntoa(clnt_addr->addr.sin_addr), ntohs(clnt_addr->addr.sin_port));
    clnt_sock->set_non_blocking();
    new_connection_callback(clnt_sock);
    delete clnt_addr;
}

void Acceptor::set_new_connection_callback(std::function<void(Socket *)> callback) {
    new_connection_callback=callback;
}
