#include<iostream>
using namespace std;

class node{
    public:
    int val;
    node*left;
    node*right;

    node(int x):val(x),left(NULL),right(NULL){};
};

int search(int inorder[],int start,int end,int current){
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==current){
            return i;
        }
    }
    return -1;
}

node*buildtree(int postorder[],int inorder[],int start,int end){

            static int idx=4;
            if(start>end){
                return NULL;
            }
            int value=postorder[idx];
            idx--;
            node*curr=new node(value);

            if(start==end){
                    return curr;

            }

            int pos=search(inorder,start,end,value); 

            curr->right=buildtree(postorder,inorder,pos+1,end);
            curr->left=buildtree(postorder,inorder,start,pos-1);

            return curr;


}


  void inorderprint(node * root)
  {
    if(root==NULL) return;

            inorderprint(root->left);
            cout<<root->val<<"__";
            inorderprint(root->right);

  }

int_fast32_t main(){

            int inorder[]={4,2,1,5,3};
            int postorder[]={4,2,5,3,1};

            node* root=buildtree(postorder,inorder,0,4);

            inorderprint(root);

}