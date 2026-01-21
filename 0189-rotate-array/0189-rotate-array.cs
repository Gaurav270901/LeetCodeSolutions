public class Solution {
    public void ReverseArray(int[] nums ,int start , int end){
        int i = start , j = end ; 
        while(i < j ){
            int temp = nums[i];
            nums[i]=nums[j];
            nums[j] = temp ; 
            i++;
            j--;
        }
    }
    public void Rotate(int[] nums, int k) {
        k = k % nums.Length ;
        if(nums.Length == 1) return ;
        ReverseArray(nums , 0 , nums.Length-1);
        ReverseArray(nums , 0 , k-1);
        ReverseArray(nums , k , nums.Length-1);

    }
}