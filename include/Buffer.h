/*
 * File: Buffer.h
 * brief:
 * 接收数据和发送数据缓冲区
 * Author: gyz
 * Email: mni_gyz@163.com
 * Last Modified: Saturday, 6th October 2018 8:52:25 pm
 * -----
 * Copyright 2018 - 2018
 */

#ifndef __BUFFER_H__
#define __BUFFER_H__

#include <string>

class Buffer
{
  public:
    Buffer();
    ~Buffer();
    void append(const std::string &buf);
    void retrieve(int len);
    std::string retrieveAllAsString();
    std::string retrieveAsString(size_t len);
    int readableBytes();
    const char *peek();

  private:
    std::string buf_;
};

#endif // __BUFFER_H__