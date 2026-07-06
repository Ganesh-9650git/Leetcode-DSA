class Solution {
public:

    void getsub(vector<int>& nums,vector<int>& ans,int i,vector<vector<int>>& result){
        if(i==nums.size()){
        result.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        getsub(nums,ans,i+1,result);
        ans.pop_back();
        getsub(nums,ans,i+1,result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> result;
        getsub(nums,ans,0,result);
        return result;
    }
};