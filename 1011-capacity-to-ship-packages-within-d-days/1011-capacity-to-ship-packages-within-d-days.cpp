class Solution {
public:

    // Check if 'guess' capacity is sufficient to ship all packages
    // within the given number of days.
    bool isCapacityValid(vector<int>& weights, int days, int guess) {

        int currentday = 1;      // Start shipping from day 1
        int requiredWeight = 0;  // Current load for the day

        for (auto weight : weights) {

            // If adding the current package exceeds capacity,
            // move the package to the next day.
            if (requiredWeight + weight > guess) {
                currentday++;
                requiredWeight = weight;
            }
            else {
                requiredWeight += weight;
            }
        }

        // Valid capacity if packages can be shipped
        // in <= allowed days.
        return currentday <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        // Binary Search Range:
        // Minimum capacity = largest single package.
        // Maximum capacity = sum of all packages.
        int minWeight = INT_MIN;
        int maxWeight = 1;

        for (auto weight : weights) {
            minWeight = max(weight, minWeight);
            maxWeight += weight;
        }

        int low = minWeight;
        int high = maxWeight;
        int ans = -1;

        // Binary Search on answer space (capacity)
        while (low <= high) {

            int guess = (low + high) / 2;

            // If this capacity works,
            // try finding a smaller valid capacity.
            if (isCapacityValid(weights, days, guess)) {
                ans = guess;
                high = guess - 1;
            }
            else {
                // Capacity too small,
                // increase capacity.
                low = guess + 1;
            }
        }

        return ans;
    }
};