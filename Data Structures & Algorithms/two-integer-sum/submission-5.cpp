class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++){
            int s = target - nums[i];
            for (int j = 0; j < i; j++){
                if (nums[j] == s){
                    return vector<int>{j, i};
                }
            }
            for (int j = i + 1; j < nums.size(); j++){
                if (nums[j] == s){
                    return vector<int>{i, j};
                }
            }
        }
    }
};
