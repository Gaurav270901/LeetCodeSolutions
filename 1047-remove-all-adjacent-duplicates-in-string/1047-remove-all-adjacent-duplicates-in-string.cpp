class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st ; 
        string ans = "";
        for(int i = 0 ; i < s.size() ; i++){
            
            if(st.size() != 0 && st.top() == s[i]){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        while(st.size() != 0){
            char c = st.top();
            ans = c + ans ;
            st.pop();
        }
        return ans ;
    }
};