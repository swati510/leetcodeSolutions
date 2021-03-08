class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int>res;
       map<pair<int,int>,int>mp;
       vector<int>cnt(n+1,0);
        vector<int>scnt(n+1,0);
        for(auto i:edges){
            int minm=min(i[0],i[1]);
            int maxm=max(i[0],i[1]);
            mp[{minm,maxm}]++;
            cnt[minm]++;
            scnt[minm]++;
            cnt[maxm]++;
            scnt[maxm]++;
        }
    sort(res.begin(),res.end());
    sort(scnt.begin(),scnt.end());
    vector<int>ans;
        for(auto q:queries){
           int ans1=0;
            int i=1,j=n;
            while(i<j){
                if(scnt[i]+scnt[j]>q){
                    ans1+=(j--)-i;
                   // j--;
                }
                else i++;
            }
            for(auto e:mp){
                int u=e.first.first;
                int v=e.first.second;
                int w=e.second;
                if(cnt[u]+cnt[v]>q&&cnt[u]+cnt[v]<=q+mp[{u,v}])ans1--;
            }
            
            ans.push_back(ans1);
            
        }
           
        return ans;
        
        
    }
};