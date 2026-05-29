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

    ListNode* reverseLinkedList(ListNode *head){
        ListNode *prev = NULL ;
            while(head != NULL){
                ListNode *nextNode = head->next ;
                head->next = prev ;
                prev = head ;
                head = nextNode ;
            }
            return prev ;
    }
    bool isPalindrome(ListNode* head) {

        if(!head || !head->next) return true ;

        ListNode *slow = head , *fast = head ; 
        while(fast!=NULL && fast->next != NULL){
            slow = slow->next ; 
            fast = fast->next->next;
        }

        ListNode * head1 = reverseLinkedList(slow);
        slow = head ;
        while(head1){
            if(slow->val != head1->val){
                return false ;
            }
            slow = slow ->next ;
            head1 = head1->next ;
        }
        return true ;
    }
};