#include<bits/stdc++.h>
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

node* small_val(node* root);
node* insert_node(node* root,int key)
{
    if(root == NULL)
    {
        node* temp = new node(key);
        root = temp;
        return root;
    }
    if(key < root->data)
    {
        root->left = insert_node(root->left,key);
    }
    else
    {
        root->right = insert_node(root->right,key);
    }
     return root;
}
bool search_ele(node* root,int key)
{
    if(root == NULL)
        return false;
    if(key == root->data)
        return true;
    else if(key < root->data)
        return search_ele(root->left,key);
    else
        return search_ele(root->right,key);
}

node* delete_node(node* root,int key)
{
    if(root == NULL)
        return NULL;
    if(key < root->data )
    {
        root->left = delete_node(root->left,key);
    }
    else if(key > root->data)
    {
        root->right = delete_node(root->right,key);
    }
    else
    {
        if(root->left == NULL)
        {
            node* temp = root->right;
            delete(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            node* temp = root->left;
            delete(root);
            return temp;
        }
        else
        {
            node* temp = small_val(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right,temp->data);
        }
    }
    return root;
}

node* small_val(node* root)
{
    node* temp = root;
    while(temp && temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

void preorder(node* root)
{
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int n,data;
    node* root = NULL;
    cout<<"Enter the no. of nodes"<<endl;
    cin>>n;
    cout<<"Enter the nodes element"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<"Enter ["<<i<<"] element: ";
        cin>>data;
        root = insert_node(root,data);
    }
    cout<<"preorder traversing"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"Enter the element for searching"<<endl;
    int key;
    cin>>key;
    bool res = search_ele(root,key);
    if(res)
        cout<<"Required element is present in BST"<<endl;
    else
        cout<<"Required element is not present in BST"<<endl;
    cout<<"Enter the element for deletion"<<endl;
    cin>>key;
    root = delete_node(root,key);
    cout<<"BST after deletion"<<endl;
    preorder(root);
    return 0;
}
