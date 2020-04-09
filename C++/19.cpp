#include <iostream>
#include <vector>
#include <string>

using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* findTail = head;
        for (int i = 0; i < n - 1; i++)
        {
            findTail = findTail->next;
        }
        ListNode* lastN = nullptr;
        while (findTail->next)
        {
            findTail = findTail->next;
            if (!lastN) lastN = head;
            else lastN = lastN->next;
        }
        if (lastN == nullptr)
        {
            auto retVal = head->next;
            delete head;
            return retVal;
        }
        else
        {
            auto temp = lastN->next;
            lastN->next = lastN->next->next;
            delete temp;
            return head;
        }
    }
};

int main()
{
    Solution s;
    return 0;
}