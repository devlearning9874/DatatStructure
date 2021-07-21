

#include<iostream>
using namespace std;
#define MAX 1000


void heapify(int arr[], int n, int i){
     
     int parent = (i-1)/2;

     if(parent >= 0){

         if(arr[i] > arr[parent]){
             swap(arr[i], arr[parent] );
             heapify(arr, n, parent);
         }
     }
}

void insertHeap(int arr[], int &n, int key){

     n  = n+1;

     arr[n-1] = key;
     
     heapify(arr, n, n-1);

}


void printHeap(int arr[], int n){
     
     for(int i=0; i<n; i++){
         
         cout<<arr[i]<<" ";
     }
     cout<<"\n";

}


int main(){


     // Array representation of Max-Heap
    //     10
    //    /  \
    //   5    3
    //  / \
    // 2   4
    int arr[MAX] = { 10, 5, 3, 2, 4 };
    
    int n = 5;
    int key = 15;
    insertHeap(arr, n, key);
    
    printHeap(arr, n);


    return 0;
}

// Required Output

// 15 5 10 2 4 3