class Solution {
public:

//if we use min heap in this example then we need to find which is the smallest element in the group of k element and whenever we encounter larger element in our traversal we will add that in our heap while maintaining the size of k , hence popping top element
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq ;
        int n = nums.size();
        for(auto num : nums){
            pq.push(num);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};