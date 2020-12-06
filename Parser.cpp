#include "TwitterGraph.h"
#include "Parser.h"
#include <iterator>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

using string;
using map;
using vector;
using ifstream;
using istream;
using istream_iterator;
using stringstream;

void Parser::readData(TwitterGraph& g, string filename){
    ifstream file(filename);
    string line;
    string firstId;
    string secondId;
    if (file.is_open()){
        while ( getLine(file,line) ){
            int space = line.find(" ");
            firstId = line.substr(0, space);
            secondId = line.substr(space+1, line.length());
            
            //Now turning strings into unsigned long and creating User objects
            unsigned long idOne = stoul(firstId, nullptr, 0);
            unsigned long idTwo = stoul(secondId, nullptr, 0);
            g.addUser(idOne);
            g.addUser(idTwo);
            g.addConnection(idOne, idTwo);
        }
    }
    
    g.betweenessCentral();
}