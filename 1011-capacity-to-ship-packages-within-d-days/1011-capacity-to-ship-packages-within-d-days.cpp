class Solution {
public:

    bool isCapacityValid(vector<int>& weights , int days , int guess){
        int requiredDays = 0 ; 
        int requiredWeight = 0 ;
        for(auto weight : weights){
            if(guess < weight) return false;
            if(weight + requiredWeight > guess){
                requiredDays++;
                requiredWeight = 0 ;
            }
            requiredWeight+=weight ;
        }
        if(requiredWeight <= guess) requiredDays++;
        
        return requiredDays <= days ;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int minWeight = INT_MAX , maxWeight = 1 ; 
        for(auto weight : weights){
            minWeight = min(weight , minWeight);
            maxWeight += weight ;
        }

        int low = minWeight , high = maxWeight , ans = -1;

        while(low <= high){
            int guess = (low + high)/2 ;
            if(isCapacityValid(weights , days , guess)){
                high = guess - 1;
                ans = guess;
            }
            else
                low = guess + 1;

        }
        return ans;
    }
};