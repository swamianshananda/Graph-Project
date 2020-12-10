#include "TwitterGraph.h"
#include <iostream>
void TwitterGraph::addUser(unsigned long n){

    

    if(users.find(n) == users.end()){
        int x = users.size();
        indices[n] = x;
        inverse[x] = n;
        users[n] = new User(n);
    }   //check is user in the hash table
         //if not, create a new user and add it to the hash table

}
void TwitterGraph::removeUser(unsigned long n){
    if(users.find(n) != users.end()){   //check if the person is in the hash table
        for(auto it = (users[n]->adjList).begin(); it != (users[n]->adjList).end(); ++it){  //for every connection a person has
            delete it->second;  //delete the connection
        }
        delete users[n];    //delete the user
        users.erase(n); //erase the key from the hash table.
        createIndexes();
    }
    
}

void TwitterGraph::addConnection(unsigned long s, unsigned long d){
    if(users.find(s) != users.end() && users.find(d) != users.end() && (users[s]->adjList).find(d) == (users[s]->adjList).end()){   //if the connection does not exist
        users[s]->adjList[d] = new Connection(s,d); //add the connection
    }   
}

void TwitterGraph::removeConnection(unsigned long s, unsigned long d){
    if(users.find(s) != users.end() && (users[s]->adjList).find(d) != (users[s]->adjList).end()){   //checks if the connection existed
        delete users[s]->adjList[d];    //delete the connection
        (users[s]->adjList).erase(d);   //erase connection from the hash table
    }
}

std::vector<unsigned long> TwitterGraph::connections(unsigned long n){
    std::vector<unsigned long> ans; //vector that contains a bunch of nodeIds
    if(users.find(n) != users.end()){   //checks if person is in the hash table
        for(auto it = (users[n]->adjList).begin(); it != (users[n]->adjList).end(); ++it){
            ans.push_back(it->first);   //adds ids of connections to vector.
        }
    }
    return ans; //return the vector
}

bool TwitterGraph::isFollowing(unsigned long n1, unsigned long n2){
    return users.find(n1) != users.end() && (users[n1]->adjList).find(n2) != (users[n1]->adjList).end();    //checks if connection exists
}

bool TwitterGraph::isUser(unsigned long n){
    return users.find(n) != users.end();
}

std::vector<std::vector<unsigned long>> TwitterGraph::BFS(){
    std::vector<std::vector<unsigned long>> traversals;
    for(auto it = users.begin(); it!=users.end(); it++){
        it->second->l = UNEXPLORED;
        for(auto itt = it->second->adjList.begin(); itt != it->second->adjList.end(); itt++){
            itt->second->l = UNEXPLORED;
        }
    }
    for(auto it = users.begin(); it!=users.end(); it++){
        if(it->second->l == UNEXPLORED){
            traversals.push_back(BFS(it->first));
        }
    }
    return traversals;
}

std::vector<unsigned long> TwitterGraph::BFS(unsigned long n){
    std::vector<unsigned long> nodes;
    std::queue<unsigned long> q;
    q.push(n);
    users[n]->l = VISITED;
    unsigned long temp;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        nodes.push_back(temp);
        for(unsigned long& c: connections(temp)){
            if(users[c]->l == UNEXPLORED){
                q.push(c);
                users[c]->l = VISITED;
                users[temp] -> adjList[c]->l = DISCOVERY;
            }
            else if(users[temp] -> adjList[c]->l == UNEXPLORED)
                users[temp] -> adjList[c]->l = CROSS;
        }
    }
    return nodes;
}

void TwitterGraph::createIndexes(){
    int v = 0;
    indices.erase(indices.begin(),indices.end());
    inverse.erase(inverse.begin(), inverse.end());
    for(auto it = users.begin(); it!=users.end(); it++){
        indices[it->first] = v;
        inverse[v] = it->first;
        v++;
    }
}

void TwitterGraph::calculateDistances(){
    unsigned v = users.size();
    unsigned x;
    unsigned y;
    distMatrix.resize(v);
    pathMatrix.resize(v);
    for(std::vector<int>& n : distMatrix){
        n.resize(v);
    }
    
    for(std::vector<int>& n : pathMatrix){
        n.resize(v);
    }
    
    for(auto it = users.begin(); it!= users.end(); ++it){
        for(auto it2 = users.begin(); it2 != users.end(); ++it2){
            x = indices[it->first];
            y = indices[it2->first];
            if(x == y){
                distMatrix[x][y] = 0;
                pathMatrix[x][y] = y;
            }
            else if(isFollowing(indices[x], indices[y])){
                distMatrix[x][y] = 1;
                pathMatrix[x][y] = y;
            }
            else{
                distMatrix[x][y] = INT_MAX;
                pathMatrix[x][y] = -1;
            }
        }
    }

    for(unsigned k = 0; k<v; k++){
        for(x = 0; x<v; x++){
            if(distMatrix[x][k] == INT_MAX)
                continue;
            for(y = 0; y<v; y++){
                if(distMatrix[k][y] == INT_MAX)
                    continue;
                if(distMatrix[x][y] > (distMatrix[x][k]+distMatrix[k][y])){
                    distMatrix[x][y] = distMatrix[x][k] + distMatrix[k][y];
                    pathMatrix[x][y] = pathMatrix[x][k];
                }
            }
        }
    }
}

int TwitterGraph::findDistance(unsigned long n1, unsigned long n2){
    //need index corresponding to userid
    int indexNodeOne;
    int indexNodeTwo;
    for (auto it = indices.begin(); it != indices.end(); ++it) {
      if (it->second == n1) {
        indexNodeOne = it->first;
      }
      if (it->second == n2) {
        indexNodeTwo = it->first;
      }
    }
    
    int d = distMatrix[indexNodeOne][indexNodeTwo];
    if(d == INT_MAX)
        return -1;
    return d;
}

void TwitterGraph::calculateCentrality(){
    unsigned v = users.size();
    for(unsigned x = 0; x<v; x++){
        for(unsigned y = 0; y<v; y++){
           if(pathMatrix[x][y]!= (int) y && pathMatrix[x][y] != -1){
               (users[inverse[pathMatrix[x][y]]]->betweenessCentralValue)++;
           } 
        }
    }
}

TwitterGraph::~TwitterGraph(){
    for(auto it = users.begin(); it!=users.end(); it++){
        User*& u = it->second;
        for(auto itt = u->adjList.begin(); itt!= u->adjList.end(); itt++){
            delete itt->second;
        }
        delete u;
    }
}
