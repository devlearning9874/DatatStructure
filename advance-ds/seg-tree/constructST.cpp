#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int getMid(int s, int e) {
	return s + (e - s)/2;
} 
void updateSTUtil(int *st, int ss, int se, int i, int diff, int si){

    if( i>se || i < ss) return;

    st[si] = st[si] + diff;
    if(se != ss){
        int mid = getMid(ss, se);
        updateSTUtil(st, ss, mid, i, diff, 2*si+1);
        updateSTUtil(st, mid+1, se, i, diff, 2*si+2);
    }
}
void updateST(int arr[],int *st, int n, int i, int value){
     
     int diff = value - arr[i];
     arr[i] = value;
     updateSTUtil(st, 0, n-1, i, diff, 0);
}

int getSumUtil(int *st, int ss, int se, int qs, int qe, int si){

     if(qs <= ss && qe >= se){
         return st[si];
     }

     if(se < qs || ss > qe){
         return 0;
     }

     int mid = getMid(ss, se);

     return getSumUtil(st, ss, mid, qs, qe, si*2+1)+getSumUtil(st, mid+1, se, qs, qe, si*2+2);

}

int getSum(int *st, int n,int qs, int qe){

    if(qs < 0 || qs > qe || qe > n-1){
        cout<< "Invalid Query"<<"\n";
        return -1;
    }

    return getSumUtil(st, 0, n-1, qs, qe, 0);
}

int constructSTUtil(int arr[], int *st, int ss, int se, int si ){

    if(ss == se){
        st[si] = arr[ss];
        return arr[ss];
    }
    
    int mid = getMid(ss, se);

    st[si] = constructSTUtil(arr, st, ss, mid, si*2+1)+ constructSTUtil(arr, st, mid+1, se, si*2+2);
	
	return st[si];     

}

int *constructST(int arr[], int n){
      
      int heightST = (int)ceil(log2(n));

      int max_size = 2*(int)pow(2,heightST) - 1;
      
      //memory allocated for segment tree
      int *st = new int[max_size];

      constructSTUtil(arr, st, 0, n-1, 0);

      return st;

}

int main(){
    
    //constructing segment tree
    

    int arr[] = {1,3,5,7, 9, 11};

    int n = sizeof(arr)/sizeof(arr[0]);

    int *st = constructST(arr,n); //segTree constructed now use it
    //segement tree constucted using given array
    //Now get query for sum of range
    cout<<"Sum of the given range:"<<getSum(st,n,1,4)<<endl;
   
   //Upadating Segment Tree takes log(n) T.C
   updateST(arr,st, n, 1, 10);

   //Now after update range query sum will be

   cout<<"After update Sum:"<<getSum(st,n, 1, 4)<<endl;


    return 0;
}
