class Solution {
    public:
    bool isValidSudoku(vector<vector<char>>& board) {
    unordered_set<char> s;
    char ch;
    for(int i = 0; i < 9; ++i) {
        s.clear();
        for(int j = 0; j < 9; ++j) {
            ch = board[i][j];
            if(ch != '.') {
                if(s.find(ch) != s.end())
                    return false;
                s.insert(ch);
            }
        }
    }
    for(int i = 0; i < 9; ++i) {
        s.clear();
        for(int j = 0; j < 9; ++j) {
            ch = board[j][i];
            if(ch != '.') {
                if(s.find(ch) != s.end())
                    return false;
                s.insert(ch);
            }
        }
    }
    for(int i = 0; i < 9; i += 3) {
        for(int j = 0; j < 9; j += 3) {
            s.clear();
            for(int r = i; r < i + 3; ++r)
                for(int c = j; c < j + 3; ++c) {
                    ch = board[r][c];
                    if(ch != '.') {
                        if(s.find(ch) != s.end())
                            return false;
                        s.insert(ch);
                    }
                }
        }
    }
    return true;
}
};