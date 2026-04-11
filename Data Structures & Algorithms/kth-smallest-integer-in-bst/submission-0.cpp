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
    void dfs(std::vector<int>& vec, TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        dfs(vec, root->left);
        vec.emplace_back(root->val);
        dfs(vec, root->right);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr) {
            return -1;
        }
        std::vector<int> vec{};
        dfs(vec, root);
        return vec[k - 1];
    }
};