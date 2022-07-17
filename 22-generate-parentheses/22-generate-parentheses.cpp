class Solution {
public:
    vector<string> ans;

void generateParenthesisHelper(int open, int close, string s) {
    if(open == 0) {
        while(close--)
            s.push_back(')');
        ans.push_back(s);
        return;
    }
    generateParenthesisHelper(open - 1, close, s + '('); // open only when equal
    if(open == close) {
        return;
    }
    generateParenthesisHelper(open, close - 1, s + ')');
}

vector<string> generateParenthesis(int n) {
    if(n == 0)
        return {};
    generateParenthesisHelper(n - 1, n, "(");
    return ans;
}
};