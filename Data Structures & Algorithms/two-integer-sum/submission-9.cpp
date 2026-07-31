class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> hash;
       for (int i = 0; i < nums.size(); ++i) {
        int t = target - nums[i];
        for (int j = i + 1; j < nums.size(); ++j) {
            if (t == nums[j]) return {i, j};
            hash[i] = j;
        }
       }
       return {};
    }
};
