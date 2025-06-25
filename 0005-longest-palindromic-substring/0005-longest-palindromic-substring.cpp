class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 1) return s;

        vector<vector<bool>> dp(n, vector<bool>(n, false)); 

        for(int i = 0 ; i < n ; i++){
            dp[i][i] = true ;
        }

        int ans = 1 , startIndex = 0 ;
        for(int length = 2 ; length <= n ; length++){
            for(int i = 0 ; i <= n - length ; i++){
                int j = i + length - 1;
                if(s[i] == s[j]){
                    if(length == 2){
                        dp[i][j] = true ;
                    }else{
                        dp[i][j] = dp[i+1][j-1];
                    }
                }

                if(dp[i][j] && length > ans){
                    ans = length ;
                    startIndex = i ;
                }
            }
        }

        return s.substr(startIndex, ans);
    }
};
