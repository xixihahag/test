#include <string>
#include "catch.h"
#include "../include/Buffer.h"

using namespace std;

TEST_CASE("test Buffer")
{
    Buffer *b = new Buffer();
    b->append("abcdef");

    SECTION("readableBytes")
    {
        REQUIRE(b->readableBytes() == 6);
    }
    SECTION("peek")
    {
        const char tc[] = "abcdef";
        REQUIRE(strcmp(b->peek(), tc) == 0);
    }
    SECTION("retrieve")
    {
        b->retrieve(1);
        REQUIRE(b->readableBytes() == 5);
    }
    SECTION("retrieveAllAsString")
    {
        string t = "abcdef";
        REQUIRE(b->retrieveAllAsString() == t);
    }
    SECTION("retrieveAsString")
    {
        string t = "a";
        REQUIRE(b->retrieveAsString(1) == t);
    }

    delete b;
}