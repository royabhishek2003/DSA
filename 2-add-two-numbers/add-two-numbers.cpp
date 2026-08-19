class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* newhead = new ListNode(-1);
        ListNode* Head = newhead;
        int carry = 0;
        while (l1 || l2) {
            int add = carry;
            if (l1) {
                add += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                add += l2->val;
                l2 = l2->next;
            }
            int result = add % 10;
            carry = add / 10;
            newhead->next = new ListNode(result);
            newhead = newhead->next;
        }

        if (carry) {
            newhead->next = new ListNode(carry);
        }

        return Head->next;
    }
};