#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxElement = *max_element(piles.begin() , piles.end());
        if(h == piles.size()) return maxElement ;
        int low = 1 , high = maxElement ,ans = INT_MAX ,totalCount = 0;
        while(low <= high ){
            long long mid = (low+high)/2 , cnt = 0 ;
            for(int pile : piles){
                cnt += pile/mid + (pile % mid ? 1 : 0);
            }
            if(cnt<=h){
                ans = mid , high = mid-1 ; 
            }
            else low = mid+1 ;
        }
        return ans ;
    }
};