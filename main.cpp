#include "TwitterGraph.h"
#include "Parser.h"
#include "BetweenessCentral.h"
int main(){
    TwitterGraph g;
    readData(g,"twitter_combined.txt");
    betweenessCentral(g);
    outputBFS(g,"BFS.txt");
    return 0;
}