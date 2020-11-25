#include "TwitterGraph.h"

void TwitterGraph::addUser(unsigned long n){
    if(users.find(n) == users.end())    //check is user in the hash table
        users[n] = new User(n); //if not, create a new user and add it to the hash table
}

void TwitterGraph::removeUser(unsigned long n){
    if(users.find(n) != users.end()){   //check if the person is in the hash table
        for(auto it = (users[n]->adjList).begin(); it != (users[n]->adjList).end(); ++it){  //for every connection a person has
            delete it->second;  //delete the connection
        }
        delete users[n];    //delete the user
        users.erase(n); //erase the key from the hash table.
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