

#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

char *reverse(char *S, long long int len){
    //  cout<<len;
     stack<char> s;

    //  char *rev;

     for(int i=0; i<len; i++){
         s.push(S[i]);
     }

     int k=0;

     while(!s.empty()){
         S[k] = s.top();
         s.pop();
         k++;
     }
     
     return S;
}

int main(){

     char str[10000];

     cin>>str;  // Palak

     long long int len = strlen(str);
    
     
     char *ch = reverse(str, len);
     cout<<ch<<" ";

     return 0;
}