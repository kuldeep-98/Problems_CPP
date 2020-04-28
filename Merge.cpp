#include <iostream>
#include <bits/stdc++.h>
#include "LinkedList.h"
using namespace std;
class Solution
{
    public:
    ListNode* Merge(List *l, List *r)
    {
        ListNode *f = l->getHead();
        ListNode *s = r->getHead();
        ListNode *third;
        ListNode *last;
        if (f == NULL && s != NULL)
            return s;
        else if (f != NULL && s == NULL)
            return f;
        else if (f == NULL && s == NULL)
            return NULL;
        if (f->val < s->val)
        {
            third = last = f;
            f = f->next;
            last->next = NULL;
        }
        else
        {
            third = last = s;
            s = s->next;
            last->next = NULL;
        }
        while (f != NULL && s != NULL)
        {
            if (f->val < s->val)
            {
                last->next = f;
                last = f;
                f = f->next;
                last->next = NULL;
            }
            else
            {
                last->next = s;
                last = s;
                s = s->next;
                last->next = NULL;
            }
        }
        if (f != NULL)
            last->next = f;
        if (s != NULL)
            last->next = s;
        return third;
    }
};

int main()
{
    List l, r;
    Solution s;
    int a[3] = {1, 2, 4};
    int b[3] = {1, 3, 4};
    r.Create(a, 3);
    l.Create(b, 3);
    cout << endl;
    r.Display();
    cout << endl;
    ListNode *t = s.Merge(&l, &r);
    List third(t);
    third.Display();
}