#include<iostream>
#include<vector>

using namespace std;


class Node{
    public:
     int data;
     Node* left;
     Node* right;
};

Node* getNewNode(int root){
     
        Node* newNode = new Node();

        newNode->data = root;
        newNode->left  = NULL;
        newNode->right  = NULL;

        return newNode;

}

Node* Insert(Node* root , int data){
       
       if(root == NULL){
           root = getNewNode(data);

       }
       else if(data <= root->data){
           root->left = Insert(root->left, data);
       }
       else {
           root->right = Insert(root->right, data);
       }

       return root;
}



int main(){
     
     Node* root = NULL;

     root = Insert(root, 15);
     root = Insert(root, 10);
     root = Insert(root, 20);
     root = Insert(root, 8);
     root = Insert(root, 12);
     root = Insert(root, 17);
     root = Insert(root, 25);
     
     cout<<root->data;
    return 0;
}

        /*
           Binary Tree

                15
              /    \
            10      20
          /  \     /   \
         8   12    17  25
        */