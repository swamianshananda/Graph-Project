#include "TwitterGraph.h"
#include "Parser.h"
//#include "BetweenessCentral.h"
int main(){
    TwitterGraph g;
    
    readData(g,"Wiki-Vote.txt");
    std::cout<<"data read"<<std::endl;
    outputBFS(g,"BFS.txt");
    std::cout<<"did BFS"<<std::endl;
    outputDistances(g, "distances.txt");
    std::cout<<"found distances"<<std::endl;
    outputC(g, "centrality.txt");
    std::cout<<"found central nodes"<<std::endl;
    
    return 0;
}