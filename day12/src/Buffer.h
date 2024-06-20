//
// Created by yeluo on 24-6-18.
//


#pragma once

#include <string>

class Buffer{
private:
    std::string buf;

public:
    Buffer();
    ~Buffer();

    void append(const char *str,int size);
    void set_buf(const char*);
    void set_buf(const std::string&);
    unsigned int size();
    const char* c_str();
    void clear();
    void getline();
};