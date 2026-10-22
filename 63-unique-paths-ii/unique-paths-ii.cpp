class Solution {
public:
    int dp[101][101];
    long long solve(int i, int j, vector<vector<int>>& grid){
        if(i<0 || j<0) return 0;
        if(grid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        long long topdown = solve(i-1,j,grid) ;
        long long leftright= solve(i,j-1,grid);
        return  dp[i][j]= topdown+ leftright;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n=obstacleGrid[0].size();
        // memset(dp, -1, sizeof(dp));
        // return solve(m-1,n-1,obstacleGrid);


        // using tabulation 
        if(obstacleGrid[0][0]==1) return 0;
        if(obstacleGrid[m-1][n-1]==1) return 0;
        vector<vector<int >> t(m,vector<int>(n,0));
        bool flag=false;
        for(int i=0;i<m;i++){
           if(obstacleGrid[i][0]==1) flag=true;
           if(flag) t[i][0]=0;
           else t[i][0]=1; 
        }
        flag=false;
         for(int j=0;j<n;j++){
            if(obstacleGrid[0][j]==1) flag=true;
            if(flag) t[0][j]=0;
            else t[0][j]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1) t[i][j]=0;
                else {
                    t[i][j]= t[i-1][j]+t[i][j-1];
                }
            }
        }
        return t[m-1][n-1];
    }
};