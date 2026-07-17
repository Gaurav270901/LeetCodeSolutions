class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st ; 
        string folder ;

        for(int i = 0 ; i <= path.size() ; i++){
          if (i == path.size() || path[i] == '/') {

                if (folder == "" || folder == ".") {
                }
                else if (folder == "..") {
                    if (!st.empty())
                        st.pop();
                }
                else {
                    st.push(folder);
                }

                folder.clear();
            }
            else {
                folder += path[i];
            }
        }
        vector<string> temp;

        while (!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }

        reverse(temp.begin(), temp.end());

        string ans;

        for (string &dir : temp) {
            ans += "/" + dir;
        }

        return ans.empty() ? "/" : ans;
    }
};