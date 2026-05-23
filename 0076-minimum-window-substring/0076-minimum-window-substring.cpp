class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> freq(256,0);
        int high = 0 , low = 0 , result = INT_MAX , n = s.size() , required = t.size() , start , end ; 

        for(int i = 0 ; i < t.size() ; i++){
            freq[t[i]]++;
        }
        while(high < n ){
           //check if character present in map
           if(freq[s[high]]>0){
            required--;//we got one required character so reduce the number
           }
           //add first value in result , but here we will decrease the freq of map for each character
           freq[s[high]]--;

           //while we get correct ans try to minimize the window by moving low and maintaing required count
           while(required == 0){
            int len = high - low + 1 ; 
            if(len < result){
                start = low ; 
                result = len ;
            }
            freq[s[low]]++;
            if(freq[s[low]] > 0){
                required++;
            }
            low++;
           }
           high++;
        }

        return (result < INT_MAX) ? s.substr(start , result) : "";
    }

    bool allCharPresent(vector<int> sfreq , vector<int> tfreq , string t){
        for(int i = 0 ; i < t.size() ; i++){
            if(sfreq[t[i]]<tfreq[t[i]])
                return false ;
        }
        return true ;
    }
};

  