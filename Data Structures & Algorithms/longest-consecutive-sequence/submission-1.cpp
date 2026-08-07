class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> hash;
    for (int n : nums) {
      hash.insert(n);
    }

    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (!hash.contains(nums[i] - 1)) {
        int len = 1;
        int cur = nums[i];
        while (hash.contains(cur + 1)) {
            cur++;
            len++;
        }
        res = max(len, res);
      }
    }

    return res;
  }
};
