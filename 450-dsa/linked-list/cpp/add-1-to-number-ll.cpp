// https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

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

       void print(Node* Head){

           if(Head == NULL){
               cout<<"List is empty!";
               return;
           }

           Node *printTemp = Head;

           while(printTemp != NULL){
               cout<<printTemp->data<<" ";
               printTemp = printTemp->next;
           }

           cout<<endl;
       }

       void addOneLL(Node* head){

           int sum = 0;

           Node *temp = head;

           while(temp != NULL){

               sum = sum*10 +(temp->data);
               temp = temp->next;
           }

           cout<<sum+1<<"\n";

       }
};

 


int main(){

     LinkedList obj;
     int val;
     cout<<"Enter number of nodes \n";
     int n;
     cin>>n;
     for(int i=0; i<n; i++){
         cin>>val;
         obj.insertAtTail(val);
     }
     obj.print(obj.head);
     obj.addOneLL(obj.head);

    return 0;
}