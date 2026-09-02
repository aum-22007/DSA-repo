class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for(int j = 0; j< strs[0].size();j++)
        {
            for(int i = 0; i< strs.size();i++)
            {

                if(j >= strs[i].size())
                {
                    return ans;
                }

                if(strs[i][j] != strs[0][j])
                {
                    return ans;
                }
            }
            ans = ans + strs[0][j];
        }
        return ans;
    }
};