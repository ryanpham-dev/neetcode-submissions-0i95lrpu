
class Solution {
    int maxHeight {};
  int height(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    int left = height(root->left);
    int right = height(root->right);
    maxHeight = max(left + right, maxHeight);
    return 1 + std::max(left, right);
  }

public:
  int diameterOfBinaryTree(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    return height(root->left) + height(root->right);
  }
};