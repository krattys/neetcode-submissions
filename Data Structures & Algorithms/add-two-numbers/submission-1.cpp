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
    void addTwoDigits(ListNode* l1, ListNode* l2, ListNode* resCurr,  int &carry) {
        int sum = 0;

        if (l1) {
            sum += l1 -> val;
        }
        if (l2) {
            sum += l2 -> val;
        }
        sum += carry;

        int nxtDigit = sum % 10;
        carry = sum / 10;
        ListNode* resNxt = new ListNode(nxtDigit);
        resCurr -> next = resNxt;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* resHead = new ListNode();
        ListNode* resCurr = resHead;
        int carry = 0;
        while (l1 && l2) {
            addTwoDigits(l1, l2, resCurr, carry);

            l1 = l1 -> next;
            l2 = l2 -> next;
            resCurr = resCurr -> next;
        }

        while (l1) {
            addTwoDigits(l1, l2, resCurr, carry);

            l1 = l1 -> next;
            resCurr = resCurr -> next;
        }

        while (l2) {
            addTwoDigits(l1, l2, resCurr, carry);

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
