/*
 * File: Acceptor.h
 * brief:
 * 负责socket4网络的初始化
 * 处理新来的链接（监听listenfd）
 * Author: gyz
 * Email: mni_gyz@163.com
 * Last Modified: Monday, 1st October 2018 12:17:20 pm
 * -----
 * Copyright 2018 - 2018
 */

#ifndef _Acceptor__H__
#define _Acceptor__H__

#include "Declear.h"
#include "IChannelCallBack.h"

class Acceptor : public IChannelCallBack
{
    // public:
    //   struct CallBack
    //   {
    //       void virtual newConnection(int sockfd) = 0;
    //   };

  private:
    int listenfd_;
    Channel *acceptChannel_;
    IAcceptorCallBack *pCallBack_;
    EventLoop *loop_;

  public:
    Acceptor(EventLoop *loop);
    ~Acceptor();

    void setCallBack(IAcceptorCallBack *pCallBack);
    void start();
    int createAndListen();
    void virtual handleRead();
    void virtual handleWrite();
};

#endif // _Acceptor__H__
