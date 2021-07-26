
#include<iostream>
#include<set>
#include<iterator>

using namespace std;


int main(){
   
   int arr[] = {5,8, 2, 6, 2, 2, 6,10, 7};

   int n = sizeof(arr)/sizeof(arr[0]);

   set<int> s;

   for(int i=0; i<n; i++){
       s.insert(arr[i]);
   }
    // To print set value
    cout<<"Printing Set values "<<"\n";

    for(auto itr = s.begin(); itr!= s.end(); itr++){

        cout<<*itr<<" ";
    }
    cout<<endl;
   // Now find number in set
   int key;
   cout<<"Enter to find a number"<<"\n";
   cin>>key;

   if(s.find(key) != s.end()){
       cout<<key<<" is present"<<"\n";
   }else{
       cout<<key<<" is not present"<<"\n";
   }

   

    return 0;
}