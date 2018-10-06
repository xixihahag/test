#include <arpa/inet.h>
#include <sys/socket.h>
#include <cstdio>
#include <unistd.h>
#include <cstring>
#include <fcntl.h>

#include "../include/Acceptor.h"
#include "../include/Channel.h"
#include "../include/IAcceptorCallBack.h"
#include "../include/Define.h"
#include "../include/EventLoop.h"

using namespace std;

Acceptor::Acceptor(EventLoop *loop)
    : loop_(loop)
{
    // printf("new Acceptor\n");
}

Acceptor::~Acceptor() {}

void Acceptor::setCallBack(IAcceptorCallBack *pCallBack)
{
    pCallBack_ = pCallBack;
}

struct sockaddr_in initSockAddr4()
{
    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    return servaddr;
};

int Acceptor::createAndListen()
{
    printf("this is createAndListen\n");
    listenfd_ = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in servaddr = initSockAddr4();

    bind(listenfd_, (SA *) &servaddr, sizeof(servaddr));

    fcntl(listenfd_, F_SETFL, O_NONBLOCK);

    listen(listenfd_, MAX_LISTENQ);
    printf("createAndListen end\n");

    return listenfd_;
}

void Acceptor::start()
{
    printf("this is Acceptor::start()\n");
    listenfd_ = createAndListen();
    acceptChannel_ = new Channel(loop_, listenfd_);
    acceptChannel_->setCallBack(this);
    acceptChannel_->enableReading();
    printf("start end\n");
}

void Acceptor::handleRead()
{
    int connfd;
    connfd = accept(listenfd_, NULL, NULL);
    fcntl(connfd, F_SETFL, O_NONBLOCK);

    pCallBack_->newConnection(connfd);
}

void Acceptor::handleWrite() {}