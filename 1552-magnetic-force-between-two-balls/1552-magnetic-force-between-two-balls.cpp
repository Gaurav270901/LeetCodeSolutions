class Solution {
public:
    bool isGuessValid(vector<int>& arr , int m , long long guess){
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
        long long low = 1 , high = position[n-1] - position[0] ;
        int ans = -1 ;
        while(low<=high){
            long long guess = (low + high)/2;
            if(isGuessValid(position , m , guess)){
                ans = guess ;
                low = guess+1 ;
            }else
                high = guess-1 ;
        }
        return ans ;
    }
};