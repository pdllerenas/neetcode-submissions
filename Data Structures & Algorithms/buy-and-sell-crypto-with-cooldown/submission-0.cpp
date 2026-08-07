class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
       for (int i = n - 1; i >= 0 ; --i) {
         // if can buy
         // buy
         int buy = dp[i + 1][0] - prices[i];
         // hold
         int cd = dp[i+1][1];
         dp[i][1] = max(buy, cd);

         // if can't buy (just sold prev)
         int sell = (i + 2 < n) ? dp[i+2][1] + prices[i] : prices[i];
         cd = dp[i+1][0];
         dp[i][0] = max(sell, cd);
       }

       return dp[0][1];
    }
};
