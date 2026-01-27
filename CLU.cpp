#include <iostream>
#include <vector>
#include <list> //a doubly linked list
#include<queue> //queue for BFS 
using namespace std;

class GraphDir{


    int Vertices;
    list<int> *listOfIntegers;

    public:

    GraphDir(int Vertices){
        this -> Vertices=Vertices;
        listOfIntegers= new list<int>[Vertices];

    }

    void addEdge(int u, int v){
        listOfIntegers[u].push_back(v);  // u -> v directed graph
    }


    bool isCycleUnderDFS(int u, vector<bool>&vis,vector<bool>&recpath ){
        vis[u]=true;
        recpath[u]=true;

        for(int v : listOfIntegers[u]){

            if(!vis[v]){  //neighbour visited 

                if(isCycleUnderDFS(v,vis,recpath)){   //if cycle found in the beginning then return true.
                    return true;

                //neighbour is already visited + it's a part of the recurion path meaning while backtracking that mode has alreasy been visited , especially in directed graphs.then also return true.

                }
            }else if(recpath[v]){
                    return true;
                }

        }
       recpath[u]=false;
       return false;

    }

    bool CycleDFS(){
        vector<bool> visited(Vertices,false);
        vector<bool> path(Vertices,false);

            for(int i=0;i<Vertices;i++){

                if(!visited[i]){
                    if(isCycleUnderDFS(i,visited,path)){
                        return true;
                    }
                }
            }
            return false;
    }
};



    int main(){

        
    GraphDir c(5);

    c.addEdge(1,0);
    c.addEdge(0,2);
    c.addEdge(2,3);
    c.addEdge(3,0);
   

    
    cout << c.CycleDFS()<< endl;
    
    c.CycleDFS()? cout << "Cycle detected using DFS \n" : cout << "No Cycles detected\n";


    }
