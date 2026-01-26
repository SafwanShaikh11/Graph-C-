#include <iostream>
#include <vector>
#include <list> //a doubly linked list
#include<queue> //queue for BFS 
using namespace std;

class Graph{


    int V;
    list<int> *listOfIntegers;

public:                                                          // I believe this is the constructor, no this is the actual constructor
    Graph(int V){                                               // Number of vertices of graph

            this->V=V;
            listOfIntegers=new list<int>[V];

    }  

   
    void addEdge(int u, int v){                                    // u -> v
        listOfIntegers[u].push_back(v);
        listOfIntegers[v].push_back(u);                             // v -> u


    }
      //Bfs Traversal
void BFS(){    //O(V+E)
    queue<int> queue;
    queue.push(0);

    vector<bool> visited(V,false);

    visited[0]=true;


    while(queue.size() >0) {

        int u =queue.front();   // u-v
        queue.pop();

        cout << u << " ";

        for (int neighbour : listOfIntegers[u]){    //v -> immediate neighbours

            if(!visited[neighbour]){
                visited[neighbour]=true;
                queue.push(neighbour);
            }
        }
    }
cout << endl; 

};
void dfsHelper(int u,vector<bool> &vis ){   //O(V+E)

    cout << u << " " ;
    vis[u] =true;

    for (int v : listOfIntegers[u]){   //u -> v 

        if(!vis[v]){
            dfsHelper(v,vis);

        }
    }

};

//DFS Traversal
void DFS(){
    int src =0 ;
    vector<bool> vis(V,false);

    dfsHelper(src,vis);
}


//Cycle detectin in undirected graph
bool isCycleUnderDSF(int src, int parent , vector<bool>&vis){    //core logic of the cycle detection in DFS
            vis[src]=true;
            list<int> neighbours = listOfIntegers[src];

            for(int v : neighbours){
                if(!vis[v]){

                  if( isCycleUnderDSF(v,src,vis)){
                        return true;
                  }
                   
                }else if (v !=parent){
                    return true;
                }
                
            }
            return false;
            
}
//to get rid of unnecessary  parameters 
bool isCycle(){
vector <bool> vis(V,false);

for(int i=0;i<V;i++){
    if(!vis[i]){
        isCycleUnderDSF(i,-1,vis);

    }
}
return false;
};


int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    
    cout << "BFS : " ;
    g.BFS();

    cout << "DFS : ";
    g.DFS();

    //g.printAdjList();
    return 0;
};
};