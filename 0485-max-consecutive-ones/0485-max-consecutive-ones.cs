public class Solution {
    public int FindMaxConsecutiveOnes(int[] nums) {
        int maxOnes = 0 , currentMax = 0 ; 
        for(int i = 0 ; i < nums.Length ; i++){
            if(nums[i] == 1){
                currentMax++;
                if(currentMax > maxOnes){
                    maxOnes = currentMax ;
                }
            }
            else
                currentMax = 0 ;
        }
        return maxOnes;
    }
}