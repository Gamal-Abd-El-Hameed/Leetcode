class Solution {
private:
    int m, n, wordLen;
    bool dfs(vector<vector<char>>& board, const string& word, int counter,
             int row, int col) {
        if (row < 0 || col < 0 || row == m || col == n || board[row][col] != word[counter]) return false;
        char originalChar = board[row][col];
        board[row][col] = '#';
        counter++;
        if (counter == wordLen) return true;
        bool found = dfs(board, word, counter, row + 1, col) ||
                     dfs(board, word, counter, row - 1, col) ||
                     dfs(board, word, counter, row, col + 1) ||
                     dfs(board, word, counter, row, col - 1);
        board[row][col] = originalChar;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        if (board.empty()) return false;
        m = board.size(), n = board[0].size(), wordLen = word.size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(board, word, 0,
                        i, j))
                    return true;
        return false;
    }
};