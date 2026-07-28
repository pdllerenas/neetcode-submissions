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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        int root_val = preorder[0];
        TreeNode *root = new TreeNode{root_val};
        if (preorder.size() == 1) {
            return root;
        }
        auto it = find(inorder.begin(), inorder.end(), root_val);
        vector<int> inorder_left(inorder.begin(), it);
        vector<int> inorder_right(it + 1, inorder.end());

        vector<int> preorder_left(preorder.begin() + 1, preorder.begin() + 1+inorder_left.size());
        vector<int> preorder_right(preorder.begin() + inorder_left.size() + 1, preorder.end());
        root->left = buildTree(preorder_left, inorder_left);
        root->right = buildTree(preorder_right,inorder_right);
        return root;
    }
};
