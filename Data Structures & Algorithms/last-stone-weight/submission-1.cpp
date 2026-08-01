class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> heap;
        for (int w : stones) {
            heap.push(w);
        }
        while (heap.size() > 1) {
            int w1 = heap.top();
            heap.pop();
            int w2 = heap.top();
            heap.pop();
            if (w2 < w1) {
                heap.push(w1 - w2);
            }
        }
        if (heap.size() == 0) return 0;
        return heap.top();
    }
};
