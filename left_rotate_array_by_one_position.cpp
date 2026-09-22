class Solution {
public:
    void rotateArrayByOne(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return;
        }
        vector<int> temp(n);

        for (int index = 1; index < n; index++) {
            temp[index - 1] = nums[index];
        }

        temp[n - 1] = nums[0];

        for (int index = 0; index < n; index++) {
            nums[index] = temp[index];
        }
    }
};