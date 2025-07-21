class Solution {
public:
    void helper(string str , vector<string> &ans , int open , int close , int n){
        if(open == n && close == n){
            ans.push_back(str);
            return ;
        }

        if(open < n){
            helper(str+"(",ans,open+1,close,n);
        }

        if(close < open){
            helper(str+")" , ans ,open , close+1 , n);
        }
        return ;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans ;
        helper("" , ans , 0 , 0 , n);
        return ans ;
    }
};