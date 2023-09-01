class MedianFinder {
private:
    priority_queue<int> leftHeap; // Store the lower half
    priority_queue<int, vector<int>, greater<>> rightHeap; // Store the upper half

public:
    MedianFinder() {}

    void addNum(int num) {
        if (leftHeap.empty() || num <= leftHeap.top()) {
            leftHeap.push(num);
        } else {
            rightHeap.push(num);
        }

        // Balance the heaps if necessary
        if (leftHeap.size() > rightHeap.size() + 1) {
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
        } else if (rightHeap.size() > leftHeap.size()) {
            leftHeap.push(rightHeap.top());
            rightHeap.pop();
        }
    }

    double findMedian() {
        if (leftHeap.size() == rightHeap.size()) {
            return (static_cast<double>(leftHeap.top()) + rightHeap.top()) / 2.0;
        } else {
            return static_cast<double>(leftHeap.top());
        }
    }
};