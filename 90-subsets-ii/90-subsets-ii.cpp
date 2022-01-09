class Solution {
public:
    void solve(int idx,vector<vector<int>>& ans,vector<int>& curr,vector<int>& arr){
        int n=arr.size();
        if(idx==n){
            ans.push_back(curr);
            return;
        }
        if(idx+1<n && arr[idx]==arr[idx+1]){
            int pos=idx+1;
            while(pos<n && arr[pos]==arr[idx]) ++pos;
            solve(pos,ans,curr,arr);
            int j=idx;
            while(j<pos){
                curr.push_back(arr[j]);
                solve(pos,ans,curr,arr);
                ++j;
            }
            j=idx;
            while(j<pos){
                curr.pop_back();
                ++j;
            }
        }
        else{
            solve(idx+1,ans,curr,arr);
            curr.push_back(arr[idx]);
            solve(idx+1,ans,curr,arr);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr=nums;
        sort(arr.begin(),arr.end());
        vector<int> curr;
        solve(0,ans,curr,arr);
        return ans;
    }
};