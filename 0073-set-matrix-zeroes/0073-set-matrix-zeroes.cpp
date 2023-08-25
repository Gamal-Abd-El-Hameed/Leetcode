class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        unordered_set<int> rowsSet, colsSet;
        vector<bool> colsBool(cols, false);
        for (int row = 0; row < rows; row++)
            for (int col = 0; col < cols; col++)
                if (matrix[row][col] == 0)
                    rowsSet.insert(row), colsSet.insert(col);
        // loop over rowsSet and colsSet
        for (const auto &row : rowsSet)
            for (int col = 0; col < cols; col++)
                matrix[row][col] = 0;
        for (const auto &col : colsSet)
            for (int row = 0; row < rows; row++)
                matrix[row][col] = 0;
    }
};