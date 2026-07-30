class Solution {
 private:
  vector<vector<string>> res;
  bool canPlaceQueen(vector<string> &board, int row, int col, int n) {
    // only check above squares (no need to check squares we havent placed a queen in)
    // vertical
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 'Q') return false;
    }
    // diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 'Q') return false;
    }
    // antidiagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
        if (board[i][j] == 'Q') return false;
    }
    return true;
  }

  void dfs(int row, int n, vector<string>& board) {
    if (row == n) {
        res.push_back(board);
        return;
    }
    for (int c = 0; c < n; ++c) {
        if (canPlaceQueen(board, row, c, n)) {
            board[row][c] = 'Q';
            dfs(row + 1, n, board);
            board[row][c] = '.';
        }
    }
  }

 public:
  vector<vector<string>> solveNQueens(int n) {
    res.clear();
    vector<string> board(n, string(n, '.'));
    dfs(0, n, board);
    return res;
  }
};
