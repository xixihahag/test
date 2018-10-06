/*
 * File: IAcceptorCallBack.h
 * brief:
 * Accrptor的回调函数 纯虚函数 接口类
 * Author: gyz
 * Email: mni_gyz@163.com
 * Last Modified: Monday, 1st October 2018 4:59:27 pm
 * -----
 * Copyright 2018 - 2018
 */

#ifndef __IACCEPTORCALLBACK_H__
#define __IACCEPTORCALLBACK_H__

class IAcceptorCallBack
{
  public:
    void virtual newConnection(int sockfd) = 0;
};

#endif // __IACCEPTORCALLBACK_H__
