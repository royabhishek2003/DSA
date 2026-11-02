class Solution {
public:
    int n;
    int solve(vector<int> &prices, int i, int bought, auto &dp){
        if(i>=n){
            return 0;
        }
        if(dp[i][bought]!=-1){
            return dp[i][bought];
        }
        if(bought==0){
            // khridoon 
            int buy = -prices[i] +  solve(prices,i+1,1,dp);
            // nahi kharidoon 
            int not_buy= solve(prices,i+1,0,dp);
            return dp[i][bought]= max(buy,not_buy);
        }
        else{
            // bechoon
            int sell =  prices[i] + solve(prices,i+1,0,dp);
            // nahi bechoon 
            int not_sell = solve(prices,i+1,1,dp);
            return dp[i][bought]= max(sell,not_sell);
        }
    }
    int maxProfit(vector<int>& prices) {
        n= prices.size();
        int maxval= *(max_element(prices.begin(),prices.end()));
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(prices,0,false,dp);
    }
};