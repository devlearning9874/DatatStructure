// https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

#include<iostream>
#include<unordered_set>

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

      void cyclePoint(Node* head, int k){

           int n = k-2;
             Node* temp = head;

            while(n >  0){
                temp = temp->next;
                n--;
            }
            // return temp->data; data = 8
            // cout<<temp->next<<"\n";
            Node *temp1 = head;
            while(temp1->next != NULL){
                temp1 = temp1->next;
            }
            //   cout<<temp1->next;
            temp1->next = temp->next;

      }

      bool detectLoop(Node *head){

          unordered_set<Node*> s;

          Node* h = head;

          while(h  != NULL){

              if(s.find(h) != s.end()){
                  return true;
              }

              s.insert(h);
              h = h->next;
          }

           return false;
      }
};

 


int main(){

     LinkedList obj;

     obj.insertAtTail(2);
     obj.insertAtTail(4);
     obj.insertAtTail(6);
     obj.insertAtTail(8);
     obj.insertAtTail(9);
     obj.insertAtTail(10);
     obj.print(obj.head);
     
     if(obj.detectLoop(obj.head)){
         cout<<"Yes";
     }else{
         cout<<"No";
     }
     cout<<endl;
     int k;
     cout<<"Enter the cycle point"<<endl;
     cin>>k;
     
     obj.cyclePoint(obj.head, k);

     if(obj.detectLoop(obj.head)){
         cout<<"Yes";
     }else{
         cout<<"No";
     }

    return 0;
}