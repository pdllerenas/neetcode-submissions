class Solution {
private:
    vector<string> res;
    vector<string> letters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    inline int to_int(char c) {
        return c - '0';
    }

    void dfs(string &digits, string cur, int index) {
        if (index == digits.size()) {
            res.push_back(cur);
            return;
        }
         // 2-based
        dfs(digits, cur + letters[to_int(digits[index] - 2)][0], index + 1);
        dfs(digits, cur + letters[to_int(digits[index]- 2)][1], index + 1);
        dfs(digits, cur + letters[to_int(digits[index]- 2)][2], index + 1);
        if (digits[index] == '7' || digits[index] == '9') 
            dfs(digits, cur + letters[to_int(digits[index]- 2)][3], index + 1);
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
       dfs(digits, "", 0);
       return res;
    }
};
