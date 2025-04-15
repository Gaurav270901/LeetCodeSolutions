class Solution {
public:
     void reverse(vector<int>& nums , int start , int end){
        while(start<=end){
            int temp = nums[start];
            nums[start]=nums[end];
            nums[end]=temp ; 
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
       int size = nums.size();
       k = k % size ; 
       if(size==1) return ; 

       reverse(nums , 0 , size-1); //reverse whole array 

       reverse(nums , 0 , k-1);//reverse first k element 

       reverse(nums , k , size-1); //reverse next element till last element
    }
};