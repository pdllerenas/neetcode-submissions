class Solution {
 public:
  // assumes size a < size b
  double findPartition(vector<int>& a, vector<int>& b) {
    int n = a.size(), m = b.size();
    int low = 0;
    int high = n;
    while (low <= high) {
      int partitionA = (low + high) / 2;
      int partitionB = (n + m + 1) / 2 - partitionA;

      int leftA = (partitionA == 0) ? INT_MIN : a[partitionA - 1];
      int rightA = (partitionA == n) ? INT_MAX : a[partitionA];

      int leftB = (partitionB == 0) ? INT_MIN : b[partitionB - 1];
      int rightB = (partitionB == m) ? INT_MAX : b[partitionB];

      if (leftA <= rightB && leftB <= rightA) {
        if ((n + m) % 2) {
          return max(leftA, leftB);
        } else {
          return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
        }
      }

      if (leftA > leftB) {
        high = partitionA - 1;
      } else {
        low = partitionA + 1;
      }
    }
  }
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    double median;
    if (n < m) {
      median = findPartition(nums1, nums2);
    } else {
      median = findPartition(nums2, nums1);
    }
    return median;
  }
};
