//
// Created by yeluo on 24-6-12.
//

#pragma once

#include <memory>

class InetAddress;

class Socket {
private:
    int fd;

public:
    Socket();

    Socket(int);

    ~Socket();

    void bind(const std::unique_ptr<InetAddress> &addr);

    void listen(uint);

    void set_non_blocking();

    int accept(std::unique_ptr<InetAddress> &);

    int get_fd() const;
};