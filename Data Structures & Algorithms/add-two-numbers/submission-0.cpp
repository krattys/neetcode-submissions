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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* resHead = new ListNode();
        ListNode* resCurr = resHead;
        int carry = 0;
        while (l1 && l2) {
            int val = l1 -> val + l2 -> val + carry;
            int nxtDigit = val % 10;
            carry = val / 10;

            ListNode* resNxt = new ListNode(nxtDigit);
            resCurr -> next = resNxt;

            l1 = l1 -> next;
            l2 = l2 -> next;
            resCurr = resCurr -> next;
        }

        while (l1) {
            int val = l1 -> val + carry;
            int nxtDigit = val % 10;
            carry = val / 10;

            ListNode* resNxt = new ListNode(nxtDigit);
            resCurr -> next = resNxt;

            l1 = l1 -> next;
            resCurr = resCurr -> next;
        }

        while (l2) {
            int val = l2 -> val + carry;
            int nxtDigit = val % 10;
            carry = val / 10;

            ListNode* resNxt = new ListNode(nxtDigit);
            resCurr -> next = resNxt;

            l2 = l2 -> next;
            resCurr = resCurr -> next;
        }

        if (carry) {
            ListNode* final = new ListNode(carry);
            resCurr -> next = final;
        }

        return resHead -> next;
    }
};
