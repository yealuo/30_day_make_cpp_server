//
// Created by yeluo on 24-6-17.
//

#include "Connection.h"
#include "util.h"

#define MAX_BUFFER 1024

Connection::Connection(EventLoop *_loop, Socket *_sock):loop(_loop),sock(_sock) {
    channel=new Channel(loop,sock->get_fd());
    std::function<void()> callback=[this]{ echo(sock->get_fd());};
    channel->set_callback(callback);
    channel->enable_reading();
    read_buf=new Buffer();
}

Connection::~Connection() {
    delete channel;
    delete sock;
}

void Connection::echo(int clnt_fd) {
    char buf[MAX_BUFFER]{};
    while (true) {
        int read_len = read(clnt_fd, buf, MAX_BUFFER);
        if (read_len > 0) {
            read_buf->append(buf,read_len);
        } else if (read_len == 0) {
            printf("client(fd: %d) disconnected!\n", clnt_fd);
            delete_connection_callback(sock);
            break;
        } else {
            if (errno == EINTR) {
                printf("continue reading!\n");
                continue;
            } else if (errno == EAGAIN) {
                printf("finish reading once...\n");
                printf("message from client fd %d: %s\n", clnt_fd, read_buf->c_str());
                error_handle(write(clnt_fd,read_buf->c_str(),read_buf->size())==-1,"socket write error");
                read_buf->clear();
                break;
            }
        }
    }
}

void Connection::set_delete_connection_callback(std::function<void(Socket *)> callback) {
    delete_connection_callback=callback;
}
