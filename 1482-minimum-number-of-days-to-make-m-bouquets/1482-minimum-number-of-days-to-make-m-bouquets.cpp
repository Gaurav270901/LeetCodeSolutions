class Solution {
public:

//we need to find the minimun number of days by which we can make m bouquet so we have to guess the days from lowest to highest and hence we will use binary search here


    bool countBouquet(vector<int>& arr , int m , int k , int guess){
        int flower = 0 ; 
        int bouquet = 0 ;

        for(int i = 0 ; i < arr.size() ; i++){
            if(arr[i] <= guess){
                flower++;
                if(flower == k){
                    bouquet++;
                    flower = 0 ;
                }
            }
            else
                flower = 0 ;
        }

        return bouquet >= m ;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size() ; 
        long long totalFlowers =(long long) m*k;

        if(n < totalFlowers) return -1 ;

        int maxDay = 1 , minDay = INT_MAX; 
        for(int i = 0 ; i < n ; i++){
            maxDay = max(bloomDay[i] , maxDay);
            minDay = min(bloomDay[i] , minDay);
        }

        int low = minDay , high = maxDay , ans = -1 ;

        while(low <= high){
            int guess = (low + high) / 2 ;

            if(countBouquet(bloomDay , m , k , guess)){
                ans = guess;
                high = guess-1 ;
            }
            else
                low = guess + 1 ;
        }
        return ans ;
        
    }
};