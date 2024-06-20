//
// Created by yeluo on 24-6-18.
//

#include <iostream>
#include <unistd.h>
#include <cstring>
#include <functional>

#include "src/Buffer.h"
#include "src/InetAddress.h"
#include "src/Socket.h"
#include "../thread_pool/Thread_pool.h"

using namespace std;

void oneClient(int msgs, int wait,int index){
    Socket *sock = new Socket();
    InetAddress *addr = new InetAddress("127.0.0.1", 12345);
    sock->connect(addr);

    int sockfd = sock->get_fd();

    Buffer *sendBuffer = new Buffer();
    Buffer *readBuffer = new Buffer();

    sleep(wait);
    int count = 0;
    while(count < msgs){
        string msg="I'm client! index: "+std::to_string(index);
        sendBuffer->set_buf(msg);
        ssize_t write_bytes = write(sockfd, sendBuffer->c_str(), sendBuffer->size());
        if(write_bytes == -1){
            printf("socket already disconnected, can't write any more!\n");
            break;
        }
        int already_read = 0;
        char buf[1024];    //这个buf大小无所谓
        while(true){
            bzero(&buf, sizeof(buf));
            ssize_t read_bytes = read(sockfd, buf, sizeof(buf));
            if(read_bytes > 0){
                readBuffer->append(buf, read_bytes);
                already_read += read_bytes;
            } else if(read_bytes == 0){         //EOF
                printf("server disconnected!\n");
                exit(EXIT_SUCCESS);
            }
            if(already_read >= sendBuffer->size()){
                printf("count: %d, message from server: %s\n", count++, readBuffer->c_str());
                break;
            }
        }
        readBuffer->clear();
    }
    delete addr;
    delete sock;
}

int main(int argc, char *argv[]) {
    int threads = 10000;
    int msgs = 100;
    int wait = 0;
    int o;
    const char *optstring = "t:m:w:";
    while ((o = getopt(argc, argv, optstring)) != -1) {
        switch (o) {
            case 't':
                threads = stoi(optarg);
                break;
            case 'm':
                msgs = stoi(optarg);
                break;
            case 'w':
                wait = stoi(optarg);
                break;
            case '?':
                printf("error optopt: %c\n", optopt);
                printf("error opterr: %d\n", opterr);
                break;
        }
    }

    Thread_pool *poll = new Thread_pool(threads);
    for(int i = 0; i < threads; ++i){
        std::function<void()> func = [msgs, wait, i] { oneClient(msgs, wait, i); };
        poll->thread_pool_post(func);
    }
    delete poll;
    return 0;
}
