#include<iostream>
#include<vector>
#include<algorithm>

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

bool searchData( Node* root, int data){

    if(root == NULL){
        return false;
    }
    else if(root->data == data){
        return true;
    }
    else if(data <= root->data){
        return searchData(root->left, data);
    }
    else{
        return searchData(root->right, data);
    }
}

int findMin(Node* root){

    if(root == NULL){
        cout<<"Tree is empty \n";
        return -1;
    }
    else if(root->left == NULL){
        return root->data;
    }
    
    return findMin(root->left);
}

int findMax(Node* root){

    if(root == NULL){
        cout<<"Tree is empty \n";
        return -1;
    }
    else if(root->right == NULL){
        return root->data;
    }

   

    return findMax(root->right);
}

int findHeight(Node* root){

    if(root == NULL){
        return -1;
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    // cout<<"Left Height:"<<leftHeight<<"\n";
    // cout<<"Right Height:"<<rightHeight<<"\n";
    return max(leftHeight, rightHeight)+1;
}
// Preorder should be: 15 10 8 12 20 17 25
void preOrder(Node* root){
   
   if(root == NULL){
      return;
   }
   cout<<root->data<<" ";
   preOrder(root->left);
   preOrder(root->right);
}
// Printing inorder sequence: 8 10 12 15 17 20 25
void inOrder(Node* root){

    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

// Printing Post Order: 8 12 10 17 25 20 15

void postOrder(Node* root){

    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
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
     
     cout<<"This is root!"<<root->data<<"\n";

     int val;
     cout<<"Enter data to search in tree \n";
     cin>>val;
     bool result = searchData(root,val);
     cout<<"Result:"<<result<<"\n";
     cout<<"Smallest Number in tree:-"<<findMin(root)<<"\n";
     cout<<"Largest Number in tree:- "<<findMax(root)<<"\n";
     cout<<"Height of Tree:"<<findHeight(root)<<endl;
     
     cout<<"Pre Order:";
     preOrder(root);
     cout<<"\n";
     cout<<"In Order:";
     inOrder(root);
     cout<<"\n";
     cout<<"Post Order:";
     postOrder(root);
     cout<<"\n";
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