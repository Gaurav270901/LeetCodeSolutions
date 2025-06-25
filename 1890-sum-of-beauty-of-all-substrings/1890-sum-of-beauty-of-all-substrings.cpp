class Solution {
public:
    int findMinFreq(vector<int> &freq) {
        int minFreq = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                minFreq = min(minFreq, freq[i]);
            }
        }
        return minFreq;
    }

    int beautySum(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < s.size(); j++) {
                freq[s[j] - 'a']++;
                int maxFreq = *max_element(freq.begin(), freq.end());
                int minFreq = findMinFreq(freq);
                ans += maxFreq - minFreq;
            }
        }
        return ans;
    }
};
