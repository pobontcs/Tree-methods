#include<alg.h>
#include<algorithm>
#include<iostream>

using namespace std;

class node{

    public:
        int data;
        node* left;
        node* right;

        node(int val){
                data=val;
                left=NULL;
                right=NULL;      
        }

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
 
 
 
  node * buildTree(int preorder[],
                   int inorder[],
                   int start,int end)
{

    static int idx=0;
    if(start>end){
        return NULL;
    }
            int curr=preorder[idx];
                idx++;//THis increment is for recursion//
            node* root=new node(curr);
        if(start==end){
                return root;
        }

        int pos=search(inorder,start,end,curr);

        root->left=buildTree(preorder,inorder,start,pos-1);
        root->right=buildTree(preorder,inorder,pos+1,end);
        
        return root;


}

  void inorderprint(node * root)
  {
    if(root==NULL) return;

            inorderprint(root->left);
            cout<<root->data<<"__";
            inorderprint(root->right);

  }

int main()
{
  int preorder[]={1,2,4,3,5};
  int inorder[]={1,2,4,3,5};

  node * mail=buildTree(preorder,inorder,0,4);

  inorderprint(mail);

return 0;
}