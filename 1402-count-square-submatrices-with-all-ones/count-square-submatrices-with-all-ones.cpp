class Solution {
public:
    int n,m;
    int dp[301][301];
    int solve(vector<vector<int>> &matrix, int i, int j){
        if(i>=n || j>=m || matrix[i][j]==0){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int leftone= solve(matrix,i,j+1);
        int downone= solve(matrix,i+1,j);
        int diagonalone= solve(matrix,i+1,j+1);
        return dp[i][j]= 1 + min({leftone, downone , diagonalone});

    }
    int countSquares(vector<vector<int>>& matrix) {
        // using recusrion + memoization 
        n= matrix.size();
        m= matrix[0].size();
        int count=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                count+= solve(matrix,i,j);
            }
        }
        return count;
    }
};