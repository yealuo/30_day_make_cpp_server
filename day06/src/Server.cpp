//
// Created by yeluo on 24-6-16.
//

#include "Server.h"
#include "InetAddress.h"
#include "Channel.h"

#include <functional>
#include <unistd.h>

#define READ_BUF 1024

Server::Server(EventLoop *_loop) : loop(_loop) {
    Socket *serv_sock = new Socket();
    InetAddress *serv_addr = new InetAddress("127.0.0.1", 12345);
    serv_sock->bind(serv_addr);
    serv_sock->listen(8);
    serv_sock->set_non_blocking();

    Channel *serv_channel = new Channel(loop, serv_sock->get_fd());
    std::function<void()> callback = std::bind(&Server::new_connect, this, serv_sock);
    serv_channel->set_callback(callback);
    serv_channel->enable_reading();
}

Server::~Server() {}

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
    std::function<void()> callback = std::bind(&Server::handle_read_event, this, clnt_sock->get_fd());
    clnt_channel->set_callback(callback);
    clnt_channel->enable_reading();
}
