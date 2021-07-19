// Maximum and minimum of an array using minimum number of comparisons
// https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

#include<iostream>
#include<algorithm>

using namespace std;

class minMax{
    public:
       int min = 0;
       int max = 0;

      minMax(int arr[], int n){
            
            if(n==1){
              min = max = arr[0];
            } 
                if(arr[0]> arr[1]){
                    max = arr[0];
                    min = arr[1];
                }else{
                    max = arr[1];
                    min = arr[0];
                }
            
            for(int i=2; i<n; i++){

                if(arr[i]>max){
                    max = arr[i];

                }else if(arr[i] < min){
                    min = arr[i];
                }
            }

      }

};


 int main(){
 
  int arr[] = {7,15,9,3,4,6};
  int n = sizeof(arr)/sizeof(arr[0]);
  minMax obj(arr,n);
  
 cout<<"Maximum:"<<obj.max<<endl;
 cout<<"Minimum:"<<obj.min<<endl;

 return 0;

}