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
/* if new node is greater than root than then insert it on right 
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

node* findMax(node* root){
    if(root==null) return null;

    else if(root->right==null) return root;
    // if root right id null then node is founded
    else return findMax(root->right);
}

node* deletion(node* root , int data){
    node* temp;

    // if root is null then we have no element to delete
    if(!root){
        cout<<"nothing for deletion";
        return null;
    }
    else if(data < root->data){
        // then recursively call deletion for left child
        root->left=deletion(root->left, data);

    }
    else if(data > root->data){
        // then recursively calll deletion for the right child
        root->right=deletion(root->right,data);

    }
    else{

        // check if both child is present or not
        if(root->left && root->right){
            // create a temp node maximum of left subtree
            temp=findMax(root); 

            // replace root data with temp data 
            root->data=temp->data;
            // now temp is root call deletion for temp is roots left subtree
             root->left=deletion(root->left, temp->data);
        }
        else{
            // if only one child is present
            temp=root;
            if(root->left){
                root=root->left;
            }

            if(root->right){
                root=root->right;
            }

            // if leaf node or zero child
            delete temp;
        }
       
        
    }
    return root;
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
    
    deletion(root, 4);
    inorder(root);
    
    return 0;
}
