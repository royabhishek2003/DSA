class Solution {
public:
    const int MOD= 1e9+7;
    int n,m;
    vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
    int dfs(int i, int j, auto & dp, auto &grid){
        if(dp[i][j]!=-1) return dp[i][j];
        int result=1;
        for(vector<int> &vec: dir){
            int ni= i+ vec[0];
            int nj= j+ vec[1];
            if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj] <grid[i][j] ){
                result = (result + dfs(ni,nj,dp,grid))%MOD;
            }
        }
        return dp[i][j]=result;
    }
    int countPaths(vector<vector<int>>& grid) {
        n= grid.size();
        m= grid[0].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        vector<vector<int>> ans(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]= dfs(i,j,dp,grid);
            }
        }

        int result=0;
        for(vector<int> &vec: ans){
            for(int &ele: vec) result = (result + ele)%MOD;
        }

        return (int)result;
    }
};