class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        int size = findLength(head);

        k %= size;
        if (k == 0)
            return head;

        // Step 1: Reverse entire list
        head = reverseList(head, size);

        // Step 2: Reverse first k nodes
        ListNode* curr = head;
        for (int i = 1; i < k; i++)
            curr = curr->next;

        ListNode* rem = curr->next;
        curr->next = nullptr;

        ListNode* firstPart = reverseList(head, k);
        ListNode* secondPart = reverseList(rem, size - k);

        // Step 3: Connect both parts
        ListNode* tail = firstPart;
        while (tail->next)
            tail = tail->next;

        tail->next = secondPart;

        return firstPart;
    }

    int findLength(ListNode* head) {
        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode* reverseList(ListNode* head, int size) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (size--) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
};