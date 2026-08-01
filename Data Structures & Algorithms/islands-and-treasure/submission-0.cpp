class Solution {
private:
    int bfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited) {
        queue<tuple<int, int, int>> q;
        q.push({i, j, 0});
        while (!q.empty()) {
            auto [curi, curj, distance] = q.front();
            q.pop();
            if (curi < 0 || curj < 0 || curi >= grid.size() || curj >= grid[0].size() || visited[curi][curj] || grid[curi][curj] == -1) {
                continue;
            }
            if (grid[curi][curj] == 0) {
                return distance;
                break;
            }

            visited[curi][curj] = true;
            q.push({curi+1,curj, distance + 1});
            q.push({curi-1,curj, distance + 1});
            q.push({curi,curj+1, distance + 1});
            q.push({curi,curj-1, distance + 1});
        }
        return INT_MAX;
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            fill(visited.begin(), visited.end(), vector<bool>(m, false));
            if (grid[i][j] == INT_MAX) {
                grid[i][j] = bfs(grid, i, j, visited);
            }
        }
      }
    }
};
