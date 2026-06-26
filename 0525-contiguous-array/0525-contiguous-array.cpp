class Solution {
public:
    int findMaxLength(vector<int>& arr) {
        int zero = 0 , one = 0 , ans = 0 ; 
        map<int,int> mp ; 

        for(int i = 0 ; i < arr.size() ; i++){
            arr[i] == 0 ? zero++ : one++ ;
            int diff = one - zero ; 

            if(diff == 0){
                ans = max(ans , i+1);
                continue ;
            }

            if(mp.find(diff) != mp.end()){
                ans = max(ans , i - mp[diff]);
                continue ;
            }

            mp[diff] = i ;
        }
        return ans;
    }
};