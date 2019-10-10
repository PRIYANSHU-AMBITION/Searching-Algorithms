#include<bits/stdc++.h>
using namespace std;
struct linkedlist{
int data;
struct linkedlist* next;
};
linkedlist* push(linkedlist* head,int data)
{
    struct linkedlist* new_node=new linkedlist();
    new_node->data=data;
    if(head==NULL)
    {
        head=new_node;
        return head;
    }
    else
    {
        new_node->next=head;
        head=new_node;
        return head;
    }
}
linkedlist* anypos(linkedlist* head,int data,int position)
{
    //0 based index
    struct linkedlist* new_node=new linkedlist();
    new_node->data=data;
    struct linkedlist* curr=head;
    struct linkedlist* prev;
    struct linkedlist* nextnode=head;
    int count=0;
    if(position==0)
    {
        head=push(head,data);
        return head;
    }
    while(curr!=NULL)
    {
        if(count==position)
        {
            nextnode=prev->next;
            prev->next=new_node;
            new_node->next=nextnode;
            return head;
        }
        count++;
        prev=curr;
        curr=curr->next;
    }
    if(curr->next==NULL)
    {
        cout<<"invalid";
        return head;
    }
}
linkedlist* append(linkedlist* head,int data)
{
    struct linkedlist* new_node=new linkedlist();
    struct linkedlist* curr=head;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=new_node;
    new_node->data=data;
    return head;
}
linkedlist* delhead(linkedlist* head)
{
    struct linkedlist* temp=head;
    //temp=head;
    head=head->next;
    temp->next=NULL;
    free(temp);
    return head;
}

int main()
{
    struct linkedlist* head=NULL;
    head=push(head,10);
    head=push(head,20);
    head=anypos(head,40,0);
    head=anypos(head,80,1);
    head=anypos(head,6,3);
    head=append(head,100);
    head=delhead(head);
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
