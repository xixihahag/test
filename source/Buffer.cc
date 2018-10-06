#include "../include/Buffer.h"
using namespace std;

Buffer::Buffer() {}
Buffer::~Buffer() {}

int Buffer::readableBytes() { return static_cast<int>(buf_.size()); }
const char *Buffer::peek() { return buf_.c_str(); }
void Buffer::append(const string &buf) { buf_.append(buf); }
void Buffer::retrieve(int len) { buf_ = buf_.substr(len, buf_.size() - len); }
string Buffer::retrieveAllAsString()
{
    return retrieveAsString(readableBytes());
}
string Buffer::retrieveAsString(size_t len)
{
    string res(peek(), len);
    retrieve(len);
    return res;
}