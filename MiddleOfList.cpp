#include "LinkedList.h"
#include "iostream"

class Solution{
public:
    ListNode* middleNode(List *l){
        int mid=0;
        ListNode* head = l->getHead();
        if(head!=NULL){
            mid = l->Size()/2;
        }
        for (int i = 0; i <mid; i++)
        {
            head = head->next;
        }
        return head;
    }
};

int main(){
    List l;
    int a[0];
    l.Create(a,0);
    Solution s;
    ListNode *head = s.middleNode(&l);
    List third(head);
    third.Display();
}