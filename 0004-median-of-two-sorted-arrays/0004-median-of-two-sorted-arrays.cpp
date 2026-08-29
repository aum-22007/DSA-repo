class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> c(nums1.begin(), nums1.end());
        c.insert(c.end(), nums2.begin(), nums2.end());

        // Sort the concatenated array
        sort(c.begin(), c.end());

        int len = c.size();

        // If length is even
        if (len % 2 == 0) {
            return (c[len / 2] + c[len / 2 - 1]) / 2.0;
        }

        // If length is odd
        else {
            return c[len / 2];
        }
    }
};