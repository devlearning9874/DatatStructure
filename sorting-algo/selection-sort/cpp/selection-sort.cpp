// Running time analysis for Selection Sort
// Space Complexity: O(1)
// Time Complexity: O(n^2)

#include<iostream>
#include<algorithm>
using namespace std;

void swapA(int *a, int *b){

    int temp = *a;
     *a = *b;
     *b = temp;

}

void selectionSort(int arr[], int n){
      
    
    for(int i=0; i<n-1; i++){
         
         int min_index = i;
         for(int j=i+1; j<n; j++){

             if(arr[j]<arr[min_index]){
                 min_index = j;
             }
         }
         swapA(&arr[min_index], &arr[i]);
    }
}

int main(){
   int arr[] = {64, 25, 12, 22,11,9,9,7,3};
   
   int n = sizeof(arr)/sizeof(arr[0]);

   selectionSort(arr,n);
   cout<<"Selection Sort:";
   for(auto it: arr){
       cout<<it<<" ";
   }
   return 0;
}