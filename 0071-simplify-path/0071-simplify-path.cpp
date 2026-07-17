class Solution {
public:
//iterate through string store each charater in variable when you encounter / then we get end of current folder , so at then point we need to check if the value stored in folder 
// . -> do nothing 
// .. -> pop from the folder
// empty -> do nothing 
// otherwise folder name must be present in folder so we pushed it in stack 
// if we didnt encounter any / then we will keep on adding the character in folder until we hit string size
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