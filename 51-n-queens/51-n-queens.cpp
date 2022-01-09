class Solution {
public:
    void solve(int i,vector<vector<string>>& ans,vector<string>& curr,int n){
        if(i==n){
            ans.push_back(curr);
            return;
        }
        for(int j=0;j<n;j++){
            curr[i][j]='Q';
            int col=j-1;
            int row=i-1;
            bool flag=false;
            while(row>=0 && col>=0){
                if(curr[row][col]=='Q'){
                    curr[i][j]='.';
                    flag=true;
                    break;
                }
                --row;
                --col;
            }
            if(flag==true) continue;
            col=j;
            row=i-1;
            while(row>=0){
                if(curr[row][col]=='Q'){
                    curr[i][j]='.';
                    flag=true;
                    break;
                }
                --row;
            }
            if(flag==true) continue;
            col=j+1;
            row=i-1;
            while(row>=0 && col<n){
                if(curr[row][col]=='Q'){
                    curr[i][j]='.';
                    flag=true;
                    break;
                }
                --row;
                ++col;
            }
            if(flag==true) continue;
            solve(i+1,ans,curr,n);
            curr[i][j]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> curr;
        string toAdd;
        for(int j=0;j<n;j++){
            toAdd+=string(1,'.');
        }
        for(int i=0;i<n;i++){
            curr.push_back(toAdd);
        }
        solve(0,ans,curr,n);
        return ans;
    }
};