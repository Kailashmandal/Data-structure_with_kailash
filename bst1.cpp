#include<bits/stdc++.h>
using namespace std;
#define null NULL

struct node
{
    int data;
    node* left;
    node * right;
    node(int val){
        data=val;
         left=NULL;
         right=NULL;
    }
    /* data */
};

node* builtBST(node* root , int val){
    if(root==NULL){
        return new node(val);
    }
    if( root->data >val){
       root->left= builtBST(root->left,val);

    }
    else{
        root->right=builtBST(root->right,val);
    }
    return root;
}

void inorder(node * root){
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right); 
}

// searching in BST
bool searchBSTnode(node* root , int key){
    if(root==NULL) return false;
    if(root->data==key) return true;

    if(root->data >key){
     return searchBSTnode(root->left,key);
    }
// if key > root-> data
    return searchBSTnode(root->right , key);
}
int main(int argc, char const *argv[])
{
    node* root=NULL;
    root=builtBST(root,1);
    builtBST(root,2);
    builtBST(root,3);
    builtBST(root,4);
    builtBST(root,5);
    builtBST(root,3);
    builtBST(root,7);
    cout<<"The inorder treversal is :\n";
    inorder(root);
   if(searchBSTnode(root,5)) cout<<"\n5 is present";
   else cout<<"5 is not present";
   //searchBSTnode(root,5);
    return 0;
}

