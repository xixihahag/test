/*
 * File: TcpServer.h
 * brief:
 * 负责处理Accopter的调用，新建一个Connection
 * Author: gyz
 * Email: mni_gyz@163.com
 * Last Modified: Monday, 1st October 2018 5:00:17 pm
 * -----
 * Copyright 2018 - 2018
 */

#ifndef __TCPSERVER_H__
#define __TCPSERVER_H__

#include "Declear.h"
#include "IAcceptorCallBack.h"

class TcpServer : public IAcceptorCallBack
{
  private:
    EventLoop *ploop_;
    Acceptor *Acceptor_;
    IMuduoUser *pUser_;

  public:
    TcpServer(EventLoop *loop);
    ~TcpServer();
    void start();
    void setUser(IMuduoUser *user);
    virtual void newConnection(int sockfd);
};

#endif // __TCPSERVER_H__
