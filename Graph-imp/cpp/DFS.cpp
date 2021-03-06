#include<iostream>
#include<vector>
using namespace std;

class DFS{

    void dfs(int node, vector<int> &visited, vector<int> adj[], vector<int> &storeDfs){
          storeDfs.push_back(node);

          for(auto it: adj[node]){
              if(!visited[it]){
                  visited[it] = 1;
                  dfs(it, visited, adj, storeDfs);
              }
          }

    }

  public:
     vector<int> dfsOfGraph(int node, vector<int> adj[]){
              
              vector<int> storeDfs;
              vector<int> visited(node+1,0);

              for(int i=1; i<=node; i++){
                  if(!visited[i]){
                      visited[i] = true;
                      dfs(i, visited,adj, storeDfs);
                  }
              }

              return storeDfs;
      }
};


int main(){
    int n,e;
    cin>>n>>e;            // n = 5

    vector<int> adj[n+1];   
    
    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

     DFS objDFS;

     vector<int> resutlOfDfs = objDFS.dfsOfGraph(n,adj);
     
     for(auto it: resutlOfDfs){
         cout<<it<<" ";
     }
     
     return 0;

}
// input: n = 4, e = 6 
// 0 -> 1,
//  0 -> 2,
//   1 -> 2,
//    2 -> 0,
//     2 -> 3,
//      3 -> 3 
// Output: DFS from vertex 1 : 1 2 0 3 
