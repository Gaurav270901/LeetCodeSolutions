class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
        sort(arr.begin() , arr.end());
        int minDiff = INT_MAX , n = arr.size();
        int ans = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            int low = i+1 , high = n-1 ; 
            while(low < high){
                int sum = arr[i]+arr[low]+arr[high];
                int diff = abs(sum - target);
                if(sum == target) return sum;
                else if(sum < target){
                    if(minDiff > diff){
                        minDiff = diff;
                        ans = sum;
                    }
                    low++;
                }
                else{
                    if(minDiff > diff){
                        minDiff = diff;
                        ans = sum;
                    }
                    high--;
                }
            }
        }
        return ans;
        
    }
};