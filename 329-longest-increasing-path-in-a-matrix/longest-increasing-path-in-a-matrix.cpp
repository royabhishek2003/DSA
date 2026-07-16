class Solution {
public:
    int n,m;
    vector<vector<int>> dir= {{0,1},{-1,0},{0,-1},{1,0}};
    int dfs(int i, int j, auto& matrix, auto& dp){
        if(dp[i][j]!=-1) return dp[i][j];
        int result = 1;
        int maxresult=0;
        for(vector<int> &vec: dir){
            int ni= i+ vec[0];
            int nj= j+ vec[1];
            if(ni>=0 && ni<n && nj>=0 && nj<m && matrix[ni][nj] > matrix[i][j]){
                maxresult = max(maxresult,dfs(ni,nj,matrix,dp));
            }
        }
        return dp[i][j]= result + maxresult;

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n= matrix.size();
        m= matrix[0].size();

        int maxlength =1;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               maxlength= max(maxlength,dfs(i,j,matrix,dp));
            }
        }
        return maxlength;


    }
};