class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (auto & child : children) {
            child = nullptr;
        }
    }
};

class Solution {
private:
    static const int MAX_WORD_LEN = 10;
    char visitedChar = '#';
    TrieNode* root = new TrieNode();
    int m, n;

    void insert(const string& word) const {
        TrieNode* node = root;
        int index;
        for (char c : word) {
            index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    void search(vector<vector<char>>& board, string& word, int row, int col, vector<string>& res, TrieNode* node) {
        if (row < 0 || col < 0 || row == m || col == n || board[row][col] == visitedChar) {
            return;
        }
        char originalChar = board[row][col];
        node = node->children[originalChar - 'a'];
        if (!node) {
            return;
        }
        word.push_back(originalChar);
        if (node->isEndOfWord) {
            res.push_back(word);
            node->isEndOfWord = false;
        }
        if (word.length() == MAX_WORD_LEN) {
            word.pop_back();
            return;
        }
        board[row][col] = visitedChar;
        search(board, word, row + 1, col, res, node);
        search(board, word, row - 1, col, res, node);
        search(board, word, row, col + 1, res, node);
        search(board, word, row, col - 1, res, node);
        board[row][col] = originalChar;
        word.pop_back();
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (const string& word : words)
            insert(word);

        vector<string> res;
        m = board.size(), n = board[0].size();
        string word;
        TrieNode* node = root;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                search(board, word, i, j, res, node);
            }
        }
        return res;
    }
};