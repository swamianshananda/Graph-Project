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

//floyd warshall algorithm
void TwitterGraph::calculateDistances(){
    unsigned v = users.size();
    unsigned x;
    unsigned y;
    distMatrix.resize(v);
    //pathMatrix.resize(v);
    for(std::vector<int>& n : distMatrix){
        n.resize(v);
    }
    /*
    for(std::vector<int>& n : pathMatrix){
        n.resize(v);
    }
    */
    for(auto it = users.begin(); it!= users.end(); ++it){
        for(auto it2 = users.begin(); it2 != users.end(); ++it2){
            x = indices[it->first];
            y = indices[it2->first];
            if(x == y){
                distMatrix[x][y] = 0;
                //pathMatrix[x][y] = y;
            }
            else if(isFollowing(it->first, it2->first)){
                distMatrix[x][y] = 1;
                //pathMatrix[x][y] = y;
            }
            else{
                distMatrix[x][y] = INT_MAX;
                //pathMatrix[x][y] = -1;
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
                    //pathMatrix[x][y] = pathMatrix[x][k];
                }
            }
        }
    }
}

int TwitterGraph::findDistance(unsigned long n1, unsigned long n2){   
    int d = distMatrix[indices[n1]][indices[n2]];
    if(d == INT_MAX)
        return -1;
    return d;
}

//betweeness centriality algorithm
void TwitterGraph::calculateCentrality(){
    /*
    unsigned v = users.size();
    if(v != pathMatrix.size()){
        calculateDistances();
    }
    for(auto it = users.begin(); it!= users.end(); ++it){
        it->second->betweenessCentralValue = 0;
    }
    unsigned i;
    int temp;
    for(unsigned x = 0; x<v; x++){
        for(unsigned y = 0; y<v; y++){
           if(pathMatrix[x][y] != -1 && x!=y) { //make sure not same node and that nodes have connection 
               i = x;
               temp = pathMatrix[i][y];
               for(int g = 0; g< distMatrix[x][y]-1; g++){
                   (users[inverse[temp]]->betweenessCentralValue)++;
                   i = temp;
                   temp = pathMatrix[i][y];
               }
               (users[inverse[temp]]->betweenessCentralValue)++;
           } 
        }
    }
    */
    
    unsigned len = users.size();
    int v;
    int w;
    for(auto it = users.begin(); it!= users.end(); ++it){
        it->second->betweenessCentralValue = 0;
    }
    for(int s = 0; s< (int) len; s++){
        std::stack<int> S;
        std::vector<std::vector<int>> P;
        P.resize(len);
        std::vector<double> sigma;
        sigma.resize(len,0.0);
        sigma[s] = 1.;
        std::vector<int> d;
        d.resize(len,-1);
        d[s] = 0;
        std::queue<int> Q;
        Q.push(s);
        while(!Q.empty()){
            v = Q.front();
            Q.pop();
            S.push(v);
            for(unsigned long wUser : connections(inverse[v])){
                w = indices[wUser];
                if(d[w]<0){
                    Q.push(w);
                    d[w] = d[v]+1;
                }
                if(d[w] == d[v]+1){
                    sigma[w] = sigma[w]+sigma[v];
                    P[w].push_back(v);
                }
            }
        }
        std::vector<double> delta;
        delta.resize(len,0.);
        while(!S.empty()){
            w = S.top();
            S.pop();
            for(int v: P[w]){
                delta[v] = delta[v] + (sigma[v]/sigma[w])*(1+delta[w]);       
            }
            if(w!=s)
                (users[inverse[w]]->betweenessCentralValue)+=delta[w];
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
