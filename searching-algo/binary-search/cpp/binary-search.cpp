// Binary search is more efficient than linear search.
// Perform searching operation on sorted array or list in logarthmic time complexity
// Time complexity will be O(logn)
#include<iostream>

using namespace std;

int binarySearch(int arr[], int start, int end, int key){

   
    
    while(start <= end){
        int mid = start + (end - start)/2;
        if(arr[mid] == key){
           return mid;
        } if(arr[mid] < key){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }

    return -1;
}


int main(void){

    int arr[] = {1,2,3,4,5,6,7,8,9};

    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 8;
    cout<<"Enter number to search:"<<endl;
    cin>>key;
    int idx = binarySearch(arr,0,n-1,key);

    cout<<"Binary Search Index:"<<idx;

    return 0;
}
