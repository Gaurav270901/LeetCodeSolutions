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

    void reverse(ListNode *head){
        ListNode *current = head , *prev = nullptr , *nxt = nullptr ;
        while(current != nullptr){
            nxt = current->next ;
            current->next = prev ;
            prev = current ;
            current = nxt ;
        }
        head = prev ;
    }

    ListNode* findKthNode(ListNode *head , int k ){
        ListNode *ptr = head ;
        k = k - 1;
        while(ptr != nullptr && k > 0){
            ptr = ptr->next ;
            k--;
        }
        return ptr ;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *prevLast = nullptr , *temp = head ;

        while(temp != nullptr){
            ListNode *kthNode = findKthNode(temp , k);
            if(kthNode == NULL){
                if(prevLast){
                    prevLast->next = temp;
                }
                break;
            }

            ListNode *nextNode = kthNode->next ;
            kthNode->next = nullptr;
            reverse(temp);

            if(temp == head){
                head = kthNode ;
            }else{
                prevLast->next = kthNode;
            }
            prevLast = temp;
            temp = nextNode ;
        }
        return head;
    }
};