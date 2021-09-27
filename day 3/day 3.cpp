#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *head;
void insert(int x,int n)
{
    node* temp = new node();
    temp->data = x;
    temp->next = NULL;
    if(n==1){
        temp->next=head;
        head=temp;
        return;
    }
    node *temp2 = head;
    for(int i=0;i<n-2;i++)
    {
      temp2 = temp2->next;
    }
    temp->next = temp2->next;
    temp2->next = temp;
}
void print()
{
    cout<<"list is:";
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n"<<endl;
}
void delete_end(node *head)
{
    if(head==NULL)
        return;
    if(head->next==NULL)
    {
        delete head;
        return;
    }
    node *curr = head;
    while(curr->next->next!=NULL)
        curr = curr->next;
    delete(curr->next);
    curr->next = NULL;
}
int main()
{
    head = NULL;
    int n,x,sized;
    cout<<"enter the size of linked list:";
    cin>>sized;
    for(int i=0;i<sized;i++)
    {
        cout<<"enter the data:";
        cin>>x;
        cout<<"enter index of linked list:";
        cin>>n;
        insert(x,n);
    }
    cout<<endl;
    print();
    cout<<"After deleting last node ";
    delete_end(head);
    print();
}
