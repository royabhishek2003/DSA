class Solution {
public:
    int dp[46];
    int solve(int n){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(dp[n] !=-1) return dp[n];
        int ways1= solve(n-1);
        int ways2= solve(n-2);
        return dp[n]= ways1+ways2;
    }
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};