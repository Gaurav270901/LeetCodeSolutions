class Solution {
public:
    bool isValid(string s) {
        stack<char> st ; 
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '(' || s[i]== '[' || s[i] == '{'){
                st.push(s[i]);
                continue ;
            }
            if(s[i] == ')' && !st.empty() && st.top() == '(')
                {
                    st.pop();
                    continue;
                }
            if(s[i] == '}' && !st.empty() && st.top() == '{')
                {
                    st.pop();
                    continue;
                }
            
            if(s[i] == ']' && !st.empty() && st.top() == '[')
                {
                    st.pop();
                    continue;
                }

                return false;
        }

        if(st.empty()) 
            return true ;
        return false;
    }
};