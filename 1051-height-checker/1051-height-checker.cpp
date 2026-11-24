class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected;
        for(int i = 0;i<heights.size();i++)
        {
            expected.push_back(heights[i]);
        }
        sort(expected.begin(), expected.end());
        int a = 0;
         for(int i = 0;i<heights.size();i++)
         {
            if(heights[i] != expected[i])
            {
                a++;
            }
         }
        return a;
    }
};