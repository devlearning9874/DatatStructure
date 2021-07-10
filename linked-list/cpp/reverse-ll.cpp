

#include<iostream>

using namespace std;

class Node{
    public:
      int val;
      Node *next;   
};

class LinkedList{
    public:
      Node *head = NULL;
      
      void insertTail(int data){

          Node *newNode = new Node();
          newNode->val = data;
          newNode->next = NULL;

          if(head == NULL){
              head = newNode;
              return;
          }

          Node *temp = head;

          while(temp->next != NULL){
              temp = temp->next;
          }

          temp->next = newNode;
      }
      
      Node* reverseLL(){

          Node *next;
          Node* current = head;
          Node *prev = NULL;

          while(current != NULL){
             next = current->next;
              current->next = prev;
              prev = current;
              current = next;
          }

          return prev;
        
      }

      void print(){

          if(head == NULL){
              cout<<"List is Empty!"<<endl;
              return;
          }

          Node *temp = head;

          while(temp != NULL){
              int value = temp->val;
              cout<<value<<" ";
              temp = temp->next;
          }

          cout<<endl;
      }

      void printReverse(Node* rev){

          if(rev == NULL){
              cout<<"Empty List!"<<endl;
              return;
          }

          Node *temp = rev;

          while(temp != NULL){
              cout<<temp->val<<" ";
              temp = temp->next;
          }

          cout<<endl;
      }
};
int main(){
    
    LinkedList ll;
    
    ll.print();  // List is empty
    ll.insertTail(5);
    ll.insertTail(10);
    ll.insertTail(15);
    ll.insertTail(20);
    ll.insertTail(25);
    ll.print();
    Node *rev = ll.reverseLL();
    ll.printReverse(rev);

    return 0;
}