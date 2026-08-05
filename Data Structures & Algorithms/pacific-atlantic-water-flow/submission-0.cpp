class Solution {
 private:
  vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int r, int c) {
    ocean[r][c] = true;
    for (auto [dr, dc] : dirs) {
      int nr = r + dr, nc = c + dc;
      if (nr >= 0 && nr < heights.size() && nc >= 0 && nc < heights[0].size() && !ocean[nr][nc] &&
          heights[nr][nc] >= heights[r][c]) {
        dfs(heights, ocean, nr, nc);
      }
    }
  }

 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();

    vector<vector<bool>> pacific(n, vector<bool>(m, false));
    vector<vector<bool>> atlantic(n, vector<bool>(m, false));

    // upper lower limits
    for (int j = 0; j < m; j++) {
      dfs(heights, pacific, 0, j);
      dfs(heights, atlantic, n - 1, j);
    }
    for (int i = 0; i < n; i++) {
      dfs(heights, pacific, i, 0);
      dfs(heights, atlantic, i, m - 1);
    }
    vector<vector<int>> res;
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < m; ++c) {
        if (pacific[r][c] && atlantic[r][c]) {
          res.push_back({r, c});
        }
      }
    }
    return res;
  }
};
