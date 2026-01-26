#include <iostream>
#include <vector>
#include <list> //a doubly linked list
#include<queue> //queue for BFS 
using namespace std;

class Graph{


    int Vertices;
    list<int> *listOfIntegers;

public:                                                          // this is the actual constructor
    Graph(int Vertices){                                               // Number of vertices of graph

            this->Vertices=Vertices;
            listOfIntegers=new list<int>[Vertices];

    }  

   
    void addEdge(int u, int v){                                    // u -> v
        listOfIntegers[u].push_back(v);
        listOfIntegers[v].push_back(u);                             // v -> u


    }
      //Bfs Traversal
void BFS(){                                                          //O(V+E)
    queue<int> queue;
    queue.push(0);

    vector<bool> visited(Vertices,false);

    visited[0]=true;


    while(queue.size() >0) {

        int u =queue.front();                                           // u-v
        queue.pop();

        cout << u << " ";

        for (int neighbour : listOfIntegers[u]){               //v -> immediate neighbours

            if(!visited[neighbour]){
                visited[neighbour]=true;
                queue.push(neighbour);
            }
        }
    }
cout << endl; 

}
void dfsHelper(int u,vector<bool> &vis ){                             //O(V+E)

    cout << u << " ";
    vis[u] =true;

    for (int v : listOfIntegers[u]){                                   //u -> v 

        if(!vis[v]){
            dfsHelper(v,vis);

        }
    }

}

//DFS Traversal
void DFS(){ 
    int src = 0 ;                                                                     //hardcoded value ,really curious how i can turn it into finding a src arbitrarily.
    vector<bool> vis(Vertices,false);

    dfsHelper(src,vis);
}


//Cycle detectin in undirected graph using DFS
bool isCycleUnderDSF(int src, int parent , vector<bool>&vis){                           //core logic of the cycle detection in DFS
            vis[src]=true;
            list<int> neighbours = listOfIntegers[src];

            for(int v : neighbours){
                if(!vis[v]){

                  if( isCycleUnderDSF(v,src,vis)){
                        return true;
                  }
                   
                }else if (v !=parent){                                                    //if cycle exists then return true.
                    return true;
                }
                
            }
            return false;                                                                //found no cycle
            
}
//to get rid of passing parent and source again and again
bool isCycle(){
vector <bool> vis(Vertices,false);                                                                   //V = number of vertices already has false values assigned.

for(int i=0;i<Vertices;i++){
    if(!vis[i]){

        isCycleUnderDSF(i,-1,vis);                                                  // i: source , -1 : parent of source , vis : visited array

    }
}
return false;
}
bool isCycleUnderBFS(int src, vector<bool> &vis){
    queue<pair<int,int>> q;

   vis[src]=true;
    q.push({src,-1});

    while(q.size()>0){
     
        int u=q.front().first;
        int parentU=q.front().second;
        q.pop();

        list<int> neighbours = listOfIntegers[u];        //storing the listofintegers on my u.


        for( int v : neighbours){
            if(!vis[v]){
                q.push({v,u});        //u-----------v
                 vis[v]=true;
            }else if(v!=parentU){    //if there exist an edge then we got a cycle
                return true;
            }               

        }
    }
    return false;  //got no cycle

}
bool isCycleBFS(){          //using these method to ensure we cover the entire graph as the graphs might be disjoint and also to make the code look readable
    vector<bool> visited(Vertices,false);
    if(!visited[Vertices]){
        if(isCycleUnderBFS(Vertices,visited)){
            return true;
        }
    }
}
};

int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,4);
    
    //cout << "BFS : " ;
    //g.BFS();

    //cout << "DFS : ";
    //g.DFS();

  //  g.isCycle() ? cout << "Cycle detected using DFS \n" : cout << "No Cycle detected\n";

    g.isCycleBFS() ? cout << "Cycle detected using BFS \n" : cout << "No Cycles detected\n";

    return 0;
}
