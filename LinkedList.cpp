#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL) {}
};

class List
{
private:
    ListNode *head;
    ListNode *end;
public:
    List(){
        head = NULL;
        end = NULL;
    };
    void Create(int A[], int n);
    void InsertLast(int val);
    void Display();
};

void List::Create(int A[],int n)
{
    ListNode *temp;
    this->head = new ListNode(A[0]);
    this->end = this->head;
    for (int i = 1; i < n; i++)
    {
        temp = new ListNode(A[i]);
        this->end->next = temp;
        this->end = temp;
    } 
}

void List::InsertLast(int val){
    ListNode *temp = new ListNode(val);
    if (this->head==NULL)
    {
        this->head=this->end=temp;
    }else
    {
        this->end->next = temp;
        this->end = temp;
    }
}

void List::Display(){
    ListNode *temp = this->head;
    while (temp!=NULL)
    {
        cout<<temp->val<<"->";
        temp = temp->next;
    }
}

int main(){
    List l;
    int a[4] = {1,2,3,4};
    l.Create(a,4);
    // l.InsertLast(1);
    // l.InsertLast(2);
    // l.InsertLast(3);
    // l.InsertLast(4);
    l.Display();
}