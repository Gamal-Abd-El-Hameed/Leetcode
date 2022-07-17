class Solution {
public:
    vector<string> ans;
string numberToString(char ch) {
    switch (ch) {
        case '2':
            return "abc";
        case '3':
            return "def";
        case '4':
            return "ghi";
        case '5':
            return "jkl";
        case '6':
            return "mno";
        case '7':
            return "pqrs";
        case '8':
            return "tuv";
        case '9':
            return "wxyz";
        default:
            return "";
    }
}

void helper(const string digits, int index, string output) {
    if(index == digits.length())
        return ans.push_back(output);
    string pattern = numberToString(digits[index]);
    for(char ch: pattern)
        helper(digits, index + 1, output + ch);
}
vector<string> letterCombinations(string digits) {
    if(digits.empty())
        return {};
    helper(digits, 0, "");
    return ans;
}
};