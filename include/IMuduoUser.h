/*
 * File: IMuduoUser.h
 * brief:
 * User的基类
 * Author: gyz
 * Email: mni_gyz@163.com
 * Last Modified: Monday, 1st October 2018 5:00:01 pm
 * -----
 * Copyright 2018 - 2018
 */

#ifndef __IMUDUO_H__
#define __IMUDUO_H__

#include <string>
#include "Declear.h"

class IMuduoUser
{
  public:
    void virtual onConnection(TcpConnection *pCon) = 0;
    void virtual onMessage(TcpConnection *pCon, Buffer *pBuf) = 0;
};

#endif // __IMUDUO_H__