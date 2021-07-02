// Reverse the array
// https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/

//Solution approach
// 1. Iterative -> Time Complexity : O(n)
//              -> Space Complexity: O(1);
// -------------------------------------------
// 2. Recursive -> Time Complexity: O(n)
//              -> Space Complexity: O(n)

#include<iostream>

using namespace std;

void recReverseArray(int arr[], int n, int i){
    if(i>=n){
        return;
    }

    int temp = arr[i];
    arr[i] = arr[n];
    arr[n] = temp;
    recReverseArray(arr, n-1,i+1);
    
}

void itrReverseArray(int arr[], int n){

     for(int i=0; i<n/2; i++){
        int temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;

     }
 
}

int main(){
    
    int iarr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(iarr)/sizeof(iarr[0]);
    itrReverseArray(iarr, n);
    cout<<"Iterative Reverse:-";
    for(int i=0; i<n; i++){
        cout<<iarr[i]<<" ";
    }
    cout<<"\n";
     int rarr[] = {7,8,9,10,11,12};
    cout<<"Recursive Reverse:";
     recReverseArray(rarr, n-1, 0);
    for(int i=0; i<n; i++){
         cout<<rarr[i]<<" ";
    }
    return 0;
}