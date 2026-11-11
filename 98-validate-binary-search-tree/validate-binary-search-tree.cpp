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

bool helper(TreeNode* root,long minrange,long maxrange){
    if(root==NULL) return true;
    if(root->val<=minrange || root->val>=maxrange){
        return false;
    }
    return helper( root->left, minrange, root->val)
    && helper( root->right, root->val, maxrange);
}
    bool isValidBST(TreeNode* root) {
        long  minrange=LONG_MIN;
        long maxrange=LONG_MAX;
        return helper(root,minrange,maxrange);
    }
};