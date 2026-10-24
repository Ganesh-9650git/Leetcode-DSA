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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans =0;

        if(root==NULL) return 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            long long size=q.size();
            long long minm=q.front().second;
            long long first,last;
            for(int i=0;i<size;i++){
                long long curr_idx=q.front().second-minm;
                TreeNode* root=q.front().first;
                q.pop();
                if(i==0) first=curr_idx;
                if(i==size-1) last=curr_idx;

                if(root->left!=NULL) q.push({root->left,curr_idx*2+1}); 
                if(root->right!=NULL) q.push({root->right,curr_idx*2+2}); 

            }
            ans=max(ans,last-first+1);
        }
        return (int)ans;
    }
};