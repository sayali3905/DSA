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
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MAX, LONG_MIN);
    }
    bool helper(TreeNode* node, long maxNode, long minNode) {
        if(node==nullptr) {
            return true;
        }
        if(maxNode<=node->val || minNode>=node->val) {
            return false;
        }
        return helper(node->left, node->val, minNode) && helper(node->right, maxNode, node->val);
    }
};