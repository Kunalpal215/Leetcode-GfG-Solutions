class Solution {
public:
    void solve(int idx,vector<vector<int>> &ans,vector<int>& vec,vector<int> curr,int target){
        if(target==0){
            ans.push_back(curr);
        }
        for(int i=idx;i<vec.size();i++){
            if(vec[i]<=target){
                vector<int> toPass=curr;
                toPass.push_back(vec[i]);
                solve(i,ans,vec,toPass,target-vec[i]);
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        solve(0,ans,candidates,{},target);
        return ans;
    }
};