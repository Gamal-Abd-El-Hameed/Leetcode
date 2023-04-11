class Solution {
public:
    bool isValid(string s) {
    if (s.length() % 2) return false;
    stack<char> st;
    const char openingBrackets[] = {'(', '{', '['};
    const char closingBrackets[] = {')', '}', ']'};
    for (char ch : s) {
        switch (ch) {
            case '(':
            case '{':
            case '[':
                st.push(ch);
                break;
            case ')':
            case '}':
            case ']':
                if (st.empty() || st.top() != openingBrackets[find(closingBrackets, closingBrackets + 3, ch) - closingBrackets])
                    return false;
                st.pop();
                break;
        }
    }
    return st.empty();
}
};