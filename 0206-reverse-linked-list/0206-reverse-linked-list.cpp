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
    // ListNode* reverseList(ListNode* head) {
        // if( head == nullptr || head->next == nullptr) return head;
        // ListNode *current = head , *nxt = nullptr , *prev = nullptr;
        // while(current != nullptr){
        //     nxt = current->next ;
        //     current->next = prev ;
        //     prev = current ;
        //     current = nxt ;
        // }

        // return prev;

    // }

    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr ) return head ;

        ListNode *reverse = reverseList(head->next);
        ListNode *temp = reverse ;
        while(temp->next != nullptr) temp = temp->next ;
        temp->next = head ;
        head->next = nullptr;
        return reverse;
    }
};