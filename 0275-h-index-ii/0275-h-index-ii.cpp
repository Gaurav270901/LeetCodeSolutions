class Solution {
public:
//optimization to previous solution 
//as this array is sorted 
//we dont need to iterate through array again and again to check for citation count 
//0 1 3 5 6 
//we guess one index suppose 1 arr[1] = 2 all element after 2 will be greater than 2 , this is obvious 
//and hece number of papers where minimum citations were 2 = arr.size()-i=5-1 = 4 (1 3 5 6)
//if papers > citations , increase citation 
//other wise decrease citation
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0 ; 
        int high = n-1 ;
        while(low <= high){
            int guess = (low + high)/2 ;
            int citationsCount = citations[guess] ;

            int paperCount = n - guess ;
            if(citationsCount == paperCount) return paperCount ;
            if(citationsCount > paperCount){
                high = guess-1 ;
            }
            else low = guess+1 ;
        }
        return n-low ;
        
    }
};