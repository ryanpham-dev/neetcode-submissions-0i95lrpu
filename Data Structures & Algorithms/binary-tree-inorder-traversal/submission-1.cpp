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
        vector<int> output {};
        stack<TreeNode*> st {};
        TreeNode* current {root};
        while (current || !st.empty()) {
            if (current) {
                st.push(current);
                current = current->left;
            }
            else {
                current = st.top();
                st.pop();
                output.push_back(current->val);
                current = current->right;
            }
        }
        return output;
    }
};