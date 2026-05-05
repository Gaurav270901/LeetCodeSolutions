class Solution {
public:
    void sortColors(vector<int>& arr) {
        int left = 0 , right = arr.size()-1 , mid = 0 ;
        while(mid <= right){
            if(arr[mid] == 0){
                swap(arr[mid] , arr[left]);
                left++;
                mid++;
            }
            else if(arr[mid] == 2){
                swap(arr[mid] ,arr[right]);
                right--;
            }
            else{
                mid++;
            }
        }
    }
};