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
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        while(!q.empty()) {
            TreeNode* rightmost = q.back();
            res.push_back(rightmost->val);
            int qLen = q.size();
            for (int i = 0; i < qLen; ++i) {
                TreeNode* cur = q.front();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                q.pop();
            }
        }
        return res;
    }
};
