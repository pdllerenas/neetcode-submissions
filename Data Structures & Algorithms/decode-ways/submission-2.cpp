class Solution {
 private:
  vector<int> cache;
  int dfs(string& s, int i) {
    if (i >= s.size()) {
      return 1;
    }
    if (cache[i] != -1) {
      return cache[i];
    }
    if (s[i] == '0') return 0;
    int res = dfs(s, i + 1);
    if (i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
      res += dfs(s, i + 2);
    }
    cache[i] = res;
    return res;
  }

 public:
  int numDecodings(string s) {
    cache.resize(s.size(), -1);
    return dfs(s, 0);
  }
};
