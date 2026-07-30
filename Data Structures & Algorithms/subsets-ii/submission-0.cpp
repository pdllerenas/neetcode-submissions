class Solution {
private:
    vector<vector<int>> res;
    void dfs(vector<int> &nums, vector<int> cur, int i) {
        if (i == nums.size()) {
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[i]);
        dfs(nums, cur, i+1);
        cur.pop_back();

        while (i < nums.size() - 1 && nums[i] == nums[i+1]) i++;
        dfs(nums, cur, i+1);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       dfs(nums, {}, 0);
       return res;
    }
};
