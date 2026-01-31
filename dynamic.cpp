#include<iostream>
#include<climits>
#include<vector>

using namespace std;

/*Bellman Foed : Shortest path from src to all vertices for weighed graph with negative weights
    TC: 
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

void bellmanFord(int src,vector<vector<Edge>> g,int vertices ){
    vector <int> distance(vertices,INT_MAX);
    distance[src]=0;

    for(int i=0;i<vertices-1;i++){  //core logic for thgis agorithmn

        for(int u=0;u<vertices;u++){  //u ------>v

            for(Edge e: g[u]){       // Edge relaxation
                    if(distance[e.vertices] > distance[u] + e.weight) {
                        distance[e.vertices]=distance[u]+e.weight;
                    }
            }

        }
    }
        for(int i=0;i< vertices;i++){
            cout << distance[i] << " , ";
        }
        cout << endl;

}   




int main(){
    
int V=6;  //no. of vertices
vector<vector<Edge>> g(V);  //it's a jagged array 


g[0].push_back(Edge(1,2));  //(edge, weight)
g[0].push_back(Edge(2,4));

g[1].push_back(Edge(4,-1));
g[1].push_back(Edge(2,-4));

g[2].push_back(Edge(3,2));

g[3].push_back(Edge(4,4));

bellmanFord(0,g,V);


}

