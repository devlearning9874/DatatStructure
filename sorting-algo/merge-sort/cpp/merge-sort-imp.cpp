// Time complexity for merge sort is O(nlogn) for all three cases (best, average, worst)

#include<iostream>

using namespace std;

void merge(int arr[], int l,int m, int r){

     int i,j,k;

     int n1 = m - l + 1;
     int n2 = r - m;

     int L[n1], R[n2];

     //copy arr element in L and R
     for(int i=0; i<n1; i++){
         L[i] = arr[l+i];
     }
     for(int i=0; i<n2; i++){
         R[i]  = arr[m+1+i];
     }
  //  initilize looping variables
    i = 0; //starting index of first subarray L
    j = 0; //starting index of second subarray R
    k = l;  //starting index of merged array
     //Start sorting now
     while(n1>i && n2>j){

         if(L[i] <= R[j]){
             arr[k] = L[i];
             i++;
         }
         else{
             arr[k] = R[j];
             j++;
         }
         k++;
     }

     while(n1>i){
         arr[k] = L[i];
         k++;
         i++;
     }
     while(n2>j){
         arr[k] = R[j];
         j++;
         k++;
     }


}

void mergeSort(int arr[], int l, int r){

    if(r>l){
        int m = l + (r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l,m, r);
    }

}

int main(){
    
    int arr[]  = {5,3,6,2,1,8,7,9};

    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, n-1);

    cout<<"Merge Sort:";

    for(auto it: arr){
        cout<<it<<" ";
    }

    return 0;
}