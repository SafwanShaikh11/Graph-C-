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
void BFS(){
    queue<int> queue;
    queue.push(0);

    vector<bool> visited(V,false);

    visited[0]=true;


    while(queue.size() >0) {

        int u =queue.front();
        queue.pop();

        cout << u << " ";

        for (int neighbour : listOfIntegers[u]){

            if(!visited[neighbour]){
                visited[neighbour]=true;
                queue.push(neighbour);
            }
        }
    }
cout << endl; 

}
    void printAdjList(){
            for(int i=0;i<V;i++){  
                cout << i << " :" ;
                for(int neighbour : listOfIntegers[i]){

                    cout << neighbour << " ";

                }
                cout << endl;
             }
        }
};



int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    

    g.BFS();

    //g.printAdjList();
    return 0;
}
