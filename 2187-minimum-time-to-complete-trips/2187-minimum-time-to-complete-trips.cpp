class Solution {
public:
    bool isGuessValid(vector<int>& time , int totalTrips , long long guess){
        long long count = 0 ; 
        for(auto t : time ){
            count += (guess/t);
        }
        return count >= totalTrips ;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(),time.end());
        long long low = 1 ;
        int n = time.size() ; 
        long long high = 1ll * time[0] * totalTrips  ;
        long long ans = -1 ;

        while(low <= high){
            long long guess = (low + high)/ 2ll ;
            if(isGuessValid(time , totalTrips , guess)){
                ans = guess ; 
                high = guess-1;
            }
            else
                low = guess + 1 ;
                
        }
        return ans ;
    }
};