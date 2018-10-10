/*
 * File: EventLoop.h
 * brief:
 * 和Epoll沟通，负责对监听事件的注册修改
 * Author: gyz
 * Email: mni_gyz@163.com
 * Last Modified: Monday, 1st October 2018 4:57:35 pm
 * -----
 * Copyright 2018 - 2018
 */

#ifndef __EVENTLOOP_H__
#define __EVENTLOOP_H__

#include "Declear.h"

class EventLoop
{
  private:
    bool quit_; // 是否退出事件监听循环
    Epoll *poller_;

  public:
    EventLoop();
    ~EventLoop();

    void loop();                   // 事件循环
    void modify(Channel &channel); // 注册修改事件接口
    void regist(Channel &channel); // 注册添加事件接口
};

#endif // __EVENTLOOP_H__
