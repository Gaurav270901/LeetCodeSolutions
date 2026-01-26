class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& arr) {
        int low = 0 , mid = 0 , high = arr.size()-1;
        if(high == 0) return arr;
        while(mid<=high){
            if(arr[mid]%2==0){
                swap(arr[low] , arr[mid]);
                low++;
                mid++;
            }
            else
            {
                swap(arr[mid],arr[high]);
                high--;
            }
        }
        return arr;
    }
};