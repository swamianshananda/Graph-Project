#include "floyd-warshall.h"
#include <iostream>

#define INF 9001 //Not actually infinity, but just some really high number

using namespace std; 

//Returns array dist, a two-dimentional array containing the path lengths from one user (first arguement) to another (second user). Indexes of dist
//are the same as the index of the respective user in the users map
int** floyds(TwitterGraph& g){
    unsigned long v = g.users.size();

    unsigned long i;
    unsigned long j;
    unsigned long k;

    
    //Intializing 2d array
    int** dist = new int*[v];
    for (i = 0; i<v; i++){ dist[i] = new int[v]; }

    //First set of for loops to populate the dist array
    auto iti = g.users.begin();
    auto itj = g.users.begin();
    i=0;
    while(i<v){
        j=0;
        itj = g.users.begin();
        while(j<v){
            if (i == j){ dist[i][j] = 0; } //Weight for path of a user to itself is 0
            else{
                if (g.isFollowing( (iti)->second->userId, (itj)->second->userId )){ //Check if user at index i is following user at index k
                    dist[i][j] = 1; //If so, set the edge weight to 1 (since nothing in this set is weighting, all existing edges will have equal weight 1)
                }
                else {
                    dist[i][j] = INF; //If there is no edge between the two users, the edge has infinite weight I.E. there is no edge
                }
            }
            itj++;
            j++;
        }
        i++;
        iti++;
        
    }

    //Second set of loops 
    for (k=0; k<v; k++){
        for (i=0; i<v; i++){
            for (j=0; j<v; j++){
                if (dist[i][j] > (dist[i][k] + dist[k][j])){ //Check if there is a shorter path
                    dist[i][j] = dist[i][k] + dist[k][j]; //If so, update dist[i][j] with the shorter value
                }
            }
        }
    }

    return dist;
}