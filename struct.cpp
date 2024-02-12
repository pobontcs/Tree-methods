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

void preorder(node * root){
            if(root==NULL) return;

            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right); 
    /*        1
            /   \
           2     3
          / \   / \
         4   5 6   7
        / \       / \
       8   9    10   11
*/
}

void inorder(node*root){
             if(root==NULL) return;

             inorder(root->left);
             cout<<root->data<<" ";
             inorder(root->right);
    /*        1
            /   \
           2     3
          / \   / \
         4   5 6   7
        / \       / \
       8   9    10   11
*/
}

void postorder(node* root){
    if(root==NULL) return;
    inorder(root->left);
    inorder(root->right);
    cout<<root->data<<" ";

    /*        1
            /   \
           2     3
          / \   / \
         4   5 6   7
        / \       / \
       8   9    10   11
*/


}

int main(){

            node *root= new node(1);
            
            root->left=new node(2);
            root->left->left=new node(4);
            root->left->right=new node(5);
            
            root->right=new node(3);
            root->right->left=new node(6);
            root->right->right= new node(7) ;

            preorder(root);
            cout<<endl;
            inorder(root);
            cout<<endl;
            postorder(root);


            
        return 0;

}