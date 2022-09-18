#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;
int prefix(string s)
{
    stack<int> number;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i]>='0' && s[i]<='9')
            number.push(s[i] - '0');
        else
        {
            int operand1 = number.top();
            number.pop();
            int operand2 = number.top();
            number.pop();
            switch (s[i])
            {
            case '+':
                number.push(operand1 + operand2);
                break;
            case '*':
                number.push(operand1 * operand2);
                break;
            case '/':
                number.push(operand1 / operand2);
                break;
            case '-':
                number.push(operand1 - operand2);
                break;
            }
        }
    }
    return number.top();
}
int postfix(string s)
{
    stack<int> number;
    for (int i = 0; i <s.length(); i++)
    {
        if (s[i]>='0' && s[i]<='9')
            number.push(s[i] - '0');
        else
        {
            int operand1 = number.top();
            number.pop();
            int operand2 = number.top();
            number.pop();
            switch (s[i])
            {
            case '+':
                number.push(operand1 + operand2);
                break;
            case '*':
                number.push(operand1 * operand2);
                break;
            case '/':
                number.push(operand1 / operand2);
                break;
            case '-':
                number.push(operand1 - operand2);
                break;
            }
        }
    }
    return number.top();
}
int main()
{
    //-+7*45+20
    string s = "-+7*45+20";
    cout << prefix(s);

    return 0;
}