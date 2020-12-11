#define CATCH_CONFIG_MAIN
#include "../catch/catch.hpp"
#include "../TwitterGraph.h"
#include "../Parser.h"

TEST_CASE("Graph works how it should"){
    TwitterGraph g;
    g.addUser(1);
    g.addUser(2);
    g.addUser(3);
    g.addUser(4);
    g.addUser(55);
    g.addConnection(1,2);
    g.addConnection(3,4);
    REQUIRE(g.isUser(3) == true);
    REQUIRE(g.isUser(55) == true);
    REQUIRE(g.isUser(33) == false);
    REQUIRE(g.isFollowing(1,2) == true);
    REQUIRE(g.isFollowing(3,55) == false);
    g.removeUser(3);
    REQUIRE(g.isUser(3) == false);
    REQUIRE(g.isFollowing(3,4) == false);
}

TEST_CASE("Checking of indices work"){
    TwitterGraph g;
    g.addUser(7);
    g.addUser(14);
    g.addUser(21);
    g.addUser(28);
    g.addUser(35);
    bool case1 = true;
    for(int i = 1; i<6; i++){
        for(int j = i+1; j<6; j++){
            if(g.indices[7*i] == g.indices[7*j])
                case1 = false;
            if(g.indices[7*i]<0 || g.indices[7*i]>4)
                case1 = false;
        }
    }
    REQUIRE(case1 == true);
    g.removeUser(7);
    bool case2 = true;
    for(int i = 2; i<6; i++){
        for(int j = i+1; j<6; j++){
            if(g.indices[7*i] == g.indices[7*j])
                case2 = false;
            if(g.indices[7*i]<0 || g.indices[7*i]>3)
                case2 = false;
        }
    }
    REQUIRE(case2 == true);

}

TEST_CASE("Checking of inverse indices work"){
    TwitterGraph g;
    for(unsigned i = 1; i<11; i++){
        g.addUser(i*13);
    }
    for(unsigned i = 1; i<11; i++){
        REQUIRE(i*13 == g.inverse[g.indices[i*13]]);
    }

}

TEST_CASE("Check if BFS works"){
    TwitterGraph g;
    for(int i = 1; i<6; i++){
        g.addUser(i);
    }
    g.addConnection(1,2);
    g.addConnection(1,3);
    g.addConnection(3,4);
    g.addConnection(2,4);
    g.addConnection(3,5);
    std::vector<unsigned long> b = g.BFS(1);
    REQUIRE(b.size()==5);
    TwitterGraph g2;
    for(int i = 1; i<6; i++){
        g2.addUser(i);
    }
    std::vector<std::vector<unsigned long>> b2 = g2.BFS();
    REQUIRE(b2.size()==5);
    for(int i = 0; i<5; i++){
        REQUIRE(b2[i].size() == 1);
    }
    TwitterGraph g3;
    for(int i = 1; i<5; i++){
        g3.addUser(i);
    }
    g3.addConnection(1,3);
    g3.addConnection(2,4);
    std::vector<unsigned long> b3 = g3.BFS(1);
    std::vector<unsigned long> b4 = g3.BFS(2);
    REQUIRE(b3.size() ==2);
    REQUIRE(b4.size()==2);
    REQUIRE(b3[0] == 1);
    REQUIRE(b3[1] == 3);
    REQUIRE(b4[0] == 2);
    REQUIRE(b4[1] == 4);
}

TEST_CASE("Check if the Floyd-Warshall Algorithm Works"){
    TwitterGraph g;
    for(int i = 1; i<6; i++){
        g.addUser(i);
    }
    g.addConnection(1,2);
    g.addConnection(1,3);
    g.addConnection(3,4);
    g.addConnection(2,4);
    g.addConnection(3,5);
    g.calculateDistances();
    REQUIRE(g.findDistance(1,2) == 1);
    REQUIRE(g.findDistance(1,3) == 1);
    REQUIRE(g.findDistance(1,4) == 2);
    REQUIRE(g.findDistance(1,5) == 2);
    REQUIRE(g.findDistance(5,1) == -1);
    REQUIRE(g.findDistance(3,4) == 1);
    REQUIRE(g.findDistance(4,2) == -1);
    REQUIRE(g.findDistance(4,4) == 0);
    g.addConnection(5,4);
    g.addConnection(5,1);
    g.calculateDistances();
    REQUIRE(g.findDistance(1,2) == 1);
    REQUIRE(g.findDistance(1,3) == 1);
    REQUIRE(g.findDistance(1,4) == 2);
    REQUIRE(g.findDistance(1,5) == 2);
    REQUIRE(g.findDistance(3,1) == 2);
    REQUIRE(g.findDistance(3,4) == 1);
    REQUIRE(g.findDistance(4,2) == -1);
    REQUIRE(g.findDistance(5,4) == 1);
    REQUIRE(g.findDistance(5,2) == 2);
}
/*
TEST_CASE("Check if the Betweeness Centriality Algorithm Works") {
  TwitterGraph g;
  for(int i = 1; i<6; i++){
    g.addUser(i);
  }
  g.addConnection(1,2);
  g.addConnection(2,3);
  g.addConnection(2,4);
  g.addConnection(4,5);
  g.calculateDistances();
  g.calculateCentrality();
  REQUIRE(g.users[1]->betweenessCentralValue == 0);
  REQUIRE(g.users[2]->betweenessCentralValue == 3);
  REQUIRE(g.users[3]->betweenessCentralValue == 0);
  REQUIRE(g.users[4]->betweenessCentralValue == 1);
  REQUIRE(g.users[5]->betweenessCentralValue == 0);
  TwitterGraph g2;
  for(int i = 1; i<6; i++){
    g2.addUser(i);
  }
  g2.addConnection(1,2);
  g2.addConnection(2,3);
  g2.addConnection(2,4);
  g2.addConnection(4,5);
  g2.addConnection(2,5);
  g2.calculateDistances();
  g2.calculateCentrality();
  REQUIRE(g2.users[1]->betweenessCentralValue == 0);
  REQUIRE(g2.users[2]->betweenessCentralValue == 3);
  REQUIRE(g2.users[3]->betweenessCentralValue == 0);
  REQUIRE(g2.users[4]->betweenessCentralValue == 0);
  REQUIRE(g2.users[5]->betweenessCentralValue == 0);
}
*/
/*
TEST_CASE("Check if the Betweeness Centriality Algorithm Works with directed nodes acting as undirected graph") {
  TwitterGraph g;
  for(int i = 1; i<6; i++){
    g.addUser(i);
  }
  g.addConnection(1,2);
  g.addConnection(2,1);
  g.addConnection(2,3);
  g.addConnection(3,2);
  g.addConnection(2,4);
  g.addConnection(4,2);
  g.addConnection(4,5);
  g.addConnection(5,4);
  g.calculateDistances();
  g.calculateCentrality();
  REQUIRE(g.users[1]->betweenessCentralValue == 4);
  REQUIRE(g.users[2]->betweenessCentralValue == 14);
  REQUIRE(g.users[3]->betweenessCentralValue == 4);
  REQUIRE(g.users[4]->betweenessCentralValue == 10);
  REQUIRE(g.users[5]->betweenessCentralValue == 4);
  g.addConnection(2,5);
  g.addConnection(5,2);
  g.calculateDistances();
  g.calculateCentrality();
  REQUIRE(g.users[1]->betweenessCentralValue == 4);
  REQUIRE(g.users[2]->betweenessCentralValue == 14);
  REQUIRE(g.users[3]->betweenessCentralValue == 4);
  REQUIRE(g.users[4]->betweenessCentralValue == 4);
  REQUIRE(g.users[5]->betweenessCentralValue == 4);
}
*/

TEST_CASE("Check") {
  TwitterGraph g;
  for(int i = 0; i<8; i++){
    g.addUser(i);
  }
  g.addConnection(0,2);
  g.addConnection(2,0);
  g.addConnection(0,1);
  g.addConnection(1,0);
  g.addConnection(2,1);
  g.addConnection(1,2);
  g.addConnection(2,3);
  g.addConnection(3,2);
  g.addConnection(3,5);
  g.addConnection(5,3);
  g.addConnection(1,5);
  g.addConnection(5,1);
  g.addConnection(3,4);
  g.addConnection(4,3);
  g.addConnection(2,4);
  g.addConnection(4,2);
  g.addConnection(4,5);
  g.addConnection(5,4);
  g.addConnection(4,7);
  g.addConnection(5,7);
  g.addConnection(7,5);
  g.addConnection(6,4);
  g.addConnection(4,6);
  g.addConnection(7,4);
  g.addConnection(5,6);
  g.addConnection(6,5);
  g.addConnection(6,7);
  g.addConnection(7,6);
  g.calculateCentrality();
  REQUIRE(g.users[0]->betweenessCentralValue == 0);
  REQUIRE(g.users[1]->betweenessCentralValue == 14.0/3.0);
  REQUIRE(g.users[2]->betweenessCentralValue == 8.0);
  REQUIRE(g.users[3]->betweenessCentralValue == 2.0/3.0);
  REQUIRE(g.users[4]->betweenessCentralValue == 26.0/3.0);
  REQUIRE(g.users[5]->betweenessCentralValue == 10.0);  
  REQUIRE(g.users[6]->betweenessCentralValue == 0.0);
  REQUIRE(g.users[7]->betweenessCentralValue == 0.0);
  
}