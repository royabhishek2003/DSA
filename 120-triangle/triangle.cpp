class Solution {
public:
    int n;
    int dp[201][20101];
    bool vis[201][20101];
    int solve(vector<vector<int>> & triangle, int i, int j){
        if(i==n-1){
            return triangle[i][j];
        }
        if(vis[i][j]){
            return dp[i][j];
        }
        vis[i][j]=true;
        int minsum= INT_MAX;
        if(i+1<n){
            minsum = min(minsum, triangle[i][j] + solve(triangle,i+1,j));
            minsum = min(minsum, triangle[i][j] + solve(triangle,i+1,j+1));
        }
        return dp[i][j]= minsum;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n= triangle.size();
        memset(vis,false,sizeof(vis));
        return solve(triangle,0,0);
    }
};