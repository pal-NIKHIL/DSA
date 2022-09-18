#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool isValid(string s) {
        int n=s.size();
        stack <char> a;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                a.push(s[i]);
            }
            else if(!a.empty()){
                if(s[i]==')' && a.top()=='(' ){
                    a.pop();
                }
                else if(s[i]==']' && a.top()=='['){
                    a.pop();
                }
                else if(s[i]=='}' && a.top()=='{'){
                    a.pop();
                }
                else return false;
            }
            else return false;
        }
        if(a.empty()) return true;
        else return false;
    }
int main()
{

    return 0;
}