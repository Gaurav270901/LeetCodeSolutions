class Solution {
public:
    int majorityElement(vector<int>& nums) {

        //store <elements , freqency > in map and you wil get the ans :)
        unordered_map < int , int > map ; 
        int output = 0 ; 
        int majFactor = nums.size()/2;

        for(int i = 0 ; i < nums.size() ; i++){
            if(map.count(nums[i])){
                map[nums[i]]++;
            }else {
                map[nums[i]]=1 ;
            }
        }

        for(int num : nums){
            if(map[num] > majFactor && map[num] > output){
                output = num;
            }
        }
        return output ; 
    }
};