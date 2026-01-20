public class Solution {
    public bool Check(int[] nums) {
        int arrayInversionCount = 0 ; 
        if(nums[nums.Length-1] > nums[0])
            arrayInversionCount++;
        for(int i = 0 ; i < nums.Length-1; i++){
            if(nums[i]>nums[i+1]) arrayInversionCount++;
        }
        return (arrayInversionCount > 1) ? false : true ; 
    }
}