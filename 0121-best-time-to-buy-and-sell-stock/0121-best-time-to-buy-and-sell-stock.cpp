class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int a = prices[0];
        int b = 0;
        int n = prices.size();
        for(int i = 1;i<n;i++)
        {
            if(a>prices[i])
            {
                a = prices[i];
            }
            b = max(b,prices[i] - a);
        }
        return b;
    }
};