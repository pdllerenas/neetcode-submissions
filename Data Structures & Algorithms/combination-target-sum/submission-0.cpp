class Solution {
private:
    vector<vector<int>> res;
public:

    void dfs(vector<int> nums, vector<int> perm, int sum, int target) {
        if (sum > target) return;
        if (sum == target) {
            res.push_back(perm);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            perm.push_back(nums[i]);
            dfs({nums.begin() + i, nums.end()}, perm, sum + nums[i], target);
            perm.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(nums, {}, 0, target);
        return res;
    }
};
