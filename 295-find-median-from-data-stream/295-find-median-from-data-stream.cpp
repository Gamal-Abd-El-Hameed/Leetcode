class MedianFinder {
    priority_queue<int> leftHeap;
    priority_queue<int, vector<int>, greater<>> rightHeap;
    double median;
public:
    MedianFinder() {

    }

    void addNum(int num) {
        if(leftHeap.empty() && rightHeap.empty()) {
            median = num;
            leftHeap.push(num);
            return;
        }
        if(leftHeap.size() > rightHeap.size()) {
            if(num < median) {
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
                leftHeap.push(num);
            }
            else
                rightHeap.push(num);
            median = (leftHeap.top() + rightHeap.top()) / 2.0;
        }
        else if(leftHeap.size() == rightHeap.size()) {
            if(num < median) {
                leftHeap.push(num);
                median = leftHeap.top();
            }
            else {
                rightHeap.push(num);
                median = rightHeap.top();
            }
        }
        else {
            if(num > median) {
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(num);
            }
            else
                leftHeap.push(num);
            median = (leftHeap.top() + rightHeap.top()) / 2.0;
        }
    }

    double findMedian() {
        return median;
    }
};