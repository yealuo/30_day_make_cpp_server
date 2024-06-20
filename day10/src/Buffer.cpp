//
// Created by yeluo on 24-6-18.
//

#include <iostream>

#include "Buffer.h"

Buffer::Buffer() {

}

Buffer::~Buffer() {

}

void Buffer::append(const char *str, int size) {
    for(int i=0;i<size;++i){
        if(str[i]=='\0') break;
        buf.push_back(str[i]);
    }
}

unsigned int Buffer::size() {
    return buf.size();
}

const char *Buffer::c_str() {
    return buf.c_str();
}

void Buffer::clear() {
    buf.clear();
}

void Buffer::getline() {
    buf.clear();
    std::getline(std::cin,buf);
}
