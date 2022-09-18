#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
void insertathead(Node *&head,int data){
        Node *node=new Node(data);
        node->next=head;
        if(head!=NULL){
        head->prev=node;
        }
        head=node;
}
void insertattail(Node *&head,int data){
    if(head==NULL){
        insertathead(head,data);
        return;
    }
    Node *temp=head;
    Node *newnode=new Node(data);
    while(temp->next!=NULL) temp=temp->next;
    temp->next=newnode;
    newnode->prev=temp;
}
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}
void deleteathead(Node *&head){
    Node *todelete=head;
    head=head->next;
    head->prev=NULL;
    delete todelete;
}
void deletion(Node *&head,int pos){
    if(pos==1){
        deleteathead(head);
    }
    Node *temp=head;
    while(pos--){
        temp=temp->next;
    }   
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    delete temp;
}
void print_double(Node *head){
    while(head->next!=NULL){
        head=head->next;
    }
    Node *temp=head;
    while (temp!=NULL)
    {
       cout<<temp->data<<"->";
       temp=temp->prev;
    }
    cout<<"NULL"<<endl;
    
}

int main(){
    Node *head = NULL;
    insertattail(head, 1);
    insertattail(head, 3);
    insertattail(head, 2);
    insertattail(head, 9);
    insertattail(head, 11);
    insertattail(head, 100);
    print(head);
    print_double(head);
    deletion(head,3);
    print(head);
}