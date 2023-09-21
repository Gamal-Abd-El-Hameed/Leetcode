class Solution {
public:
    string convert(string s, int numRows) {
        int numCols = 0, len = s.length(), tmpLen = len, colsIterator;
        while (tmpLen > 0) {
            numCols++;
            tmpLen -= numRows;
            if (tmpLen <= 0)
                break;
            colsIterator = numRows - 2;
            while (colsIterator-- && tmpLen--)
                numCols++;
        }
        vector<vector<char>> zigzag(numRows, vector<char>(numCols, ' '));
        int j = 0, counter = 0, i;
        while (counter < len) {
            for (i = 0; i < numRows && counter < len; i++) {
                zigzag[i][j] = s[counter++];
            }
            i = numRows - 2;
            j++;
            while (counter < len && i > 0) {
                zigzag[i][j] = s[counter++];
                i--; j++;
            }
        }
        string res;
        for (i = 0; i < numRows; i++)
            for (j = 0; j < numCols; j++)
                if (zigzag[i][j] != ' ')
                    res += zigzag[i][j];
        return res;
    }
};