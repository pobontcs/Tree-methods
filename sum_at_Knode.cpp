#include<bits/stdc++.h>
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

int sumatK(node * root, int k){
      if(root==NULL) return 0;

      queue<node*>q;

        q.push(root);
        q.push(NULL);
        int level=0;
        int sum=0;
    while(! q.empty())
    {
        node * head= q.front();
        q.pop();
        if(head!=NULL)
        {
            if(level==k){
                sum+=head->data;
            }
            if(head->left) q.push(head->left);
            if(head->right) q.push(head->right);
        }
        else if(!q.empty())
        {
            q.push(NULL);
            level++;
        }
    }

    return sum;
    

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

            cout<<sumatK(root, 0);

return 0;
}