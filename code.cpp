#include <iostream>
#include <vector>
#include <list> //a doubly linked list
using namespace std;

class Graph{


    int V;
    list<int> *listOfIntegers;

public:                                                          // I believe this is the constructor
    Graph(int V){                                               // taking value from the user

            this->V=V;
            listOfIntegers=new list<int>[V];

    }  

   
    void addEdge(int u, int v){                                    // u -> v
        listOfIntegers[u].push_back(v);
        listOfIntegers[v].push_back(u);                             // v -> u


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
    g.addEdge(2,3);
    g.addEdge(2,4);
    
    g.printAdjList();
}
