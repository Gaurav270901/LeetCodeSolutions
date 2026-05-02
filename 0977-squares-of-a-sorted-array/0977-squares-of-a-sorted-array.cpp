class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
        int low = 0 , high = arr.size()-1 , ptr = high ;
        vector<int> ans(arr.size());
        while(low <= high){
            int lowSqr = arr[low]*arr[low];
            int highSqr = arr[high]*arr[high];

            if(highSqr >= lowSqr){
                ans[ptr] = highSqr ; 
                high--;
            }
            else{
                ans[ptr] = lowSqr ;
                low++;
            }
            ptr--;
        }
        return ans;
    }
};