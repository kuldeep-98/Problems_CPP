#include <iostream>
using namespace std;

class Node
{
public:
    char val;
    Node *next;
    Node(char val) : val(val), next(NULL) {}
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    void Push(char val);
    char Pop();
    char Peek();
    int Size();
    void Display();
};

void Stack::Push(char val)
{
    Node *t = new Node(val);
    t->next = top;
    top = t;
}

char Stack::Pop()
{
    char val;
    if (top == NULL)
    {
        return '0';
    }
    val = top->val;
    top = top->next;
    return val;
}

char Stack::Peek()
{
    if (top==NULL)
    {
        return '0';
    }
    
    return top->val;
}

int Stack::Size()
{
    Node *t = top;
    int count = 0;
    while (t != NULL)
    {
        count++;
        t = t->next;
    }
    return count;
}

void Stack::Display(){
    Node *t = top;
    while (t!=NULL)
    {
        cout<<t->val<<endl;
        t = t->next;
    }
}

class Solution{
    Stack s;
public:
    bool ValidParentheses(string str){
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str.at(i);
            if(ch=='{'||ch=='['||ch=='('){
                s.Push(ch);
            }else
            {
                switch (ch)
                {
                case '}':
                    if (s.Pop()!='{')
                        return 0;
                    break;
                case ']':
                    if (s.Pop()!='[')
                        return 0;
                    break;
                case ')':
                    if (s.Pop()!='(')
                        return 0;
                    break;
                default:
                    return 0;
                }
            }
        }
        if (s.Size()==0)
        {
            return 1;
        }
        return 0;
    }
};

int main(){
    Solution sol;
    cout<<sol.ValidParentheses("{{}{}(()}");
}