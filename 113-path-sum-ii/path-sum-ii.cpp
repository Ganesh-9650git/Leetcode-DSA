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
vector<vector<int> > result;
vector<int> ans ;
void func(TreeNode* root, int targetSum,int sum){
    if(root==NULL ) return;
    sum=sum+root->val;
    ans.push_back(root->val);
    if(root->left==NULL && root-> right==NULL){
        if(sum==targetSum){
            result.push_back(ans);
            ans.pop_back();
            return;
        }
    }
    func(root->left,targetSum,sum);
    func(root->right,targetSum,sum);
    ans.pop_back();
    return;

}

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        func(root,targetSum,sum);
        return result;
    }
};