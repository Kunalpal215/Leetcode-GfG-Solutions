class Solution {
public:
    void solve(int i,vector<vector<int>>& ans, vector<int> curr,vector<int>& vec,int target){
        int n=vec.size();
        if(i==n){
            if(target==0) ans.push_back(curr);
            return;
        }
            if(i+1<n && vec[i]==vec[i+1]){
                int pos=i+1;
                while(pos<n && vec[pos]==vec[i]) ++pos;
                int newTarget=target;
                int j=i;
                vector<int> toPass=curr;
                while(j<pos && vec[j]<=newTarget){
                    newTarget-=vec[j];
                    toPass.push_back(vec[j]);
                    solve(pos,ans,toPass,vec,newTarget);
                    ++j;
                }
                solve(pos,ans,curr,vec,target);
            }
            else{
                solve(i+1,ans,curr,vec,target);
                if(vec[i]<=target){
                    vector<int> toPass=curr;
                    toPass.push_back(vec[i]);
                    solve(i+1,ans,toPass,vec,target-vec[i]);
                }
            }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        solve(0,ans,{},candidates,target);
        return ans;
    }
};