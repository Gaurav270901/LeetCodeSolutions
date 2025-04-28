class Solution {
public:

    int first_occ(vector<int> arr , int x){
        int low = 0 ; 
        int high = arr.size()-1 ; 
        int ans = -1 ;
        while(low <= high){
            int mid = (low+high)/2 ; 
            if(arr[mid]==x){
                ans = mid ; 
                high = mid- 1 ; 
            }
            else if(arr[mid] < x){
                low = low+1 ; 
            }
            else {
                high = high- 1; 
            }
        }
        return ans ; 
    }

     int last_occ(vector<int> arr , int x){
        int low = 0 ; 
        int high = arr.size()-1 ; 
        int ans = -1 ;
        while(low <= high){
            int mid = (low+high)/2 ; 
            if(arr[mid]==x){
                ans = mid ; 
                low = mid + 1 ; 
            }
            else if(arr[mid] < x){
                low = low+1 ; 
            }
            else {
                high = high- 1; 
            }
        }
        return ans ; 
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans ; 
        ans.push_back(first_occ(nums , target));
        ans.push_back(last_occ(nums , target));
        return ans ; 
    }
};