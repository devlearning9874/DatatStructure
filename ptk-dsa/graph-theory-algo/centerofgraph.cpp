#include<bits/stdc++.h>
using namespace std;

int findCenter(vector<vector<int>>edges)
{
      int n = edges.size();
      int arr[n+2];
      
      for(int i=0; i<n+2; i++) 
          arr[i] = 0;
      
      for(int i=0; i<n; i++){
           
                for(auto it: edges[i]){
                
                    arr[it]++;
                   
                }
                
       }
    
       int result = -1;
       
       
       
       for(int i=1; i<n+2; i++){
               
               if(arr[i] == n){
                   
                   result = i;
                   break;
               }
       }
       
       return result;
}

int main(){
	
	vector<vector<int>> edges = { {1,2},{2,3},{4,2}};
	
	int result = findCenter(edges);
	cout<<"center of graph:"<<result<<endl;
	
	
	return 0;
}                                    
                     // 1->2->3, 2->4                