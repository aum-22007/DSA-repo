
class Solution {
public:
    vector<int> insertionSort(vector<int>& nums) {
        for(int i = 1; i<nums.size();i++)
        {
            int target = nums[i];
            int j = i-1;
            while(j >=0 && nums[j] > target)
            {
                nums[j+1] = nums[j];
                j = j-1;
            }
            nums[j+1] = target;
        }
        return nums;
    }
};
