class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    // n (n + 1) / 2 - sum(nums)
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] <= nums.size() && nums[nums[i] - 1] > nums.size()) {
        return nums[i];
      }
      if (nums[i] > nums.size()) {
        if (nums[nums[i] - nums.size() - 1] > nums.size()) {
          return nums[i] - nums.size();
        } else {
          nums[nums[i] - nums.size() - 1] += nums.size();
        }
      } else {
        nums[nums[i] - 1] += nums.size();
      }
    }
    return 0;
  }
};
