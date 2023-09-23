class Solution {
private:
    int m, n;
    bool isLive(vector<vector<int>>& board, int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n && (board[i][j] == 1 || board[i][j] == -1);
    }
    void updateValOf(vector<vector<int>>& board, int i, int j) {
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
            if (liveNeighbors < 2 || liveNeighbors > 3)
                board[i][j] = -1;
        }
        else if (liveNeighbors == 3)
                board[i][j] = 2;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                updateValOf(board, i, j);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (board[i][j] == -1)
                    board[i][j] = 0;
                else if (board[i][j] == 2)
                    board[i][j] = 1;
            }
    }
};