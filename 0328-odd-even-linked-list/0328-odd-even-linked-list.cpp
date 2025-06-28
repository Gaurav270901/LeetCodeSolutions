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
//keep in mind that we dont want to re-arrange linked list according to odd even data present in linked list , we just need to collect node from odd index and then even index and then link them , dont think that rearranging data , we want to rearrange nodes only
    ListNode* oddEvenList(ListNode* head) {
        //if linked list has 0,1 or 2 nodes only no need to rearrange
        if(!head || !head->next || !head->next->next) return head;

        ListNode *evenHead = head->next , *odd = head , *even = evenHead;
        while(even && even->next){
            //next node to the even will be on odd indices so we are linking it to the oddList
            odd->next = even->next ;
            odd = odd->next ; 

            //same we are doing for even list 
            even->next = odd->next ;
            even = even->next ;
        }
    //at the end link oddhead with even list
        odd->next = evenHead ;
        return head ;
    }
};