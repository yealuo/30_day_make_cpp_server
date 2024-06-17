//
// Created by yeluo on 24-6-12.
//

#include <cstring>
#include "InetAddress.h"

InetAddress::InetAddress() : addr_len(sizeof addr) {
    bzero(&addr, sizeof addr);
}

InetAddress::InetAddress(const char *ip, short port) : addr_len(sizeof addr) {
    bzero(&addr, sizeof addr);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(port);
    addr_len = sizeof addr;
}

InetAddress::~InetAddress() = default;
