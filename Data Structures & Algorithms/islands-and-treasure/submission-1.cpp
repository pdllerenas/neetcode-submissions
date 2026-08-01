class Solution {
 public:
  void islandsAndTreasure(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 0) {
          q.push({i, j});
        }
      }
    }

    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    while (!q.empty()) {
      auto [curi, curj] = q.front();
      q.pop();

      for (auto [x, y] : directions) {
        int nx = curi + x;
        int ny = curj + y;

        if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != INT_MAX) {
          continue;
        }
        grid[nx][ny] = grid[curi][curj] + 1;
        q.push({nx, ny});
      }
    }
  }
};
