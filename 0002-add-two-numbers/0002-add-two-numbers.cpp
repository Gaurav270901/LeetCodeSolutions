class Solution {
public:
    ListNode* CreateNode(int sum, bool &isCarry) {
        if (sum > 9) {
            sum = sum % 10;
            isCarry = true;
        } else {
            isCarry = false;
        }
        return new ListNode(sum);
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool isCarry = false;
        ListNode *head1 = l1, *head2 = l2;
        ListNode *ans = nullptr, *tail = nullptr;

        while (head1 != nullptr || head2 != nullptr) {
            int val1 = head1 ? head1->val : 0;
            int val2 = head2 ? head2->val : 0;
            int sum = val1 + val2 + (isCarry ? 1 : 0);

            ListNode* newNode = CreateNode(sum, isCarry);

            if (ans == nullptr) {
                ans = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }

            if (head1) head1 = head1->next;
            if (head2) head2 = head2->next;
        }

        if (isCarry) {
            tail->next = new ListNode(1);
        }

        return ans;
    }
};