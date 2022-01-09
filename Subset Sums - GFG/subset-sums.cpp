// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void solve(vector<int>& ans,vector<int>& arr,int i,int n){
        if(i==n) return;
        vector<int> back=ans;
        for(int j=0;j<back.size();j++){
            back[j]+=arr[i];
        }
        int p1=0;
        int p2=0;
        vector<int> swap;
        while(p1<ans.size() && p2<ans.size()){
            if(ans[p1]<=back[p2]){
                swap.push_back(ans[p1]);
                ++p1;
            }
            else{
                swap.push_back(back[p2]);
                ++p2;
            }
        }
        while(p1<ans.size()){
            swap.push_back(ans[p1]);
            ++p1;
        }
        while(p2<back.size()){
            swap.push_back(back[p2]);
            ++p2;
        }
        ans=swap;
        solve(ans,arr,i+1,n);
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int> ans={0};
        solve(ans,arr,0,n);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends