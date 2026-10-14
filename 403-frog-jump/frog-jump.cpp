class Solution {
public:
    int n;
    unordered_map<int,int> mp;
    int dp[2001][2001];
    bool solve(vector<int> &stones, int i,int prevstepcount){
        if(i==n-1){
            return true;
        }
        if(i>=n) return false;
        if(dp[i][prevstepcount]!=-1) return dp[i][prevstepcount];
        for(int j=prevstepcount-1;j<=prevstepcount+1;j++){
            if(j<0 || j==0) continue;
            if(mp.find(j+stones[i])==mp.end()){
                continue;
            }
            if(solve(stones,mp[j+stones[i]],j)) return dp[i][prevstepcount]=true;
        }

        return dp[i][prevstepcount]= false;

    }
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1) return false;
        n= stones.size();
        mp.clear();
        for(int i=0;i<n;i++) mp[stones[i]]=i;
        memset(dp,-1,sizeof(dp));
        return solve(stones,1,1);
    }
};