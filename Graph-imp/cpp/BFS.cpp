#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class BFS{

    public:
        vector<int> bfsOfGraph(int N, vector<int> adj[]){
            vector<int> bfs;
            vector<int> visited(N+1,0);
             
            for(int i=1; i<=N; i++){

                if(!visited[i]){
                    queue<int> q;
                    q.push(i);
                    visited[i] = 1;
                    while(!q.empty()){
                        int node = q.front();
                        q.pop();
                        bfs.push_back(node);

                        for(auto it: adj[node]){
                            if(!visited[it]){
                              q.push(it);
                              visited[it] = 1;
                            }
                        }
                    }
                }
            }
            
            return bfs;
            
        }

        
};


int main(){

    int n, e;

    cin>>n>>e;

    
    vector<int> adj[n+1];
    cout<<"Add Graph Input-";
    for(int i=0; i<e; i++){
        int u, v;

        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

      BFS bfsObj;

     

      vector<int> bfsResult = bfsObj.bfsOfGraph(n,adj);
      
      

       for(int res:bfsResult){
           cout<<res<<" ";
       }
      
}