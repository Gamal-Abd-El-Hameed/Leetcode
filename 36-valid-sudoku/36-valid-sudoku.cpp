class Solution {
public:
	bool isSquare(vector<vector<char>> &board, int row, int column) {
		vector<char> v {};
		set<char> se {};
		for(int i = row; i < row + 3; i++) {
			for(int j = column; j < column + 3; j++) {
				if(board[i][j] != '.') {
					se.insert(board[i][j]);
					v.push_back(board[i][j]);
				}
			}
		}
		if(se.size() != v.size()) return false;
		return true;
	}
	bool isValidSudoku(vector<vector<char>>& board) {
		for(int i = 0; i < 9; i++) {
			vector<char> v {};
			set<char> se {};
			for(int j = 0; j < 9; j++) {
				if(board[i][j] != '.') {
					se.insert(board[i][j]);
					v.push_back(board[i][j]);
				}
			}
			if(se.size() != v.size()) return false;
		}
		for(int j = 0; j < 9; j++) {
			vector<char> v {};
			set<char> se {};
			for(int i = 0; i < 9; i++) {
				if(board[i][j] != '.') {
					se.insert(board[i][j]);
					v.push_back(board[i][j]);
				}
			}
			if(se.size() != v.size()) return false;
		}
		for(int i = 0; i < 9; i += 3) {
			for(int j = 0; j < 9; j += 3) {
				if(isSquare(board, i, j) == false) return false;
			}
		}
		return true;
	}
};