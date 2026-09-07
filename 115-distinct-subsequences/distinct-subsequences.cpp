class Solution {
public:
    int dp[1001][1001];
    int n;
    int m;
    int solve(string &s, string &t, int i, int j){
        if(j == m){
            return 1;
        }
        if(i == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int take=0;
        if(s[i] == t[j]){
            take = solve(s, t,i+1,j+1);
        }
        int not_take= solve(s,t,i+1,j);
        return  dp[i][j] = take + not_take;
    }
    int numDistinct(string s, string t) {
        if(s.length() < t.length()) return false;
        n= s.length();
        m= t.length();
        memset(dp,-1,sizeof(dp));
        return solve(s,t,0,0);
    }
};