class Solution {
 private:
  void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
    int n = grid.size();
    int m = grid[0].size();
    if (i > 0 && !visited[i-1][j] && grid[i-1][j] == '1') {
        visited[i-1][j] = true;
        dfs(grid, i - 1, j, visited);
    }
    if (j > 0 && !visited[i][j-1] && grid[i][j-1] == '1') {
        visited[i][j-1] = true;
        dfs(grid, i, j-1, visited);
    }
    if (i < n - 1 && !visited[i+1][j] && grid[i+1][j] == '1') {
        visited[i+1][j] = true;
        dfs(grid, i + 1, j, visited);
    }
    if (j < m - 1 && !visited[i][j+1] && grid[i][j+1] == '1') {
        visited[i][j+1] = true;
        dfs(grid, i, j+1, visited);
    }
  }

 public:
  int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int res = 0;

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '1' && visited[i][j] == false) {
                res++;
                dfs(grid, i, j, visited);
            }
        }
    }
    return res;
  }
};
