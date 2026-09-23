class Solution {
public:
    vector<int> selectionSort(vector<int>& nums) {
        int min;

        for(int i = 0; i < nums.size() - 1; i++)
        {
            min = i;

            for(int j = i + 1; j < nums.size(); j++)
            {
                if(nums[j] < nums[min])
                {
                    min = j;
                }
            }

            if(min != i)
            {
                swap(nums[i], nums[min]);
            }
        }

        return nums;
    }
};