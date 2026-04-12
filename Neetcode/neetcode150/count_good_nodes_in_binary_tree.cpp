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
    int goodNodes(TreeNode* root) {
        TreeNode* node = root;
        int maxVal = node->val;
        int count = dfs(node,maxVal);
        return count;
    }
    int dfs(TreeNode* node,int maxVal) {
        if(node==nullptr) {
            return 0;
        }
        int count = 0;
        if(maxVal<=node->val) {
            count++;
        }
        maxVal = max(maxVal, node->val);
        count = count+dfs(node->left, maxVal);
        count = count+dfs(node->right, maxVal);
        return count;
    }
};