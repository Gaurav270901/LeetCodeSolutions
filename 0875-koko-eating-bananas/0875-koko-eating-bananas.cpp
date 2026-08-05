class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxStock = 0 ; 
        for(int i = 0 ; i < piles.size(); i++){
            maxStock = max(maxStock , piles[i]);
        }

        int low = 1 , high = maxStock , ans = 0 ;

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
            if(i <= hour) ans++ ;
            else
                ans += (i + hour - 1) / hour;
        }
        return ans;
    }
};