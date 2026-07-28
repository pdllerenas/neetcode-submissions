class Solution {
private:
    vector<vector<int>> perms = {{}};
public:
    void dfs(vector<int> nums, vector<int> iter) {
        if (nums.size() == 0) return;
        // without nums[0]
        dfs({nums.begin() + 1, nums.end()}, iter);

        // with nums[0]
        iter.push_back(nums[0]);
        perms.push_back(iter);
        dfs({nums.begin() + 1, nums.end()}, iter);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, {});
        return perms;
    }
};
