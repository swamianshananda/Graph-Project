#include "../catch/catch.hpp"
#include "../TwitterGraph.h"

TEST_CASE("Graph works how it should"){
    TwitterGraph g;
    g.addUser(1);
    g.addUser(2);
    g.addUser(3);
    g.addUser(4);
    g.addUser(55);
    g.addConnection(1,2);
    g.addConnection(3,4);
    REQUIRE(g.isUser(3) == true && g.isUser(55) == true && g.isUser(33) == false);
    REQUIRE(g.isFollowing(1,2) == true && g.isFollowing(3,55) == false);
    g.removeUser(3);
    REQUIRE(g.isUser(3) == false && g.isFollowing(3,4) == false);
}