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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head , *fast = head ;
        bool isCyclePresent = false;
        while(fast!= NULL && fast->next != NULL){
            slow = slow->next ; 
            fast=fast->next->next ; 
            if(slow == fast){
                slow = head ; 
                while(slow != fast){
                    slow = slow->next ; 
                    fast = fast->next ; 
                }
                isCyclePresent = true ;
                break;
            }
        }
        return (isCyclePresent)?slow : NULL ;
    }
};