class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minStrLen = INT_MAX, longestCommonPrefixLen;
        for (string str:strs)
            minStrLen = min(minStrLen, (int)str.length());
        char currChar;
        for (longestCommonPrefixLen = 0; longestCommonPrefixLen < minStrLen; longestCommonPrefixLen++) {
            currChar = strs[0][longestCommonPrefixLen];
            for (int strsCounter = 1; strsCounter < strs.size(); strsCounter++)
                if (strs[strsCounter][longestCommonPrefixLen] != currChar)
                    return strs[0].substr(0, longestCommonPrefixLen);
        }
        return strs[0].substr(0, longestCommonPrefixLen);
    }
};