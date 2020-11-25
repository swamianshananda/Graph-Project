#pragma once
#include <vector>
#include <unordered_map>
#include <string>
class TwitterGraph{ //graph to use to map Twitter Users
    private:
        struct Connection{  //essentially an edge
            const unsigned long source; //the person who is the follower
            const unsigned long destination;    //the followee
            int weight; //added a weight variable in case it could ever be used.
            Connection(unsigned long s, unsigned long d) : source(s), destination(d), weight(0){};  //Constructor
        };
        struct User{    //essentially a vertex
            const unsigned long userId; //to represent the nodeId used in the files.
            std::vector<std::string> features;  //features described in the original files
            std::unordered_map<unsigned long, Connection*> adjList; //used a hashtable to determine all the people a user follows
            User(unsigned long id) : userId(id){};  //constructs user based on nodeId
        };
        std::unordered_map<unsigned long, User*> users; //hash table to determine nodeId to actual users.
    public:
        void addUser(unsigned long);    //adds user to graph
        void removeUser(unsigned long); //removers user from graph.
        void addConnection(unsigned long, unsigned long);   //add connection where first person follows another person
        void removeConnection(unsigned long, unsigned long);    //removes connection where first person was following another person
        std::vector<unsigned long> connections(unsigned long);  //returns nodeIds of all people a person is following
        bool isFollowing(unsigned long, unsigned long); //determines if the first person is following another person
};