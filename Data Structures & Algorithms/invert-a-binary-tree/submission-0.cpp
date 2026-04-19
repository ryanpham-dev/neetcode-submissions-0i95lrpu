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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        invert(root->left, root->right);
        return root;
    }

    void invert(TreeNode* r1, TreeNode* r2) {
        if (r1 && r2) {
        std::swap(r1->val, r2->val);
        invert(r1->left, r2->right);
        invert(r1->right, r2->left);
        } else {
            std::swap(r1, r2);
        }
    }


};
