#include<bits/stdc++.h>
#include<queue>
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

void inorder(node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

node* createNode()
{
    node* root;
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    if(data == -1)
        return NULL;
    root = new node(data);
    cout<<"Enter the Left of "<<data<<"\n";
    root->left = createNode();
    cout<<"Enter the Right of "<<data<<"\n";
    root->right = createNode();
    return root;
}

void deleteDeepestNode(node* root,node* req_node)
{
    queue<node*> q;
    q.push(root);
    node* temp;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        if(temp == req_node)
        {
           temp = NULL;
           delete(req_node);
           return;
        }
        if(temp->right)
        {
            if(temp->right == req_node)
            {
                temp->right = NULL;
                delete(req_node);
                return;
            }
            else{
                q.push(temp->right);
            }
        }
        if(temp->left)
        {
           if(temp->left == req_node)
            {
                temp->left = NULL;
                delete(req_node);
                return;
            }
            else{
                q.push(temp->left);
            }
        }
    }
}
node* deletion(node* root,int key)
{
    if(root == NULL)
        return NULL;
    if(root->left==NULL && root->right==NULL)
    {
        if(root->data == key)
            return NULL;
        else
            return root;
    }
    queue<node*> q;
    q.push(root);
    node* temp;
    node* node_key = NULL;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        if(temp->data == key)
            node_key = temp;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    if(node_key != NULL)
    {
        int x = temp->data;
        deleteDeepestNode(root,temp);
        node_key->data = x;
    }
    return root;
}
int main()
{
    cout<<"Create the binary tree"<<"\n";
    node* root = createNode();
    cout<<"Tree before deletion"<<"\n";
    inorder(root);
    cout<<"Enter the element to be deleted: ";
    int key;
    cin>>key;
    root = deletion(root,key);
    cout<<"Tree after deletion"<<"\n";
    inorder(root);
    return 0;
}
