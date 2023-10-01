class Solution {
private:
    int m, n;
    void dfs(vector<vector<bool>> &visited, int i, int j) {
        if (i < 0 || i == m || j < 0 || j == n || visited[i][j])
            return;
        visited[i][j] = true;
        int directions[][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        for (auto const direction:directions)
            dfs(visited, i + direction[0], j + direction[1]);
    }
public:
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == 'X')
                    visited[i][j] = true;

        for (int i = 0; i < m; i++) {
            dfs(visited, i, 0);
            dfs(visited, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            dfs(visited, 0, j);
            dfs(visited, m - 1, j);
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!visited[i][j])
                    board[i][j] = 'X';
    }
};