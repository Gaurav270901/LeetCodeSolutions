class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
        int maxCurrentSum = arr[0] , minCurrentSum = arr[0] , n = arr.size() , totalSum = 0  , ans = arr[0];
        for(int a : arr){
            totalSum+=a ;
        }

        for(int i = 1 ; i < n ; i++){
            maxCurrentSum = max(arr[i]+maxCurrentSum , arr[i]);
            minCurrentSum = min(arr[i]+minCurrentSum , arr[i]);
            if(totalSum == minCurrentSum) {
                ans = max(ans , maxCurrentSum);
                continue;
            }
            ans = max(ans , max(maxCurrentSum , totalSum-minCurrentSum));
        }
        return ans;
    }
};