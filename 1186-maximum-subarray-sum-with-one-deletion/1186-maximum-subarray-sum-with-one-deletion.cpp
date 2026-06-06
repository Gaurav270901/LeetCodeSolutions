class Solution {
public:
//prevNodelete
//prevOneDelete
//find max sum with no delete first , 
//for one delete find max between adding that number in one delete or removing that number from nodelete
    int maximumSum(vector<int>& arr) {
        int ans = arr[0] , noDelete = arr[0] , oneDelete = INT_MIN  , n = arr.size() ;
        if(n < 2) return ans ; 
        for(int i = 1 ; i < n ; i++){
            int prevNoDelete = noDelete ; 
            int prevOneDelete = oneDelete ; 
            if(prevOneDelete == INT_MIN) prevOneDelete = 0; // for first element prevOnedelete will be 0 
            noDelete = max(noDelete+arr[i] , arr[i]);
            oneDelete = max(prevNoDelete , prevOneDelete + arr[i]);
            ans = max(ans , max(noDelete , oneDelete));
        }
        return ans;
    }
};