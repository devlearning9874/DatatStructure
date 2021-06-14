#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Cycle{

     bool checkForCycle(int s,int V, vector<int> adj[], vector<int> &visited){
                
                queue<pair<int,int>> q;
                q.push({s,-1});
                visited[s] = true;

                while(!q.empty()){

                    int node = q.front().first;
                    int par =  q.front().second;
                    q.pop();

                    for(auto it: adj[node]){
                          
                          if(!visited[it]){
                              visited[it] = true;
                              q.push({it,node});
                          }

                          else if(par != it)
                             return true;

                    }
                }

        return false;
     }

  public:
      bool bfsCycleDetection(int node, vector<int> adj[]){
         vector<int> visited(node+1,0);
             
         for(int i=1; i<=node; i++){
             
             if(!visited[i]){
            if(checkForCycle(i,node, adj, visited))
                  return true;
           }
         
       }
       return false;
    }
};


int main(){
    
    int n, e;
    cin>>n>>e;
    
    vector<int> adj[n+1];
    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Cycle obj;

    bool result = obj.bfsCycleDetection(n, adj);
    
    cout<<result;
    



    return 0;
}