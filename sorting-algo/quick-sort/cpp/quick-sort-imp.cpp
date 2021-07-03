// Most of the language use quick sort algorithm in their library for sort function 


#include<iostream>
#include<algorithm>
using namespace std;

int partition(int *arr, int start, int end){
    
    int pivot = arr[end];
    int partitionIndex = start;
    for(int i=start; i<end; i++){
        if(arr[i]<= pivot){
            swap(arr[i], arr[partitionIndex]);
            partitionIndex++;
        }
        
    }
    swap(arr[partitionIndex], arr[end]);
    return partitionIndex;
}

int* quickSort(int *arr, int start, int end){

   if(start < end){
       int pIndex = partition(arr, start, end);

       quickSort(arr, start, pIndex-1);
       quickSort(arr, pIndex+1, end);
   }
   
   return arr;
    
}

int main(){

    int arr[]  = {5,3,2,6,2,9,6,1};

    int n = sizeof(arr)/sizeof(arr[0]);

    int *res = quickSort(arr, 0, n-1);
     cout<<"Quick Sort:";
     for(int i=0; i<n; i++) cout<<res[i]<<" ";
    return 0;
}