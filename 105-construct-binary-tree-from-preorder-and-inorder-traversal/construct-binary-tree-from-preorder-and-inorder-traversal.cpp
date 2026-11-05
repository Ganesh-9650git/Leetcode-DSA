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
int idx=0;
unordered_map<int,int> inmap;
    TreeNode* makeTree( vector<int>& preorder,int low ,int high){
        if(low>high) return NULL;
        TreeNode* root=new TreeNode(preorder[idx]);
        idx++;
        int id=inmap[root->val];
        root->left=makeTree(preorder, low , id-1);
        root->right=makeTree(preorder, id+1, high);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]]=i;
        }
        return makeTree(preorder,0,inorder.size()-1);
    }
};