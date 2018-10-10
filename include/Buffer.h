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
  private:
    std::string buf_; //缓冲区

  public:
    Buffer();
    ~Buffer();

    void append(const std::string &buf);      // 追加
    void retrieve(int len);                   // 扔掉缓冲中前len个字节
    std::string retrieveAllAsString();        // 取出全部缓冲区数据
    std::string retrieveAsString(size_t len); // 取缓冲区中前len个字节
    int readableBytes();                      // 缓冲区中有多少字节
    const char *peek();                       // 缓冲区转换成char
};

#endif // __BUFFER_H__