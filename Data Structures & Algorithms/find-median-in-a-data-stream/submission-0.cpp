class MedianFinder {
    // we must keep them balanced (at most diff of 1). WLOG, we keep maxHeap equal or larger (by 1) than minHeap
    priority_queue<int, vector<int>> maxHeap; // left side of array
    priority_queue<int, vector<int>, greater<int>> minHeap; // right side of array
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};
