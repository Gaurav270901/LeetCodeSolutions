class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        long long low = 0 , high = 0 ,result = INT_MAX , n = arr.size() ;
        long long sum = 0 ;
        while(high < n){
            sum += arr[high];
            while(sum >= target && low <= high){
                long long len = high - low + 1 ;
                result = std::min(len , result);
                sum = sum - arr[low];
                low++;
            }
            high++;
        }

        return (result == INT_MAX) ? 0 : result ;
    }
};