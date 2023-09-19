class Solution {
private:
    int getValueOfTwoSymbols(char currentChar, char nextChar) {
        if (currentChar == 'I' && nextChar == 'V')
            return 4;
        if (currentChar == 'I' && nextChar == 'X')
            return 9;
        if (currentChar == 'X' && nextChar == 'L')
            return 40;
        if (currentChar == 'X' && nextChar == 'C')
            return 90;
        if (currentChar == 'C' && nextChar == 'D')
            return 400;
        if (currentChar == 'C' && nextChar == 'M')
            return 900;
        return 0;
    }

    int getValOfSymbol(char c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return  10;
            case 'L':
                return  50;
            case 'C':
                return  100;
            case 'D':
                return  500;
            case 'M':
                return  1000;
            default:
                return 0;
        }
    }
public:
    int romanToInt(const string& s) {
        int n = s.length(), ans = 0;
        for (int i = 0; i < n; i++) {
            if (i < n - 1) {
                int valOfTwoSymbols = getValueOfTwoSymbols(s[i], s[i + 1]);
                if (valOfTwoSymbols) {
                    ans += valOfTwoSymbols;
                    i++;
                    continue;
                }
            }
            ans += getValOfSymbol(s[i]);
        }
        return ans;
    }
};