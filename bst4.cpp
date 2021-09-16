#include<bits/stdc++.h>
using namespace std;
#define null NULL

// binary search tree building.

// structure of binary search tree 
struct node
{
    /* data */
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

// building the bst .
/* if new node is greater than root  then insert it on right 
  if root is greater than insert  it on left 
   if root is null than create a new node */
node* builtBST(node* root ,int val){

    if(!root){
        return new node(val);
    }

    if(val< root->data){
        root->left=builtBST(root->left,val);
    }else{
        // if val > root->data
        root->right=builtBST(root->right,val);
    }

    return root;
}

void inorder(node* root){
    if(root==NULL){
       return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int findMAX( node* root){
    if(root==null){
        return 0;
    }

    if(root->right==null){
        root->data;
    }

    return findMAX(root->right);
}
int findMIN(node* root){
    if(root==null) return 0;
    if(root->left==null) return root->data;

    return findMAX(root->left);
}
bool isBST( node* root){
  int leftmax=findMAX(root->left); 
  int rightmin=findMIN(root->right);

  return (rightmin>root->data && leftmax <root->data);
}

int main(int argc, char const *argv[])
{
    node * root =NULL;
    root=builtBST(root, 1);
    for (int i = 2; i < 6; i++)
    {
        builtBST(root,i);
        /* code */
    }
    
    if(isBST(root)){
        cout<<"yes it is BST";
    }else cout<<"not valid BST";
    
    return 0;
}
