#include "Parser.h"


using std::string;
using std::ifstream;
using std::stoul;
using std::getline;
using std::vector;
using std::ofstream;
using std::stringstream;
void readData(TwitterGraph& g, string filename){
    ifstream file(filename);
    string line;
    stringstream ss;
    if (file.is_open()){
        while (getline(file,line) ){
            unsigned long idOne;
            unsigned long idTwo;
            ss<<line;
            ss>>idOne>>idTwo;
            //Now turning strings into unsigned long and creating User objects
            g.addUser(idOne);
            g.addUser(idTwo);
            g.addConnection(idOne, idTwo);
        }
    }
}

void outputBFS(TwitterGraph& g, string filename){
    vector<vector<unsigned long>> nodes = g.BFS();
    ofstream myfile;
    myfile.open(filename);
    int i = 1;
    myfile<<"The following is an output of a BFS traversal of twitter users and is seperated in components:\n\n";
    for(vector<unsigned long>& component: nodes){
        myfile<<"Component "<<i<<" has users: ";
        for(unsigned long& user: component){
            myfile<<user<<" ";
        }
        myfile<<"\n\n";
        i++;
    }
    myfile.close();
}

void outputDistances(TwitterGraph& g, string filename){
    g.calculateDistances();
    int d;
    ofstream myfile;
    myfile.open(filename);
    myfile<<"The following is a list of distances between two nodes in the graph with positive distance:\n\n";
    for(auto it = g.users.begin(); it != g.users.end(); it++){
        for(auto it2 = g.users.begin(); it2 != g.users.end(); it2++){
            d = g.findDistance(it->first,it2->first);
            if(d>0)
                myfile<<it->first<<" -> "<<it2->first<<" : "<<d<<"\n";
        }
    }
    myfile.close();
}

void outputC(TwitterGraph& g, std::string filename){
    g.calculateCentrality();
    ofstream myfile;
    myfile.open(filename);
    myfile<<"The following is a list of how central each of the nodes are in the graph:\n\n";
    for(auto it = g.users.begin(); it != g.users.end(); it++){
        
        myfile<<it->first<<" : "<<it->second->betweenessCentralValue<<"\n";
    }
    myfile.close();
}