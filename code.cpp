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
    queue.push(0);                                      //hardcoded value ,really curious how i can turn it into finding a src arbitrarily.

    vector<bool> visited(Vertices,false);

    visited[0]=true;


    while(queue.size() >0) {

        int u =queue.front();                                           // u-v
        queue.pop();

        //cout << u << " ";

        for (int neighbour : listOfIntegers[u]){               //v -> immediate neighbours

            if(!visited[neighbour]){
                visited[neighbour]=true;
                queue.push(neighbour);
            }
            cout << neighbour << " ";
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

};

int main(){
    Graph g(5);

   
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);


    cout << "BFS : " ;
    g.BFS();

    cout << "DFS \n: ";
    g.DFS();


    return 0;
}
