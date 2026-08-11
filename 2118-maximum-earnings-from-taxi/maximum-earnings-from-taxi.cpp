class Solution {
public:
    int size;
    long long dp[30001];
    long long solve(int i, auto &rides) {
    if (i >= size) {
        return 0;
    }

    if(dp[i]!=-1) return dp[i];

    int nxt = lower_bound(
        rides.begin(), rides.end(), rides[i][1],
        [](const vector<int>& ride, int start) {
            return ride[0] < start;
        }
    ) - rides.begin();

    long long take =
        (long long)(rides[i][1] - rides[i][0] + rides[i][2]
        + solve(nxt, rides));

    long long not_take = solve(i + 1, rides);

    return dp[i]= max(take, not_take);
}
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        size=rides.size();
        memset(dp,-1,sizeof(dp));
        sort(rides.begin(),rides.end());
        return solve(0,rides);
    }
};