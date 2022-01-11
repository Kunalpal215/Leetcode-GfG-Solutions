class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int i=0;
        map<int,int> mp;
        int last=-1;
        int ans=0;
        while(i<n){
            if(mp.find(fruits[i])==mp.end()){
                if(mp.size()==0){
                    mp[fruits[i]]+=1;
                    int sum=0;
                    for(auto it : mp) sum+=it.second;
                    ans=max(ans,sum);
                    last=i;
                }
                else if(mp.size()==1){
                    mp[fruits[i]]+=1;
                    int sum=0;
                    for(auto it : mp) sum+=it.second;
                    ans=max(ans,sum);
                    last=i;
                }
                else{
                    int sum=0;
                    for(auto it : mp) sum+=it.second;
                    ans=max(ans,sum);
                    auto check=mp.begin();
                    auto it = mp.begin();
                    while(it!=mp.end()){
                        if(it->first!=fruits[last]){
                            check=it;
                            break;
                        }
                        ++it;
                    }
                    mp.erase(check);
                    mp[fruits[last]]=i-last;
                    mp[fruits[i]]+=1;
                    last=i;
                }
            }
            else{
                if(fruits[i]!=fruits[last]){
                    last=i;
                }
                mp[fruits[i]]+=1;
                int sum=0;
                for(auto it : mp) sum+=it.second;
                ans=max(ans,sum);
            }
            ++i;
        }
        return ans;
    }
};