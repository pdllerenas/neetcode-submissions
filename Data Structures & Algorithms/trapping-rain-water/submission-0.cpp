class Solution {
 public:
  int trap(vector<int>& height) {
    if (height.size() < 3) {
      return 0;
    }
    int n = height.size();
    vector<int> suffix(n), prefix(n);
    int pre_maxi = -1, suff_maxi = -1;
    for (int i = 0; i < n; i++) {
        if (height[i] > pre_maxi) {
            prefix[i] = height[i];
            pre_maxi = height[i];
        } else {
            prefix[i] = pre_maxi;
        }

        if (height[n - i - 1] > suff_maxi) {
            suffix[n - i - 1] = height[n - i - 1];
            suff_maxi = height[n - i - 1];
        } else {
            suffix[n - i - 1] = suff_maxi;
        }
    }


    int water = 0;
    for (int i = 0; i < n; i++) {
        water += min(prefix[i], suffix[i]) - height[i];
    }
    return water;

  }
};
