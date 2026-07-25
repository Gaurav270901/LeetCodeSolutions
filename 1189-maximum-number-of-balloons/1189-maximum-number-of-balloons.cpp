class Solution {
    //the maximun number of balloons words is depend on the frequecy of minumum number of charater present in text 
    // The maximum number of "balloon" words that can be formed  is limited by the character with the smallest  (available frequency / required frequency) ratio.
    //ex. bbbbbbbbbaaaaaaaaaalllllllllllooooooooooonsssssssssssss
    //only one balloon can be make from this becasue only one n is present
    //ex.bbbbbbbbaaaaaaaaalllooooooooooooonnnnnnnnnnnnnnn
    //here also only one balloon is made becasue we need at leaset 2 l for one ballon and currently we have 3 so we can make only one balloon 
    // so we can say that for number of words is depend on freq(minLetterIntext)/freq(requiredForThatLetterInWord) for l => freq present in 3 and required for one word is 2 hence 3/2 = 1 , hence we can make only one word from give text 
    //so store the frequency of required and current in two maps then find the minimun ratio of frequency and that will be the ans;
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> reqFreq ;
        unordered_map<char,int> textFreq ; 
        int maxBalloonCount = INT_MAX; // its the answer but will store the minimun freq / req ration in it

        reqFreq['b'] = 1;
        reqFreq['a'] = 1;
        reqFreq['l'] = 2;
        reqFreq['o'] = 2;
        reqFreq['n'] = 1;

        for(auto i : text){
            textFreq[i]++;
        }

        for(auto mp : reqFreq){
            char letter = mp.first;
            int requiredCount = mp.second;
            int balloonsFromCurrentLetter = textFreq[letter]/requiredCount ;
            maxBalloonCount =  min(maxBalloonCount, balloonsFromCurrentLetter);
        }

        if(maxBalloonCount == INT_MAX) return 0 ;
        return maxBalloonCount ;
        
    }
};