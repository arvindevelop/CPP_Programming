#include<iostream>
using namespace std;

class node{
 public:
     int data;
     node* left;
     node* right;
     node(int val)
     {
        data = val;
        left = right = NULL;
     }
};

node* preorder(node* root)
{
    if(root == NULL)
    {
        return NULL;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    //cout<<root->data<<" ";
}

node* creatNode()
{
    node* root = NULL;
    int x;
    cout<<"Enter the data"<<"\n";
    cin>>x;
    if(x == -1)
    {
        return NULL;
    }
    root = new node(x);
    cout<<"Enter left for "<<x<<"\n";
    root->left = creatNode();
    cout<<"Enter right for "<<x<<"\n";
    root->right = creatNode();
    return root;
}

int main()
{
    cout<<"Enter nodes for tree"<<"\n";
    node* root = creatNode();
    preorder(root);
    return 0;
}

