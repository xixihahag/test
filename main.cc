/*
 * File: main.cc
 * brief: 
 * 回射服务器主文件
 * Author: gyz
 * Email: mni_gyz@163.com
 * Last Modified: Sunday, 7th October 2018 9:39:06 am
 * -----
 * Copyright 2018 - 2018
 */

#include <glog/logging.h>
#include "EchoServer.h"
#include "EventLoop.h"

int main(int argc, char const *argv[])
{
    // 初始化glog库
    google::InitGoogleLogging(argv[0]);
    FLAGS_log_dir = "./log";

    EventLoop loop;
    EchoServer echoserver(&loop);
    echoserver.start();
    loop.loop();

    // 关库
    google::ShutdownGoogleLogging();
    return 0;
}