#include<bits/stdc++.h>
using namespace std;
class Stack{
queue <int> q1,q2;
public:
void push(int data){
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    q1.push(data);
    while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }
}
int pop(){
    int data=q1.front();
    q1.pop();
    return data;
}
};
int main()
{   Stack s;
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<s.pop();

    return 0;
}