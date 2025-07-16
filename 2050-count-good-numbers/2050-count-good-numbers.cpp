class Solution {
public:

    const long long MOD = 1000000007;
    long long modPow(long long base, long long exp) {
        if (exp == 0) return 1;

        long long half = modPow(base, exp / 2);
        long long halfSquared = (half * half) % MOD;

        if (exp % 2 == 0) {
            return halfSquared;
        } else {
            return (base % MOD * halfSquared) % MOD;
        }
    }
    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;
        long long oddCount = n / 2;

        long long evenWays = modPow(5, evenCount);
        long long oddWays = modPow(4, oddCount);

        return (evenWays * oddWays) % MOD;
    }
};