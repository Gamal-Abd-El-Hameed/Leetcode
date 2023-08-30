class Solution {
private:
    int m, n, wordLen;
    bool dfs(vector<vector<char>>& board, const string& word, vector<vector<bool>>& visited, int counter,
             int row, int col, int prevRow, int prevCol) {
        if (row == -1 || col == -1 || row == m || col == n) return false;
        if (visited[row][col])
            return false;
        visited[row][col] = true;
        if (board[row][col] == word[counter]) {
            counter++;
            if (counter == wordLen) return true;
            if (prevRow != row + 1 && dfs(board, word, visited, counter,
            row + 1, col, row, col)) return true;
            if (prevRow != row - 1 && dfs(board, word, visited, counter,
            row - 1, col, row, col)) return true;
            if (prevCol != col + 1 && dfs(board, word, visited, counter,
                row, col + 1, row, col)) return true;
            if (prevCol != col - 1 && dfs(board, word, visited, counter,
                row, col - 1, row, col)) return true;
            visited[row][col] = false;
            return false;
        }
        visited[row][col] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        if (board.empty()) return false;
        m = board.size(), n = board[0].size(), wordLen = word.size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(board, word, visited, 0,
                        i, j, -1, -1))
                    return true;
        return false;
    }
};