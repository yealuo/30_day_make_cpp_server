//
// Created by yeluo on 24-6-19.
//

#include "Connection.h"

#include <unistd.h>
#include <cstring>

Connection::Connection(EventLoop *_loop, Socket *_sock) : loop(_loop), sock(_sock), channel(nullptr) {
    channel = new Channel(loop, sock->get_fd());
    channel->set_et();
    channel->set_read_callback(std::move([this] { echo(sock->get_fd()); }));
    channel->enable_read();
}

Connection::~Connection() {
    delete channel;
    delete sock;
}

void Connection::echo(int clnt_fd) {
    char t_buf[1024]{};
    while (true) {    //由于使用非阻塞IO，读取客户端buffer，一次读取buf大小数据，直到全部读取完毕
        ssize_t bytes_read = read(clnt_fd, t_buf, sizeof t_buf);
        if (bytes_read > 0) {
            buf.append(t_buf, bytes_read);
            continue;
        } else if (bytes_read == -1 && errno == EINTR) {  //客户端正常中断、继续读取
            printf("continue reading\n");
            continue;
        } else if (bytes_read == -1 && ((errno == EAGAIN) || (errno == EWOULDBLOCK))) {//非阻塞IO，这个条件表示数据全部读取完毕
            printf("message from client fd %d: %s\n", clnt_fd, &buf[0]);
            // errif(write(clnt_fd, readBuffer->c_str(), readBuffer->size()) == -1, "socket write error");
            write(clnt_fd, &buf[0], buf.size());
            bzero(t_buf, sizeof t_buf);
            buf.clear();
            break;
        } else if (bytes_read == 0) {  //EOF，客户端断开连接
            printf("EOF, client fd %d disconnected\n", clnt_fd);
            delete_connection_callback(clnt_fd);
            break;
        } else {
            printf("Connection reset by peer\n");
            delete_connection_callback(clnt_fd);
            break;
        }
    }
}

void Connection::set_delete_connection_callback(std::function<void(int)> &&cb) {
    delete_connection_callback = cb;
}
