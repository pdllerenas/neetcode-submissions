class Solution {
 private:
  bool dfs(vector<vector<char>>& board, int i, int j, string& cur, int index) {
    if (index == cur.size()) return true;
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != cur[index]) {
      return false;
    }
    char temp = board[i][j];
    board[i][j] = '#';  // mark as visited
    bool found = dfs(board, i + 1, j, cur, index + 1) || dfs(board, i - 1, j, cur, index + 1) ||
                 dfs(board, i, j + 1, cur, index + 1) || dfs(board, i, j - 1, cur, index + 1);
    board[i][j] = temp;

    return found;
  }

 public:
  bool exist(vector<vector<char>>& board, string word) {
      for (int r = 0; r < board.size(); ++r) {
    for (int c = 0; c < board[0].size(); ++c) {
        if (board[r][c] == word[0] && dfs(board, r, c, word, 0)) return true;
      }
    }
    return false;
  }
};
