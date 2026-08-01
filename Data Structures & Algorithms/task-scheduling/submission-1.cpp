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
    queue<pair<int, int>> q;
    int time = 0;
    while (!maxHeap.empty() || !q.empty()) {
      time++;
      if (!maxHeap.empty()) {
        int count = maxHeap.top() - 1;
        maxHeap.pop();
        if (count > 0) {
          q.push({count, time + n});
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
