/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
 private:
  int pos = 1;
  int ans;

 public:
  void dfs(TreeNode* root, int k) {
    if (!root) return;
    dfs(root->left, k);
    if (k == pos) {
      ans = root->val;
      pos++;
      return;
    };
    pos++;
    dfs(root->right, k);
  }
  int kthSmallest(TreeNode* root, int k) { dfs(root, k); return ans; }
};
