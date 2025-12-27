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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int smallestValue = 0; 
        dfs(root, k, count, smallestValue);
        return smallestValue;
    }
    void dfs(TreeNode* node, int k, int& count, int& smallestValue) {
        if(node==nullptr || count>=k) {
            return;
        }
        dfs(node->left, k, count, smallestValue);
        count++;
        if(count==k) {
            smallestValue = node->val;
            return;
        }
        dfs(node->right, k, count, smallestValue);
        return;
    }
};