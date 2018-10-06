/*
 * File: EventLoop.cc
 * brief:
 *
 * Author: gyz
 * Email: mni_gyz@163.com
 * Last Modified: Saturday, 29th September 2018 8:28:18 pm
 * -----
 * Copyright 2018 - 2018
 */

#include <cstdio>
#include <vector>

#include "../include/EventLoop.h"
#include "../include/Channel.h"
#include "../include/Epoll.h"
#include "../include/Define.h"

EventLoop::EventLoop()
    : quit_(false)
    , poller_(new Epoll)
{
    // printf("new EventLoop\n");
}

EventLoop::~EventLoop() {}

void EventLoop::loop()
{
    while (!quit_) {
        // printf("this is EventLoop::loop() while\n");
        // std::vector<Channel *> channels;
        Channel *array[MAXevents_];
        int size = poller_->poll(array, MAXevents_);

        // std::vector<Channel *>::iterator it; // 数组的开销更小
        // for (it = channels.begin(); it != channels.end(); it++) {
        //     (*it)->handleEvent();
        // }
        for (int i = 0; i < size; i++) {
            array[i]->handleEvent();
        }
    }
}

void EventLoop::modify(Channel &channel) { poller_->modify(channel); }

void EventLoop::regist(Channel &channel) { poller_->regist(channel); }