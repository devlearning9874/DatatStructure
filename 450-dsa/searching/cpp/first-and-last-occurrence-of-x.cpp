#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void getFirstLastIndex(int arr[], int n, int x){
        
        int first_index = -1;
        int last_index = -1;

        int check;

       for(int i=0; i<n; i++){
          
          check = arr[i];

          if(check == x && first_index == -1){

              first_index = i;
              last_index = i;
          }else if(check == x){
              last_index = i;
          }
       }
       cout<<"first_index:"<<first_index<<"\n";
          cout<<"last_index:"<<last_index<<"\n";
}

int main(){

    int n,x;

    cin>>n>>x;

    int arr[n];

    for(int i=0; i<n; i++){
         cin>>arr[i];
    }

    getFirstLastIndex(arr, n, x);

    

    return 0;
}

// n=9, x=5
// arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
// Output:  2 5
// Explanation: First occurrence of 5 is at index 2 and last
//              occurrence of 5 is at index 5. 

// Input:
// n=9, x=7
// arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 }
// Output:  6 6 
