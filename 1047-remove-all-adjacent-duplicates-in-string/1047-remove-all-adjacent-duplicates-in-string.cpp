class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> pre;
        int n=s.length();
        stack<char> suf;
        int i=n-1;
        while(i>=0){
            suf.push(s[i]);
            --i;
        }
        while(!suf.empty()){
            if(pre.empty()){
                pre.push(suf.top());
                suf.pop();
            }
            else{
                if(pre.top()==suf.top()){
                    pre.pop();
                    suf.pop();
                }
                else{
                    pre.push(suf.top());
                    suf.pop();
                }
            }
        }
        string ans;
        while(!pre.empty()){
            ans=string(1,pre.top())+ans;
            pre.pop();
        }
        return ans;
    }
};