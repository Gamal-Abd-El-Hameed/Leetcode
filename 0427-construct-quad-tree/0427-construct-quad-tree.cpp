class Solution {
private:
    bool isSubGridHasSameVal(vector<vector<int>>& grid, int r1, int c1, int r2, int c2) {
        int val = grid[r1][c1];
        for (int i = r1; i <= r2; i++)
            for (int j = c1; j <= c2; j++)
                if (grid[i][j] != val)
                    return false;
        return true;
    }
    Node* rec(vector<vector<int>>& grid, int r1, int c1, int r2, int c2) {
        if (isSubGridHasSameVal(grid, r1, c1, r2, c2)) {
            return new Node(grid[r1][c1], true);
        }
        auto *topLeft = rec(grid, r1, c1, r1 + (r2 - r1) / 2, c1 + (c2 - c1) / 2);
        auto *topRight = rec(grid, r1, c1 + (c2 - c1) / 2 + 1, r1 + (r2 - r1) / 2, c2);
        auto *bottomLeft = rec(grid, r1 + (r2 - r1) / 2 + 1, c1, r2, c1 + (c2 - c1) / 2);
        auto *bottomRight = rec(grid, r1 + (r2 - r1) / 2 + 1, c1 + (c2 - c1) / 2 + 1, r2, c2);
        return new Node(grid[r1][c1], false, topLeft, topRight, bottomLeft, bottomRight);
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return rec(grid, 0, 0, n - 1, n - 1);
    }
};