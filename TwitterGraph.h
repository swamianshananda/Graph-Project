#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
class TwitterGraph{ //graph to use to map Twitter Users
    public:
        enum Label {VISITED, UNEXPLORED, DISCOVERY, CROSS};
        struct Connection{  //essentially an edge
            const unsigned long source; //the person who is the follower
            const unsigned long destination;    //the followee
            Label l;
            Connection(unsigned long s, unsigned long d) : source(s), destination(d), l(UNEXPLORED){};  //Constructor
        };
        
        struct User{    //essentially a vertex
            const unsigned long userId; //to represent the nodeId used in the files.
            std::unordered_map<unsigned long, Connection*> adjList; //used a hashtable to determine all the people a user follows
            Label l;
            float betweenessCentralValue; //betweeness centriality value
            User(unsigned long id) : userId(id), l(UNEXPLORED), betweenessCentralValue(0.0){};  //constructs user based on nodeId
            
        };
        std::unordered_map<unsigned long, User*> users; //hash table to determine nodeId to actual users.
        std::unordered_map<int, unsigned long> indices;
        //std::unordered_map<unsigned long, int> indicesReversed;
        std::vector<std::vector<int>> distMatrix;
        
        void addUser(unsigned long);    //adds user to graph
        void removeUser(unsigned long); //removers user from graph.
        void addConnection(unsigned long, unsigned long);   //add connection where first person follows another person
        void removeConnection(unsigned long, unsigned long);    //removes connection where first person was following another person
        std::vector<unsigned long> connections(unsigned long);  //returns nodeIds of all people a person is following
        bool isFollowing(unsigned long, unsigned long); //determines if the first person is following another person
        bool isUser(unsigned long);
        std::vector<unsigned long> BFS(unsigned long);
        std::vector<std::vector<unsigned long>> BFS();
        void createIndexes();
        void createIndexesReversed();
        void calculateDistances();
        int findDistance(unsigned long, unsigned long);
        ~TwitterGraph();
};