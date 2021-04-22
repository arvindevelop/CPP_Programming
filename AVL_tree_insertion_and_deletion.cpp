#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    int ht;
};

int BF(node* root);
node* LL(node* root);
node* LR(node* root);
node* RR(node* root);
node* RL(node* root);
node* rotate_right(node* root);
node* rotate_left(node* root);
int height(node* root);
node* delete_node(node* root,int key);
node* small_val(node* root);
void preorder(node* root);

node* insert_node(node* root,int key)
{
    if(root == NULL)
    {
        root = new node();
        root->data = key;
        root->left = root->right = NULL;
    }
    else
    {
        if(key < root->data)
        {
            root->left = insert_node(root->left,key);
            if(BF(root) == 2)
            {
                if(key < root->left->data)
                    root = LL(root);
                else
                    root = LR(root);
            }
        }
        else
        {
            root->right = insert_node(root->right,key);
            if(BF(root) == -2)
            {
                if(key > root->right->data)
                    root = RR(root);
                else
                    root = RL(root);
            }
        }
    }
    root->ht = height(root);
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

node* delete_node(node* root,int key)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(key < root->data )
    {
        root->left = delete_node(root->left,key);
        if(BF(root)==-2)
        {
            if(BF(root->right)<=0)
                root=RR(root);
            else
                root=RL(root);
        }
    }
    else if(key > root->data)
    {
        root->right = delete_node(root->right,key);
        if(BF(root)==2)
        {
             if(BF(root->left)>=0)
                root=LL(root);
             else
                root=LR(root);
        }
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
    root->ht = height(root);
    return root;
}


int main()
{
    int n,x;
    node* root = NULL;
    cout<<"Enter the no. of nodes"<<endl;
    cin>>n;
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    {
       cin>>x;
       root = insert_node(root,x);
    }
    preorder(root);
    cout<<"Enter the elements for deletion"<<"\n";
    int key;
    cin>>key;
    root = delete_node(root,key);
    cout<<"After deletion the AVL is:"<<"\n";
    preorder(root);

    return 0;
}

int height(node* root)
{
    int lh,rh;
    /*if(root == NULL)
        return 0;     */
    if(root->left == NULL)
        lh = 0;
    else
        lh = 1 + root->left->ht;
    if(root->right == NULL)
        rh = 0;
    else
        rh = 1 + root->right->ht;
    if(lh > rh)
        return lh;
    return rh;
}

int BF(node* root)
{
    /*if we wanted to find BF directly then simply we subtract (root->left->ht + 1) - (root->right->ht + 1)
       but we can see that in insert_node function , when we insert node and immediately after that we are finding BF
       that means here height changed but we haven"t update ht variable right now so that,s why again we do the same
       function as we have done in height() function and then finding BF.  */

    int lh,rh;
    /*if(root == NULL)
        return 0 ;    */
    if(root->left == NULL)
        lh = 0;
    else
        lh = 1 + root->left->ht;
    if(root->right == NULL)
        rh = 0;
    else
        rh = 1 + root->right->ht;
    return lh-rh;
}

node* LL(node* root)
{
    root = rotate_right(root);
    return root;
}
node* RR(node* root)
{
    root = rotate_left(root);
    return root;
}
node* LR(node* root)
{
    root->left = rotate_left(root->left);
    root = rotate_right(root);
    return root;
}
node* RL(node* root)
{
    root->right = rotate_right(root->right);
    root = rotate_left(root);
    return root;
}

node* rotate_right(node* root)
{
    node* temp;
    temp = root->left;          // for updating the left link of root we store root->left in temp pointer.
    root->left = temp->right;   //root->data > root->left->right->data so that's why written that step
    temp->right = root;         // rotation takes place
    root->ht = height(root);
    temp->ht = height(temp);
    return temp;
}

node* rotate_left(node* root)
{
    node* temp;
    temp = root->right;         // for updating the right link of root we store root->right in temp pointer.
    root->right = temp->left;   //root->data < root->right->left->data so that's why written that step
    temp->left = root;          // rotation takes place
    root->ht = height(root);
    temp->ht = height(temp);
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

