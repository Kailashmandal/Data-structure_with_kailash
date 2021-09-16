#include<bits/stdc++.h>
using namespace std;
#define null NULL

//built balanced binary search tree.

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


// built balance BST using sorted array
node* BalanceBST(int arr[], int start ,int end){
    if(start> end){
        return null;
    }
     // calculate the mid of sorted array and make it root node 
    int mid=(start + end)/2;
    node* root= new node(arr[mid]);
   

   // recursively do the same for left and right subtree 
    root->left= BalanceBST(arr, start, mid-1);
    root->right=BalanceBST(arr ,mid+1 ,end);
  // return root of tree
    return root;
}

void preorder(node* root){
    if(root==NULL){
       return;
    }
    cout<<root->data<<" ";
   
    preorder(root->left);
    preorder(root->right);
}
int main(int argc, char const *argv[])
{
    int arr[]={2,4,6,8,10,12};
    node* root=BalanceBST(arr ,0,5);
    
    cout<<"The preorder terversal is : \n";
    preorder(root);
    
    return 0;
}
