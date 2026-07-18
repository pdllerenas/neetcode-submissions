class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = (int)numbers.size() - 1;
        int prev = numbers[r];
        while (l < r) {
            int diff = target - numbers[r];
            
            if (numbers[l] == diff) {
                return {l + 1, r + 1};
            } else if (numbers[l] > diff) {
                while (numbers[r] == numbers[r-1]) {
                    r--;
                }
                r--;
            } else {
                while (numbers[l] == numbers[l+1]) {
                    l++;
                }
                l++;
            }
        }
        return {};
    }
};
