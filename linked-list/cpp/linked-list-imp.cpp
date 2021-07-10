

#include <iostream>

using namespace std;

class Node
{

public:
    int data;
    Node *next;
};
class LinkedList
{
public:
    Node *head = NULL;
    int totalNodes = 0;

    void addAtFront(int el)
    {
        

        Node *newNode = new Node(); // Create new Node
        newNode->data = el;
        newNode->next = head;
        head = newNode;
        totalNodes++;
    }

    void addAtTail(int el){

        
       
       Node *newNode = new Node();

       newNode->data = el;
       newNode->next = NULL;

       if(head == NULL){
            addAtFront(el);
            return;
        }

       Node *tail = head;

       while(tail->next != NULL){
           tail = tail->next;
       }

       tail->next = newNode;
       
      
    }
    void addAtPos(int pos, int el){
          Node* newNode = new Node();
          newNode->data = el;
          newNode->next = NULL;
          if(pos == 1){
              
             addAtFront(el);
              return;
          }
          Node* link = head;
          
          
          for(int i=0; i<pos-2; i++){
              link  = link->next;
          }
           
           newNode->next = link->next;
           link->next = newNode;
          

    }

    void displayLinkedList()
    {
         if(head == NULL) {
             cout<<"Linked List is Empty!";
             return;
         }
        Node *temp = head;
        while (temp != NULL)
        {
            int val = temp->data;
            cout << val << " ";
            temp = temp->next;
        }

        cout<<endl;
    }
};

int main()
{

    LinkedList obj;
    obj.addAtFront(2);
    obj.addAtFront(3);
    obj.addAtFront(4);

    obj.displayLinkedList();

    obj.addAtTail(5);
    obj.addAtTail(6);
    obj.addAtTail(7);
    obj.addAtTail(5);
    obj.addAtTail(6);
    obj.addAtTail(7);
    obj.displayLinkedList();

    obj.addAtPos(1,2); //(pos, data)
    obj.addAtPos(2,4);
    obj.addAtPos(3,6);
    obj.addAtPos(4,8);
    obj.addAtPos(3,7);
    obj.displayLinkedList();



    return 0;
}