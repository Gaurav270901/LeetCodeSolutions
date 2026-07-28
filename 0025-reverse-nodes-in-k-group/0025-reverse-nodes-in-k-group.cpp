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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* left = head ; 
        ListNode* right = NULL ;
        ListNode* prevLeft = NULL ;
        ListNode* res = NULL ;

        while(true){
            right = left ;
            for(int i = 0 ; i < k-1 ; i++){
                if(right)
                    right = right->next ; 
                else 
                    break;
            }


            if(right){
                ListNode *nextLeft = right->next ; 
                reverseList(left , k);

                if(prevLeft)
                    prevLeft->next = right ; 
                prevLeft = left ; 
                if(!res)
                    res = right ;
                
                left = nextLeft ;
            }
            else{
                if(prevLeft)
                    prevLeft->next = left ;
                if(!res)
                    res = left ;
                break;
            }
        }
        return res ;  
    }

    void reverseList(ListNode* head , int size){
            ListNode *curr = head ; 
            ListNode *prev = NULL ; 

            while(size--){
                ListNode *nextNode = curr->next ; 
                curr->next = prev ; 
                prev = curr ; 
                curr = nextNode;
            }
            return ;
        }
};