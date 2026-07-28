#include <iostream>
using namespace std;
char stack[200];
int top=-1;
void push (char x)
{
    stack[++top]=x;

}
char pop()
{
    return stack[top--];
}
char peek()
{
    return stack[top];
}
int precedence(char op)
{
    if(op=='^')
    return 3;
    if(op=='*'|| op=='/')
    return 2;
    if(op=='+'|| op=='-')
    return 1;
    return 0;
}
int main()
{
    string infix , postfix="";
    cout<<"enter infix operation:";
    cin>>infix;
    for( int i=0; i < infix.length(); i++)
    {
        char ch=infix[i];
        if (isalnum(ch))
        {
            postfix +=ch;
        }
        else if (ch=='(')
        {
            push(ch);
        }
        else if (ch==')')
        {
            while (peek() !='(')
            {
                postfix += pop();
            }
            pop();
        }
        else
        {
            while(top != -1 && precedence (peek())>= precedence(ch))
            {
                postfix +=pop();
            }
            push(ch);
        }
    }
    while (top != -1)
    {
        postfix += pop();

    }
    cout<< "postfix expression:"<< postfix;
    return 0;
}
