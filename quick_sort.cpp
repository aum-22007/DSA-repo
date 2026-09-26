
class Solution {
public:
    vector<int> quickSort(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums;
        }
 
        sortRange(nums, 0, static_cast<int>(nums.size()) - 1);
        return nums;
    }
 
private:
    void sortRange(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }
 
        int pivotIndex = partition(nums, left, right);
        sortRange(nums, left, pivotIndex - 1);
        sortRange(nums, pivotIndex + 1, right);
    }
 
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int smallerEnd = left;
 
        for (int i = left; i < right; ++i) {
            if (nums[i] <= pivot) {
                swap(nums[i], nums[smallerEnd]);
                ++smallerEnd;
            }
        }
 
        swap(nums[smallerEnd], nums[right]);
        return smallerEnd;
    }
};