//
// Created by yeluo on 24-6-16.
//

#include "Server.h"
#include "InetAddress.h"
#include "Channel.h"

#include <functional>
#include <unistd.h>

#define READ_BUF 1024

Server::Server(EventLoop *_loop) : loop(_loop),acceptor(nullptr) {
    acceptor=new Acceptor(loop);
    std::function<void(Socket*)> callback=[this](Socket* sock){ new_connect(sock);};
    acceptor->set_new_connection_callback(callback);
}

Server::~Server() {
    delete acceptor;
}

void Server::handle_read_event(int clnt_fd) {
    char buf[READ_BUF]{};
    while (true) {
        int read_len = read(clnt_fd, buf, READ_BUF);
        if (read_len > 0) {
            printf("message from client(fd: %d):%s\n", clnt_fd, buf);
            write(clnt_fd, buf, read_len);
        } else if (read_len == 0) {
            printf("client(fd: %d) disconnected!\n", clnt_fd);
            close(clnt_fd);
            break;
        } else {
            if (errno == EINTR) {
                printf("continue reading!\n");
                continue;
            } else if (errno == EAGAIN) {
                printf("finish reading once...\n");
                break;
            }
        }
    }
}

void Server::new_connect(Socket *serv_sock) {
    InetAddress *clnt_addr = new InetAddress();
    Socket *clnt_sock = new Socket(serv_sock->accept(clnt_addr));
    printf("new client connect!\nfd: %d\nIP: %s\nPort: %d\n", clnt_sock->get_fd(), inet_ntoa(clnt_addr->addr.sin_addr),
           clnt_addr->addr.sin_port);
    clnt_sock->set_non_blocking();
    Channel *clnt_channel = new Channel(loop, clnt_sock->get_fd());
    std::function<void()> callback = [this, clnt_sock] { handle_read_event(clnt_sock->get_fd()); };
    clnt_channel->set_callback(callback);
    clnt_channel->enable_reading();
}
