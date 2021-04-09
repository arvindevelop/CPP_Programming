#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* insert_node(node* head,int key)
{
    node* temp = new node();
    temp->data = key;
    temp->next = NULL;
    if(head == NULL)
    {
      head = temp;
      return head;
    }
    node* temp1 = head;
    while(temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    return head;
}

void reverse_list(node** head_ref)
{
    node* prev = NULL;
    node* next1 = NULL;
    node* curr = *head_ref;
    while(curr != NULL)
    {
        next1 = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next1;
    }
    *head_ref = prev;
}

void display(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    int n;
    cout<<"Enter the no. of nodes"<<endl;
    cin>>n;
    node* head = NULL;
    int data;
    for(int i=0;i<n;i++)
    {
      cout<<"Enter the data:"<<endl;
      cin>>data;
      head = insert_node(head,data);
    }
    display(head);
    reverse_list(&head);
    display(head);
}
