#include <sys/epoll.h>
#include <unistd.h>
#include <glog/logging.h>

#include "../include/Epoll.h"
#include "../include/Channel.h"
#include "../include/Define.h"

using namespace std;

Epoll::Epoll()
    : epfd_(-1)
{
    this->initialize();
}

void Epoll::initialize()
{
    if ((epfd_ = epoll_create(1)) < 0)
        LOG(ERROR) << "epoll_create failed\n";
    else
        LOG(INFO) << "epoll create\n";
}

Epoll::~Epoll()
{
    if (epfd_ != -1) ::close(epfd_);
}

int Epoll::poll(Channel *channels[], int length)
{
    struct epoll_event events[MAXevents_]; // 在栈上分配内存
    int ret = epoll_wait(epfd_, events, MAXevents_, -1);

    // 遍历获得的事件集合
    for (int i = 0; i < ret; i++) {
        Channel *pChannel = reinterpret_cast<Channel *>(events[i].data.ptr);
        pChannel->setRevents(events[i].events);
        channels[i] = pChannel;
    }

    return ret;
}

int Epoll::regist(Channel &channel)
{
    struct epoll_event ev;
    ev.data.ptr = &channel;
    ev.events = channel.getEvents();
    int fd = channel.getSockfd();

    epoll_ctl(epfd_, EPOLL_CTL_ADD, fd, &ev);
}

int Epoll::modify(Channel &channel)
{
    struct epoll_event ev;
    ev.data.ptr = &channel;
    ev.events = channel.getEvents();
    int fd = channel.getSockfd();

    epoll_ctl(epfd_, EPOLL_CTL_MOD, fd, &ev);
}
