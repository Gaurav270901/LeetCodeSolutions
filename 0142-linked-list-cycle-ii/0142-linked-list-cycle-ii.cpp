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
        // ListNode *slow = head , *fast = head;
        // while(fast != nullptr && fast->next != nullptr){
        //     fast = fast->next->next ;
        //     slow = slow->next;
        //     if(fast == slow) {
        //     slow = head ; 
        //         while(slow != fast){
        //             slow = slow->next ;
        //             fast = fast->next ;
        //         }
        //         return slow ;
        //     }
        // }
        // return nullptr;

        //solving it my hashmap

        unordered_map<ListNode* , int> mp ;

        ListNode *ptr = head ;
        while(ptr!=nullptr){
            if(mp.count(ptr)!=0) return ptr ;
            else {
                mp[ptr] = 1;
            }
            ptr = ptr->next;
        }
        return nullptr;
    }
};