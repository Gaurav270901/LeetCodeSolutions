class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0 , high = arr.size()-1 , ans = -1 ;
        while(low <= high ){
          int mid = (low + high)/2 ;
          int num = arr[mid];

          if(num == target) return mid ;

          //mid lies in first part 
          if(num > arr[n-1]){
            if(num < target){
                low = mid + 1 ; 
            }
            else{
                if(arr[0] <= target){
                    high = mid - 1; 
                }
                else
                    low = mid + 1 ;
            }
          }
          else{
            if(num > target){
                high = mid - 1 ;
            }
            else{
                if(arr[n-1] >= target){
                    low = mid + 1 ;
                }
                else
                    high = mid - 1;
            }
          }          
          
        }
        return ans ;
        
    }
};