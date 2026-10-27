class Solution {
public:
    int n,m;
    int dp[101][101];
    bool vis[101][101];
    int solve(vector<vector<int>> &matrix, int i, int j){
        if(i==n-1){
            return matrix[i][j];
        }
        if(vis[i][j]) return dp[i][j];
        vis[i][j]=true;
        int minsum=INT_MAX;
        if(i+1 <n)
        minsum= min(minsum, matrix[i][j] + solve(matrix,i+1,j));
        if(j+1 <m && i+1 <n){
        minsum= min(minsum, matrix[i][j] + solve(matrix,i+1,j+1));
        }
        if(j-1 >=0 && i+1 <n){
        minsum= min(minsum, matrix[i][j] + solve(matrix,i+1,j-1));
        }
        return dp[i][j]= minsum;

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n= matrix.size();
        m= matrix[0].size();
        int minsum=INT_MAX;
        int row=0;
        memset(dp,false,sizeof(vis));

        for(int col=0;col<m;col++){
            minsum= min(minsum, solve(matrix,row,col));
        }
        return minsum;
    }
};