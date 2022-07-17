class Solution {
    public:
    bool isValid(string s) {
    stack<char> brackets;
    for(char ch: s) {
        switch (ch) {
            case '(':
            case '[':
            case '{':
                brackets.push(ch);
                break;
            case ')':
                if(brackets.empty())
                    return false;
                if(brackets.top() != '(')
                    return false;
                brackets.pop();
                break;
            case ']':
                if(brackets.empty())
                    return false;
                if(brackets.top() != '[')
                    return false;
                brackets.pop();
                break;
            case '}':
                if(brackets.empty())
                    return false;
                if(brackets.top() != '{')
                    return false;
                brackets.pop();
        }
    }
    return brackets.empty();
}
};