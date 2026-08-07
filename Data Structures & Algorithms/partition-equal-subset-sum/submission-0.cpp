class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int n : nums) {
      sum += n;
    }
    int h = sum / 2;
    if (2 * h != sum) return false;
    vector<bool> dp(h + 1);
    dp[0] = true;
    for (int n : nums) {
      for (int i = h; i >= n; --i) {
        dp[i] = dp[i] | dp[i - n];
      }
    }
    return dp[h];
  }
};
