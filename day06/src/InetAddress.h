//
// Created by yeluo on 24-6-12.
//

#pragma once

#include <arpa/inet.h>

class InetAddress {
public:
    struct sockaddr_in addr;
    socklen_t addr_len;

    InetAddress();

    InetAddress(const char *, short);

    ~InetAddress();
};