class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<pair<int, int>> dp;
    dp.resize(n, {0,1});
    dp[n - 1] = {nums[n - 1], 1};
    int best = 1;
    for (int i = n - 2; i >= 0; --i) {
      dp[i] = {nums[i], 1};
      for (int j = i + 1; j < n; ++j) {
        if (dp[i].first < dp[j].first) {
          dp[i].second = max(dp[i].second, 1 + dp[j].second);
          if (dp[i].second > best) best = dp[i].second;
        }
      }
    }
    return best;
  }
};
