class Solution {
private:
    vector<string> res;
    void dfs(int n, int open, int close, string cur) {
      if (close == n) {
        res.push_back(cur);
        return;
      }
      if (open < n) {
        dfs(n, open + 1, close, cur + '(');
        if (close < open) dfs(n, open, close + 1, cur + ')');
      } else {
        dfs(n, open, close + 1, cur + ')');
      }
    }
public:
    vector<string> generateParenthesis(int n) {
       dfs(n, 0, 0, "");
       return res;
    }
};
