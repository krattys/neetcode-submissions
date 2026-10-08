class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int rightMax = prices[n - 1];
        int res = 0;

        for (int i = n - 2; i >= 0; i--) {
            res = max(res, rightMax - prices[i]);
            rightMax = max(rightMax, prices[i]);
        }

        return res;
    }
};
