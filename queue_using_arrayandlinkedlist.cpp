#include <iostream>
using namespace std;
//using array
// #define n 20
// class Queue{
//     public:
//     int *arr;
//     int front; 
//     int back;
//     Queue(){
//         arr=new int[n];
//         front=-1;
//         back=-1;
//     }
// void enqueue(int data){
//     if(back==n-1){
//         cout<<"queue is full";
//         return;
//     }
//     back++;
//     arr[back]=data;
//     if(front==-1) front++;
// }
// void dequeue(){
//     if(front==-1 || front>back){ 
//         cout<<"no element in queue";
//         return;}
//     front++;
// }
// int peek(){
//     if(front==-1 || front>back){ 
//         return -1;}
//     return arr[front];
// }
// bool empty(){
//     if(front==-1 || front>back){ 
//         return true;}
//     return false;
// }
// };
// int main(){
//     Queue a;
//     a.enqueue(10);
//     a.enqueue(20);
//     cout<<a.peek();
//     a.dequeue();
//    cout<<a.peek();
//    a.dequeue();
//    a.dequeue();
//    cout<<a.empty();
//    }
class Node{
    public:
    int data;
    Node *next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

class queue{
    Node *front;
    Node *back;
    public:
    queue(){
        front=back=NULL;    
    }
void enqueue(int x){
    Node *newnode=new Node(x);
    if(front==NULL){
        back=newnode;
        front=newnode;
        return;
    }
    back->next=newnode;
    back=newnode;
}
void dequeue(){
    if(front==NULL){
        cout<<"Queue underflow";
        return;
    }
    Node *temp=front;
    front=front->next;
    delete temp;
}
int peek(){
    if(front==NULL){
        cout<<"No element in queue";
        return -1;
    }
    return front->data;
}
bool empty(){
    if(front==NULL){
        return true;
    }
    return false;
}
};
int main(){
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    cout<<q.peek();
}