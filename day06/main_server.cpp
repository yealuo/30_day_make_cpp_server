#include "src/EventLoop.h"
#include "src/Server.h"

int main() {
    auto *loop = new EventLoop();
    auto *server = new Server(loop);
    loop->loop();
    return 0;
}
