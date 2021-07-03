#include<iostream>

using namespace std;

int getMax(int arr[], int n){

    int mx = arr[0];
    for(int i=1; i<n; i++){
       if(arr[i]>mx){
            mx = arr[i];
       }   
    }
    return mx;        
}

void countSort(int arr[], int n, int base){
    
    int op[n];
    int farr[10] = {0};

    for(int i=0; i<n; i++){
        farr[(arr[i]/base) % 10]++;
    } //digit count stored

    for(int i=1; i<10;  i++){
        farr[i] += farr[i-1];
    }

    for(int i= n-1; i>=0; i--){
        op[farr[(arr[i]/base) % 10] - 1] = arr[i];
        farr[(arr[i]/base) % 10]--;
    }
     
    for(int i=0; i<n; i++){
        arr[i] = op[i];
    }
    
}

void radixSort(int arr[], int n){
  
  int max = getMax(arr,n);

  for(int base=1; max/base >0; base*=10 ){
      countSort(arr,n, base);
  }
      

}

int main(){
    int arr[] = {10,15,1,60,5,100,25,50};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixSort(arr,n);
   cout<<"Radix Sort:";
   for(auto it: arr){
       cout<<it<<" ";
   }

    return 0;
}