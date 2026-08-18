class Solution {
public:
    int n;

    int solve(auto &events, int i, int k, int count, auto &dp){
        if(i>=n || count >=k){
            return 0;
        }
        if(dp[count][i]!=-1) return dp[count][i];

        int  next= upper_bound(events.begin(),events.end(),events[i][1], [](int end,vector<int> &event){
            return end < event[0];
        }) - events.begin();

        long long  take= events[i][2] + solve(events,next,k,count+1,dp);
        long long  not_take= solve(events,i+1,k,count,dp);

        return dp[count][i]= (int)max(take,not_take);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        n= events.size();
        sort(events.begin(),events.end());
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        return solve(events,0,k,0,dp);
    }
};