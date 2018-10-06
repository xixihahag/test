/**
 * @file main.cc
 * @brief 回射服务器主文件
 * 
 * @author gyz
 * @email
 */

#include "EchoServer.h"
#include "EventLoop.h"

int main(int argc, char const *argv[]) {
    EventLoop loop;
    EchoServer echoserver(&loop);
    echoserver.start();
    loop.loop();

    return 0;
}
