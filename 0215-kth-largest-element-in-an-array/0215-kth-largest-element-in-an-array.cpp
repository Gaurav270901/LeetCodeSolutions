class Solution {
public:

// Use a min-heap of size k.
//
// Why min-heap?
// The kth largest element is the smallest element among
// the k largest elements in the array.
//
// By continuously removing the smallest element whenever
// the heap size exceeds k, we ensure that only the k
// largest elements remain in the heap.
//
// Hence, heap.top() gives the kth largest element.
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