#include "TwitterGraph.h"
#include "Parser.h"

int main(){
    TwitterGraph g;
    readData(g,"twitter_combined.txt");
    outputBFS(g,"BFS.txt");
    return 0;
}