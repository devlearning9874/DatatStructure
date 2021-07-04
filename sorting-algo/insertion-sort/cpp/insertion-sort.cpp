// 

#include<iostream>

using namespace std;


void insertionSort(int arr[], int n){
     
     int i, j, key;
     for(int i=1; i<n; i++){

         int key = arr[i];
         int j = i - 1;
        while(j>=0 && key < arr[j]){

            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
     }
}

int  main(){
    
   int arr[] = {4, 3, 2, 10, 12, 1, 5, 6};
   
   int n = sizeof(arr)/sizeof(arr[0]);

   insertionSort(arr,n);

   cout<<"Insetion Sort:";

   for(auto it: arr){
       cout<<it<<" ";
   }

    return 0;
}