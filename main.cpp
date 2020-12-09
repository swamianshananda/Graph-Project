#include "TwitterGraph.h"
#include "Parser.h"
#include "floyd-warshall.h"
#include "BetweenessCentral.h"
#include "iostream"
int main(){
    TwitterGraph g;
    readData(g,"twitter_combined.txt"); //reads data
    //betweenessCentral(g, floyds(g)); //calls Between centriality which needs input of Floyd-Warshall
    //outputBFS(g,"BFS.txt"); 
    std::cout << floyds(g);
    
    /*
    int edges = 0;
    for (auto pair : g.users) {
      //std::cout << pair.second->adjList.size();
      edges += pair.second->adjList.size();
      //std::cout << "\n";
    }
    std::cout << edges;*/
    return 0;
}