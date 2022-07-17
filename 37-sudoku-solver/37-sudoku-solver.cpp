class Solution {
    const int SUDOKU_SIZE = 9;
    bool isValidNumber(vector<vector<char>>& board, int row, int col, char num) {
    for(int i = 0; i < SUDOKU_SIZE; ++i)
        if(board[i][col] == num || board[row][i] == num)
            return false;
    int rowRegion = row / 3 * 3, colRegion = col / 3 * 3;
    for(int i = rowRegion; i < rowRegion + 3; ++i)
        for(int j = colRegion; j < colRegion + 3; ++j)
            if(board[i][j] == num)
                return false;
    return true;
}

vector<char> letters = {'0','1','2','3','4','5','6','7','8','9'};

bool helper(vector<vector<char>>& board, int row, int col) {
    if(row == SUDOKU_SIZE) {
        cout << "[";
        for(int i = 0; i < SUDOKU_SIZE; ++i) {
            cout << "[";
            for(int j = 0; j < SUDOKU_SIZE; ++j) {
                cout << board[i][j];
                if(j != SUDOKU_SIZE - 1)
                    cout << ",";
            }
            cout << "]";
            if(i != SUDOKU_SIZE - 1)
                cout << ",";
        }
        cout << "]";
        return true;
    }
    if(col == SUDOKU_SIZE)
        return helper(board, row + 1, 0);
    if(board[row][col] != '.')
        return helper(board, row, col + 1);
    for(int i = 1; i <= SUDOKU_SIZE; ++i) {
        char num = letters[i];
        if(isValidNumber(board, row, col, num)) {
            board[row][col] = num;
            if(helper(board, row, col + 1))
                return true;
        }
    }
    board[row][col] = '.';
    return false;
}
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};