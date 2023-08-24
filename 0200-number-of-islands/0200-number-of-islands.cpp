class Solution {
private:
    vector<vector<bool>> visited;
    int rows, cols;
    void dfs(int i, int j, vector<vector<char>>& grid) {
        if (i < 0 || j < 0 || i == rows || j == cols) return;
        if (visited[i][j] || grid[i][j] == '0') return;
        visited[i][j] = true;
        dfs(i + 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i - 1, j, grid);
        dfs(i, j - 1, grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        rows = grid.size(), cols = grid[0].size();
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) {
                if (visited[i][j] || grid[i][j] == '0') continue;
                islands++;
                dfs(i, j, grid);
            }
        return islands;
    }
};