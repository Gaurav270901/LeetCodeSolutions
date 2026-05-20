class Solution {
public:
    int characterReplacement(string s, int k) {
        int low = 0 , high = 0 , n = s.size() , ans = INT_MIN ; 
        vector<int> map(256,0);

        while(high < n){
            map[s[high]]++;
            int len = high - low + 1;
            int maxFreq = findMaxFreq(map);
            int diff = len - maxFreq ;

            while(diff > k){
                map[s[low]]--;
                low++;
                len = high - low + 1;
                maxFreq = findMaxFreq(map);
                diff = len - maxFreq ;     
            }

            ans = max(ans , high-low+1);
            high++;

        }
        return ans ;
    }

    int findMaxFreq(vector<int> &arr){
        int count = INT_MIN ; 
        for(int i = 0 ; i < 256 ; i++){
            count = max(count , arr[i]);
        }
        return count ;
    }
};