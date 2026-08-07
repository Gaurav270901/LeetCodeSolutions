class Solution {
public:

    bool isCapacityValid(vector<int>& weights , int days , int guess){
        int currentday = 1  ; 
        int requiredWeight = 0 ;
        for(auto weight : weights){
            if(weight + requiredWeight > guess){
                currentday+=1;
                requiredWeight = weight ;
            }
            else 
                requiredWeight+=weight ;
        }
        
        return currentday <= days ;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int minWeight = INT_MIN , maxWeight = 1 ; 
        for(auto weight : weights){
            minWeight = max(weight , minWeight);
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