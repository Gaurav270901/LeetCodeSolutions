class Solution {
public:

    int findNext(vector<int>& arr , int num){
        int n = arr.size() ; 
        return ((num+arr[num])%n+n)%n;
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i]==0) continue ;
            int slow = i , fast = i ; 
                bool forward = nums[i] > 0 ;
            while(true){
                int nextSlow = findNext(nums , slow);
                int nextFast = findNext(nums , fast);
                int nextFast1 = findNext(nums , nextFast);

                if((nums[nextSlow] > 0) != forward ||
                    (nums[nextFast] > 0) != forward ||
                    (nums[nextFast1] > 0) != forward ) break;

                slow = nextSlow ; 
                fast = nextFast1 ;

                if(slow == fast){
                    if(slow == findNext(nums , slow)){
                        break;
                    }

                    return true ;
                }
            }

            int curr = i ;
            while(nums[curr] > 0 == forward){
                int next = findNext(nums ,curr);
                if(next == curr)
                {
                    nums[curr] = 0;
                    break;
                }
                nums[curr] = 0 ;
                curr = next ; 
            }
        }
        return false ;
           
    }
};