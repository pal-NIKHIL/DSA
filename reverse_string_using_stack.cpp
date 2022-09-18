#include<bits/stdc++.h>
using namespace std;
#define ll long long
void insertatbottom(stack<int> &st,int element){
    if(st.empty()){
        st.push(element);
        return;
    }
    int topp=st.top();
    st.pop();
    insertatbottom(st,element);
    st.push(topp);
}
void reverse(stack<int> &st){
    if(st.empty()){
        return;
    }
    int bottom=st.top();
    st.pop();       
    reverse(st);
    insertatbottom(st,bottom);

}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);  
    s.push(4);
    s.push(5);
    reverse(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    
    
}