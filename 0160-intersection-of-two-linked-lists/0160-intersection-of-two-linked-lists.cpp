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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode* , int> mp ;
        ListNode *itr = headA ;
        while(itr != nullptr){
            mp[itr] = 1;
            itr = itr->next ;
        }

        itr = headB ; 
        while(itr != nullptr){
            if(mp.count(itr) > 0){
                return itr ;
            }
            itr = itr->next ;
        }
        return nullptr;
    }
};