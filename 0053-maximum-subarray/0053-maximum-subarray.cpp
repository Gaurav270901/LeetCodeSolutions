class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n = arr.size();
        if(n < 2) return arr[0];

        int currentSum = arr[0] , ans = arr[0];
        for(int i = 1 ; i < n ; i++){
            currentSum = max(currentSum+arr[i] , arr[i]);
            ans = max(ans , currentSum);
        }
        return ans ;
    }
};