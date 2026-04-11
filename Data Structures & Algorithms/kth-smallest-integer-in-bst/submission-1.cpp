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
    int kthSmallest(TreeNode* root, int kClosest) {
        TreeNode* current = root;
        while (current != nullptr) {
            if (current->left == nullptr) {
                kClosest--;
                if (kClosest == 0) {
                    return current->val;
                }
                current = current->right;
            } else {
                TreeNode* predecessor = current->left;
                while (predecessor->right != nullptr && predecessor->right != current) {
                    predecessor = predecessor->right;
                }
                if (predecessor->right == nullptr) {
                    predecessor->right = current;
                    current = current->left;
                } else {
                    predecessor->right = nullptr;
                    kClosest--;
                    if (kClosest == 0) {
                        return current->val;
                    }
                    current = current->right;
                }
            }
        }
        return -1;
    }
};