class TimeMap {
 private:
  unordered_map<string, vector<pair<string, int>>> moods;

 public:
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    moods[key].push_back(make_pair(value, timestamp));
  }

  string get(string key, int timestamp) {
    if (moods.contains(key)) {
      int low = 0, high = moods[key].size() - 1;
      string most_recent;
      while (low <= high) {
        int mid = low + (high - low) / 2;
        cout << "timestamp: " << timestamp << endl;
        cout << mid << endl;
        vector<pair<string, int>> m_vec = moods[key];
        if (m_vec[mid].second == timestamp) {
          return m_vec[mid].first;
        } else if (timestamp < m_vec[mid].second) {
          high = mid - 1;
        } else {
          most_recent = m_vec[mid].first;
          low = mid + 1;
        }
      }
    return most_recent;
    }
    return "";
  }
};
