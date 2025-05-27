class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();        // number of rows
        int n = mat[0].size();     // number of columns
        int left = 0, right = n - 1;

        while (left <= right) {
            int midCol = left + (right - left) / 2;

            int maxRow = 0;
            for (int i = 1; i < m; ++i) {
                if (mat[i][midCol] > mat[maxRow][midCol]) {
                    maxRow = i;
                }
            }

            int current = mat[maxRow][midCol];
            int leftVal = (midCol > 0) ? mat[maxRow][midCol - 1] : -1;
            int rightVal = (midCol < n - 1) ? mat[maxRow][midCol + 1] : -1;

            // Check if it's a peak
            if (current > leftVal && current > rightVal) {
                return {maxRow, midCol};
            } else if (leftVal > current) {
                right = midCol - 1;
            } else {
                left = midCol + 1;
            }
        }

        return {-1, -1};
    }
};