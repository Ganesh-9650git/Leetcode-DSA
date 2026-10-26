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
int result=0;
void func(TreeNode* root,int sum){
    if(root==NULL) return;
    sum=sum*10+root->val;
    if(root->left==NULL && root->right==NULL){
        result+=sum;
        return;
    }
    func(root->left,sum);
    func(root->right,sum);
}
    int sumNumbers(TreeNode* root) {
        int sum=0;
            func(root,sum);
return result;
    }
};