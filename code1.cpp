#include <iostream>
#include <vector>
#include <list> //a doubly linked list
#include<queue> //queue for BFS 
using namespace std;

class Cycle{


    int Vertices;
    list<int> *listOfIntegers;

    public:

    Cycle(int Vertices){
        this -> Vertices=Vertices;
        listOfIntegers= new list<int>[Vertices];

    }

    void addEdge(int u, int v){
        listOfIntegers[u].push_back(v);    //undirected graph
        listOfIntegers[v].push_back(u);  

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

        if(isCycleUnderDSF(i,-1,vis)){
            return true;
        }                                                  // i: source , -1 : parent of source , vis : visited array

    }
}
return false;
}
bool isCycleUnderBFS(int src, int parent ,vector<bool> &vis){
    
    queue<pair<int,int>> q;
        q.push({src,parent});
        vis[src]=true;

    while(q.size()>0){
     
        int u=q.front().first;
        int parentU=q.front().second;
        q.pop();

        list<int> neighbours = listOfIntegers[u];        //storing the listofintegers on my u.


        for( int v : neighbours){
            if(!vis[v]){
                q.push({v,u});        //u-----------v
                 vis[v]=true;
            }else if(v!=parentU){    //if there exist an edge then we got a cycle backedge
                return true;
            }               

        }
    }
    return false;  //got no cycle

}
bool isCycleBFS(){          //using these method to ensure we cover the entire graph as the graphs might be disjoint and also to make the code look readable
    vector<bool> visited(Vertices,false);
    
   
    if(!visited[Vertices]){
        if(isCycleUnderBFS(Vertices,-1,visited)){
            return true;
            }
        }
    
}


};

int main(){

    Cycle c(4);

    c.addEdge(0,1);
    c.addEdge(1,2);
    c.addEdge(1,3);
    c.addEdge(2,3);

    
    cout << c.isCycle()<< " ";
    
    c.isCycle()? cout << "Cycle detected using DFS \n" : cout << "No Cycle detected\n";
    
    //cout << c.isCycleBFS() << " ";  //the problem lies here in this algorithmn , thahts why dfs is the goat ACTUALLY


    //c.isCycleBFS() 

    


}