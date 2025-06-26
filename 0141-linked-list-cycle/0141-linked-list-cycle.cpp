/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        if(head->next == head) return true ;
        ListNode *slow = head , *fast = head->next ;
        while(fast != nullptr && fast->next != nullptr){
            if(fast->next == slow) return true ;

            fast = fast->next->next ;
            slow = slow->next;
        }
        return false;
    }
};