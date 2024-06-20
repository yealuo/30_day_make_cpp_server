//
// Created by yeluo on 24-6-19.
//


#pragma once

#include <arpa/inet.h>

class InetAddress {
private:
    sockaddr_in addr;

public:
    InetAddress();

    InetAddress(const char *ip, uint16_t port);

    ~InetAddress();

    void set_addr(sockaddr_in _addr);

    sockaddr_in get_addr() const;

    char *get_ip() const;

    uint16_t get_port();
};

class Socket {
private:
    int fd;

public:
    Socket();

    explicit Socket(int _fd);

    ~Socket();

    void bind(InetAddress *);

    void listen(uint32_t listen_num = SOMAXCONN);

    int accept(InetAddress *);

    void connect(InetAddress *);

    void set_nonblocking();

    int get_fd();
};