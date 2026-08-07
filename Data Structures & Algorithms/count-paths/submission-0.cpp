class Solution {
 private:
 public:
  int uniquePaths(int m, int n) {
    // dp[i][j] represents the # of ways to get from i distance and j distance from bottom right corner
    vector<vector<int>> dp;
    dp.assign(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }

    for (int j = 0; j < n; j++) {
        dp[0][j] = 1;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
  }
};
