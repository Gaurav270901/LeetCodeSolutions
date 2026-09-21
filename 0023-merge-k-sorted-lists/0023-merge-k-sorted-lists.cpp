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
 //create min heap with node 
 //insert head of k list 
 //head with least value will come first 
 //add that in our ans if head->next != null then move that head to next element after popping the current top element




class Solution {
public:

    struct cmp{
        bool operator()(ListNode* node1 , ListNode* node2){
            return node1->val > node2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = NULL;
        ListNode* head = ans ; 
        ListNode* last = ans ;

        priority_queue<ListNode* , vector<ListNode*> ,cmp> heap ;

        for(auto node : lists){
            if(node) heap.push(node);
        }


        while(!heap.empty()){
            ListNode* current = heap.top();
            heap.pop();
            if(head == NULL) {
                head = current ; 
                last = current ;
            }else{
                last->next = current ; 
                last = current ;
            }

           if(current->next){
                heap.push(current->next);
            }

        }
        return head ;
    }
};