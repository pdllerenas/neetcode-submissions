class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> hash = {};
        for (auto n : nums){
            if (hash.contains(n)) {
                return true;
            }
            hash.insert(n);
        }
        return false;
    }
};