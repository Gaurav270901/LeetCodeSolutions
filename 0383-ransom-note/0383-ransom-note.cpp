class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char , int >  noteFreq ; 
        unordered_map<char , int >  magFreq ;

        for(auto i : ransomNote){
            noteFreq[i]++;
        }
        for(auto i : magazine){
            magFreq[i]++;
        }

        for(auto i : noteFreq){
            int reqChar = i.first ;
            int reqFreq = i.second ; 
            int currentFreq = magFreq[reqChar];

            if(currentFreq < reqFreq)
                return false;

        }
        return true ;
    }
};