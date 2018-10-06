/*
 * File: IChannelCallBack.h
 * brief:
 * Channel的回调函数
 * Author: gyz
 * Email: mni_gyz@163.com
 * Last Modified: Monday, 1st October 2018 4:59:46 pm
 * -----
 * Copyright 2018 - 2018
 */

#ifndef __ICHANNELCALLBACK_H__
#define __ICHANNELCALLBACK_H__

class IChannelCallBack
{
  public:
    void virtual handleRead() = 0;
    void virtual handleWrite() = 0;
};

#endif // __ICHANNELCALLBACK_H__
