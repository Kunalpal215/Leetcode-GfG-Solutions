// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int mod=1e9+7;
	int solve(int i,int n,vector<long long>& dp){
	    if(i==n-1) return 1;
	    if(dp[i+1]==-1) dp[i+1]=solve(i+1,n,dp);
	    long long ans=dp[i+1];
	    if(i+2<n){
	        if(dp[i+2]==-1) dp[i+2]=solve(i+2,n,dp);
	        ans=ans+dp[i+2];
	        ans=ans%mod;
	    }
	    return ans;
	}
		int nthPoint(int n){
		    vector<long long> dp(n,-1);
		    return solve(-1,n,dp);
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
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends