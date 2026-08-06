class Solution {
public:
    int isDayValid(vector<int>& bloomDay , int m , int k , int guess){
        int flower = 0 ; 
        int bouquet = 0 ;
        for(auto day : bloomDay){
            if(day <= guess){
                flower++;
                if(flower == k){
                    bouquet++ ; 
                    flower = 0 ;
                }
            }
            else
                flower = 0 ;
        }
        return bouquet >= m ;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalDays = (long long) m*k ;
        int n = bloomDay.size();

        if(totalDays > n) return -1 ;
        int minDays = INT_MAX , maxDays = 1 ;
        for(auto day : bloomDay){
            minDays = min(day , minDays);
            maxDays = max(day , maxDays);
        }

        int low = minDays , high = maxDays , ans = -1 ;
        while(low <= high){
            int guess = (low + high) / 2 ;

            if(isDayValid(bloomDay , m , k , guess)){
                ans = guess ; 
                high = guess - 1 ;
            }
            else
                low = guess + 1 ;
        }
        return ans;
        
    }
};