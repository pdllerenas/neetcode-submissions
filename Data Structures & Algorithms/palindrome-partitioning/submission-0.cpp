class Solution {
 private:
  vector<vector<string>> res;
  bool isPalindrome(string& s) {
    int n = s.size();
    for (int i = 0; i < n / 2; ++i) {
      if (s[i] != s[n - i - 1]) return false;
    }
    return true;
  }
  void dfs(string& s, vector<string>& cur, int size) {
    if (size == s.size()) {
      res.push_back(cur);
      return;
    }
    int remaining = s.size() - size;
    for (int i = 1; i <= remaining; ++i) {
      string candidate(s.begin() + size, s.begin() + size + i);
      cout << candidate << endl;
      if (isPalindrome(candidate)) {
        cur.push_back(candidate);
        dfs(s, cur, size + i);
        cur.pop_back();
      }
    }
  }

 public:
  vector<vector<string>> partition(string s) {
    vector<string> cur = {};
    dfs(s, cur, 0);
    return res;
  }
};
