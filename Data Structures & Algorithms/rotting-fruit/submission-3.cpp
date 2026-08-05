class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    // bfs (starting at rotten fruit)
    int n = grid.size();
    int m = grid[0].size();
    int fresh = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 2) {
          q.push({i, j});
        } else if (grid[i][j] == 1) {
          fresh++;
        }
      }
    }
    if (fresh == 0) return 0;
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int res = -1;
    while (!q.empty()) {
      res++;
      // depth of bfs is result (assuming start at each rotten fruit simultaneously)
      int sz = q.size();
      // go thru all rotten fruit
      for (int k = 0; k < sz; k++) {
        auto [ci, cj] = q.front();
        q.pop();
        // only go to fresh fruit, mark as rotten (must be before pushing, as the other nodes may visit the same one)
        for (auto& dir : dirs) {
          int ni = ci + dir.first;
          int nj = cj + dir.second;

          if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 1) {
            grid[ni][nj] = 2;
            fresh--;
            q.push({ni, nj});
          }
        }
      }
    }
    
    // check if there are unvisited fresh fruit
    return fresh > 0 ? -1 : res;
  }
};
