class Solution {
public:
    vector<vector<int>>dp;
   long long int minDistance(int low,int high ,vector<int>a){
        
        int mid=(low+high)/2;
        long long int distance=0;
        for(int i=low;i<=high;i++)distance+=abs(a[i]-a[mid]);
        return distance;
    }
    long long int getMinDistance(int i,int k,vector<int>& houses){
       int n=houses.size();
        
        if(i==n){
            if(k==0)return 0;
            else return INT_MAX;
        }
        if(dp[i][k]!=-1)return dp[i][k];
        long long int minDistanc=INT_MAX;
        if(k>0)
        for(int j=i;j<n;j++){
            minDistanc=min(minDistanc, minDistance(i,j,houses)+getMinDistance(j+1,k-1,houses));
        }
        
        return dp[i][k]=minDistanc;
        
    }
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(),houses.end());
        dp= vector<vector<int>>(10004,vector<int>(105,-1));
        long long int ans=getMinDistance(0,k,houses);
        return ans;
    }
    
};