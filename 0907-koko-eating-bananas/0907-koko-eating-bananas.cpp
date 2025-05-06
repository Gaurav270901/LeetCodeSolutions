#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxElement = *max_element(piles.begin() , piles.end());
        if(h == piles.size()) return maxElement ;
        int low = 1 , high = maxElement ;
        int ans = INT_MAX;
        int totalCount = 0 ;

        while(low <= high ){
            int mid = (low+high)/2 ;
            double cnt = 0 ;
            for(int pile : piles){
                cnt += ceil((double)pile/(double)mid);
            }
            if(cnt<=h){
                ans = mid , high = mid-1 ; 
            }
            else low = mid+1 ;
        }
        return ans ;
    }
};