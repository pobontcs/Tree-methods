#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 
class node{
    public:
    int val;
    node*left;
    node*right;

    node(int x):val(x),left(NULL),right(NULL){};
};


int calcheight(node * root){
    if(root==NULL) return 0;

    int lheight=calcheight(root->left);
    int rheight=calcheight(root->right);

        return max(lheight,rheight)+1;
}
 int calcdiameter(node * root){
            if(root==NULL) return 0;
        int lheight=calcheight(root->left);
    int rheight=calcheight(root->right);
        int currdiameter=lheight+rheight+1;

        int ldiameter=calcdiameter(root->left);
        int rdiameter=calcdiameter(root->right);

        return max(currdiameter,max(ldiameter,rdiameter));
            
 }

int main()
{
node *root= new node(1);
            
            root->left=new node(2);
            root->left->left=new node(4);
            root->left->right=new node(5);
            
            root->right=new node(3);
            root->right->left=new node(6);
            root->right->right= new node(7) ;

            cout<<calcheight(root)<<endl;
            cout<<endl<<calcdiameter(root)<<endl;
return 0;
}