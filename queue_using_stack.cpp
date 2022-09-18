#include<bits/stdc++.h>
using namespace std;
class Queue{
    public: 
    stack<int> s1;
    stack<int> s2;
        void enqueue(int val){
            s1.push(val);
        }
    int dequeue(){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int data=s2.top();
        s2.pop();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return data;
    }
     int peek(){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int data=s2.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        } 
        return data;
        
    }
};
int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);  
    cout<<q.peek(); // return 1
    cout<<q.dequeue();
    return 0;
}