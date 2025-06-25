class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="" ; 
        int sum = 0  ;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i]=='('){
                if(sum > 0){
                    ans += s[i];
                }
                sum++;
            }
            else{
                sum--;
                if(sum > 0){
                    ans += s[i];
                }
            }
        }
        return ans ;
       
        
    }
};