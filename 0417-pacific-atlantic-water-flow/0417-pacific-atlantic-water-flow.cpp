class Solution {
private:
    int rows, cols;
    vector<vector<bool>> atlanticMap;
    vector<vector<bool>> pacificMap;
    vector<vector<bool>> pacificVisited;
    vector<vector<bool>> atlanticVisited;
    void flowAtlantic(int i, int j, vector<vector<int>>& heights) {
        if (atlanticVisited[i][j] || !atlanticMap[i][j]) return;
        atlanticVisited[i][j] = true;
        if (i && heights[i][j] <= heights[i -1][j]) {
            atlanticMap[i - 1][j] = true;
            flowAtlantic(i - 1, j, heights);
        }
        if (j && heights[i][j] <= heights[i][j - 1]) {
            atlanticMap[i][j - 1] = true;
            flowAtlantic(i, j - 1, heights);
        }
        if (i < rows - 1 && heights[i][j] <= heights[i + 1][j]) {
            atlanticMap[i + 1][j] = true;
            flowAtlantic(i + 1, j, heights);
        }
        if (j < cols - 1 && heights[i][j] <= heights[i][j + 1]) {
            atlanticMap[i][j + 1] = true;
            flowAtlantic(i, j + 1, heights);
        }
    }

    void flowPacific(int i, int j, vector<vector<int>>& heights) {
        if (pacificVisited[i][j] || !pacificMap[i][j]) return;
        pacificVisited[i][j] = true;
        if (i && heights[i][j] <= heights[i -1][j]) {
            pacificMap[i - 1][j] = true;
            flowPacific(i - 1, j, heights);
        }
        if (j && heights[i][j] <= heights[i][j - 1]) {
            pacificMap[i][j - 1] = true;
            flowPacific(i, j - 1, heights);
        }
        if (i < rows - 1 && heights[i][j] <= heights[i + 1][j]) {
            pacificMap[i + 1][j] = true;
            flowPacific(i + 1, j, heights);
        }
        if (j < cols - 1 && heights[i][j] <= heights[i][j + 1]) {
            pacificMap[i][j + 1] = true;
            flowPacific(i, j + 1, heights);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size(), cols = heights[0].size();
        atlanticMap = vector<vector<bool>>(rows, vector<bool>(cols));
        pacificMap = vector<vector<bool>>(rows, vector<bool>(cols));
        atlanticVisited = vector<vector<bool>>(rows, vector<bool>(cols, false));
        pacificVisited = vector<vector<bool>>(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            pacificMap[i][0] = atlanticMap[i][cols - 1] = true;
        }
        for (int j = 0; j < cols; j++) {
            pacificMap[0][j] = atlanticMap[rows - 1][j] = true;
        }
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                flowAtlantic(i, j, heights);
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols ; j++) {
                flowPacific(i, j, heights);
            }
        }
        vector<vector<int>> res;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (atlanticMap[i][j] && pacificMap[i][j])
                    res.push_back({i, j});
        return res;
    }
};