class Solution {
 private:
  struct Compare {
    bool operator()(const vector<int>& a, const vector<int>& b) {
      int distA = a[0] * a[0] + a[1] * a[1];
      int distB = b[0] * b[0] + b[1] * b[1];
      return distA < distB;
    }
  };

 public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
    for (int i = 0; i < points.size(); i++) {
      pq.push(points[i]);
      if (pq.size() > k) {
        pq.pop();
      }
    }

    vector<vector<int>> res;
    while (!pq.empty()) {
      res.push_back(pq.top());
      pq.pop();
    }
    return res;
  }
};
