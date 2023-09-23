class Solution {
private:
    int m, n;
    bool isLive(vector<vector<int>>& board, int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n && board[i][j];
    }
    int getNewValOf(vector<vector<int>>& board, int i, int j) {
        int liveNeighbors = 0;
        if (isLive(board, i - 1, j - 1))
            liveNeighbors++;
        if (isLive(board, i - 1, j))
            liveNeighbors++;
        if (isLive(board, i - 1, j + 1))
            liveNeighbors++;
        if (isLive(board, i, j - 1))
            liveNeighbors++;
        if (isLive(board, i, j + 1))
            liveNeighbors++;
        if (isLive(board, i + 1, j - 1))
            liveNeighbors++;
        if (isLive(board, i + 1, j))
            liveNeighbors++;
        if (isLive(board, i + 1, j + 1))
            liveNeighbors++;
        if (board[i][j]) {
            if (liveNeighbors < 2 || liveNeighbors > 3)
                return 0;
            return 1;
        }
        return liveNeighbors == 3;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size(), n = board[0].size();
        vector<vector<int>> res(m, vector<int>(n));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                res[i][j] = getNewValOf(board, i, j);
        board = res;
    }
};