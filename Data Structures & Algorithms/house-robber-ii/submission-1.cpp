class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    int rob1 = 0, rob2 = 0;
    int best1;
    for (int i = 0; i < nums.size() - 1; ++i) {
      int num = nums[i];
      int temp = max(num + rob1, rob2);
      rob1 = rob2;
      rob2 = temp;
    }
    best1 = rob2;

    int best2;
    rob1 = 0, rob2 = 0;
    for (int i = 1; i < nums.size(); ++i) {
      int num = nums[i];
      int temp = max(num + rob1, rob2);
      rob1 = rob2;
      rob2 = temp;
    }
    best2 = rob2;
    return max(best1, best2);
  }
};
