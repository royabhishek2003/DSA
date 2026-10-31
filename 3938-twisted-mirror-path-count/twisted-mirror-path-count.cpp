class Solution {
public:
    int n,m;
    int dp[501][501][2];
    const int MOD= 1000000007;
    int solve(int i, int j, auto &grid, int up){
        if(i>=n || j>=m){
            return 0;
        }
        if(i==n-1 && j==m-1){
            return 1;
        }
        if(dp[i][j][up]!=-1) return dp[i][j][up];
        if(grid[i][j]==1){
            if(up==0){ // left se aaya hai toh neeche reflect hoga
                return dp[i][j][up]= solve(i+1,j,grid,1);
            }else{ // else right reflect hoga 
                return dp[i][j][up]= solve(i,j+1,grid,0);
            }
        }
        int left = solve(i,j+1,grid,0)%MOD;
        int down = solve(i+1,j,grid,1)%MOD;
        return dp[i][j][up]= (left + down)%MOD;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        n= grid.size();
        m= grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,grid,1);
    }
};