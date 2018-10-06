#include <sys/epoll.h>
#include <cstdio>

#include "../include/Channel.h"
#include "../include/IChannelCallBack.h"
#include "../include/EventLoop.h"

Channel::Channel(EventLoop *loop, int sockfd)
    : sockfd_(sockfd)
    , loop_(loop)
{}

Channel::~Channel() {}

void Channel::handleEvent()
{
    // printf("this is Channel::handleEvent()\n");
    if (revents_ & EPOLLIN) callBack_->handleRead();
    if (revents_ & EPOLLOUT) callBack_->handleWrite();
}

void Channel::enableWriting()
{
    events_ |= EPOLLOUT;
    modify();
}

void Channel::disableWriting()
{
    events_ &= ~EPOLLOUT;
    modify();
}

void Channel::enableReading()
{
    events_ |= EPOLLIN;
    regist();
}

void Channel::setCallBack(IChannelCallBack *callBack) { callBack_ = callBack; }

void Channel::modify() { loop_->modify((*this)); }

void Channel::regist() { loop_->regist((*this)); }

int Channel::getEvents() { return events_; }

int Channel::getSockfd() { return sockfd_; }

void Channel::setRevents(int revents) { revents_ = revents; }

bool Channel::isWriting() { return revents_ & EPOLLOUT; }

void Channel::setIndex(int index) { index_ = index; }

int Channel::getIndex() { return index_; }