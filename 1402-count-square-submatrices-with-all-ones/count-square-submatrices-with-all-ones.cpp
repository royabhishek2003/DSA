class Solution {
public:
    int n,m;
    int dp[301][301];
    int solve(vector<vector<int>> &matrix, int i, int j){
        if(i>=n || j>=m || matrix[i][j]==0){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int rightone= solve(matrix,i,j+1);
        int downone= solve(matrix,i+1,j);
        int diagonalone= solve(matrix,i+1,j+1);
        return dp[i][j]= 1 + min({rightone, downone , diagonalone});

    }
    int countSquares(vector<vector<int>>& matrix) {
        // using recusrion + memoization 
        n= matrix.size();
        m= matrix[0].size();
        // int count=0;
        // memset(dp,-1,sizeof(dp));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         count+= solve(matrix,i,j);
        //     }
        // }
        // return count;


        // using Tabulation
        vector<vector<int>> t(n,vector<int>(m,0));
        //t[i][j] -> t[i][j] se kitne square submatrices bane hai uper ki tarf 
        // fill the first row and column as it is cause waha se uper ya toh 1 sqaure matrices honge ye 0 
        //  and for rest keep the logic as it is 
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0){
                    t[i][j]=matrix[i][j];
                }else{
                    if(matrix[i][j]==1){
                        t[i][j]= 1 + min({t[i][j-1], t[i-1][j] , t[i-1][j-1]});
                    }
                }
                result+=t[i][j];
            }
        }
        return result;
    }
};