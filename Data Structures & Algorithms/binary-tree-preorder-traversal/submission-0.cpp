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
    void dfs(vector<int> &v, TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        v.push_back(root->val);
        dfs(v, root->left);
        dfs(v, root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> output;
        if (!root) return output;
        dfs(output, root);
        return output;
    }
};