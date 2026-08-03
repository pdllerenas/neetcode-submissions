class Solution {
public:
    bool isValid(vector<int>& nums, int t, int p) {
        int i = 0, cnt = 0;
        while (i < nums.size() - 1) {
            if (abs(nums[i] - nums[i+1]) <= t) {
                cnt++;
                i += 2;
            } else {
                i += 1;
            }
            if (cnt == p) {
                return true;
            }
        }
        return false;
    }

    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0;
       sort(nums.begin(), nums.end());
        int l = 0, r = pow(10, 9);
        int res = r;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (isValid(nums, m, p)) {
                res = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

       return res;
    }
};