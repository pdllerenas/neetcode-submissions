class Solution {
public:
    vector<int> countBits(int n) {
        if (n == 0) return {0};
        if (n == 1) return {0,1};
        vector<int> dp(n + 1);
        int offset = 1;
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) offset = i;
            dp[i] = dp[i - offset] + 1;
        }
        return dp;
    }
};
