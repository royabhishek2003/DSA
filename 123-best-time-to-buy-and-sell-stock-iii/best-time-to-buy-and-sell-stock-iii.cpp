class Solution {
public:
    int n;
    int solve(vector<int> &prices, int i, int canbuy, int bought, auto &dp){
        if(i>=n || (canbuy && bought ==2)){
            return 0;
        }
        if(dp[i][canbuy][bought]!=-1){
            return dp[i][canbuy][bought];
        }
        if(canbuy){
            int buy = -prices[i] + solve(prices, i+1,0, bought+1,dp);
            int not_buy=  solve(prices,i+1,1,bought,dp);

            return dp[i][canbuy][bought]= max(buy, not_buy);
        }else{
            int sell= prices[i] + solve(prices,i+1,1,bought,dp);
            int not_sell= solve(prices,i+1,0,bought,dp);
            return dp[i][canbuy][bought]=  max(sell, not_sell);
        }
    }
    int maxProfit(vector<int>& prices) {
        n= prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,0,true,0,dp);

        // using tabulation 
        // int n= prices.size();
        // vector<vector<vector<int>>> t(n+1,vector<vector<int>>(3,vector<int>(3,0)));
        // t[n][2][1]=0;
        // for(int i=n-1;i>=0;i--){
        //     for(int j=0;j<3;j++){
        //         for(int k=0;k<3;k++){
        //             if(j!=0){

        //             }
        //         }
        //     }
        // }

    }
};