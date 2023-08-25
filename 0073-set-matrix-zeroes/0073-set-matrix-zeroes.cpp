class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        bool firstRow = false;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    if (i == 0) firstRow = true;
                    else matrix[i][0] = 0;
                }
        for (int i = 1; i < rows; i++)
            if (matrix[i][0] == 0)
                for (int j = 0; j < cols; j++)
                    matrix[i][j] = 0;
        for (int j = 0; j < cols; j++)
            if (matrix[0][j] == 0)
                for (int i = 0; i < rows; i++)
                    matrix[i][j] = 0;
        if (firstRow)
            for (int j = 0; j < cols; j++)
                matrix[0][j] = 0;
    }
};