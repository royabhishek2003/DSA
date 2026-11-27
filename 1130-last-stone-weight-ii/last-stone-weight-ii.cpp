class Solution {
public:
    int n;
    int targetsum;
    int solve(vector<int> &stones, int i, int sum, vector<vector<int>> &dp){
        if(i>=n){
            return sum;
        }
        if(dp[i][sum] !=-1){
            return dp[i][sum];
        }
        int take=0;
        if(sum+stones[i] <= targetsum){
            take = solve(stones,i+1,sum+stones[i],dp);
        }
        int not_take= solve(stones,i+1,sum,dp);
        return dp[i][sum]= max(take, not_take);
    }
    int lastStoneWeightII(vector<int>& stones) {
        // fantastic problem 
        // here we need to find the subset sum closest to sum/2 then only (S - 2*s1)-> will be minimum 
        int totalsum=0;
        for(int &ele: stones){
            totalsum+=ele;
        }
        targetsum= totalsum/2;
        n= stones.size();
        vector<vector<int>> dp(n+1,vector<int>(targetsum+1, -1));
        int closestsum= solve(stones,0,0, dp);
        return totalsum - 2*closestsum;
    }
};