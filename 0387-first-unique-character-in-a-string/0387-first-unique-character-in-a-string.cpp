class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> mp(26 , 0) ;
        int maxCount = INT_MIN ;
        char ans ; 

        for(auto i : s){
            mp[i - 'a']++;
        }

        for(int i = 0 ; i < s.size() ; i++){
            if(mp[s[i] - 'a'] == 1)
                return i ;
        }
        return -1 ;
    }
};