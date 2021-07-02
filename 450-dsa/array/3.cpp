// Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo
// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1#
//VVI Problem revise 
//Note: This problem is based on Dutch National Flag Algorithm modification
//  Link:- https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

// Time complexity: O(n)
// Space Complexity: O(1)


#include<iostream>

using namespace std;

void sortArray(int a[],  int n){
    
    int low =0, mid=0;
    int high = n-1;

    while(mid<=high){
      
       switch (a[mid])
       {
       case 0:
           swap(a[low++], a[mid++]);
           break;
       case 1:
           mid++;
           break;
       case 2:
           swap(a[mid], a[high--]);
       default:
           break;
       }
        
    }
}

int main(){
    cout<<"Hello!";

    int  arr[]= {0, 2, 1, 2, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortArray(arr,n);
    cout<<"Sorted Array:";
    for(auto it: arr){
        cout<<it<<" ";
    }
    return 0;
}