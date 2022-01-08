// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool solve(int i,int n,int req,vector<vector<int>> &vec,int arr[]){
        if(req==arr[i]){
            vec[i][req]=1;
            return true;
        }
        if(i==n-1){
            return false;
        }
        if(req-arr[i]>0){
            if(vec[i+1][req-arr[i]]==1){
                return true;
            }
            else if(vec[i+1][req-arr[i]]==-1){
                bool res = solve(i+1,n,req-arr[i],vec,arr);
                if(res==true){
                    vec[i+1][req-arr[i]]=1;
                    return true;
                }
                else{
                    vec[i+1][req-arr[i]]=0;
                }
            }
        }
        if(vec[i+1][req]==1){
                return true;
            }
            else if(vec[i+1][req]==-1){
                bool res = solve(i+1,n,req,vec,arr);
                if(res==true){
                    vec[i+1][req]=1;
                    return true;
                }
                else{
                    vec[i+1][req]=0;
                }
            }
        return false;
    }
    bool isSubsetSum(int n, int arr[], int sum){
        vector<vector<int>> dp(100,vector<int>(100001,-1));
        return solve(0,n,sum,dp,arr);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends