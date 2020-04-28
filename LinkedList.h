#ifndef LinkedList
#define LinkedList
#include <iostream>
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
    List(ListNode *t){
        head = t;
        end=NULL;
    }
    ListNode* getHead();
    void Create(int A[], int n);
    void InsertLast(int val);
    void Display();
    int Size();
};

ListNode* List::getHead(){
    return head;
}

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

void List::Display(){
    ListNode *temp = this->head;
    while (temp!=NULL)
    {
        cout<<temp->val<<"->";
        temp = temp->next;
    }
}

int List::Size()
{
    ListNode *t = head;
    int count = 0;
    while (t != NULL)
    {
        count++;
        t = t->next;
    }
    return count;
}
#endif