#include <string>
#include <glog/logging.h>

#include "../include/EchoServer.h"
#include "../include/Define.h"
#include "../include/TcpConnection.h"

using namespace std;

EchoServer::EchoServer(EventLoop *loop)
    : pServer_(loop)
{
    pServer_.setUser(this);
}

EchoServer::~EchoServer() {}

void EchoServer::start() { pServer_.start(); }

void EchoServer::onMessage(TcpConnection *pCon, Buffer *pBuf)
{
    // printf("pBuf = %s\n", pBuf->peek());

    if (pBuf->readableBytes() > 0 && pBuf->readableBytes() <= MESSAGE_LENGTH) {
        pCon->send(pBuf->retrieveAllAsString());
    }

    while (pBuf->readableBytes() > MESSAGE_LENGTH) {
        string message = pBuf->retrieveAsString(MESSAGE_LENGTH);
        pCon->send(message);
    }
}

void EchoServer::onConnection(TcpConnection *pCon)
{
    printf("new Connection\n");
}