class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> solutions;
        findSolutions(board, 0, solutions);
        return solutions;
    }
private:
    int n;
    void findSolutions(vector<string> &board, int row, vector<vector<string>> &solutions) {
        if (row == n)
            return solutions.push_back(board);
        for (int col = 0; col < n; col++)
            if (isValid(board, row, col)) {
                board[row][col] = 'Q';
                findSolutions(board, row + 1, solutions);
                board[row][col] = '.';
            }
    }
    bool isValid(vector<string> &board, int row, int col) {
        for (int i = row - 1; i >= 0; i--)
            if (board[i][col] == 'Q')
                return false;
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q')
                return false;
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q')
                return false;
        return true;
    }
};