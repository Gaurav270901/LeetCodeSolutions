class Solution {
public:
//find the first and last day of blomming flower 
//use binary search and between these range
//travers mid and check if consecutive flowers are blooming at mid day or not and if then check if ther are equat to k and yes then one bouquet will form 
//we need to find minimum days so for that if we get any ans as mid the we will check for value less than mikd
    bool isBouquetValid(vector<int>& bloomDay, int m, int k ,int day){
        int flower = 0 ; 
        int bouquet = 0 ; 
        for(int bloom : bloomDay){
            if(bloom <= day){
                flower++;
                if(flower==k){
                    bouquet++;
                    flower = 0 ;
                }
            }else{
                flower = 0 ;
            }
        }
        return bouquet >= m ;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalFlowersNeeded = (long long)m * k;
        if (bloomDay.size() < totalFlowersNeeded) return -1;

        int left = *min_element(bloomDay.begin() , bloomDay.end());
        int right =  *max_element(bloomDay.begin() , bloomDay.end());

        int ans = -1 ;

        while(left <= right){
            int mid = left+ (right-left)/2;
            if(isBouquetValid(bloomDay , m , k , mid)){
                right = mid-1 ;
                ans = mid ;
            }else{
                left = mid+1 ;
            } 
        }
        return ans ;
        
    }
};