class Solution {
private:
    int m, n;
    bool isLive(vector<vector<int>>& board, int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n && board[i][j];
    }
    int getNewValOf(vector<vector<int>>& board, int i, int j) {
        int liveNeighbors = 0;
        int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1},
                                {0, -1}, {0, 1},
                                {1, -1}, {1, 0}, {1, 1}};
        for (auto & direction : directions) {
            int x = i + direction[0], y = j + direction[1];
            if (isLive(board, x, y))
                liveNeighbors++;
        }
        if (board[i][j]) {
            return liveNeighbors == 2 || liveNeighbors == 3;
        }
        return liveNeighbors == 3;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size(), n = board[0].size();
        vector<int> prevRow(n, 0), curRow(n, 0);
        curRow = board[0];

        for (int i = 0; i < m; i++) {
            prevRow = curRow;
            curRow = board[i];
            for (int j = 0; j < n; j++)
                curRow[j] = getNewValOf(board, i, j);
            if (i)
                board[i - 1] = prevRow;
        }
        board[m - 1] = curRow;
    }
};