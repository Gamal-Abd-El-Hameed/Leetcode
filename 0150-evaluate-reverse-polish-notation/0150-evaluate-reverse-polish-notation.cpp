class Solution {
private:
    bool isSymbol(const string &token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
    int applyOperation(char operation, int firstNumber, int secondNumber) {
        switch (operation) {
            case '+':
                return firstNumber + secondNumber;
            case '-':
                return firstNumber - secondNumber;
            case '*':
                return firstNumber * secondNumber;
            case '/':
                return firstNumber / secondNumber;
            default:
                return 0;
        }
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        for (auto &token:tokens) {
            if (isSymbol(token)) {
                int secondNumber = numbers.top();
                numbers.pop();
                int firstNumber = numbers.top();
                numbers.pop();
                numbers.push(applyOperation(token[0], firstNumber, secondNumber));
            }
            else {
                numbers.push(stoi(token));
            }
        }
        return numbers.top();
    }
};