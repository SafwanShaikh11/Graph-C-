#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<climits>

using namespace std;

/* This algorithmn is also known as the greedy algorithmn as we always try to find the minimal solution on each step in this process.
*/


class Edge{
public:                      //constructor

int vertices;
int weight;

    Edge(int vertices, int weight){
        this->vertices=vertices;
        this->weight=weight;
    }
    
};

void dijkstra(int src,vector<vector<Edge>> g,int Vertex ){

    vector<int> distance(Vertex,INT_MAX);

    distance[src]=0;

    priority_queue<pair<int,int>> pqueue;  //this is a default max-heap priority queue.


    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;  //min-heap queue by rev. the logic adding the greater comparator.  
    //dist[u],u

    pq.push({0,src});

    while(pq.size()>0){
        int u=pq.top().second;
        pq.pop();

        for(Edge e  : g[u]){ // Edge-relaxation

            if(distance[e.vertices]>distance[u]+e.weight){

                distance[e.vertices]=distance[u]+e.weight;

                pq.push({distance[e.vertices],e.vertices});
            }
             
        }
    }

    //loop for all the distance values
    for(int i=0;i<Vertex;i++){
        cout << distance[i] << " ";
    }
        cout<<endl;
}

int main(){

int V=6;  //no. of vertices
vector<vector<Edge>> g(V);  //it's a jagged array 


g[0].push_back(Edge(1,2));  //(edge, weight)
g[1].push_back(Edge(2,4));

g[1].push_back(Edge(2,1));
g[1].push_back(Edge(3,7));

g[2].push_back(Edge(4,3));

g[3].push_back(Edge(5,1));

g[4].push_back(Edge(3,2));
g[4].push_back(Edge(5,5));

dijkstra(0,g,V); //stack matters 


return 0;
}