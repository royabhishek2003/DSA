class Solution {
public:
    int n;
    int solve(vector<int> &prices, int i, int canbuy, int k, int bought,vector<vector<vector<int>>> &dp){
        if(i>=n || bought>k ){
            return 0;
        }
        if(dp[i][canbuy][bought] !=-1){
            return dp[i][canbuy][bought];
        }
        if(canbuy ==1){
            int buy= -prices[i] + solve(prices, i+1,0,k,bought+1, dp);
            int not_buy= solve(prices,i+1, 1,k,bought,dp);
            return dp[i][canbuy][bought]= max(buy, not_buy);
        }else{
            int sell = prices[i] + solve(prices,i+1,1,k,bought,dp);
            int not_sell= solve(prices,i+1,0,k,bought,dp);
            return dp[i][canbuy][bought] =max(sell, not_sell);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        // n= prices.size();
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2, vector<int>(k+2,-1)));
        // return solve(prices,0,1,k,0,dp);

        // using tabulation 
        int n= prices.size();
       vector<vector<vector<int>>>t(n+1,vector<vector<int>>(2, vector<int>(k+2,0)));
       for(int i=n-1;i>=0;i--){
        for(int canbuy=0;canbuy<2;canbuy++){
            for(int bought=0;bought<k+2;bought++){
                if(canbuy==1){
                    if(bought+1 < k+1){
                         t[i][canbuy][bought]= max( -prices[i] + t[i+1][0][bought+1],
                                                t[i+1][1][bought]);
                    }else{
                        t[i][canbuy][bought]=0;
                    }
                }else{
                    t[i][canbuy][bought]= max(prices[i] + t[i+1][1][bought],
                                                t[i+1][0][bought]);
                }
            }
        }
       }

       return t[0][1][0];

    }

};