class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> copyMatrix = matrix;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (copyMatrix[i][j] == 0)
                    for (j = 0; j < cols; j++)
                        matrix[i][j] = 0;
        for (int j = 0; j < cols; j++)
            for (int i = 0; i < rows; i++)
                if (copyMatrix[i][j] == 0)
                    for (i = 0; i < rows; i++)
                        matrix[i][j] = 0;
    }
};