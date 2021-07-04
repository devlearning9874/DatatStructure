//Running time analysis for Bubble Sort
// Space Complexity: O(1)
// Time Complexity: Worst case time complexity O(n*n) if array is reverse sorted
//                  In Best Case:- O(n) when array is already sorted;
// This is easiest sorting algorithm one can relate it with brute-force approach
// Sorting type is in-place because it takes constant memory
// In this solution we will reduce unwanted swaps if array is already sorted

#include<iostream>

using namespace std;


void bubbleSort(int arr[], int n){

      int i,j;

      for(i=0; i<n; i++){
            bool checkSwap = false;
          for(j = i+1; j<n-1; j++){

                if(arr[i] > arr[j]){
                    swap(arr[i], arr[j]);
                    checkSwap = true;
                }

          }

          if(checkSwap == false){
              break;
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