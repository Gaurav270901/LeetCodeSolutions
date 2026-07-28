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
 //take first node as left and find right node from it , mark next node to the right node as next left node
 //reverse linkedlist for left to right 
 //after reversal if there is any prevleft node then prevleft->next = right
 //update the prev left to the be the current left prevLeft = left
 //left = nextLeft 
 
 //if right is null that means there is only one node in pair at that time we will do prevLeft->next = left as left is the only node remaining 

 //we will take one one variable as res which will point to the head of the resuled list 
 //for the first node where prevLeft = null we will make res = right ;
 //or if there is any situation where there is only one node in our list at that time we will update res = left
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if(head == NULL) return head ;
        ListNode *left = head ;
        ListNode *res = NULL ; 
        ListNode *right = NULL ;
        ListNode *prevLeft = NULL ; 

        int size = 2 ;
        while(true){
            right = left ;
            for(int i = 0 ; i < size-1 ; i++){
                if(right == NULL) break ; 
                right = right ->next ;
            }

            if(right){
                ListNode *nextLeft = right->next ;
                reverseList(left , 2);
                if(prevLeft)
                    prevLeft ->next = right ;
                if(res == NULL)
                    res = right ;
                prevLeft = left ;
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
        return res;
    }

    void reverseList(ListNode* head , int times){
        ListNode* curr = head ; 
        ListNode* prev = NULL ; 
        while(times--){
            ListNode* nextNode = curr->next ; 
            curr->next = prev ; 
            prev = curr ; 
            curr = nextNode ;
        }
        return ;
    }
};