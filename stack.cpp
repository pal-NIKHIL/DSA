#include <iostream>
using namespace std;
#define n 100
class stack{
    int *arr;
    int top;
    public:
    stack(){
        arr=new int[n];
        top=-1;
    }
    
    void push(int x){
        if(top==n-1){
            cout<<"stack overflow";
            return;
        }
        top++;
        arr[top]=x;
    }
    void pop(){
        if(top==-1){ 
            cout<<"NO eleemnt to pop";
            return;}
        top--;
    }
    void Top(){
        if(top==-1){
            cout<<"empty stack";
            return;}
        cout<<arr[top];
    } 
    bool isempty(){
        return top==-1;
    }

};
int main(){
    stack st;
    st.push(10);
    st.push(3);
    st.push(33);
    st.push(55);
    st.pop();
    st.Top();
    st.pop();
    st.Top();
    st.pop();
    st.pop();
    st.pop();

    
    
}