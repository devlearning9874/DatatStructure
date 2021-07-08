// Four operation of stack are:
// 1. Push 2. Pop 3. Peek or Top 4. isEmpty()
// Time complexity for above operation are O(1).
// Stack Implementaion using array
#include<iostream>
using namespace std;

#define MAX 1000

class Stack{
     
     int top;

     public:
        int a[MAX];

        Stack(){
            top = -1;
        }

        bool push(int x);
        int pop();
        bool isEmpty();
        int peek();
};

bool Stack::push(int x){

    if(top >= (MAX-1)){
        cout<<"Stack Overflow";
        return false;
    }else{
        a[++top] = x;
        cout<<"Pushed into stack"<<endl;
        return true;
    }
}

int Stack::pop(){

    if(top < 0){
        cout<<"Stack Underflow"<<endl;
        return 0;
    }else{
        int x = a[top--];
        return x;
    }
}

bool Stack::isEmpty(){
    return (top<0);
}

int Stack::peek(){
     
     if(top<0){
         cout<<"Stack is Empty!";
         return 0;
     }
     else{
         int x = a[top];
         return x;
     }
}

int main(){
    
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);
    cout<<"Element at top:"<<st.peek()<<endl;
    cout<<"Popped from stack:"<<st.pop()<<endl;

    cout<<"Empty or Not?"<<st.isEmpty()<<endl;
    cout<<"Element at Top:"<<st.peek()<<endl;
    
    return 0;
}