class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       vector<int> frequencies(26, 0);
       for (char c : tasks) {
         frequencies[c - 'A']++;
       }
       priority_queue<int, vector<int>> maxHeap;
       for (int f : frequencies) {
        if (f > 0) {
            maxHeap.push(f);
        }
       }
       int time = 0;
       queue<pair<int, int>> q;
       while (!q.empty() || !maxHeap.empty()) {
        time++;
        if (maxHeap.empty()) {
            time = q.front().second;
        } else {
            int cnt = maxHeap.top() - 1;
            maxHeap.pop();
            if (cnt > 0) {
                q.push({cnt, time + n});
            }
        }
        if (!q.empty() && q.front().second == time) {
            maxHeap.push(q.front().first);
            q.pop();
        }
       }
       return time;
    }
};
