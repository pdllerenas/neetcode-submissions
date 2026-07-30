class Solution {
 private:
  vector<vector<string>> res;
  bool isPalindrome(const string& s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
  }
  void dfs(string& s, vector<string>& cur, int start) {
    if (start == s.size()) {
      res.push_back(cur);
      return;
    }
    for (int end = start; end < s.size(); ++end) {
        if (isPalindrome(s, start, end)){
            cur.push_back(s.substr(start, end - start + 1));
            dfs(s, cur, end + 1);
            cur.pop_back();
        }
    }
  }

 public:
  vector<vector<string>> partition(string s) {
    res.clear();
    vector<string> cur = {};
    dfs(s, cur, 0);
    return res;
  }
};
