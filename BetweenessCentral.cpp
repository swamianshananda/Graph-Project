#include "BetweenessCentral.h"
#include "floyd-warshall.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <stack>

using namespace std;

void betweenessCentral(TwitterGraph &g) {
  
  stack<int> S;
  queue<int> Q;
  
  vector<int> pred;
  vector<int> sigma;
  vector<int> delta;
  
  for (auto it = g.users.begin(); it != g.users.end(); ++it) {
    
    int dist[g.users.size()];
    
    
    
    /*
    //enqueue s into Q
    
    while(!Q.empty()) {
      int v = Q.front();
      Q.pop();
      
      S.push(v);
      
      User* currentNode = users[v];
      
      for (adjacentNode : currentNode->adjList) {
        if (d[adjacentNode.first] < 0) {
          Q.push(adjacentNode.first);
          d[adjacentNode.first] = d[currentNode->userID] + 1;
        }
        
        if (d[adjacentNode.first] == d[currentNode->userID] + 1) {
          sigma[adjacentNode.first] = sigma[adjacentNode.first] + sigma[currentNode->userID];
          P.append(currentNode->userID);
        }
      }
    }
    
    vector<int> delta;
    while(!S.empty()) {
      int w = S.top();
      S.pop();
      for 
    }
     */
    
  }
     
}  
  /*
  float betweenessCentralValues [users.size()] = { }; // initialize array of all betweeness values to 0
  for(auto sourceNode : g.users) {
    int* sourceDistances = distanceArray[sourceNode]; //grab all relative distances from source node
    int largestIndex = findLargestNumber(sourceDistances);
    
    //call this to recursively move from largestNode back to sourceNode
    //sourceNode = index of source node
    //largestIndex = index of largest Node that is connected to source
    //index's are relative to location in source distance array which has all nodes where if same node = 0, no connection = infinity
    
    recursiveBetweenVal(sourceNode, largestIndex, sourceDistances, betweenessCentralValues)
  }
  
  //now set every nodes to have teh corresponding betweeness central val in the array
  int count = 0;
  for (auto node : users) {
    node->second.betweenessCentralValue = betweenessCentralValues[count];
    count++;
  }
  /*
}

/*
int findLargestNumber(int* source) {
  int returnIndex = 0;
  for (int i = 1; i < source.size()-1; i++) {
    //if equal distance stick with current one
    if (source[returnIndex] < source[i]) {
      returnIndex = i;
    }
  }
  return returnIndex;
}

void recursiveBetweenVal(int source, int current, int distance[], float &betweenessCentralValues[]) {
  if (current == source) {
    betweenessCentralValues[source] += betweennessCentralValues[current] + 1;
  }
  else {
    for (auto adjacentNode : current->adjList) {
      float newBetweenVal = distance[adjacentNode]/distance[current];
      newBetweenVal = newBetweenVal + (1*betweenessCentralValues[current]);
      betweenessCentralValues[adjacentNode] += newBetweenVal;
      recursiveBetweenVal(source, adjacentNode, distance); 
    }
  }
}
*/