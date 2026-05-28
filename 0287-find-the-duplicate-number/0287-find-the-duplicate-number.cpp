class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //use two pointer approact as all elements of array are less than n 
        // and we can say that [1,3,4,2,2] for this 
        // 0 index -> 1 , 1 index -> 3 , 3 index -> 2
        // in short its working like linked list with next node of i is stored at nums[i]  0->1->3->2->4->2 
        //we need to apply the same logic as to find starting point of cycle in LL
        int slow = 0 , fast = 0 ;
        while(true){
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];

            if(slow==fast){
                slow = 0 ;
                while(slow != fast){
                    slow = nums[slow];
                    fast = nums[fast];
                }
                break;
            }

        }
        return fast;
    }
};