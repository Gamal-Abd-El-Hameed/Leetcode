class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0, top = 0, right = matrix[0].size(), bottom = matrix.size(), counter = 0;
        vector<int> result(right * bottom);

        while (top < bottom && left < right) {
            for (int j = left; j < right; j++) {
                result[counter++] = matrix[top][j];
            }
            top++;

            for (int i = top; i < bottom; i++) {
                result[counter++] = matrix[i][right - 1];
            }
            right--;

            if (top == bottom)
                break;

            for (int j = right - 1; j >= left; j--) {
                result[counter++] = matrix[bottom - 1][j];
            }
            bottom--;

            if (left == right)
                break;
            for (int i = bottom - 1; i >= top; i--) {
                result[counter++] = matrix[i][left];
            }
            left++;
        }

        return result;
    }
};