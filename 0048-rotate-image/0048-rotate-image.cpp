class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        int n = matrix.size(), left = 0, right = n - 1, i, tmp;
        while (left < right) {
            i = left;
            while (i < right) {
                tmp = matrix[left][i];
                matrix[left][i] = matrix[left + right - i][left];
                matrix[left + right - i][left] = matrix[right][left + right - i];
                matrix[right][left + right - i] = matrix[i][right];
                matrix[i][right] = tmp;
                i++;
            }
            left++;
            right--;
        }
    }
};