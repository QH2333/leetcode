#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

int main()
{
    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(9);
    ListNode* l2 = new ListNode(1);
    ListNode* result = addTwoNumbers(l1, l2);

	return 0;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* hRet = new ListNode(0);
    ListNode* pRet = hRet;

    bool of = false; // Overflow
    
    while (l1 && l2)
    {
        pRet->next = new ListNode((l1->val + l2->val + of) % 10);
        pRet = pRet->next;
        of = (l1->val + l2->val + of) >= 10;
        l1 = l1->next;
        l2 = l2->next;
    }
    if (l1 || l2)
    {
        ListNode* pRem = l1 ? l1 : l2;
        while (pRem)
        {
            pRet->next = new ListNode((pRem->val + of) % 10);
            pRet = pRet->next;
            of = (pRem->val + of) >= 10;
            pRem = pRem->next;
        }
    }
    if (of) pRet->next = new ListNode(1);

    return hRet->next;
}