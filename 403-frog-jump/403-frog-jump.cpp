class Solution {
public:
    int solve(int i,int k,map<int,map<int,int>> &mp,vector<int>& stones){
        int n=stones.size();
        if(i==n-1) return 1;
        int b=k;
        int res=-1;
        if(i==0){
            for(int j=i+1;j<n;j++){
            if(stones[j]-stones[i]>b) break;
            if(stones[j]-stones[i]==b){
                if(mp[j][b]==0) mp[j][b]=solve(j,b,mp,stones);
                if(mp[j][b]==1) res=1;
            }
                
        }
            return res;
        }
        int a=k-1;
        int c=k+1;
        for(int j=i+1;j<n;j++){
            if(stones[j]-stones[i]>a) break;
            if(stones[j]-stones[i]==a){
                if(mp[j][a]==0) mp[j][a]=solve(j,a,mp,stones);
                if(mp[j][a]==1) res=1;
            }
        }
        for(int j=i+1;j<n;j++){
            if(stones[j]-stones[i]>b) break;
            if(stones[j]-stones[i]==b){
                if(mp[j][b]==0) mp[j][b]=solve(j,b,mp,stones);
                if(mp[j][b]==1) res=1;
            }
        }
        for(int j=i+1;j<n;j++){
            if(stones[j]-stones[i]>c) break;
            if(stones[j]-stones[i]==c){
                if(mp[j][c]==0) mp[j][c]=solve(j,c,mp,stones);
                if(mp[j][c]==1) res=1;
            }
        }
        return res;
    }
    bool canCross(vector<int>& stones) {
        map<int,map<int,int>> mp;
        int n=stones.size();
        int res = solve(0,1,mp,stones);
        if(res==1) return true;
        return false;
    }
};