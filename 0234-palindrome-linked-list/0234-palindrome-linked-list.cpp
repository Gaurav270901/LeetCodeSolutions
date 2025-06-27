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
    bool isPalindrome(ListNode* head) {
        string rev = "" ; 
        ListNode* itr = head ;
        while(itr!=nullptr){
            rev += to_string(itr->val);
            itr=itr->next ;
        }
        string str = rev;
        reverse(rev.begin() , rev.end());
        return rev==str;
        
    }
};