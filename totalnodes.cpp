#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;

    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};  

int countofallnodes(node *root){
    if(root==NULL){
        return 0;
    }
     return countofallnodes(root->left)+countofallnodes(root->right)+1;
}
int sumofallnode(node*root){
    if(root==NULL)return 0;

    return sumofallnode(root->left)+sumofallnode(root->right)+root->data;
}

int main()
{      node *root= new node(1);
            
            root->left=new node(2);
            root->left->left=new node(4);
            root->left->right=new node(5);
            
            root->right=new node(3);
            root->right->left=new node(6);
            root->right->right= new node(7) ;
            root->right->right->left=new node(8);

            cout<<sumofallnode(root) <<endl;
            cout<<countofallnodes(root) <<endl;

return 0;
}