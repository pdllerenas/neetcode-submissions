class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1, high = *max_element(piles.begin(), piles.end());
    int n = piles.size();
    int best_k = high;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int hours = 0;
      for (int i = 0; i < n; i++) {
        hours += (piles[i] + mid - 1) / mid;
      }
      if (hours <= h) {
        if (best_k > mid) {
            best_k = mid;
        }
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return best_k;
  }
};
