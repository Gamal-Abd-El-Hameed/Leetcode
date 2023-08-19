class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> row(n, 1);
        vector<int> newRow(n);
        for (int i = 0; i < m - 1; i++) {
            newRow[n - 1] = 1;
            for (int j = n - 2; j >= 0; j--)
                newRow[j] = newRow[j + 1] + row[j];
            row = newRow;
        }
        return row[0];
    }
};