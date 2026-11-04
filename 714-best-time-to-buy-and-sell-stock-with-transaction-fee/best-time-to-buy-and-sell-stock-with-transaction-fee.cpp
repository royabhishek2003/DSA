class Solution {
public:
    int n;
    int solve(vector<int> &prices, int fees, int i, int canbuy,vector<vector<int>> &dp){
        if(i>=n){
            return 0;
        }
        if(dp[i][canbuy]!=-1){
            return dp[i][canbuy];
        }
        if(canbuy){
            int buy= -prices[i] + solve(prices,fees,i+1,0,dp);
            int not_buy= solve(prices,fees,i+1,1,dp);
            return dp[i][canbuy]= max(buy,not_buy);
        }
        else{
            int sell= prices[i] - fees + solve(prices, fees,i+1,1,dp);
            int not_sell= solve(prices,fees,i+1,0,dp);
            return dp[i][canbuy]=  max(sell,not_sell);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        
        // n= prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,-1));
        // return solve(prices,fee,0,true,dp);

        // using tabulation 
        int n= prices.size();
        vector<vector<int>> t(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j==1){
                    t[i][j]= max(-prices[i] + t[i+1][0], t[i+1][1]);
                }else{
                    t[i][j]= max(prices[i] - fee + t[i+1][1], t[i+1][0]);
                }
            }
        }
        return t[0][1] ;
    }
};