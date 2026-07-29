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
    int best = INT_MIN;
public:
    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int leftMax = dfs(root->left);
        int rightMax = dfs(root->right);
        leftMax = max(leftMax, 0);
        rightMax = max(rightMax, 0);
        int sum = root->val + leftMax + rightMax;
        if (sum > best) {
            best = sum;
        }
        return root->val + max(leftMax, rightMax);
    }
    int maxPathSum(TreeNode* root) {
        best = root->val;
        dfs(root);
        return best;
    }
};
