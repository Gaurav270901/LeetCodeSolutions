class Solution {
public:
    bool isGuessValid(vector<int>& arr , int m , int guess){
        int ballPlaced = 1 ; 
        int pos = 0;
        for(int i = 1 ; i < arr.size() ; i++){
            if(arr[i] - arr[pos] >= guess){
                ballPlaced++;
                pos = i ;
            }
        }
        return ballPlaced >= m ;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size() ;
        sort(position.begin() , position.end());
        int low = 1 , high = position[n-1] - position[0] ;
        int ans = -1 ;
        while(low<=high){
            int guess = (low + high)/2;
            if(isGuessValid(position , m , guess)){
                ans = guess ;
                low = guess+1 ;
            }else
                high = guess-1 ;
        }
        return ans ;
    }
};
// We are binary searching the minimum distance between balls.
//
// For a guessed distance 'd', greedily place balls from left to right.
//
// Always place the next ball at the earliest position whose
// distance from the previously placed ball is at least 'd'.

// If we can place >= m balls, then distance 'd' is feasible.
// We try to maximize it.

// As distance increases, placing balls becomes harder.

// Example:
// d = 1 -> possible
// d = 2 -> possible
// d = 3 -> possible
// d = 4 -> not possible
// d = 5 -> not possible

// Pattern:
// True True True False False
// We need the last valid distance, hence binary search.