class Solution {
public:

    // Checks whether it is possible to make at least 'm' bouquets
    // if we wait until 'guess' number of days.
    bool isDayValid(vector<int>& bloomDay, int m, int k, int guess) {

        int flower = 0;   // Count consecutive bloomed flowers
        int bouquet = 0;  // Number of bouquets formed

        for (auto day : bloomDay) {

            // Flower has bloomed by 'guess' day
            if (day <= guess) {
                flower++;

                // If we collected k consecutive flowers,
                // we can form one bouquet
                if (flower == k) {
                    bouquet++;
                    flower = 0; // Reset because flowers cannot be reused
                }
            }
            else {
                // Consecutive sequence breaks
                // because this flower has not bloomed yet
                flower = 0;
            }
        }

        // Return true if we can make at least m bouquets
        return bouquet >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        // Total flowers required to make m bouquets
        long long totalFlowersNeeded = 1LL * m * k;

        int n = bloomDay.size();

        // Not enough flowers available
        if (totalFlowersNeeded > n)
            return -1;

        // Find search space for binary search
        // Minimum possible answer = earliest bloom day
        // Maximum possible answer = latest bloom day
        int minDay = INT_MAX;
        int maxDay = 1;

        for (auto day : bloomDay) {
            minDay = min(day, minDay);
            maxDay = max(day, maxDay);
        }

        int low = minDay;
        int high = maxDay;
        int ans = -1;

        /*
            Binary Search on Answer

            Observation:
            If it is possible to make m bouquets on day X,
            then it is also possible on every day > X.

            Thus answer space is monotonic:

            F F F F T T T T
                    ^
              first valid day

            We need to find the first True.
        */
        while (low <= high) {

            int guess = low + (high - low) / 2;

            // Check whether current day is sufficient
            if (isDayValid(bloomDay, m, k, guess)) {

                // Possible answer found
                ans = guess;

                // Try to find a smaller valid day
                high = guess - 1;
            }
            else {

                // Need more days for flowers to bloom
                low = guess + 1;
            }
        }

        return ans;
    }
};