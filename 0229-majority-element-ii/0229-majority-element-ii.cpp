class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //we will take two pointer and two counter 
        //intuation here is there can only maximum two elements exists in array with frequency grerater than n/3
        //then we will follow Moore's voting algorithm
        // Step 1: There can be at most two elements in the array that appear more than n/3 times.
        // So, we track two potential candidates (elm1, elm2) and their counts (cnt1, cnt2).
        vector<int> ans ; 
        int cnt1 = 0 , cnt2 = 0 , elm1 = INT_MIN , elm2 = INT_MIN ; 

        // Step 2: First pass — Find potential candidates using Moore's Voting.
        //If we see the same element again, we increment its counter.
        //If we see a new element and a counter is 0, we replace the candidate.
        //If both counters are non-zero and the number is different, we reduce both counters.
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i]==elm1) cnt1++ ; 
            else if(nums[i]==elm2) cnt2++;
            else if(cnt1 == 0 ){
                elm1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0){
                elm2=nums[i];
                cnt2 = 1 ;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        // Step 3: Second pass — Verify if the candidates appear more than n/3 times.
        cnt1 = cnt2 = 0 ;
        for(int num : nums){
            if(num == elm1) cnt1++;
            if(num == elm2) cnt2++;
        }

        if(cnt1 > nums.size()/3) ans.push_back(elm1);
        if(cnt2 > nums.size()/3) ans.push_back(elm2);


        return ans ; 
    }
};