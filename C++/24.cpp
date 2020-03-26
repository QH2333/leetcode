#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode temp(0);
        ListNode* pointer = head;
        ListNode* newHead = &temp;
        ListNode* last = newHead;
        while (pointer && pointer->next)
        {
            ListNode* p1 = pointer;
            ListNode* p2 = pointer->next;
            pointer = p2->next;
            last->next = p2;
            p2->next = p1;
            last = p1;
        }
        last->next = nullptr;
        if (pointer) last->next = pointer;
        return newHead->next;
    }
};

int main()
{
    Solution s;
    return 0;
}