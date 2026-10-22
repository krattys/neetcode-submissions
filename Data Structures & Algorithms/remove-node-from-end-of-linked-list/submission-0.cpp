/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0;
        ListNode* curr = head;
        while (curr) {
            curr = curr -> next;
            sz++;
        }

        if (n == sz) {
            ListNode* tmp = head -> next;
            head -> next = nullptr;
            return tmp;
        }

        curr = head;
        for (int i = 1; i < sz - n; i++) {
            curr = curr -> next;
        }

        ListNode* tmp = curr -> next -> next;
        ListNode* target = curr -> next;
        curr -> next = tmp;
        target -> next = nullptr;
        return head;
    }
};
