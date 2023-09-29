class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        vector<int> queenCols(n, -1);
        vector<vector<string>> res;
        solveNQueens(queenCols, 0, res);
        return res;
    }
private:
    int n;
    void solveNQueens(vector<int> &queenCols, int row, vector<vector<string>> &res) {
        if (row == n) {
            vector<string> board(n, string(n, '.'));
            for (int queenRow = 0; queenRow < n; queenRow++)
                board[queenRow][queenCols[queenRow]] = 'Q';
            res.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(queenCols, row, col)) {
                queenCols[row] = col;
                solveNQueens(queenCols, row + 1, res);
                queenCols[row] = -1;
            }
        }
    }
    bool isSafe(vector<int> &queenCols, int currRow, int currCol) {
        for (int queenRow = 0; queenRow < currRow; queenRow++) {
            int queenCol = queenCols[queenRow];
            if (queenCol == currCol || currRow - queenRow == abs(currCol - queenCol))
                return false;
        }
        return true;
    }
};