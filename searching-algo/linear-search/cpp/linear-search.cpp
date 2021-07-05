//Time comlexity will O(n) in worst case, O(1) in best case

#include<iostream>

using namespace std;

int linearSearch(int arr[], int n){

    int key;
    cout<<"Enter key to find:"<<endl;
    cin>>key;

    for(int i=0; i<n; i++){

        if(key == arr[i]){
            return i;
        }
    }

    return -1;
}


int main(){

    int arr[] = {5,1,3,7,9,6,4,2};
    
    int n = sizeof(arr)/sizeof(arr[0]);

    int pos = linearSearch(arr,n);

    cout<<"Element found at position:"<<pos;

    return  0;
}

