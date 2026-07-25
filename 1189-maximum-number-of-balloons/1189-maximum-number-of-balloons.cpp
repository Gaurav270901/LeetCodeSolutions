class Solution {
    //the maximun number of balloons words is depend on the frequecy of minumum number of charater present in text 
    //ex. bbbbbbbbbaaaaaaaaaalllllllllllooooooooooonsssssssssssss
    //only one balloon can be make from this becasue only one n is present
    //ex.bbbbbbbbaaaaaaaaalllooooooooooooonnnnnnnnnnnnnnn
    //here also only one balloon is made becasue we need at leaset 2 l for one ballon and currently we have 3 so we can make only one balloon 
    // so we can say that for number of words is depend on freq(minLetterIntext)/freq(requiredForThatLetterInWord) for l => freq present in 3 and required for one word is 2 hence 3/2 = 1 , hence we can make only one word from give text 
    //so store the frequency of required and current in two maps then find the minimun ratio of frequency and that will be the ans;
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> srcMap ;
        unordered_map<char,int> txtMap ; 
        int maxBalloons = INT_MAX;

        srcMap['b'] = 1;
        srcMap['a'] = 1;
        srcMap['l'] = 2;
        srcMap['o'] = 2;
        srcMap['n'] = 1;

        for(auto i : text){
            txtMap[i]++;
        }

        for(auto mp : srcMap){
            char letter = mp.first;
            int freq = mp.second;
            int minLetter = txtMap[letter]/freq ;
            if( minLetter < maxBalloons){
                maxBalloons = minLetter ;
            }
        }

        if(maxBalloons == INT_MAX) return 0 ;
        return maxBalloons ;
        
    }
};