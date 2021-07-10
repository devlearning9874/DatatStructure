

#include <iostream>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
};

class LinkedList
{

public:
    Node *head = NULL;

    void insertNodeFront(int data)
    {
        Node *newNode = new Node();
        if (head == NULL)
        {
            newNode->val = data;
            newNode->next = NULL;
            head = newNode;
            return;
        }
        newNode->val = data;
        newNode->next = head;
        head = newNode;
    }

    void insertNodeTail(int data)
    {      
          Node *new_node = new Node();
          if(head == NULL){
              insertNodeFront(data);
              return;
          }

          Node *tail = head;

          while(tail->next != NULL){
              tail = tail->next;
          }
          new_node->val = data;
          new_node->next = NULL;
          tail->next = new_node;
    }

    void insertNodePos(int pos,int data)
    {
          Node *newNode = new Node();
          newNode->val = data;
        if(head == NULL){
            insertNodeFront(data);
            return;
        }
        if(pos < 0){
            cout<<"Invalid Position"<<endl;
            return;
        }
        if(pos == 1){
            insertNodeFront(data);
            return;
        }
        pos = pos -2;
        Node *temp = head;
        while(pos > 0){
            temp = temp->next;
            pos--;
        }

        if(temp->next == NULL){
            insertNodeTail(data);
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;

    }

    void deleteNodeFront()
    {

        if (head == NULL)
        {
            cout << "List is Empty!";
            return;
        }

        Node *temp = head;

        head = temp->next;

        free(temp);
    }

    void deleteNodeTail()
    {

        if (head == NULL)
        {
            cout << "List is empty!";
            return;
        }

        Node *temp = head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Node *temp1 = temp->next;
        temp->next = NULL;

        free(temp1);
    }

    void deleteNodePos(int pos){

        if(head == NULL){
            cout<<"List is Empty!";
            return;
        }

        if(pos < 0){
            cout<<"Invalid position";
            return;
        }

        Node* temp = head;
        pos = pos - 2;
        while(pos > 0){
            temp = temp->next;
            pos--;
        }

        if(temp == NULL){
            cout<<"Out of boundary!";
            return;
        }

        if(temp->next == NULL){
            deleteNodeTail();
            return;
        }

        // cout<<temp->val<<"pos elemet";

       Node* temp1 = temp->next->next;

       free(temp->next);

       temp->next = temp1;


    }

    void print()
    {

        if (head == NULL)
        {
            cout << "LL is Empty!" << endl;
            return;
        }

        Node *temp = head;

        while (temp != NULL)
        {
            int value = temp->val;
            cout << value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{

    LinkedList ll;

    ll.insertNodeFront(5);
    ll.insertNodeFront(10);
    ll.insertNodeFront(15);
    ll.insertNodeFront(20);
    ll.insertNodeFront(25);
    ll.insertNodeFront(30);
    ll.print();
    // ll.deleteNodeFront();
    // ll.deleteNodeTail();
    // ll.print();
    ll.deleteNodePos(3);
    ll.print();
    ll.insertNodeTail(65);
    ll.print();
    ll.insertNodePos(3,13);
    ll.print();

    return 0;
}