class Solution {
public:
//n can be any integer so if we give recurive call to each value of n it will overflow 
// but we know that 2^10 = 2^5* 2^5;
//so instead of giving call to every value of n , we will first calculate value of power n/2 and then multiply it with n/2 to get the result 
    double helper(double x , int n){
        if (n == 0) return 1 ;
        double nextPower = helper(x , n/2);
        if(n % 2 == 0){
            return nextPower*nextPower;
        }
        //if power is 11 then we need to do 2^5*2^5*2
        return x*nextPower*nextPower;
    }
    double myPow(double x, int n) {
       long long N = n; 
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        return helper(x, N);
    }
};