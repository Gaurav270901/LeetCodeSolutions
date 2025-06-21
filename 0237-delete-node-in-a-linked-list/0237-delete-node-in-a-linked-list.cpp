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
    void deleteNode(ListNode* node) {
        ListNode* current = node ; 
        ListNode* nxt = node->next ;

        while(nxt != NULL){
            if(nxt->next==NULL){
                current->val = nxt->val;
                break;
            }
            current->val = nxt->val;
            current=current->next ;
            nxt = nxt->next;
        } 
        current->next = NULL;
    }
};