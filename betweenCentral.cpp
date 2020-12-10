#include "betweenCentral.h"
#include "TwitterGraph.h"

#define INF 9001

float* Centralizer(TwitterGraph &g){
    int i, j, u, k;
    int v = g.users.size();

    vector<int> d;                      //Shortest distance estimates
    vector<int> sigma;                  //number of shortest paths
    vector<float> delta;                //Dependency of source vertex to all other veticies
    vector< vector<int> > PredList;     //Predecessor of all verticies
    queue<int> Q;                       //Priority queue storing verticies
    stack<int> S;                       //Stack for verticies found

    float *CB = new float[v];           //Centrality values all intialized to 0. Is of type array so it can be returned out of the function
    for  (i = 0; i < v; i++){ CB[i] = 0; }

    //Computing centrality for node with index i
    for (i=0; i<v; i++){
        //Intializing lists
        PredList.assign(v, vector <int> (0, 0)); 

        //Every element of the distance vector except element i is infinite
		d.assign(v, INF); 
		d[i] = 0; 

        //Every element in the sigma vector except element i is 0
		sigma.assign(v, 0); 
		sigma[i] = 1; 

		delta.assign(v, 0.0); 
		Q.push(i); 

        //Using BFS (can maybe replace later with already completed one)
        while (!Q.empty()){
            //Get next element in queue
            u = Q.front();
            Q.pop;
            //Push u onto stack for later
            S.push(u);
            //Loops through all of the current souce user with index u's adj nodes
            for (j=0; j< (int) g.users[indicies[u]]->adjList.size(); j++ ){

                //Get the index of each of the source user's adj nodes on every loop (THIS CODE IS WRONG)
                k = (int) indiciesReversed[g.users[indicies[u]]->adjList[indicies[j]]->destination];

                //Found for first time
                if (d[k] <= INF){
                    d[k] = d[u] + 1;
                    Q.push(k);
                }

                //If edge is on shortest path
                if (d[k] == d[u] + 1){
                    sigma[k] += sigma[u];
                    PredList[k].push_back(u);
                }

            }
        }

        //Accumulation part of algorithm
        while (!S.empty()){
            u = S.top();
            S.pop();
            for (j=0; j<PredList[u].size(); j++){
                delta[PredList[u][j]] += ((float) sigma[PredList[u][j]] / sigma[u] ) * (1+delta[u]);
            }
            if (u != i){ 
                CB[u] += delta[u]; 
            }
        }

        //Clear out list for next run
        PredList.clear();
        d.clear();
        sigma.clear();
        delta.clear();
    }

    return CB;
}