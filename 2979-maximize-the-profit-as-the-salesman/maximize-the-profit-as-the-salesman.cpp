class Solution {
public:
    int size;
    int dp[100001];
    int solve(auto &offers, int i){
        if(i>=size){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int next = upper_bound(
        offers.begin() + i + 1,
        offers.end(),
        offers[i][1],
        [](int end, const vector<int>& offer) {
            return end < offer[0];
        }
    ) - offers.begin();
    int take = offers[i][2] + solve(offers, next);
    int not_take= solve(offers,i+1);
    return dp[i]=max(take,not_take);
        
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end());
        size= offers.size();
        memset(dp,-1,sizeof(dp));

        return solve(offers,0);
    }
};