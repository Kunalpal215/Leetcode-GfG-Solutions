class Solution {
public:
    void solve(int i,vector<vector<int>> &ans, vector<int> curr, vector<int> &vec,int target){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        for(int idx=i;idx<vec.size();idx++){
            if(vec[idx]<=target){
                int newTarget=target-vec[idx];
                vector<int> toPass=curr;
                while(newTarget>=0){
                    toPass.push_back(vec[idx]);
                    solve(idx+1,ans,toPass,vec,newTarget);
                    newTarget-=vec[idx];
                }
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        solve(0,ans,{},candidates,target);
        return ans;
    }
};