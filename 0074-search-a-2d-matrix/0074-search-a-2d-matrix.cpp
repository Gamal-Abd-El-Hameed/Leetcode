class Solution {
public:
    bool searchMatrixRec(vector<vector<int>>& matrix, int target, int low, int high) {
    if (low == high)
        return binary_search(matrix[low].begin(), matrix[low].end(), target);
    int mid = low + (high - low) / 2, col = matrix[0].size() - 1;
    if (matrix[mid][col] >= target)
        return searchMatrixRec(matrix, target, low, mid);
    return searchMatrixRec(matrix, target, mid + 1, high);    
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    return searchMatrixRec(matrix, target, 0, matrix.size() - 1);
}
};