class Solution {
public:
    string reverseWords(string s) {
        string reverse = "";
        string temp = "";
        for(int i = 0 ; i < s.length() ; i++){
            char ch = s[i];
            if(s[i]==' '){
                if(temp!=""){
                    reverse = temp+" "+reverse ; 
                }
                temp = "";
            }
            else{
                temp+=ch;
            }
        }
        
        if(temp!=""){
            reverse = temp+" "+reverse;
        }
        
        if(reverse.length() > 0 && reverse[reverse.length()-1]==' '){
            reverse = reverse.substr(0 , reverse.length()-1);
        }
        return reverse;
    }
};