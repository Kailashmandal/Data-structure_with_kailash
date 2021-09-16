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

node* LCA(node* root,int n1,int n2){
 if(!root) return null;

 // if both n1 n2 are greter then current root
 if(n1>root->data and n2 >root->data){
     return LCA(root->right,n1,n2);
 }  
 // both are less than current node then lca will lay on left subtree of current node
 else if(n1< root->data and n2< root->data){
     return LCA(root->left,n1,n2);
 }
 else return root; // lca is founded !

}
int main(int argc, char const *argv[])
{
    node * root =NULL;
    root=builtBST(root, 1);
    for (size_t i = 2; i < 9; i++)
    {
        builtBST(root,i);
        /* code */
    }
    
    int lca=LCA(root,2,8)->data;
    cout<<"lca is : "<<lca;
    return 0;
}
