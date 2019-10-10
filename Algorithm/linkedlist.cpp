#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
//code for inserting in front of linked list
void push(Node** head_ref,int data)
{
    //allocating node
    Node* new_node=new Node();
    //inserting data
    new_node->data=data;
    //making next of new node to refer to current head
    new_node->next=*head_ref;
    //no the current head will refer to new node
    *head_ref=new_node;

}
void insertafter(Node* prev_node,int new_data)
{

    //check  if prev node is null
    if(prev_node==NULL)
    {
        cout<<"error";
        return;
    }
    Node* new_node=new Node();
    new_node->data=new_data;
    new_node->next=prev_node->next;
    prev_node->next=new_node;
}
void append(Node** head_ref,int new_data)
{
    Node* new_node=new Node();
    Node* last=*head_ref;
    new_node->data=new_data;
    new_node->next=NULL;
    if(*head_ref==NULL)
    {
        *head_ref=new_node;
        return;
    }
    while(last->next!=NULL)
        last=last->next;
    last->next=new_node;
    return;
}
void print(Node *node)
{

    while(node!=NULL)
    {
        cout<<node->data<<" ";
        node=node->next;
    }
}
int main()
{
     Node* head = NULL;

    // Insert 6. So linked list becomes 6->NULL
    append(&head, 6);

    // Insert 7 at the beginning.
    // So linked list becomes 7->6->NULL
    push(&head, 7);

    // Insert 1 at the beginning.
    // So linked list becomes 1->7->6->NULL
    push(&head, 1);

    // Insert 4 at the end. So
    // linked list becomes 1->7->6->4->NULL
    append(&head, 4);

    // Insert 8, after 7. So linked
    // list becomes 1->7->8->6->4->NULL
    insertafter(head->next, 8);

    cout<<"Created Linked list is: ";
    print(head);

    return 0;
}
