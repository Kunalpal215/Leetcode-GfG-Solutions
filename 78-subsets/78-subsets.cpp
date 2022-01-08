class Solution {
public:
    void solve(vector<vector<int>> &ans,int j,vector<int>& nums){
        if(j==nums.size()) return;
        int n=ans.size();
        for(int i=0;i<n;i++){
            ans.push_back(ans[i]);
        }
        for(int i=n;i<ans.size();i++){
            ans[i].push_back(nums[j]);
        }
        solve(ans,j+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        solve(ans,0,nums);
        return ans;
    }
};