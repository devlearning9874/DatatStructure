

#include<iostream>
#include<algorithm>

using namespace std;

int max(int a, int b) {return a > b ? a : b;}

int knapsack(int W, int values[], int weight[], int n){
    
   int dp[n+1][W+1];

   for(int i=0; i<=n; i++){

       for(int w=0; w<=W; w++){

           if(i ==0 || w == 0){
               dp[i][w] = 0;
           }
           else if(weight[i-1] <= w){
               dp[i][w] = max(values[i-1]+dp[i-1][w - weight[i-1]], dp[i-1][w]);
           }
           else{
               dp[i][w] = dp[i-1][w];
           }
       }
   }

    
    
   return dp[n][W];
}


int main(){
    
//    int n = 3;
//    int W = 4;
//    int values[] = {1,2,3};
//    int weight[] = {4,5,1};
      
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

   
   cout<<"Maxm Profit:"<<knapsack(W, val, wt, n);

    return 0;
}