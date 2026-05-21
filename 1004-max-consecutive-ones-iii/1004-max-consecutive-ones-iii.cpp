class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low = 0 , high = 0 , ans = INT_MIN , n = nums.size();  
        vector<int> map(2 , 0); 

        while(high < n){
            map[nums[high]]++;

            while(map[0] > k){
                map[nums[low]]--;
                low++;
            }

            ans = max(ans , high-low+1);

            high++;
        }
        return ans ;
        
    }
};