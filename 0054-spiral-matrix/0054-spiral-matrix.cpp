class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int totalElements = m * n, counter = 0, i = 0, j, oldI, oldJ = 0;
        vector<int> res(totalElements);
        while (i < m) {
            oldI = i;
            j = oldJ;
            while (j < n && counter < totalElements) {
                res[counter++] = matrix[i][j];
                j++;
            }
            j--;
            i++;
            while (i < m && counter < totalElements) {
                res[counter++] = matrix[i][j];
                i++;
            }
            j--;
            i--;
            while (j >= oldJ && counter < totalElements) {
                res[counter++] = matrix[i][j];
                j--;
            }
            j++;
            i--;
            while (i > oldI && counter < totalElements) {
                res[counter++] = matrix[i][j];
                i--;
            }
            i = oldI + 1;
            oldJ = j + 1;
            m--;
            n--;
        }
        return res;
    }
};