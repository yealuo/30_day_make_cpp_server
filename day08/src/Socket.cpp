//
// Created by yeluo on 24-6-12.
//

#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#include "Socket.h"
#include "util.h"

Socket::Socket() {
    fd = socket(AF_INET, SOCK_STREAM, 0);
    error_handle(fd == -1, "create socket error!");
}

Socket::Socket(int _fd) : fd(_fd) {
    error_handle(fd == -1, "create socket error!");
}

Socket::~Socket() {
    if (fd != -1)
        close(fd);
}

void Socket::bind(InetAddress *addr) {
    int flag = ::bind(fd, (sockaddr *) &addr->addr, addr->addr_len);
    error_handle(flag == -1, "bind error!");
}

void Socket::listen(uint num) {
    int flag = ::listen(fd, num);
    error_handle(flag == -1, "listen error!");
}

void Socket::set_non_blocking() {
    fcntl(fd, F_SETFL, fcntl(fd, F_GETFL) | SOCK_NONBLOCK);
}

int Socket::accept(InetAddress *addr) {
    int clnt_fd = ::accept(fd, (sockaddr *) &addr->addr, &addr->addr_len);
    error_handle(clnt_fd == -1, "accept error!");
    return clnt_fd;
}

int Socket::get_fd() const {
    return fd;
}