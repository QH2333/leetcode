/*将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode(-1);
        ListNode* temp = ret;
        while(l1 && l2)
        {
            if (l1->val > l2->val)
            {
                temp->next = l2;
                l2 = l2->next;
            }
            else
            {
                temp->next = l1;
                l1 = l1->next;
            }
            temp = temp->next;
        }
        if (l1) temp->next = l1;
        if (l2) temp->next = l2;
        return ret->next;
    }
};

int main()
{
    Solution s;
    return 0;
}
