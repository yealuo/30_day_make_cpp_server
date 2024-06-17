//
// Created by yeluo on 24-6-12.
//

#include <iostream>

#include "util.h"
#include "Epoll.h"
#include "InetAddress.h"
#include "Socket.h"

#define READ_BUFFER 1024

void handle_read_event(Socket *);

int main() {
    auto serv_sock = std::make_unique<Socket>();
    auto serv_addr = std::make_unique<InetAddress>("0.0.0.0", 12345);
    serv_sock->bind(serv_addr);
    serv_sock->listen(8);

    auto ep = std::make_unique<Epoll>();
    serv_sock->set_non_blocking();
    ep->add_fd(serv_sock->get_fd(), EPOLLIN | EPOLLET);

    while (true) {
        std::vector<epoll_event> events = ep->poll();
        int events_num = events.size();
        for (int i = 0; i < events_num; ++i) {
            if (events[i].data.fd == serv_sock->get_fd()) {
                auto clnt_addr = std::make_unique<InetAddress>();
                auto clnt_sock = new Socket(serv_sock->accept(clnt_addr));
                printf("new client connect!\nfd: %d\nIP: %s\nPort: %d\n", clnt_sock->get_fd(),
                       inet_ntoa(clnt_addr->addr.sin_addr),
                       ntohs(clnt_addr->addr.sin_port));
                clnt_sock->set_non_blocking();
                ep->add_sock(clnt_sock, EPOLLIN | EPOLLET);
            } else if (events[i].events == EPOLLIN) {//客户端套接字接收到消息
                handle_read_event(static_cast<Socket *>(events[i].data.ptr));
            } else {
                std::cout << "something else happen!\n" << std::endl;
            }
        }
    }

    return 0;
}

void handle_read_event(Socket *clnt_sock) {
    char buf[READ_BUFFER] = {};
    while (true) {
        int read_len = read(clnt_sock->get_fd(), buf, sizeof buf);
        if (read_len > 0) {
            printf("message from client(fd: %d):%s", clnt_sock->get_fd(), buf);
            write(clnt_sock->get_fd(), buf, read_len);
        } else if (read_len == 0) {
            printf("client(fd: %d) disconnected!\n", clnt_sock->get_fd());
            delete clnt_sock;
            break;
        } else {
            if (errno == EINTR) {
                std::cout << "continue reading" << std::endl;
                continue;
            } else if (errno == EAGAIN) {
                std::cout << "finish read once,errno: " << (errno == EAGAIN ? "EAGAIN" : std::to_string(errno))
                          << std::endl;
                break;
            }
        }
    }
}