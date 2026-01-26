class Solution {
public:
    void sortColors(vector<int>& arr) {
        if(arr.size() == 1) return ; 
        int low = 0 , high = arr.size()-1,mid=0 ;
        while(mid<=high)
        {
            if(arr[mid]==0){
                swap(arr[mid],arr[low]);
                low++;
                mid++;//as mid will be replaced by the number which is already process we will increatement that pointer to the next index 
            }
        
            else if(arr[mid]==2){
                swap(arr[mid] , arr[high]);
                high--;
            }
            else mid++;
        }
    }
};