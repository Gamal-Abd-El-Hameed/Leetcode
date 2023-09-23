class MinStack {
    vector<int> s, minStack;
public:
    MinStack() {}

    void push(int val) {
        s.push_back(val);
        if (minStack.empty() || val <= minStack.back()) {
            minStack.push_back(val);
        }
    }

    void pop() {
        if (s.back() == minStack.back()) {
            minStack.pop_back();
        }
        s.pop_back();
    }

    int top() {
        return s.back();
    }

    int getMin() {
        return minStack.back();
    }
};