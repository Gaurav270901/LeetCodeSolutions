class Solution {
public:
     int maximumSum(vector<int>& arr) {
        int ans = arr[0] , noDelete = arr[0] , oneDelete = 0  , n = arr.size() ;
        if(n < 2) return ans ; 
        for(int i = 1 ; i < n ; i++){
            int prevNoDelete = noDelete ; 
            int prevOneDelete = oneDelete ; 
            noDelete = max(noDelete+arr[i] , arr[i]);
            oneDelete = max(prevNoDelete , prevOneDelete + arr[i]);
            ans = max(ans , max(noDelete , oneDelete));
        }
        return ans;
    }
};