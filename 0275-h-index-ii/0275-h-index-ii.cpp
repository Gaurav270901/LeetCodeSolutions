class Solution {
public:
//optimization to previous solution 
// Since the array is sorted, if we are at index mid,
// then all papers from mid to n-1 have citations >= citations[mid].
//
// papers = n - mid
//
// Compare:
// citations[mid]  vs  papers
//
// citations[mid] == papers -> valid H-index found
// citations[mid] < papers  -> need a larger citation count, move right
// citations[mid]
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0 ; 
        int high = n-1 ;
        int ans = 0 ;
        while(low <= high){
            int guess = (low + high)/2 ;
            int citationsCount = citations[guess] ;

            int paperCount = n - guess ;
            if(citationsCount >= paperCount){
                ans = paperCount ;
                high = guess-1 ;
            }
            else low = guess+1 ;
        }
        return ans;
        
    }
};