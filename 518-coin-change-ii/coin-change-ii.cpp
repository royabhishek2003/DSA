class Solution {
public:
    int n;
    int solve(auto i, auto& coins, auto amount, auto &dp){
        if(amount ==0){
            return 1;
        }
        if(i==n) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];

        int take=0;
        if(amount >= coins[i]){
            take= solve(i,coins,amount-coins[i],dp);
        }
        int not_take= solve(i+1,coins,amount,dp);

        return  dp[i][amount]= take+not_take;
    }
    int change(int amount, vector<int>& coins) {
        n= coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return solve(0,coins,amount,dp);

        // using Tabulation method 
        // vector<long long> t(amount+1,0);
        // t[0]=1;
        // for(int &coin: coins){
        //     for(int i=coin;i<=amount;i++){
        //         t[i]= (long long)(t[i]+ t[i-coin]);
        //     }
        // }
        // return t[amount];


        vector<int> t(amount+1,0);
        t[0]=1;
        for(int &coin : coins){
            for(int i=1;i<=amount;i++){
                int take=0;
                if(i>=coin){
                    take= 1+ t[i];
                }
                int not_take= t[i-1];
                t[i]= take+not_take;
            }
        }
        return t[amount];
        
        
    }
};