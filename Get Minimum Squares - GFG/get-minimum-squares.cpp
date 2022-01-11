// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int solve(int n,vector<int>& dp){
	    if(n==0) return 0;
	    int m=dp.size();
	    int i=1;
	    int ans=n;
	    while((i*i)<=n){
	        int a=n-(i*i);
	        if(dp[a]==-1){
	            dp[a]=solve(a,dp);
	        }
	        ans=min(dp[a]+1,ans);
	        ++i;
	    }
	    return ans;
	}
	int MinSquares(int n)
	{
	    vector<int> dp(n+1,-1);
	    return solve(n,dp);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends