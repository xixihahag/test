#include <cstdlib>
#include <cstdio>

#include "../include/TcpServer.h"
#include "../include/TcpConnection.h"
#include "../include/Acceptor.h"

TcpServer::TcpServer(EventLoop *loop)
    : ploop_(loop)
    , Acceptor_(NULL)
{
    // printf("new TcpServer\n");
}

TcpServer::~TcpServer() {}

void TcpServer::start()
{
    // printf("this is TcpServer::start()\n");
    Acceptor_ = new Acceptor(ploop_);
    Acceptor_->setCallBack(this);
    Acceptor_->start();
}

void TcpServer::newConnection(int sockfd)
{
    // printf("this is TcpServer::newConnection()\n");
    TcpConnection *tcp = new TcpConnection(sockfd, ploop_);
    tcp->setUser(pUser_);
}

void TcpServer::setUser(IMuduoUser *user) { pUser_ = user; }