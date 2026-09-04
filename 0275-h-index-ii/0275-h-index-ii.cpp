class Solution {
public:
// Since the array is sorted, if we are at index mid,
// then all papers from mid to n-1 have citations >= citations[mid].
//
// papers = n - mid
//
// We are checking:
//
//      citations[mid] >= papers
//
// Example:
// citations = [0,1,3,5,6]
//
// index      0 1 2 3 4
// citations  0 1 3 5 6
// papers     5 4 3 2 1
//
// check:
// 0 >= 5 ? No
// 1 >= 4 ? No
// 3 >= 3 ? Yes
// 5 >= 2 ? Yes
// 6 >= 1 ? Yes
//
// Notice the pattern:
//
//      No  No  No  Yes  Yes
//
// Once the condition becomes true, it will remain true
// for all indices to the right because:
//
// - citations keeps increasing
// - paperCount keeps decreasing
//
// Therefore, we need to find the FIRST index where
// the condition becomes true.
//
// This is a classic binary search on a monotonic condition.
//
// citations[mid] >= papers -> valid, try finding an earlier valid index
// citations[mid] <  papers -> move right
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