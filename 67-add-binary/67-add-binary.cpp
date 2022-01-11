class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        char rem='0';
        int i=0;
        int j=0;
        string res;
        while(i<a.length() && j<b.length()){
            int count=0;
            if(rem=='1') ++count;
            if(a[i]=='1') ++count;
            if(b[j]=='1') ++count;
            if(count==0) res=res+string(1,'0');
            else if(count==1){
                res=res+string(1,'1');
                rem='0';
            }
            else if(count==2){
                res=res+string(1,'0');
                rem='1';
            }
            else{
                res=res+string(1,'1');
                rem='1';
            }
            ++i;
            ++j;
        }
        while(i<a.length()){
            int count=0;
            if(rem=='1') ++count;
            if(a[i]=='1') ++count;
            if(count==0) res=res+string(1,'0');
            else if(count==1){
                res=res+string(1,'1');
                rem='0';
            }
            else if(count==2){
                res=res+string(1,'0');
                rem='1';
            }
            ++i;
        }
        while(j<b.length()){
            int count=0;
            if(rem=='1') ++count;
            if(b[j]=='1') ++count;
            if(count==0) res=res+string(1,'0');
            else if(count==1){
                res=res+string(1,'1');
                rem='0';
            }
            else if(count==2){
                res=res+string(1,'0');
                rem='1';
            }
            ++j;
        }
        if(rem=='1') res=res+string(1,'1');
        reverse(res.begin(),res.end());
        return res;
    }
};