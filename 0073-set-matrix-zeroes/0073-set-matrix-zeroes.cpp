class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<bool> rowsBool(rows, false);
        vector<bool> colsBool(cols, false);
        for (int row = 0; row < rows; row++)
            for (int col = 0; col < cols; col++)
                if (matrix[row][col] == 0)
                    rowsBool[row] = colsBool[col] = true;
        for (int row = 0; row < rows; row++)
            if (rowsBool[row])
                for (int col = 0; col < cols; col++)
                    matrix[row][col] = 0;
        for (int col = 0; col < cols; col++)
            if (colsBool[col])
                for (int row = 0; row < rows; row++)
                    matrix[row][col] = 0;
    }
};