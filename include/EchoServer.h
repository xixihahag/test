/*
 * File: EchoServer.h
 * brief:
 * 负责对发送到服务器的数据进行处理
 * 并且控制分段发送回射
 * Author: gyz
 * Email: mni_gyz@163.com
 * Last Modified: Monday, 1st October 2018 4:56:48 pm
 * -----
 * Copyright 2018 - 2018
 */

#ifndef __ECHOSERVER_H__
#define __ECHOSERVER_H__

#include "TcpServer.h"
#include "IMuduoUser.h"
#include "Buffer.h"

class EchoServer : public IMuduoUser
{
  private:
    TcpServer pServer_;

  public:
    EchoServer(EventLoop *loop);
    ~EchoServer();

    void start(); // 初始化sock4网络连接
    void virtual onMessage(
        TcpConnection *pCon,
        Buffer *pBuf); // 数据传递结束的回调函数
    void virtual onConnection(TcpConnection *pCon); // 新链接建立后的回调函数
};

#endif // __ECHOSERVER_H__