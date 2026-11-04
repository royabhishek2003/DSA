class Solution {
public:
    int n;
    int dp[5001][2];
    int solve(vector<int> &prices, int i, int canbuy){
        if(i>=n){
            return 0;
        }
        if(dp[i][canbuy]!=-1){
            return dp[i][canbuy];
        }
        if(canbuy){
            int buy= -prices[i] + solve(prices,i+1,0);
            int not_buy= solve(prices,i+1,1);
            return dp[i][canbuy]= max(buy, not_buy);
        }else{
            int sell= prices[i] + solve(prices,i+2,1);
            int not_sell= solve(prices,i+1,0);
            return dp[i][canbuy]= max(sell,not_sell);
        }
        
    }
    int maxProfit(vector<int>& prices) {
        n= prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,1);
    }
};