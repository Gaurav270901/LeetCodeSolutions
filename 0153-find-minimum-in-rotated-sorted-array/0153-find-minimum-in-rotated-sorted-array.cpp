class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int low = 0 , high = n-1 , ans = 0 ;
        while(low <= high){
            int mid = (low + high) / 2 ; 
            int num = arr[mid];

            if(num > arr[n-1])
                low = mid + 1 ; 
            else {
                ans = arr[mid];
                high = mid-1 ;
            }
        }

        return ans ;      
    }
};