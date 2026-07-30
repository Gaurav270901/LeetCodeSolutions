class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int size = arr.size();
        int low = 0 , high = size-1 , ans = -1 ;
        while(low <= high){
            int mid = (low + high) / 2 ;
            int value = arr[mid] ;
            int nextValue = arr[mid+1];
            if(value > nextValue ){
                ans = mid ;
                high = mid - 1; 
            }
            else 
                low = mid + 1 ;
            
        }
        return ans ;
    }
};