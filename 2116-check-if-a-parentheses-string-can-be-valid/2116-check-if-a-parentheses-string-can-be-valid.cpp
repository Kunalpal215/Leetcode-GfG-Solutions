class Solution {
public:
    bool canBeValid(string s, string locked) {
        int open =0;
        int close=0;
        int free=0;
        for(int i=0;i<s.length();i++){
            if(locked[i]=='0'){
                ++free;
            }
            else{
                if(s[i]=='(') ++open;
                else ++close;
            }
            if(close>open){
                int diff=close-open;
                int check=free-diff;
                if(check<0){
                    return false;
                }
            }
        }
        if((open>close && free<open-close) || (free-open+close)%2==1) return false;
        open=0;
        close=0;
        free=0;
        for(int i=s.length()-1;i>=0;i--){
            if(locked[i]=='0'){
                ++free;
            }
            else{
                if(s[i]=='(') ++open;
                else ++close;
            }
            if(close<open){
                int diff=open-close;
                int check=free-diff;
                if(check<0){
                    return false;
                }
            }
        }
        if((close>open && free<close-open) || (free-close+open)%2==1) return false;
        return true;
    }
};