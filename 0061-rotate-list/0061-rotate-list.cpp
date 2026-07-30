class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        ListNode *last = head ; 
        int size = 1 ; 
        while(last->next){
            size++;
            last = last->next;
        }

        k %= size;
        if (k == 0)
            return head;

        int count = 1 ; 
        ListNode *t = head ; 
        while(t){
            if(count == (size-k)){
                break;
            }
            count++;
            t = t->next ;
        }

        last->next = head ;
        ListNode *result = t->next ;
        t->next = NULL;       

        return result;
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