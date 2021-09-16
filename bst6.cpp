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

vector< node *> constructTrees(int start,int end){
    vector<node *> tree;
     if(start>end){
         tree.push_back(null);
         return tree;
     }
    for(int i=0;i<=end;i++){
        vector<node*> leftsubtree=constructTrees(start,i-1);
        vector<node*> rightsubtree=constructTrees(i+1,end);

        for(int j=0;j<leftsubtree.size();j++){
            node* left=leftsubtree[j];
            for(int k=0;k<rightsubtree.size();k++){
                node* right=rightsubtree[k];

                node* n=new node(i);
                n->left=left;
                n->right=right;
                tree.push_back(n);
            }

        }
        
    }

    return tree;
}

void preorder(node* root){
    if(!root) return ;
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}

int main(int argc, char const *argv[])
{
    vector<node*> totaltrees=constructTrees(1,3); // can give start and end points
      for(int i=0;i<totaltrees.size();i++){
          cout<<(i+1)<<" : ";
          preorder(totaltrees[i]);
          cout<<endl;
      }
    return 0;
}
