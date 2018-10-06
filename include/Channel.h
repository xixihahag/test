/*
 * File: Channel.h
 * brief:
 * 定义一个Channel
 * 负责事件的分发
 * Author: gyz
 * Email: mni_gyz@163.com
 * Last Modified: Saturday, 6th October 2018 3:46:39 pm
 * -----
 * Copyright 2018 - 2018
 */

#ifndef __CHANNEL_H__
#define __CHANNEL_H__

#include "Declear.h"

// 定义callback，C+11
using Callback = void (*)();
//
typedef void (*Callback)();

class Channel
{
    // public:
    //   struct CallBack
    //   {
    //       virtual void onRead() = 0; // 纯虚函数
    //       virtual void onWrite() = 0;
    //   };

  private:
    EventLoop *loop_; // 指向EventLoop
    int sockfd_;      // 文件描述符
    int events_;      // 注册事件，FIXME:
    int revents_;     // 返回事件，FIXME:
    int index_;       // 用于指示Epoll::update()是CTL还是ADD 0CTL 1ADD
    IChannelCallBack *callBack_; // 回调函数指针

  public:
    Channel(EventLoop *loop, int sockfd);
    ~Channel();

    void enableReading();
    void enableWriting();
    void disableWriting();
    void setCallBack(IChannelCallBack *callBack);
    void handleEvent();
    void setRevents(int events);
    int getEvents();
    int getSockfd();
    bool isWriting();
    int getIndex();
    void setIndex(int index);

  private:
    void modify(); //修改epoll
    void regist(); //注册epoll
};

#endif // __CHANNEL_H__
