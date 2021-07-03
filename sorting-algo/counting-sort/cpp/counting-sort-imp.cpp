

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> countingSort(vector<int> &a){

    int min = *min_element(a.begin(), a.end());
    int max  = *max_element(a.begin(), a.end());

    int range = max - min +1;

    vector<int> fa(range), op(a.size());
    //Step 1: Store frequency of numbers in fa.
    for(int i=0; i < a.size(); i++){
        fa[a[i] - min]++;
    }
    // Step 2: Get prefix sum array of fa to get track of count of element already filled
    for(int i=1; i<fa.size(); i++){
         fa[i] += fa[i-1];
    }

    for(int i=a.size()-1; i>=0; i--){
        op[fa[a[i] - min] - 1] = a[i];
        fa[a[i] - min]--;
    }

    return op;

}


int main(){
    
    vector<int> arr = {4,4,7,7,9,2,6,5,5,9};

    vector<int> res = countingSort(arr);
    cout<<"Sorted Array:";
    for(auto it: res){
        cout<<it<<" ";
    }

    return 0;
}