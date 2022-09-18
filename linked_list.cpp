#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
void insert_at_head(Node *&head, int val)
{
    Node *newnode = new Node(val);
    newnode->next = head;
    head = newnode;
}
void insert_at_tail(Node *&head, int val)
{
    Node *newnode = new Node(val);
    /*newnode->data=val; //This is same as /    Node(int value)
     newnode->next=NULL;                        {
                                                data = value;
                                                next = NULL;
                                                }
      */
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
void delete_at_head(Node *&head)
{
    Node *delete_node = head;
    head = head->next;
    delete delete_node;
}
void deletion(Node *&head, int k)
{
    if (head == NULL)
        cout << "NO element to delete";
        return;
    if (head->next == NULL) //only for 1 element
        delete head;
        return;
    Node *temp = head;
    while (--k)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
}
void reverse(Node *&head){
        Node *prev=NULL;
        Node *curr=head;
        Node *next_=curr->next;
    while(curr!=NULL){
        next_=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next_; 
    }
    head=prev;
    
}
Node *reverse_a(Node *&head){
        Node *prev=NULL;
        Node *curr=head;
        Node *next_=curr->next;
    while(curr!=NULL){
        next_=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next_; 
    }
    head=prev;
    return prev;
    
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
Node* mid(Node *head){
    Node *slow=head;
    Node *fast=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
bool palindrome(Node *head){
        if(head==NULL){
            return true;
        }
        Node *middle=mid(head);
        Node *last=reverse_a(middle);
        print(last);
        Node *curr=head;
        while(last!=NULL){
            if(curr->data!=last->data) return false;
            curr=curr->next;
            last=last->next;
        }
        return true;
}
bool hasCycle(Node *head) {
        Node *slow=head;
        Node *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(slow->data==fast->data){
                return true;
            }
        }
        return false;
    }
// int main()
// {
//     Node *head = NULL;
//     insert_at_tail(head, 1);
//     insert_at_tail(head, 3);
//     insert_at_tail(head, 2);
//     insert_at_tail(head, 5);
//     insert_at_tail(head, 3);
//     insert_at_tail(head, 1);
//     print(head);
//     palindrome(head)?cout<<"palindrome":cout<<"NOt palindrome";
//     return 0;
// }
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    insert_at_tail(head, 20);
    insert_at_tail(head, 4);
    insert_at_tail(head, 15);
    insert_at_tail(head, 10);
 
    /* Create a loop for testing */
    // head->next->next->next->next = head;
 
    if (hasCycle(head))
        cout << "Loop found";
    else
        cout << "No Loop";
 
    return 0;
}