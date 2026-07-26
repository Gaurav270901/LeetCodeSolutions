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
 //traverse to the left node when you are on left node then start reversing the list for right - left + 1 time , store left-1 node  and right +1 node to for attaching it to the liked list later on
 //as we are need to keep track of previous node to the left , but in case where left = 1 , i.e head, we dont have any previous node so we will add one dummy node in our list that will help us to handle such cases where left = 1 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right) return head ;

        ListNode dummy(0);
        dummy.next = head ;
        ListNode *prevLeft  = &dummy;

        for(int i = 1 ; i < left ; i++){
            prevLeft = prevLeft->next ;
        }
     
        ListNode *curr = prevLeft->next ;
        ListNode *lastNode = curr ;
        ListNode *prev = NULL ; 

        int nodeCount = right - left + 1 ;

        for(int i = 0 ; i < nodeCount ; i++)
        {
            ListNode *nextNode = curr->next ; 
            curr->next = prev ; 
            prev = curr ; 
            curr = nextNode ;
        }

        prevLeft->next  = prev ; 
        lastNode->next = curr ; 
        return dummy.next ;
    }

};