/*
 * File: TcpConnection.h
 * brief:
 * 和客户联系的类，负责数据的发送和接收
 * Author: gyz
 * Email: mni_gyz@163.com
 * Last Modified: Monday, 1st October 2018 4:54:08 pm
 * -----
 * Copyright 2018 - 2018
 */

#ifndef __TCPCONNECTION_H__
#define __TCPCONNECTION_H__

#include "Declear.h"
#include "IChannelCallBack.h"
#include "Buffer.h"

class TcpConnection : public IChannelCallBack
{
  private:
    EventLoop *loop_;
    int sockfd_;
    Channel *pChannel_;
    IMuduoUser *pUser_;
    Buffer inBuf_;
    Buffer outBuf_;

  public:
    TcpConnection(int sockfd, EventLoop *loop);
    ~TcpConnection();
    void virtual handleRead();
    void virtual handleWrite();
    void setUser(IMuduoUser *user);
    void send(const std::string &message);
};

#endif // __TCPCONNECTION_H__
