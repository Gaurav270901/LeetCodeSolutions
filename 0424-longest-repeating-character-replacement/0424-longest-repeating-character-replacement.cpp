class Solution {
public:
    int characterReplacement(string s, int k) {
        int low = 0 , high = 0 , n = s.size() , ans = INT_MIN ; 
        vector<int> map(26,0);

        while(high < n){
            map[s[high]-'A']++;
            int len = high - low + 1;
            int maxFreq = findMaxFreq(map);
            int diff = len - maxFreq ;

            while(diff > k){
                map[s[low]-'A']--;
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
        for(int i = 0 ; i < 26 ; i++){
            count = max(count , arr[i]);
        }
        return count ;
    }
};