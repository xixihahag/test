/*
 * File: Epoll.h
 * brief:
 * 定义一个Epoll
 * Author: gyz
 * Email: mni_gyz@163.com
 * Last Modified: Saturday, 29th September 2018 8:38:23 pm
 * -----
 * Copyright 2018 - 2018
 */

#ifndef __EPOLL_H__
#define __EPOLL_H__

// #include <sys/epoll.h>
#include <vector>
#include "Declear.h"
#include "Define.h"

class Epoll
{
  private:
    int epfd_; // epoll文件描述符

  public:
    Epoll();
    ~Epoll();
    void initialize();
    // 阻塞轮询
    int poll(Channel *channels[], int length);
    int regist(Channel &channel);
    int modify(Channel &channel);
};

#endif // __EPOLL_H__
