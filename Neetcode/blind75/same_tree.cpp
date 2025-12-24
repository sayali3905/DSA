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
//using recursive method to compare two trees
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr) {
            return true;
        }
        if(p==nullptr || q==nullptr) {
            return false;
        }
        if(p->val!=q->val) {
            return false;
        }
        bool sameTree = isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        return sameTree;
    }
};

//using preorder traversal to compare two trees
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> result1;
        vector<int> result2;
        preorder(p,result1);
        preorder(q,result2);
        if(result1==result2) {
            return true;
        }
        else {
            return false;
        }
    }
    void preorder(TreeNode* root, vector<int>& result) {
        if(root==nullptr) {
            result.push_back(INT_MIN);
            return;
        }
        result.push_back(root->val);
        preorder(root->left, result);
        preorder(root->right, result);
    }
};
