#include "TwitterGraph.h"
#include "Parser.h"
int main(){
    TwitterGraph g;
    
    readData(g,"Wiki-Vote.txt");
    
    std::cout<<"Data Read and Parsed"<<std::endl;
    outputBFS(g,"BFS.txt");
    std::cout<<"BFS complete (see BFS.txt)"<<std::endl;
    outputDistances(g, "distances.txt");
    std::cout<<"Distances found using Floyd-Warshall (see distances.txt)"<<std::endl;
    outputC(g, "centrality.txt");
    std::cout<<"Betweeness Centriality Values found (see centrality.txt)"<<std::endl;
    
    return 0;
}