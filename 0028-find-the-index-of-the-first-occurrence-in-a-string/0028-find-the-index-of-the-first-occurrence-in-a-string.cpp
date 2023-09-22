class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int haystackIterator = 0; haystackIterator < haystack.length(); haystackIterator++) {
            bool isFound = true;
            for (int needleIterator = 0; needleIterator < needle.length(); needleIterator++) {
                if (haystack[haystackIterator + needleIterator] != needle[needleIterator]) {
                    isFound = false;
                    break;
                }
            }
            if (isFound)
                return haystackIterator;
        }
        return -1;
    }
};