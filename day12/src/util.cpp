//
// Created by yeluo on 24-6-12.
//

#include <cstdio>
#include <cstdlib>
#include "util.h"

void error_handle(bool condition, const char *message) {
    if (condition) {
        perror(message);
        exit(-1);
    }
}
