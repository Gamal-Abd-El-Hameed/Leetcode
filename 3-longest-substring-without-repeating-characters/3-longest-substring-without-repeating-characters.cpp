class Solution {
public:
   int lengthOfLongestSubstring(string s) {
    int j = 0, best = 0, n = s.length();
    string temp = "";
    char ch;
    while(j < n) {
        best = max(best, (int)temp.length());
        ch = s[j];
        if(temp.find(ch) != string::npos) {
            temp = temp.substr(1);
        }
        else {
            temp.push_back(ch);
            ++j;
        }
    }
    best = max(best, (int)temp.length());
    return best;
}
};