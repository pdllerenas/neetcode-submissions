class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    int n = board.size();
    int rows[9] = {0};
    int cols[9] = {0};
    int squares[9] = {0};
    

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == '.') continue;
        int val = board[i][j] - '1';
        int sq = (i / 3) * 3 + (j / 3);
        if (rows[i] & (1 << val) || cols[j] & (1 << val) || squares[sq] & (1 << val)) return false;

        rows[i] |= (1 << val);
        cols[j] |= (1 << val);
        squares[sq] |= (1 << val);
      }
    }
    return true;
  }
};