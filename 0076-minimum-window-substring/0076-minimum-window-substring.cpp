class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> tfreq(256,0)  , sfreq(256,0);
        int high = 0 , low = 0 , result = INT_MAX , n = s.size() , start ; 
        for(int i = 0 ; i < t.size() ; i++){
            tfreq[t[i]]++;
        }
        while(high < n ){
            sfreq[s[high]]++;
            while(allCharPresent(sfreq , tfreq )){
                int len = high-low+1;
                if(len < result){
                   start = low ;
                   result = len ;
                }
                sfreq[s[low]]--;
                low++;
            }
            high++;
           
        }

        return (result < INT_MAX) ? s.substr(start , result) : "";
    }

    bool allCharPresent(vector<int> sfreq , vector<int> tfreq ){
        for(int i = 0 ; i < 256 ; i++){
            if(sfreq[i] < tfreq[i]  )
                return false;
        }
        return true ;
    }
};

  