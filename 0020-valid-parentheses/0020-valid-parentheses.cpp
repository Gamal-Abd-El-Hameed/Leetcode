class Solution {
public:
    bool isValid(string s) {
    stack<char> st;
    char temp;
    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[')
            st.push(ch);
        else {
            if (st.empty())
                return false;
            temp = st.top();
            st.pop();
            if (ch == ')' && temp != '(')
                return false;
            else if (ch == '}' && temp != '{')
                return false;
            else if (ch == ']' && temp != '[')
                return false;
        }
    }
    return st.empty();
}
};