// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(vector<string>& ans,vector<vector<int>>& arr, int r,int c,string path){
        int n=arr.size();
        if(arr[r][c]==0) return;
        if(r==n-1 && c==n-1){
            ans.push_back(path);
            return;
        }
        arr[r][c]=0;
        if(r-1>=0){
            solve(ans,arr,r-1,c,path+"U");
        }
        if(r+1<n){
            solve(ans,arr,r+1,c,path+"D");
        }
        if(c-1>=0){
            solve(ans,arr,r,c-1,path+"L");
        }
        if(c+1<n){
            solve(ans,arr,r,c+1,path+"R");
        }
        arr[r][c]=1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        solve(ans,m,0,0,"");
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends