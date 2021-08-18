
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

void printDuplicateChar(string str){

       int n = str.length();

       map<char, int> m;

       for(int i=0; i<n; i++){

           m[str[i]]++;
       }

           for(auto it : m){

               if(it.second > 1){

                   cout<<it.first<<":"<<it.second<<endl;
               }
       }
}

int main(){

    string str;

    getline(cin, str);

    printDuplicateChar(str);


    return 0;
}