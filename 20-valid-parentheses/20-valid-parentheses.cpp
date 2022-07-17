class Solution {
    bool isSameTypeofBrackets(char open, char close) {
    if(open == '(' && close == ')')
        return true;
    if(open == '[' && close == ']')
        return true;
    if(open == '{' && close == '}')
        return true;
    return false;
}
public:
    bool isValid(string s) { // ")][{{}}]"
    stack<char> brackets; // [(
    for(char ch: s) {
        if(ch == '(' || ch == '{' || ch == '[')
            brackets.push(ch);
        else {
            if(brackets.empty())
                return false;
            if(!isSameTypeofBrackets(brackets.top(), ch))
                return false;
            brackets.pop();
        }
    }
    return brackets.empty();
}
};