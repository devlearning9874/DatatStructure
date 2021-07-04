//Running time analysis for Bubble Sort
// Space Complexity: O(1)
// Time Complexity: O(n^2)
// This is easiest sorting algorithm one can relate it with brute-force approach
// Sorting type is in-place because it takes constant memory
// To optimize it further check bubble-sort-optimised.cpp
#include<iostream>

using namespace std;


void bubbleSort(int arr[], int n){

      int i,j;

      for(i=0; i<n; i++){

          for(j = i+1; j<n-1; j++){

                if(arr[i] > arr[j]){
                    swap(arr[i], arr[j]);
                }

          }
      }

}


int main(){
    
    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    int n = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr,n);
    
     cout<<"Bubble Sort:";

    for(auto it: arr){
        cout<<it<<" ";
    }

    return 0;

}