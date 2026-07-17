class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash = {};
        for (int n : nums){
            hash[n]++;
        }

        priority_queue<pair<int, int>> pq;
        for(auto &p : hash) {
            pq.push({p.second, p.first});
        }

        vector<int> res;
        res.reserve(k);
        for (int i = 0; i < k; i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
