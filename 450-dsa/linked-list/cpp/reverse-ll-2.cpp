// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

#include<iostream>

using namespace std;

class Node{
     public:
      int data;
      Node *next;
};

class LinkedList{

    public:
       Node *head = NULL;

       void insertAtTail(int val){
            
           Node *newNode  = new Node();

           newNode->data = val;
           newNode->next =  NULL;

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

       void print(Node* head){

           if(head == NULL){
               cout<<"List is empty!";
               return;
           }

           Node *temp = head;

           while(temp != NULL){
               cout<<temp->data<<" ";
               temp = temp->next;
           }

           cout<<endl;
       }

      Node* reverse(Node *head){

          Node *curr = head;
          Node *prev = NULL;
          Node *next;

          while(curr != NULL){
                 next = curr->next;
                 curr->next = prev;
                 prev = curr;
                 curr = next;
          }
          return prev;
      }
};

 


int main(){

     LinkedList obj;

     obj.insertAtTail(2);
     obj.insertAtTail(4);
     obj.insertAtTail(6);
     obj.insertAtTail(8);
     obj.print(obj.head);
     
     Node* rev = obj.reverse(obj.head);
     obj.print(rev);

    

    return 0;
}