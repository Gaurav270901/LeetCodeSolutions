class Solution {
public:
    bool isPileValid(vector<int>& candies , long long k , int guess){
        long long countChildren = 0 ;
        for(auto pile : candies){
            countChildren += (pile/guess);
        }

        return countChildren >= k ;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int maxPile = INT_MIN ;
        for(auto candy : candies){
            maxPile = max(candy , maxPile);
        }

        int low = 1 , high = maxPile , ans = 0 ; 

        while(low <= high){
            int guess = (low + high) / 2 ; 

            if(isPileValid(candies , k , guess)){
                ans = guess ; 
                low = guess + 1 ; 
            }
            else 
                high = guess - 1 ;
        }
        return ans ;
    }
};