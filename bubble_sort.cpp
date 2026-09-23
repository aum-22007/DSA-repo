#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
      // Bubble sort Functin
    vector<int> bubbleSort(vector<int>& nums) {
        int n = nums.size();
        // Traverse through the array
        for (int i = n - 1; i >= 0; i--) {
            // Track if swaps are made 
            bool didSwap = false;
            for (int j = 0; j <= i - 1; j++) {
                // Swap if next element is smaller
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                    didSwap = true;
                }
            }
            /**  Break out of loop 
         if no swaps done*/
            if (!didSwap) {
                break;
            }
        }
        return nums;
    }
};

int main() {
    // Create an instance of solution 
    Solution solution;
    
    vector<int> nums = {7, 4, 1, 5, 3};
    
    cout << "Before Using Bubble Sort: " << endl;
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // Function call for Bubble Sort
    nums = solution.bubbleSort(nums);

    cout << "Array After Using Bubble Sort: " << endl;
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}