public class Solution {
    public int MissingNumber(int[] nums) {
        int sum = 0 ;
        int size = nums.Length ;
        for(int i = 0 ; i < size; i++){
            sum+=nums[i];
        }
        int totalSum =  ((size)*(size+1))/2;
        return totalSum - sum ;
    }
}