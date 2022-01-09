class Solution {
public:
    bool isPalindrome(string str){
        int i=0;
        int n=str.length()/2;
        while(i<n){
            if(str[i]!=str[str.length()-i-1]) return false;
            ++i;
        }
        return true;
    }
    void solve(int idx,vector<vector<string>>& ans,vector<string>& curr,string s){
        if(idx==s.length()){
            ans.push_back(curr);
            return;
        }
        string add="";
        for(int i=idx;i<s.length();i++){
            add=add+string(1,s[i]);
            if(isPalindrome(add)==true){
                curr.push_back(add);
                solve(i+1,ans,curr,s);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        solve(0,ans,curr,s);
        return ans;
    }
};