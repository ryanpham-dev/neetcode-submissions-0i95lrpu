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
    vector<int> inorderTraversal(TreeNode* root) {
        auto output = vector<int>{};
        dfs(output, root);
        return output;
    }

    void dfs(vector<int>&v, TreeNode* root) {
        if (root == nullptr) return;
        dfs(v, root->left);
        v.push_back(root->val);
        dfs(v, root->right);
    }
};