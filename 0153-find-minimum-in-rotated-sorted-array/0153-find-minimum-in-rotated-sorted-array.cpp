class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int low = 0 , high = n-1 ;
        while(low < high){
            int mid = (low + high) / 2 ; 
            int num = arr[mid];

            if(num > arr[high])
                low = mid + 1 ; 
            else 
                high = mid ;
        }
        return arr[low] ;      
    }
};