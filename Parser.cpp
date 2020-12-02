#include "TwitterGraph.h"

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

int main(){
    ifstream file("twitter_combined.txt");
    string line;
    string firstId;
    string seconId;

    if (file.is_open()){
        while ( getLine(file,line) ){

            int space = line.find(" ");
            firstId = line.substr(0, space);
            seconId = line.substr(space+1, line.length());
            
            //Now turning strings into unsigned long and creating User objects
            unsigned long idOne = stoul(firstId, nullptr, 0);
            unsigned long idTwo = stoul(seconId, nullptr, 0);
            addUser(idOne);
            addUser(idTwo);
            addConnection(idOne, idTwo);
        }
    }
}