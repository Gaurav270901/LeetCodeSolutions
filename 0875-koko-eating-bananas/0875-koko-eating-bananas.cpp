class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = 0 ; 
        for(int i = 0 ; i < piles.size(); i++){
            maxPile = max(maxPile , piles[i]);
        }
        if(h == piles.size()) return maxPile;

        int low = 1 , high = maxPile , ans = 0 ;

        while(low <= high){
            int guess = (low + high)/2 ;
            long long hour = calculateHour(piles , guess);

            if(hour > h)
                low = guess + 1 ;
            else {
                ans = guess ; 
                high = guess - 1;
            }
        }
        return ans ;
    }

    long long calculateHour(vector<int>& arr , int hour){
        long long ans = 0 ;
        for(auto i : arr){
           ans += ceil((double)i / (double)hour);
        }
        return ans;
    }
};