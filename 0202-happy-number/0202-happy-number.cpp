class Solution {
    //we need to find sum of square until sum is one or there is cycle as we need to find cycle here we will use slow and fast pointer approach to find cycle 
    //slow will find square of n digits , while fast will find square of sqaure of sum on n digit , at one point fast , slow will be 1 , or both will be repeating 
public:
    bool isHappy(int n) {
        int slow = n , fast = n ;
        while(fast != 1){
            slow = findPow(slow);
            fast = findPow(findPow(fast));
            if(fast != 1 && slow == fast){
                return false;
            }
        }
        return true;
    }

    int findPow(int n){
        int sum = 0 ; 
        while(n > 0){
            int rem = n % 10 ;
            sum+=(rem*rem);
            n /= 10;
        }
        return sum ;
    }
};