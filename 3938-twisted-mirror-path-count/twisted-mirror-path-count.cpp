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
        // memset(dp,-1,sizeof(dp));
        // return solve(0,0,grid,1);


        // Tabulation 
        // left ->0, up->1
        vector<vector<vector<int>>> t(n,vector<vector<int>>(m,vector<int>(2)));
        t[0][0][0]=1;
        t[0][0][1]=1;
        // first row me jab tak mirror nhi aata tab tak 1 raste hai wo bhi left se aur mirror ke baad impossible hai jana 
        for(int col=1;col<m;col++){
            t[0][col][0]=1;
            if(grid[0][col]==1) break;
        }
        // first col me jab tak mirror nhi aata tab tak 1 raste hai wo bhi uperse se aur mirror ke baad impossible hai jana 
        for(int row=1;row<n;row++){
            t[row][0][1]=1;
            if(grid[row][0]==1) break;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[i][j-1]==1){ // agar left wala mirror tha matlab mirror pe sirf uper se hi aa sakte the 
                    t[i][j][0]= t[i][j-1][1];
                }else{ // agar left wala 0 hai matlab dono tarf se aa sakte hai
                    t[i][j][0]= (t[i][j-1][1]%MOD + t[i][j-1][0]%MOD)%MOD;
                }

                if(grid[i-1][j]==1){ // agar uper wala mirror hai toh matlab mirror pe sirf left se aa sakta the 
                    t[i][j][1]= t[i-1][j][0];
                }else{ // agar uper wala 0 hai toh waha kahi se bhi aa sakte the 
                    t[i][j][1]= (t[i-1][j][1]%MOD + t[i-1][j][0]%MOD)%MOD;
                }
            }
        }

        return (t[n-1][m-1][0] + t[n-1][m-1][1])%MOD;


    }
};