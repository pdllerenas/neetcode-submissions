class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int best_buy = prices[0];
    int best_profit = 0;
    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i - 1] < best_buy) {
        best_buy = prices[i - 1];
      }
      int profit = prices[i] - best_buy;
      if (profit > best_profit) {
        best_profit = profit;
      }
    }
    return best_profit;
  }
};
