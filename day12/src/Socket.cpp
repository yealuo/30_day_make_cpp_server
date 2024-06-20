//
// Created by yeluo on 24-6-19.
//

#include "Socket.h"
#include "util.h"

#include <unistd.h>
#include <fcntl.h>
#include <cerrno>

InetAddress::InetAddress() : addr(sockaddr_in{}) {
}

InetAddress::InetAddress(const char *ip, uint16_t port) : addr(sockaddr_in{}) {
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(port);
}

InetAddress::~InetAddress() = default;

void InetAddress::set_addr(sockaddr_in _addr) {
    addr = _addr;
}

sockaddr_in InetAddress::get_addr() const {
    return addr;
}

char *InetAddress::get_ip() const {
    return inet_ntoa(addr.sin_addr);
}

uint16_t InetAddress::get_port() {
    return ntohs(addr.sin_port);
}

Socket::Socket() : fd(-1) {
    fd = socket(AF_INET, SOCK_STREAM, 0);
    error_handle(fd == -1, "socket create error!");
}

Socket::Socket(int _fd) : fd(_fd) {
    error_handle(fd == -1, "socket create error");
}

Socket::~Socket() {
    if (fd != -1) {
        close(fd);
        fd = -1;
    }
}

void Socket::bind(InetAddress *_addr) {
    sockaddr_in addr = _addr->get_addr();
    error_handle(::bind(fd, (sockaddr *) &addr, sizeof addr) == -1, "socket bind error");
}

void Socket::listen(uint32_t listen_num) {
    error_handle(::listen(fd, listen_num) == -1, "socket listen error");
}

int Socket::accept(InetAddress *_clnt_addr) {
    int clnt_fd = -1;
    sockaddr_in clnt_addr{};
    socklen_t clnt_addr_len = sizeof clnt_addr;

    if (fcntl(fd, F_GETFL) & SOCK_NONBLOCK) {
        //服务端套接字为非阻塞模式时一直接受请求，直到成功或因为其它原因失败
        while (true) {
            clnt_fd = ::accept(fd, (sockaddr *) &clnt_addr, &clnt_addr_len);
            if (clnt_fd == -1 && ((errno == EAGAIN) || (errno == EWOULDBLOCK))) {
                continue;
            } else if (clnt_fd == -1) {
                //发生其它错误
                error_handle(true, "socket accept error");
            } else {
                //正常连接
                break;
            }
        }
    } else {
        clnt_fd = ::accept(fd, (sockaddr *) &clnt_addr, &clnt_addr_len);
        error_handle(clnt_fd == -1, "socket accept error");
    }

    _clnt_addr->set_addr(clnt_addr);
    return clnt_fd;
}

void Socket::connect(InetAddress *_serv_addr) {
    sockaddr_in serv_addr = _serv_addr->get_addr();

    if (fcntl(fd, F_GETFL) & SOCK_NONBLOCK) {
        while (true) {
            int flag = ::connect(fd, (sockaddr *) &serv_addr, sizeof serv_addr);
            if (flag == 0)
                break;
            else if (flag = -1 && (errno == EINPROGRESS)) {
                continue;
            } else if (flag == -1) {
                error_handle(true, "socket connect error");
            }
        }
    } else {
        error_handle(::connect(fd, (sockaddr *) &serv_addr, sizeof serv_addr) == -1, "socket connect error");
    }
}

void Socket::set_nonblocking() {
    fcntl(fd, F_SETFL, fcntl(fd, F_GETFL) | SOCK_NONBLOCK);
}

int Socket::get_fd() {
    return fd;
}
