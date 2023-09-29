class Solution {
public:
    int totalNQueens(int n) {
        this->n = n;
        int ans = 0;
        vector<int> queenCols(n, -1);
        solveNQueens(queenCols, 0, ans);
        return ans;
    }
private:
    int n;
    void solveNQueens(vector<int> &queenCols, int row, int &ans) {
        if (row == n) {
            ans++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(queenCols, row, col)) {
                queenCols[row] = col;
                solveNQueens(queenCols, row + 1, ans);
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