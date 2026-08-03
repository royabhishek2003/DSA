class Solution {
public:
    int dp[500][500];
    bool solve(int i, int j, auto &piles, auto &dp){
        if(i>=piles.size() || j<0) return 0;
        if(i==j){
            return piles[i];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int takefirst= piles[i] + min(solve(i+2,j,piles,dp),solve(i+1,j-1,piles,dp));
        int takelast= piles[j] + min(solve(i+1,j-1,piles,dp),solve(i,j-2,piles,dp));
        return  dp[i][j]= max(takefirst,takelast);
    }
    bool stoneGame(vector<int>& piles) {
        int n= piles.size();
        memset(dp,-1,sizeof(dp));
       int total_sum=0;
       for(int ele: piles){
        total_sum+=ele;
       }

       int alice_score= solve(0,n-1,piles,dp);
       if(total_sum- alice_score > alice_score) return true;
       return false;
    }
};