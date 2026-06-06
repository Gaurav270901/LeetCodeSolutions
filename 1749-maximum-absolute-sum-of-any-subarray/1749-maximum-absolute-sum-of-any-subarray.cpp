class Solution {
public:
    int maxAbsoluteSum(vector<int>& arr) {
        int n = arr.size() , currentMaxSum = arr[0] , currentMinSum = arr[0] , ans = arr[0];
        for(int i = 1 ; i < n ; i++){
            currentMaxSum = max(currentMaxSum+arr[i] , arr[i]);
            currentMinSum = min(currentMinSum+arr[i] , arr[i]);
            ans = max(ans , max(abs(currentMinSum),currentMaxSum));
        }
        return abs(ans);
    }
};