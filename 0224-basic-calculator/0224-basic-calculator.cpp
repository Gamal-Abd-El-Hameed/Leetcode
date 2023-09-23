class Solution {
public:
    int calculate(string s) {
        stack<int> numbers;
        stack<char> operators;
        int res = 0, num = 0, sign = 1;

        for (char c:s) {
            if (isdigit(c)) {
                num = 10 * num + (c - '0');
            }
            else if (c == '+' || c == '-') {
                res += sign * num;
                num = 0;
                sign = (c == '+') ? 1 : -1;
            }
            else if (c == '(') {
                numbers.push(res);
                operators.push(sign);
                res = 0;
                sign = 1;
            }
            else if (c == ')') {
                res += sign * num;
                num = 0;
                res *= operators.top(); operators.pop();
                res += numbers.top(); numbers.pop();
            }
        }

        res += sign * num;
        return res;
    }
};