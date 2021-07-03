

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<char> countingSort(vector<char> &a){

    int min = *min_element(a.begin(), a.end());
    int max  = *max_element(a.begin(), a.end());

    int range = max - min +1;

    vector<char> fa(range), op(a.size());
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
    char arr[] = "geekforgeeks";
    int n  = sizeof(arr)/sizeof(arr[0]);
    vector<char> varr;

    for(int i=0; i<n; i++) varr.push_back(arr[i]);

    vector<char> res = countingSort(varr);
    cout<<"Sorted Array:";
    for(auto it: res){
        cout<<it<<" ";
    }

    return 0;
}