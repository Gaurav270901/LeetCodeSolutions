class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string word = strs[0];
        string ans = "";
        for(int i = 0 ; i < word.size() ; i++){
            for(int j = 0 ; j < strs.size() ; j++){
                if( i < strs[j].size() && word[i]==strs[j][i]){
                    if(j == strs.size()-1){
                        ans += strs[j][i];
                    }
                }
                else return ans ; 
            }
        }
        return ans ;
    }
};