class Solution {
public:
    string removeKdigits(string num, int k) {

        stack<char> st;

        for(char digit : num){

            while(!st.empty() &&
                  st.top() > digit &&
                  k > 0){

                st.pop();
                k--;
            }           
             if(st.empty() && digit == '0')
                continue;

            st.push(digit);
        }

        while(!st.empty() && k > 0){
            st.pop();
            k--;
        }

        string ans;

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans.empty() ? "0" : ans;
    }
};