class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int totalSize = size1 + size2;
        
        if (totalSize == 0) {
            return 0.0;
        }


        if (size1 == 0 && size2 == 1) {
            return nums2[0];
        }

        if (size2 == 0 && size1 == 1) {
            return nums1[0];
        }

        
        vector<int> merged(totalSize);
        int i = 0, j = 0, k = 0;
        while (i < size1 && j < size2) {
            if (nums1[i] < nums2[j]) {
                merged[k++] = nums1[i++];
            } else {
                merged[k++] = nums2[j++];
            }
        }
        while (i < size1) {
            merged[k++] = nums1[i++];
        }
        while (j < size2) {
            merged[k++] = nums2[j++];
        }
        
        int mid = totalSize / 2;
        if (totalSize % 2 == 0) {
            return (merged[mid - 1] + merged[mid]) / 2.0;
        } else {
            return merged[mid];
        }
    }
};