#include "Parser.h"


using std::string;
using std::ifstream;
using std::stoul;
using std::getline;
using std::vector;
using std::ofstream;

void readData(TwitterGraph& g, string filename){
    ifstream file(filename);
    string line;
    string firstId;
    string secondId;
    if (file.is_open()){
        while (getline(file,line) ){
            int space = line.find(" ");
            firstId = line.substr(0, space);
            secondId = line.substr(space+1, line.length());
            
            //Now turning strings into unsigned long and creating User objects
            unsigned long idOne = stoul(firstId);
            unsigned long idTwo = stoul(secondId);
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
}