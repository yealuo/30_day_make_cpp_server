//
// Created by yeluo on 24-6-12.
//

#pragma once

#include <memory>

#include "InetAddress.h"

class Socket {
private:
    int fd;

public:
    Socket();

    Socket(int);

    ~Socket();

    void bind(InetAddress *addr);

    void listen(uint);

    void set_non_blocking();

    int accept(InetAddress *);

    int get_fd() const;
};