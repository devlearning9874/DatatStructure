

#include<iostream>
#include<algorithm>
using namespace std;

int knapsack(int W, int values[], int weight[], int n){
    int maxProfit;
    if(n == 0 || W == 0) return 0;  //Base Case

    if(weight[n] > W){
        knapsack(W, values,weight,n-1);
    }
    else{
        return  max(values[n]+knapsack(W-weight[n],values,weight,n-1),knapsack(W,values,weight, n-1));
    }
    
   return 0;
}


int main(){
   int n = 3;
   int W = 4;
   int values[] = {1,2,3};
   int weight[] = {4,5,1};

   cout<<"Maxm Profit:"<<knapsack(W, values, weight, n-1);
    
    
    return 0;
}