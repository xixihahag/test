/*
 * File: TcpConnection.cc
 * brief:
 * 只用于接收数据和发送数据的类
 * 数据处理不在这
 * Author: gyz
 * Email: mni_gyz@163.com
 * Last Modified: Monday, 1st October 2018 12:14:48 pm
 * -----
 * Copyright 2018 - 2018
 */

#include <unistd.h>
#include <cstdio>
#include <string.h>
#include <errno.h>
#include <glog/logging.h>

#include "../include/TcpConnection.h"
#include "../include/Define.h"
#include "../include/Channel.h"
#include "../include/EventLoop.h"
#include "../include/IMuduoUser.h"

using namespace std;

TcpConnection::TcpConnection(int sockfd, EventLoop *loop)
    : sockfd_(sockfd)
    , loop_(loop)
{
    this->createChannel();
}

TcpConnection::~TcpConnection() {}

void TcpConnection::createChannel()
{
    pChannel_ = new Channel(loop_, sockfd_);
    pChannel_->setCallBack(this);
    pChannel_->enableReading();
}

void TcpConnection::handleRead()
{
    // printf("this is TcpConnection::handleRead()\n");
    int sockfd = pChannel_->getSockfd();
    int len;
    char line[MAX_LINE];
    memset(line, 0, sizeof(line));
    if ((len = read(sockfd, line, MAX_LINE)) < 0) {
        LOG(ERROR) << "read error\n";
        return;
    } else if (len == 0) {
        LOG(INFO) << "connect close\n";
        close(sockfd);
    } else {
        string linestr(line, len);
        inBuf_.append(linestr);
        pUser_->onMessage(this, &inBuf_);
    }
}

void TcpConnection::handleWrite()
{
    int sockfd = pChannel_->getSockfd();
    if (pChannel_->isWriting()) {
        int n = ::write(sockfd, outBuf_.peek(), outBuf_.readableBytes());
        if (n > 0) {
            LOG(INFO) << "write " << n << " bytes data again\n";
            outBuf_.retrieve(n);
            if (outBuf_.readableBytes() == 0) { pChannel_->disableWriting(); }
        }
    }
}

void TcpConnection::send(const string &message)
{
    int n = 0;
    if (outBuf_.readableBytes() == 0) {
        n = write(sockfd_, message.c_str(), message.size());
    }

    if (n < static_cast<int>(message.size())) {
        outBuf_.append(message.substr(n, message.size()));
        if (pChannel_->isWriting()) { pChannel_->enableWriting(); }
    }
}

void TcpConnection::setUser(IMuduoUser *user) { pUser_ = user; }
