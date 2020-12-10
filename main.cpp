#include "TwitterGraph.h"
#include "Parser.h"
//#include "BetweenessCentral.h"
int main(){
    TwitterGraph g;
    
    //readData(g,"Wiki-Vote.txt");
    g.addUser(1);
    g.addUser(2);
    g.addUser(3);
    g.addUser(4);
    g.addUser(5);
    
    g.addConnection(1,2);
    g.addConnection(2,1);
    g.addConnection(2,3);
    g.addConnection(3,2);
    g.addConnection(2,4);
    g.addConnection(4,2);
    g.addConnection(4,5);
    g.addConnection(5,4);
    
    
    std::cout<<"data read"<<std::endl;
    outputBFS(g,"BFS.txt");
    std::cout<<"did BFS"<<std::endl;
    outputDistances(g, "distances.txt");
    std::cout<<"found distances"<<std::endl;
    outputC(g, "centrality.txt");
    std::cout<<"found central nodes"<<std::endl;
    
    for (size_t i = 0; i < g.pathMatrix.size(); i++) {
      for (size_t j = 0; j < g.pathMatrix.size(); j++) {
        std::cout<< g.inverse[g.pathMatrix[i][j]] << " -> ";
      }
      std::cout << "\n";
    }
    return 0;
}